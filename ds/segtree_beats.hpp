#pragma once
// Segment Tree Beats（AtCoder Library の lazy_segtree を元にしたもの）
//
// lazy_segtree との違いは mapping の形だけ。
//   bool mapping(F f, S& x)
//     x に f をその場で適用して true を返す。
//     このノードでまとめて適用できないときは false を返す。そのときは f を子に伝えて
//     x を子から計算し直すので、x を途中まで書き換えたまま false を返してよい。
//     長さ 1 の区間と e() に対しては、必ず true を返すこと。
// op, e, composition, id と、set, get, prod, all_prod, apply, max_right, min_left の使い方は
// atcoder::lazy_segtree と同じ。

#include <algorithm>
#include <bit>
#include <cassert>
#include <type_traits>
#include <vector>

template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct segtree_beats {
    static_assert(std::is_invocable_r_v<S, decltype(op), S, S>, "op must work as S(S, S)");
    static_assert(std::is_invocable_r_v<S, decltype(e)>, "e must work as S()");
    static_assert(std::is_invocable_r_v<bool, decltype(mapping), F, S&>,
                  "mapping must work as bool(F, S&)");
    static_assert(std::is_invocable_r_v<F, decltype(composition), F, F>,
                  "composition must work as F(F, F)");
    static_assert(std::is_invocable_r_v<F, decltype(id)>, "id must work as F()");

   public:
    segtree_beats() : segtree_beats(0) {}
    explicit segtree_beats(int n) : segtree_beats(std::vector<S>(n, e())) {}
    explicit segtree_beats(const std::vector<S>& v) : _n(int(v.size())) {
        size = int(std::bit_ceil((unsigned int)_n));
        log = std::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        [[maybe_unused]] bool ok = mapping(f, d[p]);
        assert(ok);  // 長さ 1 の区間では必ず成功する
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
        l += size;
        r += size;
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <class G>
    int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <class G>
    int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        const bool ok = mapping(f, d[k]);
        assert(ok || k < size);  // 長さ 1 の区間では必ず成功する
        if (k < size) {
            lz[k] = composition(f, lz[k]);
            // ここでまとめて適用できなかったときは、子に伝えて計算し直す
            if (!ok) {
                push(k);
                update(k);
            }
        }
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

// ---- よく使う S と F ----

// 区間 chmin、区間 chmax、区間加算、区間和（値は long long）
//   using namespace chmin_chmax_add_sum;
//   Seg seg(vector<S>(a.begin(), a.end()));  // a は vector<long long>
//   seg.apply(l, r, F::chmin(x));            // F::chmax(x)、F::add(x) も同じ形
//   seg.prod(l, r).sum                       // 最小値は .lo、最大値は .hi
// 値の絶対値は 2^61 より十分小さいこと
namespace chmin_chmax_add_sum {
using T = long long;

struct S {
    static constexpr T INF = T(1) << 61;
    T lo = INF, lo2 = INF;    // 最小値、2番目に小さい値（なければ INF）
    T hi = -INF, hi2 = -INF;  // 最大値、2番目に大きい値（なければ -INF）
    T sum = 0;
    int nlo = 0, nhi = 0, sz = 0;  // 最小値の個数、最大値の個数、長さ
    S() = default;                 // 単位元（長さ 0）
    S(T x) : lo(x), hi(x), sum(x), nlo(1), nhi(1), sz(1) {}
};

inline S op(S l, S r) {
    if (l.sz == 0) return r;
    if (r.sz == 0) return l;
    S s;
    s.lo = std::min(l.lo, r.lo);
    s.lo2 = l.lo == r.lo  ? std::min(l.lo2, r.lo2)
            : l.lo < r.lo ? std::min(l.lo2, r.lo)
                          : std::min(l.lo, r.lo2);
    s.nlo = (l.lo == s.lo ? l.nlo : 0) + (r.lo == s.lo ? r.nlo : 0);
    s.hi = std::max(l.hi, r.hi);
    s.hi2 = l.hi == r.hi  ? std::max(l.hi2, r.hi2)
            : l.hi > r.hi ? std::max(l.hi2, r.hi)
                          : std::max(l.hi, r.hi2);
    s.nhi = (l.hi == s.hi ? l.nhi : 0) + (r.hi == s.hi ? r.nhi : 0);
    s.sum = l.sum + r.sum;
    s.sz = l.sz + r.sz;
    return s;
}
inline S e() { return S(); }

// x を min(max(x + bias, lb), ub) に移す（lb <= ub）
struct F {
    T bias = 0, lb = -S::INF, ub = S::INF;
    static F chmin(T x) { return {0, -S::INF, x}; }
    static F chmax(T x) { return {0, x, S::INF}; }
    static F add(T x) { return {x, -S::INF, S::INF}; }
};

// g ∘ f（f を先に適用する）
inline F composition(F g, F f) {
    return {f.bias + g.bias, std::clamp(f.lb + g.bias, g.lb, g.ub),
            std::clamp(f.ub + g.bias, g.lb, g.ub)};
}
inline F id() { return F(); }

inline bool mapping(F f, S& x) {
    if (x.sz == 0) return true;
    // 遅延した加算が大きいと和が途中で桁あふれしうるので、和は符号なしで計算する
    // （最後の和が long long に収まれば正しい値になる）
    auto add_mul = [](T s, T a, T c) {
        using U = unsigned long long;
        return T(U(s) + U(a) * U(c));
    };
    x.lo += f.bias;
    x.hi += f.bias;
    if (x.lo2 != S::INF) x.lo2 += f.bias;
    if (x.hi2 != -S::INF) x.hi2 += f.bias;
    x.sum = add_mul(x.sum, f.bias, x.sz);
    if (f.lb > x.lo) {
        if (f.lb >= x.lo2) return false;  // 最小値以外も変わるので子に任せる
        x.sum = add_mul(x.sum, f.lb - x.lo, x.nlo);
        if (x.hi == x.lo)
            x.hi = f.lb;
        else if (x.hi2 == x.lo)
            x.hi2 = f.lb;
        x.lo = f.lb;
    }
    if (f.ub < x.hi) {
        if (f.ub <= x.hi2) return false;  // 最大値以外も変わるので子に任せる
        x.sum = add_mul(x.sum, f.ub - x.hi, x.nhi);
        if (x.lo == x.hi)
            x.lo = f.ub;
        else if (x.lo2 == x.hi)
            x.lo2 = f.ub;
        x.hi = f.ub;
    }
    return true;
}

using Seg = segtree_beats<S, op, e, F, mapping, composition, id>;
}  // namespace chmin_chmax_add_sum
