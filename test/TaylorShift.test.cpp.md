---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Binomial.cpp
    title: Binomial.cpp
  - icon: ':heavy_check_mark:'
    path: FormalPowerSeries.cpp
    title: FormalPowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod_sqrt.cpp
    title: mod_sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: modint_io.cpp
    title: modint_io.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "#line 1 \"test/TaylorShift.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n#line 1 \"Binomial.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <typename T>\nstruct Binomial {\n    vector<T> inv, fact, factinv;\n    Binomial(int\
    \ n) {\n        inv.resize(n + 1);\n        fact.resize(n + 1);\n        factinv.resize(n\
    \ + 1);\n        inv[0] = fact[0] = factinv[0] = 1;\n        for (int i = 1; i\
    \ <= n; i++) fact[i] = fact[i - 1] * i;\n        factinv[n] = fact[n].inv();\n\
    \        inv[n] = fact[n - 1] * factinv[n];\n        for (int i = n - 1; i >=\
    \ 1; i--) {\n            factinv[i] = factinv[i + 1] * (i + 1);\n            inv[i]\
    \ = fact[i - 1] * factinv[i];\n        }\n    }\n    T C(int n, int r) {\n   \
    \     if (n < 0 || n < r || r < 0) return 0;\n        return fact[n] * factinv[n\
    \ - r] * factinv[r];\n    }\n    T P(int n, int r) {\n        if (n < 0 || n <\
    \ r || r < 0) return 0;\n        return fact[n] * factinv[n - r];\n    }\n   \
    \ T H(int n, int r) {\n        if (n == 0 && r == 0) return 1;\n        if (n\
    \ < 0 || r < 0) return 0;\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n\
    };\n#line 1 \"FormalPowerSeries.cpp\"\n#include <atcoder/convolution>\n#line 2\
    \ \"template.cpp\"\nusing namespace std;\nusing ll = long long;\n#define rep(i,\
    \ n) for (int i = 0; i < n; i++)\n#define all(v) v.begin(), v.end()\ntemplate\
    \ <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\ntemplate <class\
    \ T, class U>\ninline bool chmin(T &a, U b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\nconstexpr int INF = 1000000000;\n\
    constexpr int64_t llINF = 3000000000000000000;\nconstexpr double eps = 1e-10;\n\
    const double pi = acos(-1);\nvector<int> calc_factor(int n) {\n    vector<int>\
    \ least_factor(n + 1, 0), prime_list;\n    for (int i = 2; i <= n; i++) {\n  \
    \      if (least_factor[i] == 0) {\n            least_factor[i] = i;\n       \
    \     prime_list.push_back(i);\n        }\n        for (int j = 0; j < (int)prime_list.size()\
    \ && i * prime_list[j] <= n; j++) {\n            least_factor[i * prime_list[j]]\
    \ = prime_list[j];\n            if (prime_list[j] == least_factor[i]) break;\n\
    \        }\n    }\n    return least_factor;\n}\nll extgcd(ll a, ll b, ll &x, ll\
    \ &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    ll d = extgcd(b, a % b, y, x);\n    y -= a / b * x;\n    return d;\n\
    }\nll modpow(ll a, ll b, ll m) {\n    ll res = 1;\n    while (b) {\n        if\
    \ (b & 1) {\n            res *= a;\n            res %= m;\n        }\n       \
    \ a *= a;\n        a %= m;\n        b >>= 1;\n    }\n    return res;\n}\n#line\
    \ 2 \"mod_sqrt.cpp\"\nint64_t mod_sqrt(const int64_t& a, const int64_t& p) {\n\
    \    assert(0 <= a && a < p);\n    if (a < 2) return a;\n    if (modpow(a, (p\
    \ - 1) >> 1, p) != 1) return -1;\n    int64_t q = p - 1, m = 0;\n    while (!(q\
    \ & 1)) {\n        q >>= 1;\n        m++;\n    }\n    int64_t z = 1;\n    while\
    \ (modpow(z, (p - 1) >> 1, p) == 1) z++;\n    int64_t c = modpow(z, q, p);\n \
    \   int64_t t = modpow(a, q, p);\n    int64_t r = modpow(a, (q + 1) >> 1, p);\n\
    \    if (t == 0) return 0;\n    m -= 2;\n    while (t != 1) {\n        while (modpow(t,\
    \ int64_t(1) << m, p) == 1) {\n            c = c * c % p;\n            m--;\n\
    \        }\n        r = r * c % p;\n        c = c * c % p;\n        t = t * c\
    \ % p;\n        m--;\n    }\n    return r;\n}\n#line 3 \"FormalPowerSeries.cpp\"\
    \ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n    using\
    \ vector<mint>::vector;\n    using FPS = FormalPowerSeries;\n    FPS& operator+=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n        return\
    \ *this;\n    }\n    FPS& operator+=(const mint& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n       \
    \ return *this;\n    }\n\n    FPS& operator-=(const mint& r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n \
    \   FPS& operator*=(const FPS& r) {\n        if (this->empty() || r.empty()) {\n\
    \            this->clear();\n            return *this;\n        }\n        assert(mint::mod()\
    \ == 998244353);\n        vector<mint> prod = atcoder::convolution(*this, r);\n\
    \        this->resize((int)prod.size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) (*this)[i] = prod[i];\n        return *this;\n    }\n    FPS& operator*=(const\
    \ mint& v) {\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *=\
    \ v;\n        return *this;\n    }\n    FPS& operator/=(const FPS& r) {\n    \
    \    if (this->size() < r.size()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        int n = this->size() - r.size() + 1;\n        return\
    \ *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n    }\n    FPS& operator%=(const\
    \ FPS& r) {\n        *this -= *this / r * r;\n        shrink();\n        return\
    \ *this;\n    }\n    FPS operator+(const FPS& r) const { return FPS(*this) +=\
    \ r; }\n    FPS operator+(const mint& v) const { return FPS(*this) += v; }\n \
    \   FPS operator-(const FPS& r) const { return FPS(*this) -= r; }\n    FPS operator-(const\
    \ mint& v) const { return FPS(*this) -= v; }\n    FPS operator*(const FPS& r)\
    \ const { return FPS(*this) *= r; }\n    FPS operator*(const mint& v) const {\
    \ return FPS(*this) *= v; }\n    FPS operator/(const FPS& r) const { return FPS(*this)\
    \ /= r; }\n    FPS operator%(const FPS& r) const { return FPS(*this) %= r; }\n\
    \    FPS operator-() const {\n        FPS ret(this->size());\n        for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n        return ret;\n\
    \    }\n    void shrink() {\n        while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n    }\n    FPS operator>>(int sz) const {\n        if ((int)this->size()\
    \ <= sz) return {};\n        FPS ret(*this);\n        ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n        return ret;\n    }\n    FPS operator<<(int sz) const {\n   \
    \     FPS ret(*this);\n        ret.insert(ret.begin(), sz, mint(0));\n       \
    \ return ret;\n    }\n    FPS pre(int sz) const { return FPS(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz)); }\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        reverse(begin(ret), end(ret));\n        return ret;\n    }\n    FPS diff()\
    \ const {\n        const int n = this->size();\n        FPS ret(max(0, n - 1));\n\
    \        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * mint(i);\n    \
    \    return ret;\n    }\n    FPS integral() const {\n        const int n = this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = mint(0);\n        if (n > 0) ret[1]\
    \ = mint(1);\n        auto mod = mint::mod();\n        for (int i = 2; i <= n;\
    \ i++) ret[i] = (-ret[mod % i] * (mod / i));\n        for (int i = 0; i < n; i++)\
    \ ret[i + 1] *= (*this)[i];\n        return ret;\n    }\n    FPS inv(int deg =\
    \ -1) const {\n        assert(((*this)[0]) != mint(0));\n        const int n =\
    \ this->size();\n        if (deg == -1) deg = n;\n        FPS ret({mint(1) / (*this)[0]});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret + ret - ret\
    \ * ret * pre(i << 1)).pre(i << 1);\n        }\n        return ret.pre(deg);\n\
    \    }\n    FPS log(int deg = -1) {\n        assert((*this)[0] == mint(1));\n\
    \        if (deg == -1) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n    FPS exp(int deg = -1) const {\n        assert((*this)[0]\
    \ == mint(0));\n        const int n = this->size();\n        if (deg == -1) deg\
    \ = n;\n        FPS ret({mint(1)});\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i\
    \ << 1);\n        }\n        return ret.pre(deg);\n    }\n    FPS pow(int64_t\
    \ k, int deg = -1) const {\n        const int n = this->size();\n        if (deg\
    \ == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n        \
    \    if (deg) ret[0] = 1;\n            return ret;\n        }\n        for (int\
    \ i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0)) {\n           \
    \     mint rev = mint(1) / (*this)[i];\n                FPS ret = (((*this * rev)\
    \ >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n \
    \               ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \     }\n        return FPS(deg, mint(0));\n    }\n    FPS sqrt(int deg = -1)\
    \ const {\n        const int n = this->size();\n        if (deg == -1) deg = n;\n\
    \        if (n == 0) return FPS(deg, 0);\n        if ((*this)[0] == mint(0)) {\n\
    \            for (int i = 1; i < n; i++) {\n                if ((*this)[i] !=\
    \ mint(0)) {\n                    if (i & 1) return {};\n                    if\
    \ (deg - i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(deg\
    \ - i / 2);\n                    if (ret.empty()) return {};\n               \
    \     ret = ret << (i / 2);\n                    if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n                    return ret;\n                }\n            }\n\
    \            return FPS(deg, 0);\n        }\n        int64_t sqr = mod_sqrt((*this)[0].val(),\
    \ mint::mod());\n        if (sqr == -1) return {};\n        assert(sqr * sqr %\
    \ mint::mod() == (*this)[0].val());\n        FPS ret({mint(sqr)});\n        mint\
    \ inv2 = mint(2).inv();\n        for (int i = 1; i < deg; i <<= 1) {\n       \
    \     ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n        }\n       \
    \ return ret.pre(deg);\n    }\n    mint eval(mint x) const {\n        mint r =\
    \ 0, w = 1;\n        for (auto& v : *this) r += w * v, w *= x;\n        return\
    \ r;\n    }\n};\n#line 3 \"TaylorShift.cpp\"\n// f(x + a)\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a,\
    \ Binomial<mint>& bin) {\n    int n = f.size();\n    for (int i = 0; i < n; i++)\
    \ f[i] *= bin.fact[i];\n    f = f.rev();\n    FormalPowerSeries<mint> g(n, mint(1));\n\
    \    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * bin.inv[i];\n    f = (f\
    \ * g).pre(n);\n    f = f.rev();\n    for (int i = 0; i < n; i++) f[i] *= bin.factinv[i];\n\
    \    return f;\n}\n#line 1 \"modint_io.cpp\"\n#include <atcoder/modint>\n#line\
    \ 3 \"modint_io.cpp\"\ntemplate <int T>\ninline std::ostream &operator<<(std::ostream\
    \ &os, const atcoder::static_modint<T> &p) {\n    return os << p.val();\n}\ntemplate\
    \ <int T>\ninline std::istream &operator>>(std::istream &is, atcoder::static_modint<T>\
    \ &a) {\n    int64_t t;\n    is >> t;\n    a = t;\n    return is;\n}\n#line 4\
    \ \"test/TaylorShift.test.cpp\"\nint main() {\n    using mint = atcoder::modint998244353;\n\
    \    int n;\n    cin >> n;\n    mint c;\n    cin >> c;\n    FormalPowerSeries<mint>\
    \ f(n);\n    for (auto &x : f) cin >> x;\n    Binomial<mint> bin(n);\n    FormalPowerSeries<mint>\
    \ g = TaylorShift<mint>(f, c, bin);\n    rep(i, n) cout << g[i] << \" \";\n  \
    \  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n#include \"../TaylorShift.cpp\"\n#include \"../modint_io.cpp\"\nint main() {\n\
    \    using mint = atcoder::modint998244353;\n    int n;\n    cin >> n;\n    mint\
    \ c;\n    cin >> c;\n    FormalPowerSeries<mint> f(n);\n    for (auto &x : f)\
    \ cin >> x;\n    Binomial<mint> bin(n);\n    FormalPowerSeries<mint> g = TaylorShift<mint>(f,\
    \ c, bin);\n    rep(i, n) cout << g[i] << \" \";\n    cout << endl;\n}"
  dependsOn:
  - TaylorShift.cpp
  - Binomial.cpp
  - FormalPowerSeries.cpp
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - mod_sqrt.cpp
  - template.cpp
  - modint_io.cpp
  isVerificationFile: true
  path: test/TaylorShift.test.cpp
  requiredBy: []
  timestamp: '2024-06-03 20:31:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/TaylorShift.test.cpp
layout: document
redirect_from:
- /verify/test/TaylorShift.test.cpp
- /verify/test/TaylorShift.test.cpp.html
title: test/TaylorShift.test.cpp
---
