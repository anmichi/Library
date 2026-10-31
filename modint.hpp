#include <bits/stdc++.h>
using namespace std;
template <int modulo>
struct modint {
    static_assert(1 <= modulo && modulo <= (1 << 30));
    int x;
    constexpr modint() : x(0) {}
    constexpr modint(int64_t y) : x(y >= 0 ? y % modulo : (modulo - (-y) % modulo) % modulo) {}
    static constexpr modint raw(int v) {
        modint r;
        r.x = v;
        return r;
    }
    constexpr modint& operator+=(const modint& p) {
        if ((x += p.x) >= modulo) x -= modulo;
        return *this;
    }
    constexpr modint& operator-=(const modint& p) {
        if ((x += modulo - p.x) >= modulo) x -= modulo;
        return *this;
    }
    constexpr modint& operator*=(const modint& p) {
        x = (int)(1LL * x * p.x % modulo);
        return *this;
    }
    constexpr modint& operator/=(const modint& p) {
        *this *= p.inv();
        return *this;
    }
    constexpr modint& operator++() {
        if (++x == modulo) x = 0;
        return *this;
    }
    constexpr modint& operator--() {
        if (x == 0) x = modulo;
        --x;
        return *this;
    }
    constexpr modint operator++(int) {
        modint r = *this;
        ++*this;
        return r;
    }
    constexpr modint operator--(int) {
        modint r = *this;
        --*this;
        return r;
    }
    constexpr modint operator-() const { return modint(-x); }
    constexpr modint operator+(const modint& p) const { return modint(*this) += p; }
    constexpr modint operator-(const modint& p) const { return modint(*this) -= p; }
    constexpr modint operator*(const modint& p) const { return modint(*this) *= p; }
    constexpr modint operator/(const modint& p) const { return modint(*this) /= p; }
    constexpr bool operator==(const modint& p) const { return x == p.x; }
    constexpr bool operator!=(const modint& p) const { return x != p.x; }
    constexpr modint inv() const {
        int a = x, b = modulo, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        assert(a == 1);
        return modint(u);
    }
    constexpr modint pow(int64_t n) const {
        modint ret(1), mul = n < 0 ? inv() : *this;
        uint64_t e = n < 0 ? -(uint64_t)n : n;
        while (e > 0) {
            if (e & 1) ret *= mul;
            mul *= mul;
            e >>= 1;
        }
        return ret;
    }
    friend ostream& operator<<(ostream& os, const modint& p) { return os << p.x; }
    friend istream& operator>>(istream& is, modint& a) {
        int64_t t;
        is >> t;
        a = modint<modulo>(t);
        return (is);
    }
    static constexpr int mod() { return modulo; }
};