#include <bits/stdc++.h>
using namespace std;
struct modint61 {
    static constexpr uint64_t mod = (1ULL << 61) - 1;
    uint64_t x;
    constexpr modint61() : x(0) {}
    constexpr modint61(int64_t y) : x(y >= 0 ? uint64_t(y) % mod : mod - 1 - uint64_t(-(y + 1)) % mod) {}
    constexpr modint61& operator+=(const modint61& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    constexpr modint61& operator-=(const modint61& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    constexpr modint61& operator*=(const modint61& p) {
        __uint128_t t = __uint128_t(x) * p.x;
        x = (uint64_t(t) & mod) + uint64_t(t >> 61);
        if (x >= mod) x -= mod;
        return *this;
    }
    constexpr modint61 operator-() const { return modint61() - *this; }
    constexpr modint61 operator+(const modint61& p) const { return modint61(*this) += p; }
    constexpr modint61 operator-(const modint61& p) const { return modint61(*this) -= p; }
    constexpr modint61 operator*(const modint61& p) const { return modint61(*this) *= p; }
    constexpr auto operator<=>(const modint61&) const = default;
    constexpr modint61 pow(uint64_t n) const {
        modint61 ret(1), mul = *this;
        for (; n; n >>= 1, mul *= mul) {
            if (n & 1) ret *= mul;
        }
        return ret;
    }
    constexpr modint61 inv() const {
        assert(x != 0);
        return pow(mod - 2);
    }
    constexpr uint64_t val() const { return x; }
    static modint61 random() {
        static mt19937_64 mt(random_device{}());
        return modint61(mt() % mod);
    }
    friend ostream& operator<<(ostream& os, const modint61& p) { return os << p.x; }
};
template <>
struct std::hash<modint61> {
    size_t operator()(const modint61& p) const { return p.x; }
};
struct RollingHash {
    using mint = modint61;
    static mint base() {
        static const mint b = mint::random();
        return b;
    }
    static mint pw(int n) {
        static vector<mint> p{1};
        while (int(p.size()) <= n) p.push_back(p.back() * base());
        return p[n];
    }
    template <class R>
    static mint eval(const R& s) {
        mint h;
        for (auto&& c : s) h = h * base() + c;
        return h;
    }
    static mint push_back(mint h, int64_t c) { return h * base() + c; }
    static mint concat(mint h1, mint h2, int len2) { return h1 * pw(len2) + h2; }

    struct S {
        mint h, p;
        bool operator==(const S&) const = default;
    };
    static S op(S a, S b) { return {a.h * b.p + b.h, a.p * b.p}; }
    static S e() { return {0, 1}; }
    static S single(int64_t c) { return {c, base()}; }

    vector<mint> h;
    RollingHash() : h(1) {}
    template <class R>
    RollingHash(const R& s) : h(1) {
        for (auto&& c : s) h.push_back(h.back() * base() + c);
    }
    int size() const { return int(h.size()) - 1; }
    mint get(int l, int r) const {
        assert(0 <= l && l <= r && r <= size());
        return h[r] - h[l] * pw(r - l);
    }
    int lcp(int i, const RollingHash& b, int j) const {
        int ok = 0, ng = min(size() - i, b.size() - j) + 1;
        while (ng - ok > 1) {
            int m = (ok + ng) / 2;
            (get(i, i + m) == b.get(j, j + m) ? ok : ng) = m;
        }
        return ok;
    }
};