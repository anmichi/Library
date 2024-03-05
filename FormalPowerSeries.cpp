#include <bits/stdc++.h>
using namespace std;
#include "ModSqrt.cpp"
template <typename mint>
struct FormalPowerSeries : vector<mint> {
    using vector<mint>::vector;
    using FPS = FormalPowerSeries;
    FPS& operator+=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
        return *this;
    }
    FPS& operator+=(const mint& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] += r;
        return *this;
    }

    FPS& operator-=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
        return *this;
    }

    FPS& operator-=(const mint& r) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= r;
        return *this;
    }
    FPS& operator*=(const FPS& r) {
        if (this->empty() || r.empty()) {
            this->clear();
            return *this;
        }
        assert(mint::mod() == 998244353);
        vector<mint> prod = atcoder::convolution(*this, r);
        this->resize((int)prod.size());
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] = prod[i];
        return *this;
    }
    FPS& operator*=(const mint& v) {
        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= v;
        return *this;
    }
    FPS& operator/=(const FPS& r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
    }
    FPS& operator%=(const FPS& r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }
    FPS operator+(const FPS& r) const { return FPS(*this) += r; }
    FPS operator+(const mint& v) const { return FPS(*this) += v; }
    FPS operator-(const FPS& r) const { return FPS(*this) -= r; }
    FPS operator-(const mint& v) const { return FPS(*this) -= v; }
    FPS operator*(const FPS& r) const { return FPS(*this) *= r; }
    FPS operator*(const mint& v) const { return FPS(*this) *= v; }
    FPS operator/(const FPS& r) const { return FPS(*this) /= r; }
    FPS operator%(const FPS& r) const { return FPS(*this) %= r; }
    FPS operator-() const {
        FPS ret(this->size());
        for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
        return ret;
    }
    void shrink() {
        while (this->size() && this->back() == mint(0)) this->pop_back();
    }
    FPS operator>>(int sz) const {
        if ((int)this->size() <= sz) return {};
        FPS ret(*this);
        ret.erase(ret.begin(), ret.begin() + sz);
        return ret;
    }
    FPS operator<<(int sz) const {
        FPS ret(*this);
        ret.insert(ret.begin(), sz, mint(0));
        return ret;
    }
    FPS pre(int sz) const { return FPS(begin(*this), begin(*this) + min((int)this->size(), sz)); }
    FPS rev() const {
        FPS ret(*this);
        reverse(begin(ret), end(ret));
        return ret;
    }
    FPS diff() const {
        const int n = this->size();
        FPS ret(max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * mint(i);
        return ret;
    }
    FPS integral() const {
        const int n = this->size();
        FPS ret(n + 1);
        ret[0] = mint(0);
        if (n > 0) ret[1] = mint(1);
        auto mod = mint::mod();
        for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i] * (mod / i));
        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];
        return ret;
    }
    FPS inv(int deg = -1) const {
        assert(((*this)[0]) != mint(0));
        const int n = this->size();
        if (deg == -1) deg = n;
        FPS ret({mint(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
        }
        return ret.pre(deg);
    }
    FPS log(int deg = -1) {
        assert((*this)[0] == mint(1));
        if (deg == -1) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }
    FPS exp(int deg = -1) const {
        assert((*this)[0] == mint(0));
        const int n = this->size();
        if (deg == -1) deg = n;
        FPS ret({mint(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }
    FPS pow(int64_t k, int deg = -1) const {
        const int n = this->size();
        if (deg == -1) deg = n;
        if (k == 0) {
            FPS ret(deg);
            if (deg) ret[0] = 1;
            return ret;
        }
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != mint(0)) {
                mint rev = mint(1) / (*this)[i];
                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
                ret *= (*this)[i].pow(k);
                ret = (ret << (i * k)).pre(deg);
                if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                return ret;
            }
            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));
        }
        return FPS(deg, mint(0));
    }
    FPS sqrt(int deg = -1) const {
        const int n = this->size();
        if (deg == -1) deg = n;
        if (n == 0) return FPS(deg, 0);
        if ((*this)[0] == mint(0)) {
            for (int i = 1; i < n; i++) {
                if ((*this)[i] != mint(0)) {
                    if (i & 1) return {};
                    if (deg - i / 2 <= 0) break;
                    auto ret = (*this >> i).sqrt(deg - i / 2);
                    if (ret.empty()) return {};
                    ret = ret << (i / 2);
                    if ((int)ret.size() < deg) ret.resize(deg, mint(0));
                    return ret;
                }
            }
            return FPS(deg, 0);
        }
        int64_t sqr = mod_sqrt((*this)[0].val(), mint::mod());
        if (sqr == -1) return {};
        assert(sqr * sqr % mint::mod() == (*this)[0].val());
        FPS ret({mint(sqr)});
        mint inv2 = mint(2).inv();
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        }
        return ret.pre(deg);
    }
    mint eval(mint x) const {
        mint r = 0, w = 1;
        for (auto& v : *this) r += w * v, w *= x;
        return r;
    }
};