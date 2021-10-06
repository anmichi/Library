---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconstexpr int mod = 998244353;\nvector<int> prime_list(int\
    \ n) {\n    vector<int> v(n + 1), res;\n    for (int i = n; i >= 2; i--) {\n \
    \       for (int j = i; j <= n; j += i) v[j] = i;\n    }\n    for (int i = 2;\
    \ i <= n; i++) {\n        if (v[i] == i) res.push_back(i);\n    }\n    return\
    \ res;\n}\nvector<int> next_divisor(int n) {\n    vector<int> v(n + 1);\n    for\
    \ (int i = n; i >= 2; i--) {\n        for (int j = i; j <= n; j += i) v[j] = i;\n\
    \    }\n    return v;\n}\nll modpow(ll a, ll b) {\n    ll res = 1;\n    while\
    \ (b) {\n        if (b & 1) {\n            res *= a;\n            res %= mod;\n\
    \        }\n        a *= a;\n        a %= mod;\n        b >>= 1;\n    }\n    return\
    \ res;\n}\nvector<ll> inv, fact, factinv;\nvoid init_fact(int n) {\n    inv.resize(n\
    \ + 1);\n    fact.resize(n + 1);\n    factinv.resize(n + 1);\n    inv[0] = 0;\n\
    \    inv[1] = 1;\n    fact[0] = 1;\n    factinv[0] = 1;\n    for (ll i = 1; i\
    \ <= n; i++) {\n        if (i >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] %\
    \ mod);\n        fact[i] = (fact[i - 1] * i) % mod;\n        factinv[i] = factinv[i\
    \ - 1] * inv[i] % mod;\n    }\n}\nll modinv(ll a, ll m = mod) {\n    // gcd(a,m)\
    \ must be 1\n    ll b = m, u = 1, v = 0;\n    while (b) {\n        ll t = a /\
    \ b;\n        a -= t * b;\n        swap(a, b);\n        u -= t * v;\n        swap(u,\
    \ v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\nll comb(int\
    \ a, int b) {\n    if (a < b) return 0;\n    if (a < 0) return 0;\n    return\
    \ fact[a] * factinv[a - b] % mod * factinv[b] % mod;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconstexpr\
    \ int mod = 998244353;\nvector<int> prime_list(int n) {\n    vector<int> v(n +\
    \ 1), res;\n    for (int i = n; i >= 2; i--) {\n        for (int j = i; j <= n;\
    \ j += i) v[j] = i;\n    }\n    for (int i = 2; i <= n; i++) {\n        if (v[i]\
    \ == i) res.push_back(i);\n    }\n    return res;\n}\nvector<int> next_divisor(int\
    \ n) {\n    vector<int> v(n + 1);\n    for (int i = n; i >= 2; i--) {\n      \
    \  for (int j = i; j <= n; j += i) v[j] = i;\n    }\n    return v;\n}\nll modpow(ll\
    \ a, ll b) {\n    ll res = 1;\n    while (b) {\n        if (b & 1) {\n       \
    \     res *= a;\n            res %= mod;\n        }\n        a *= a;\n       \
    \ a %= mod;\n        b >>= 1;\n    }\n    return res;\n}\nvector<ll> inv, fact,\
    \ factinv;\nvoid init_fact(int n) {\n    inv.resize(n + 1);\n    fact.resize(n\
    \ + 1);\n    factinv.resize(n + 1);\n    inv[0] = 0;\n    inv[1] = 1;\n    fact[0]\
    \ = 1;\n    factinv[0] = 1;\n    for (ll i = 1; i <= n; i++) {\n        if (i\
    \ >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);\n        fact[i] = (fact[i\
    \ - 1] * i) % mod;\n        factinv[i] = factinv[i - 1] * inv[i] % mod;\n    }\n\
    }\nll modinv(ll a, ll m = mod) {\n    // gcd(a,m) must be 1\n    ll b = m, u =\
    \ 1, v = 0;\n    while (b) {\n        ll t = a / b;\n        a -= t * b;\n   \
    \     swap(a, b);\n        u -= t * v;\n        swap(u, v);\n    }\n    u %= m;\n\
    \    if (u < 0) u += m;\n    return u;\n}\nll comb(int a, int b) {\n    if (a\
    \ < b) return 0;\n    if (a < 0) return 0;\n    return fact[a] * factinv[a - b]\
    \ % mod * factinv[b] % mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math.cpp
  requiredBy: []
  timestamp: '2021-09-18 01:45:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math.cpp
layout: document
redirect_from:
- /library/math.cpp
- /library/math.cpp.html
title: math.cpp
---
