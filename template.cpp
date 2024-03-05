#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmin(T &a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
constexpr int INF = 1000000000;
constexpr int64_t llINF = 3000000000000000000;
constexpr double eps = 1e-10;
const double pi = acos(-1);
vector<int> calc_factor(int n) {
    vector<int> least_factor(n + 1, 0), prime_list;
    for (int i = 2; i <= n; i++) {
        if (least_factor[i] == 0) {
            least_factor[i] = i;
            prime_list.push_back(i);
        }
        for (int j = 0; j < (int)prime_list.size() && i * prime_list[j] <= n; j++) {
            least_factor[i * prime_list[j]] = prime_list[j];
            if (prime_list[j] == least_factor[i]) break;
        }
    }
    return least_factor;
}
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll modpow(ll a, ll b, ll m) {
    ll res = 1;
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
template <int modulo>
struct modint {
    int x;
    modint() : x(0) {}
    modint(int64_t y) : x(y >= 0 ? y % modulo : (modulo - (-y) % modulo) % modulo) {}
    modint &operator+=(const modint &p) {
        if ((x += p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint &operator-=(const modint &p) {
        if ((x += modulo - p.x) >= modulo) x -= modulo;
        return *this;
    }
    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % modulo);
        return *this;
    }
    modint &operator/=(const modint &p) {
        *this *= p.inv();
        return *this;
    }
    modint operator-() const { return modint(-x); }
    modint operator+(const modint &p) const { return modint(*this) += p; }
    modint operator-(const modint &p) const { return modint(*this) -= p; }
    modint operator*(const modint &p) const { return modint(*this) *= p; }
    modint operator/(const modint &p) const { return modint(*this) /= p; }
    bool operator==(const modint &p) const { return x == p.x; }
    bool operator!=(const modint &p) const { return x != p.x; }
    modint inv() const {
        int a = x, b = modulo, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }
    friend istream &operator>>(istream &is, modint &a) {
        int64_t t;
        is >> t;
        a = modint<modulo>(t);
        return (is);
    }
    int val() const { return x; }
    static constexpr int mod() { return modulo; }
    static constexpr int half() { return (modulo + 1) >> 1; }
};
template <typename T>
struct Binomial {
    vector<T> inv, fact, factinv;
    Binomial(int n) {
        assert(n > 0);
        inv.resize(n + 1);
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv[0] = fact[0] = factinv[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        factinv[n] = fact[n].inv();
        inv[n] = fact[n - 1] * factinv[n];
        for (int i = n - 1; i >= 1; i--) {
            factinv[i] = factinv[i + 1] * (i + 1);
            inv[i] = fact[i - 1] * factinv[i];
        }
    }
    T C(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r] * factinv[r];
    }
    T P(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r];
    }
    T H(int n, int r) {
        if (n == 0 && r == 0) return 1;
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};