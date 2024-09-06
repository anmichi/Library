
#include <bits/stdc++.h>
using namespace std;
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