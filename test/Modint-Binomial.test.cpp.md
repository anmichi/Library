---
data:
  _extendedDependsOn:
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
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/Modint-Binomial.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define all(v)\
    \ v.begin(), v.end()\ntemplate <class T, class U>\ninline bool chmax(T &a, U b)\
    \ {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate <class T, class U>\ninline bool chmin(T &a, U b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\nconstexpr int INF = 1000000000;\nconstexpr int64_t llINF = 3000000000000000000;\n\
    constexpr double eps = 1e-10;\nconst double pi = acos(-1);\nvector<int> calc_factor(int\
    \ n) {\n    vector<int> least_factor(n + 1, 0), prime_list;\n    for (int i =\
    \ 2; i <= n; i++) {\n        if (least_factor[i] == 0) {\n            least_factor[i]\
    \ = i;\n            prime_list.push_back(i);\n        }\n        for (int j =\
    \ 0; j < (int)prime_list.size() && i * prime_list[j] <= n; j++) {\n          \
    \  least_factor[i * prime_list[j]] = prime_list[j];\n            if (prime_list[j]\
    \ == least_factor[i]) break;\n        }\n    }\n    return least_factor;\n}\n\
    ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n        x = 1;\n   \
    \     y = 0;\n        return a;\n    }\n    ll d = extgcd(b, a % b, y, x);\n \
    \   y -= a / b * x;\n    return d;\n}\nll modpow(ll a, ll b, ll m) {\n    ll res\
    \ = 1;\n    while (b) {\n        if (b & 1) {\n            res *= a;\n       \
    \     res %= m;\n        }\n        a *= a;\n        a %= m;\n        b >>= 1;\n\
    \    }\n    return res;\n}\ntemplate <int modulo>\nstruct modint {\n    int x;\n\
    \    modint() : x(0) {}\n    modint(int64_t y) : x(y >= 0 ? y % modulo : (modulo\
    \ - (-y) % modulo) % modulo) {}\n    modint &operator+=(const modint &p) {\n \
    \       if ((x += p.x) >= modulo) x -= modulo;\n        return *this;\n    }\n\
    \    modint &operator-=(const modint &p) {\n        if ((x += modulo - p.x) >=\
    \ modulo) x -= modulo;\n        return *this;\n    }\n    modint &operator*=(const\
    \ modint &p) {\n        x = (int)(1LL * x * p.x % modulo);\n        return *this;\n\
    \    }\n    modint &operator/=(const modint &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n    modint operator-() const { return modint(-x);\
    \ }\n    modint operator+(const modint &p) const { return modint(*this) += p;\
    \ }\n    modint operator-(const modint &p) const { return modint(*this) -= p;\
    \ }\n    modint operator*(const modint &p) const { return modint(*this) *= p;\
    \ }\n    modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n    bool operator==(const modint &p) const { return x == p.x; }\n    bool\
    \ operator!=(const modint &p) const { return x != p.x; }\n    modint inv() const\
    \ {\n        int a = x, b = modulo, u = 1, v = 0, t;\n        while (b > 0) {\n\
    \            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return modint(u);\n    }\n    modint pow(int64_t\
    \ n) const {\n        modint ret(1), mul(x);\n        while (n > 0) {\n      \
    \      if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const modint &p) { return os << p.x; }\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        int64_t t;\n        is >> t;\n        a = modint<modulo>(t);\n\
    \        return (is);\n    }\n    int val() const { return x; }\n    static constexpr\
    \ int mod() { return modulo; }\n    static constexpr int half() { return (modulo\
    \ + 1) >> 1; }\n};\ntemplate <typename T>\nstruct Binomial {\n    vector<T> inv,\
    \ fact, factinv;\n    Binomial(int n) {\n        assert(n > 0);\n        inv.resize(n\
    \ + 1);\n        fact.resize(n + 1);\n        factinv.resize(n + 1);\n       \
    \ inv[0] = fact[0] = factinv[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i]\
    \ = fact[i - 1] * i;\n        factinv[n] = fact[n].inv();\n        inv[n] = fact[n\
    \ - 1] * factinv[n];\n        for (int i = n - 1; i >= 1; i--) {\n           \
    \ factinv[i] = factinv[i + 1] * (i + 1);\n            inv[i] = fact[i - 1] * factinv[i];\n\
    \        }\n    }\n    T C(int n, int r) {\n        if (n < 0 || n < r || r <\
    \ 0) return 0;\n        return fact[n] * factinv[n - r] * factinv[r];\n    }\n\
    \    T P(int n, int r) {\n        if (n < 0 || n < r || r < 0) return 0;\n   \
    \     return fact[n] * factinv[n - r];\n    }\n    T H(int n, int r) {\n     \
    \   if (n == 0 && r == 0) return 1;\n        if (n < 0 || r < 0) return 0;\n \
    \       return r == 0 ? 1 : C(n + r - 1, r);\n    }\n};\n#line 3 \"test/Modint-Binomial.test.cpp\"\
    \nint main() {\n    Binomial<modint<1000000007>> bin(2000000);\n    int t;\n \
    \   scanf(\"%d\", &t);\n    while (t--) {\n        char op;\n        int n, k;\n\
    \        scanf(\"\\n%c(%d,%d)\", &op, &n, &k);\n        if (op == 'C') printf(\"\
    %d\\n\", bin.C(n, k).val());\n        if (op == 'P') printf(\"%d\\n\", bin.P(n,\
    \ k).val());\n        if (op == 'H') printf(\"%d\\n\", bin.H(n, k).val());\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include \"../template.cpp\"\
    \nint main() {\n    Binomial<modint<1000000007>> bin(2000000);\n    int t;\n \
    \   scanf(\"%d\", &t);\n    while (t--) {\n        char op;\n        int n, k;\n\
    \        scanf(\"\\n%c(%d,%d)\", &op, &n, &k);\n        if (op == 'C') printf(\"\
    %d\\n\", bin.C(n, k).val());\n        if (op == 'P') printf(\"%d\\n\", bin.P(n,\
    \ k).val());\n        if (op == 'H') printf(\"%d\\n\", bin.H(n, k).val());\n \
    \   }\n}"
  dependsOn:
  - template.cpp
  isVerificationFile: true
  path: test/Modint-Binomial.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Modint-Binomial.test.cpp
layout: document
redirect_from:
- /verify/test/Modint-Binomial.test.cpp
- /verify/test/Modint-Binomial.test.cpp.html
title: test/Modint-Binomial.test.cpp
---
