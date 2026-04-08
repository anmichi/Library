#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace prime {
__int128_t modpow128(__int128_t a, ll b, ll m) {
    __int128_t res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        b >>= 1;
    }
    return res;
}
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    ll d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (ll a : (n < 4759123141 ? vector<ll>{2, 7, 61} : vector<ll>{2, 325, 9375, 28178, 450775, 9780504, 1795265022})) {
        if (a % n == 0) continue;
        ll t = d;
        __int128_t y = modpow128(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <class T>
T rand(T l, T r) {
    static mt19937 mt(random_device{}());
    // [l, r)
    if constexpr (is_integral_v<T>) {
        return uniform_int_distribution<T>(l, r - 1)(mt);
    } else if constexpr (is_floating_point_v<T>) {
        return uniform_real_distribution<T>(l, r)(mt);
    }
}
ll rho(ll n) {
    assert(n > 1);
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    ll R;
    auto f = [&](ll x) { return ll((__int128_t(x) * x + R) % n); };
    while (1) {
        ll y = 0, g = 1, q = 1, r = 1, x, ys;
        R = rand(2LL, n), y = rand(2LL, n);
        constexpr int m = 128;
        for (int r = 1; g == 1; r <<= 1) {
            x = y;
            for (int i = 0; i < r; i++) y = f(y);
            for (int k = 0; g == 1 && k < r; k += m) {
                ys = y;
                for (int i = 0; i < m && i < r - k; i++) {
                    q = __int128_t(q) * abs(x - (y = f(y))) % n;
                }
                g = gcd(q, n);
            }
        }
        if (g == n) do
                g = gcd(abs(x - (ys = f(ys))), n);
            while (g == 1);
        if (g != n) return g;
    }
}
vector<ll> factorize(ll n) {
    vector<ll> ans;
    function<void(ll)> rec = [&](ll x) {
        if (x == 1) return;
        ll p = rho(x);
        if (p == x) return ans.push_back(p);
        rec(p);
        rec(x / p);
    };
    rec(n);
    return ans;
}
ll primitive_root(ll p) {
    if (p == 2) return 1;
    auto pf = factorize(p - 1);
    sort(pf.begin(), pf.end());
    pf.erase(unique(pf.begin(), pf.end()), pf.end());
    for (int g = 2;; g++) {
        bool ok = true;
        for (ll& f : pf) {
            if (modpow128(g, (p - 1) / f, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
};  // namespace prime