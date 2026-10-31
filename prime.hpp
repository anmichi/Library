#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace prime {
using u64 = uint64_t;
using u128 = __uint128_t;
struct Montgomery {
    u64 n, ni, r2;
    Montgomery(u64 n) : n(n), ni(n), r2(-u128(n) % n) {
        for (int i = 0; i < 5; i++) ni *= 2 - n * ni;
    }
    u64 reduce(u128 t) const {
        u64 a = t >> 64, b = (u128(u64(t) * ni) * n) >> 64;
        return a >= b ? a - b : a - b + n;
    }
    u64 to(u64 a) const { return reduce(u128(a) * r2); }
    u64 mul(u64 a, u64 b) const { return reduce(u128(a) * b); }
    u64 pow(u64 a, u64 e) const {
        u64 r = to(1);
        for (; e; e >>= 1, a = mul(a, a)) {
            if (e & 1) r = mul(r, a);
        }
        return r;
    }
};
bool is_prime(ll n) {
    if (n <= 2) return n == 2;
    if (n % 2 == 0) return false;
    Montgomery mg(n);
    int s = __builtin_ctzll(n - 1);
    u64 d = (n - 1) >> s, one = mg.to(1), minus_one = mg.to(n - 1);
    auto check = [&](u64 a) {
        if (a % n == 0) return true;
        u64 y = mg.pow(mg.to(a), d);
        if (y == one) return true;
        for (int i = 0; i < s; i++, y = mg.mul(y, y)) {
            if (y == minus_one) return true;
        }
        return false;
    };
    if (n < 4759123141) return check(2) && check(7) && check(61);
    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (!check(a)) return false;
    }
    return true;
}
ll rho(ll n) {
    assert(n > 1);
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    static mt19937_64 mt(random_device{}());
    Montgomery mg(n);
    while (true) {
        u64 c = mt() % (n - 1) + 1, y = mt() % n, x, ys, q = 1, g = 1;
        auto f = [&](u64 v) {
            v = mg.mul(v, v) + c;
            return v >= u64(n) ? v - n : v;
        };
        auto dist = [](u64 a, u64 b) { return a > b ? a - b : b - a; };
        constexpr int m = 128;
        for (int r = 1; g == 1; r <<= 1) {
            x = y;
            for (int i = 0; i < r; i++) y = f(y);
            for (int k = 0; g == 1 && k < r; k += m) {
                ys = y;
                for (int i = 0; i < m && i < r - k; i++) q = mg.mul(q, dist(x, y = f(y)));
                g = gcd(q, u64(n));
            }
        }
        if (g == u64(n)) {
            do g = gcd(dist(x, ys = f(ys)), u64(n));
            while (g == 1);
        }
        if (g != u64(n)) return g;
    }
}
vector<ll> factorize(ll n) {
    vector<ll> ans;
    auto rec = [&](auto&& rec, ll x) -> void {
        if (x == 1) return;
        ll p = rho(x);
        if (p == x) return ans.push_back(p);
        rec(rec, p);
        rec(rec, x / p);
    };
    rec(rec, n);
    sort(ans.begin(), ans.end());
    return ans;
}
ll primitive_root(ll p) {
    if (p == 2) return 1;
    auto pf = factorize(p - 1);
    pf.erase(unique(pf.begin(), pf.end()), pf.end());
    Montgomery mg(p);
    u64 one = mg.to(1);
    for (int g = 2;; g++) {
        bool ok = true;
        for (ll& f : pf) {
            if (mg.pow(mg.to(g), (p - 1) / f) == one) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
}  // namespace prime