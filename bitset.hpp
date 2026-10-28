#pragma once
// AtCoder Library の static_modint / dynamic_modint と同じ形の bitset。
// std::bitset と名前がぶつからないよう、BitSet / DynamicBitSet とする。
//
//   BitSet<N> b;                      // サイズ N をコンパイル時に決める（中身は std::array）
//
//   DynamicBitSet<0>::set_size(n);    // id ごとにサイズを実行時に決める
//   DynamicBitSet<0> c;               // サイズは n（中身は std::vector）
//   std::vector<DynamicBitSet<0>> dp(k);  // サイズを渡さずに並べられる
//
// DynamicBitSet のサイズは id ごとに1つ。set_size より前に作ったオブジェクトは
// 古いサイズのままなので、set_size のあとに作る。サイズの違うものを同時に使うなら id を分ける。
//
// std::bitset と同じ操作に加えて、次を持つ。
//   _Find_first / _Find_next  : libstdc++ の拡張と同じ（見つからなければ size()）
//   _Find_last  / _Find_prev  : 後ろ向きの検索（見つからなければ size()）
//   index_xor(x)              : b[i] <- b[i ^ x]
//   a                         : 64 ビットごとの語の配列（公開）。size() 以上のビットは常に 0

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

namespace bitset_internal {

template <std::size_t N>
struct static_storage {
    static constexpr bool is_dynamic = false;
    std::array<std::uint64_t, (N + 63) / 64> a{};
    static constexpr std::size_t size() { return N; }
};

template <int id>
struct dynamic_storage {
    static constexpr bool is_dynamic = true;
    std::vector<std::uint64_t> a;
    dynamic_storage() : a((n_ + 63) / 64) {}
    static std::size_t size() { return n_; }
    static void set_size(std::size_t n) { n_ = n; }

   private:
    static inline std::size_t n_ = 0;
};

template <class S>
struct bitset_base : S {
    using u64 = std::uint64_t;
    using S::a;
    using S::is_dynamic;
    using S::size;

    // ---- コンストラクタ ----
    bitset_base() = default;

    bitset_base(unsigned long long val) {
        if (a.size()) a[0] = val;
        trim();
    }

    // std::bitset と同じく s[pos] が最上位。読むのは size() 文字まで
    explicit bitset_base(const std::string& s, std::size_t pos = 0,
                         std::size_t len = std::string::npos, char zero = '0', char one = '1') {
        if (pos > s.size()) throw std::out_of_range("BitSet: pos > s.size()");
        const std::size_t m = std::min({len, s.size() - pos, size()});
        for (std::size_t i = 0; i < m; i++) {
            const char c = s[pos + i];
            if (c == one)
                a[(m - 1 - i) >> 6] |= bit(m - 1 - i);
            else if (c != zero)
                throw std::invalid_argument("BitSet: invalid character");
        }
    }

    // テンプレートにして、bitset(0) が const char* と曖昧にならないようにする（std::bitset と同じ）
    template <class CharT, std::enable_if_t<std::is_same_v<CharT, char>, int> = 0>
    explicit bitset_base(const CharT* s, std::size_t len = std::string::npos, char zero = '0',
                         char one = '1')
        : bitset_base(std::string(s), 0, len, zero, one) {}

    // ---- 要素アクセス ----
    struct reference {
        u64* w;
        u64 m;
        operator bool() const { return (*w & m) != 0; }
        bool operator~() const { return (*w & m) == 0; }
        reference& operator=(bool x) {
            if (x)
                *w |= m;
            else
                *w &= ~m;
            return *this;
        }
        reference& operator=(const reference& r) { return *this = bool(r); }
        reference& flip() {
            *w ^= m;
            return *this;
        }
    };

    reference operator[](std::size_t i) { return {&a[i >> 6], bit(i)}; }
    bool operator[](std::size_t i) const { return (a[i >> 6] >> (i & 63)) & 1; }
    bool test(std::size_t i) const {
        check(i);
        return (*this)[i];
    }

    // ---- 全体の性質 ----
    // 語の配列は a.data() のポインタで回す。std::array の a[i] のままだと
    // GCC が -O2 でベクトル化しないことがある
    std::size_t count() const {
        const u64* p = a.data();
        const std::size_t W = a.size();
        const std::size_t W4 = W & ~std::size_t(3);
        std::size_t c0 = 0, c1 = 0, c2 = 0, c3 = 0;  // 4 本に分けて足す
        for (std::size_t i = 0; i < W4; i += 4) {
            c0 += __builtin_popcountll(p[i]);
            c1 += __builtin_popcountll(p[i + 1]);
            c2 += __builtin_popcountll(p[i + 2]);
            c3 += __builtin_popcountll(p[i + 3]);
        }
        for (std::size_t i = W4; i < W; i++) c0 += __builtin_popcountll(p[i]);
        return c0 + c1 + c2 + c3;
    }
    bool any() const {
        const u64* p = a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++)
            if (p[i]) return true;
        return false;
    }
    bool none() const { return !any(); }
    bool all() const {
        const u64* p = a.data();
        const std::size_t W = a.size();
        if (W == 0) return true;
        for (std::size_t i = 0; i + 1 < W; i++)
            if (~p[i]) return false;
        return p[W - 1] == last_mask();
    }

    // ---- 変更 ----
    bitset_base& set() {
        u64* p = a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] = ~u64(0);
        trim();
        return *this;
    }
    bitset_base& set(std::size_t i, bool v = true) {
        check(i);
        (*this)[i] = v;
        return *this;
    }
    bitset_base& reset() {
        u64* p = a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] = 0;
        return *this;
    }
    bitset_base& reset(std::size_t i) {
        check(i);
        a[i >> 6] &= ~bit(i);
        return *this;
    }
    bitset_base& flip() {
        u64* p = a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] = ~p[i];
        trim();
        return *this;
    }
    bitset_base& flip(std::size_t i) {
        check(i);
        a[i >> 6] ^= bit(i);
        return *this;
    }

    // ---- ビット演算 ----
    bitset_base& operator&=(const bitset_base& o) {
        same_size(o);
        u64* p = a.data();
        const u64* q = o.a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] &= q[i];
        return *this;
    }
    bitset_base& operator|=(const bitset_base& o) {
        same_size(o);
        u64* p = a.data();
        const u64* q = o.a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] |= q[i];
        return *this;
    }
    bitset_base& operator^=(const bitset_base& o) {
        same_size(o);
        u64* p = a.data();
        const u64* q = o.a.data();
        const std::size_t W = a.size();
        for (std::size_t i = 0; i < W; i++) p[i] ^= q[i];
        return *this;
    }
    bitset_base operator~() const {
        bitset_base r = *this;
        r.flip();
        return r;
    }

    // b[i] <- b[i - s]
    bitset_base& operator<<=(std::size_t s) {
        if (s >= size()) return reset();
        u64* p = a.data();
        const std::size_t W = a.size(), q = s >> 6, r = s & 63;
        if (r == 0) {
            for (std::size_t i = W; i-- > q;) p[i] = p[i - q];
        } else {
            for (std::size_t i = W; i-- > q + 1;)
                p[i] = (p[i - q] << r) | (p[i - q - 1] >> (64 - r));
            p[q] = p[0] << r;
        }
        for (std::size_t i = 0; i < q; i++) p[i] = 0;
        trim();
        return *this;
    }
    // b[i] <- b[i + s]
    bitset_base& operator>>=(std::size_t s) {
        if (s >= size()) return reset();
        u64* p = a.data();
        const std::size_t W = a.size(), q = s >> 6, r = s & 63;
        if (r == 0) {
            for (std::size_t i = 0; i + q < W; i++) p[i] = p[i + q];
        } else {
            for (std::size_t i = 0; i + q + 1 < W; i++)
                p[i] = (p[i + q] >> r) | (p[i + q + 1] << (64 - r));
            p[W - 1 - q] = p[W - 1] >> r;
        }
        for (std::size_t i = W - q; i < W; i++) p[i] = 0;
        return *this;
    }
    bitset_base operator<<(std::size_t s) const {
        bitset_base r = *this;
        r <<= s;
        return r;
    }
    bitset_base operator>>(std::size_t s) const {
        bitset_base r = *this;
        r >>= s;
        return r;
    }

    // 参照を返すと戻り値でもう1回コピーが起きるので、いったん演算してから返す
    friend bitset_base operator&(bitset_base l, const bitset_base& r) {
        l &= r;
        return l;
    }
    friend bitset_base operator|(bitset_base l, const bitset_base& r) {
        l |= r;
        return l;
    }
    friend bitset_base operator^(bitset_base l, const bitset_base& r) {
        l ^= r;
        return l;
    }

    bool operator==(const bitset_base& o) const { return a == o.a; }
    bool operator!=(const bitset_base& o) const { return !(a == o.a); }

    // ---- 変換 ----
    std::string to_string(char zero = '0', char one = '1') const {
        const std::size_t n = size();
        std::string s(n, zero);
        for (std::size_t i = _Find_first(); i < n; i = _Find_next(i)) s[n - 1 - i] = one;
        return s;
    }
    unsigned long long to_ullong() const {
        for (std::size_t i = 1; i < a.size(); i++)
            if (a[i]) throw std::overflow_error("BitSet::to_ullong");
        return a.size() ? a[0] : 0;
    }
    unsigned long to_ulong() const {
        const unsigned long long v = to_ullong();
        if (v > ULONG_MAX) throw std::overflow_error("BitSet::to_ulong");
        return (unsigned long)v;
    }

    friend std::ostream& operator<<(std::ostream& os, const bitset_base& b) {
        return os << b.to_string();
    }
    // 空白で区切られた 0/1 の列を読む
    friend std::istream& operator>>(std::istream& is, bitset_base& b) {
        std::string s;
        if (is >> s) b = bitset_base(s);
        return is;
    }

    // ---- 検索（見つからなければ size()） ----
    std::size_t _Find_first() const { return find_from(0); }
    std::size_t _Find_next(std::size_t prev) const { return find_from(prev + 1); }
    std::size_t _Find_last() const { return find_before(size()); }
    std::size_t _Find_prev(std::size_t next) const { return find_before(next); }

    // ---- 添字の xor ----
    // b[i] <- b[i ^ x]。0 <= i < size() で i ^ x < size() となる x だけ受け付ける
    // （size() が 2^k の倍数で x < 2^k なら OK）
    bitset_base& index_xor(std::size_t x) {
        assert(xor_ok(x));
        static constexpr u64 M[6] = {
            0x5555555555555555ULL, 0x3333333333333333ULL, 0x0F0F0F0F0F0F0F0FULL,
            0x00FF00FF00FF00FFULL, 0x0000FFFF0000FFFFULL, 0x00000000FFFFFFFFULL,
        };
        u64* p = a.data();
        const std::size_t W = a.size();
        // 語の中: x の下位 6 ビットで立っているビットごとに全体を1回ずつ走査する。
        // 語ごとに 6 回まとめて処理するよりベクトル化が効いて速い
        for (int t = 0; t < 6; t++)
            if (x >> t & 1) {
                const int s = 1 << t;
                const u64 m = M[t];
                for (std::size_t i = 0; i < W; i++) p[i] = ((p[i] & m) << s) | ((p[i] >> s) & m);
            }
        // 語どうし: 語 j と語 j ^ hi を入れ替える。hi の最下位ビットを L とすると、
        // 長さ L の連続した塊どうしの入れ替えになる。L が大きければ塊ごとにまとめて入れ替え、
        // 小さければ1語ずつ入れ替える（塊が短いとまとめる手間のほうが重い）
        const std::size_t hi = x >> 6;
        if (hi) {
            const std::size_t L = hi & (~hi + 1);
            if (L >= 4) {
                for (std::size_t j = 0; j < W; j += L) {
                    const std::size_t t = j ^ hi;
                    if (j < t && t < W) swap_block(p + j, p + t, L);
                }
            } else {
                for (std::size_t j = 0; j < W; j++) {
                    const std::size_t t = j ^ hi;
                    if (j < t && t < W) std::swap(p[j], p[t]);
                }
            }
        }
        return *this;
    }

   private:
    // 重ならない2つの塊を入れ替える。__restrict でベクトル化させる
    static void swap_block(u64* __restrict x, u64* __restrict y, std::size_t L) {
        for (std::size_t i = 0; i < L; i++) {
            const u64 v = x[i];
            x[i] = y[i];
            y[i] = v;
        }
    }
    static u64 bit(std::size_t i) { return u64(1) << (i & 63); }
    static u64 last_mask() {
        const std::size_t r = size() & 63;
        return r ? (u64(1) << r) - 1 : ~u64(0);
    }
    void trim() {
        if (a.size()) a[a.size() - 1] &= last_mask();
    }
    void check(std::size_t i) const {
        if (i >= size()) throw std::out_of_range("BitSet: index out of range");
    }
    void same_size([[maybe_unused]] const bitset_base& o) const {
        if constexpr (is_dynamic) {
            assert(a.size() == (size() + 63) / 64 && "set_size より前に作った bitset");
            assert(a.size() == o.a.size());
        }
    }
    static bool xor_ok(std::size_t x) {
        if (x == 0) return true;
        const int k = 64 - __builtin_clzll(x);  // x < 2^k
        return k < 64 && size() % (std::size_t(1) << k) == 0;
    }

    // 位置が i 以上で最初の 1
    std::size_t find_from(std::size_t i) const {
        const std::size_t W = a.size();
        const u64* p = a.data();
        if (i >= W * 64) return size();
        std::size_t k = i >> 6;
        const u64 w = p[k] & (~u64(0) << (i & 63));
        if (w) return k * 64 + __builtin_ctzll(w);
        for (k++; k < W; k++)
            if (p[k]) return k * 64 + __builtin_ctzll(p[k]);
        return size();
    }
    // 位置が i 未満で最後の 1
    std::size_t find_before(std::size_t i) const {
        if (i > size()) i = size();
        if (i == 0) return size();
        std::size_t k = (i - 1) >> 6;
        u64 w = a[k] & (~u64(0) >> (63 - ((i - 1) & 63)));
        while (true) {
            if (w) return (k << 6) | (63 - __builtin_clzll(w));
            if (k-- == 0) return size();
            w = a[k];
        }
    }
};

}  // namespace bitset_internal

template <std::size_t N>
using BitSet = bitset_internal::bitset_base<bitset_internal::static_storage<N>>;
template <int id>
using DynamicBitSet = bitset_internal::bitset_base<bitset_internal::dynamic_storage<id>>;