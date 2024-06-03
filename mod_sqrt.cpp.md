---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: FormalPowerSeries.cpp
    title: FormalPowerSeries.cpp
  - icon: ':question:'
    path: Series.cpp
    title: Series.cpp
  - icon: ':question:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ModSqrt.test.cpp
    title: test/ModSqrt.test.cpp
  - icon: ':x:'
    path: test/StirlingFirst.test.cpp
    title: test/StirlingFirst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/StirlingSecond.test.cpp
    title: test/StirlingSecond.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/TaylorShift.test.cpp
    title: test/TaylorShift.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define all(v) v.begin(), v.end()\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmin(T &a, U\
    \ b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr int INF = 1000000000;\nconstexpr int64_t llINF = 3000000000000000000;\n\
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
    \    }\n    return res;\n}\n#line 2 \"mod_sqrt.cpp\"\nint64_t mod_sqrt(const int64_t&\
    \ a, const int64_t& p) {\n    assert(0 <= a && a < p);\n    if (a < 2) return\
    \ a;\n    if (modpow(a, (p - 1) >> 1, p) != 1) return -1;\n    int64_t q = p -\
    \ 1, m = 0;\n    while (!(q & 1)) {\n        q >>= 1;\n        m++;\n    }\n \
    \   int64_t z = 1;\n    while (modpow(z, (p - 1) >> 1, p) == 1) z++;\n    int64_t\
    \ c = modpow(z, q, p);\n    int64_t t = modpow(a, q, p);\n    int64_t r = modpow(a,\
    \ (q + 1) >> 1, p);\n    if (t == 0) return 0;\n    m -= 2;\n    while (t != 1)\
    \ {\n        while (modpow(t, int64_t(1) << m, p) == 1) {\n            c = c *\
    \ c % p;\n            m--;\n        }\n        r = r * c % p;\n        c = c *\
    \ c % p;\n        t = t * c % p;\n        m--;\n    }\n    return r;\n}\n"
  code: "#include \"template.cpp\"\nint64_t mod_sqrt(const int64_t& a, const int64_t&\
    \ p) {\n    assert(0 <= a && a < p);\n    if (a < 2) return a;\n    if (modpow(a,\
    \ (p - 1) >> 1, p) != 1) return -1;\n    int64_t q = p - 1, m = 0;\n    while\
    \ (!(q & 1)) {\n        q >>= 1;\n        m++;\n    }\n    int64_t z = 1;\n  \
    \  while (modpow(z, (p - 1) >> 1, p) == 1) z++;\n    int64_t c = modpow(z, q,\
    \ p);\n    int64_t t = modpow(a, q, p);\n    int64_t r = modpow(a, (q + 1) >>\
    \ 1, p);\n    if (t == 0) return 0;\n    m -= 2;\n    while (t != 1) {\n     \
    \   while (modpow(t, int64_t(1) << m, p) == 1) {\n            c = c * c % p;\n\
    \            m--;\n        }\n        r = r * c % p;\n        c = c * c % p;\n\
    \        t = t * c % p;\n        m--;\n    }\n    return r;\n}"
  dependsOn:
  - template.cpp
  isVerificationFile: false
  path: mod_sqrt.cpp
  requiredBy:
  - Series.cpp
  - FormalPowerSeries.cpp
  - TaylorShift.cpp
  timestamp: '2024-06-03 19:26:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/StirlingSecond.test.cpp
  - test/StirlingFirst.test.cpp
  - test/ModSqrt.test.cpp
  - test/TaylorShift.test.cpp
documentation_of: mod_sqrt.cpp
layout: document
redirect_from:
- /library/mod_sqrt.cpp
- /library/mod_sqrt.cpp.html
title: mod_sqrt.cpp
---
