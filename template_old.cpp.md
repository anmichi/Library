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
  bundledCode: "#line 1 \"template_old.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define all(v) v.begin(), v.end()\ntemplate <class T, class U>\ninline bool chmax(T&\
    \ a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n \
    \   return false;\n}\ntemplate <class T, class U>\ninline bool chmin(T& a, U b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr int INF = 1000000000;\nconstexpr ll llINF = 3000000000000000000;\n\
    constexpr int mod = 998244353;\nconstexpr double eps = 1e-10;\nvector<int> calc_factor(int\
    \ n) {\n    vector<int> least_factor(n + 1, 0), prime_list;\n    for (int i =\
    \ 2; i <= n; i++) {\n        if (least_factor[i] == 0) {\n            least_factor[i]\
    \ = i;\n            prime_list.push_back(i);\n        }\n        for (int j =\
    \ 0; j < (int)prime_list.size() && i * prime_list[j] <= n; j++) {\n          \
    \  least_factor[i * prime_list[j]] = prime_list[j];\n            if (prime_list[j]\
    \ == least_factor[i]) break;\n        }\n    }\n    return least_factor;\n}\n\
    ll modpow(ll a, ll b, ll m = mod) {\n    ll res = 1;\n    while (b) {\n      \
    \  if (b & 1) {\n            res *= a;\n            res %= m;\n        }\n   \
    \     a *= a;\n        a %= m;\n        b >>= 1;\n    }\n    return res;\n}\n\
    vector<ll> inv, fact, factinv;\nvoid init_fact(int n) {\n    inv.resize(n + 1);\n\
    \    fact.resize(n + 1);\n    factinv.resize(n + 1);\n    inv[0] = 0;\n    inv[1]\
    \ = 1;\n    fact[0] = 1;\n    factinv[0] = 1;\n    for (ll i = 1; i <= n; i++)\
    \ {\n        if (i >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);\n  \
    \      fact[i] = (fact[i - 1] * i) % mod;\n        factinv[i] = factinv[i - 1]\
    \ * inv[i] % mod;\n    }\n}\nll modinv(ll a, ll m = mod) {\n    ll b = m, u =\
    \ 1, v = 0;\n    while (b) {\n        ll t = a / b;\n        a -= t * b;\n   \
    \     swap(a, b);\n        u -= t * v;\n        swap(u, v);\n    }\n    u %= m;\n\
    \    if (u < 0) u += m;\n    return u;\n}\nll comb(int a, int b) {\n    if (a\
    \ < b) return 0;\n    if (a < 0) return 0;\n    return fact[a] * factinv[a - b]\
    \ % mod * factinv[b] % mod;\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, n) for (int i = 0; i < n; i++)\n#define all(v) v.begin(), v.end()\ntemplate\
    \ <class T, class U>\ninline bool chmax(T& a, U b) {\n    if (a < b) {\n     \
    \   a = b;\n        return true;\n    }\n    return false;\n}\ntemplate <class\
    \ T, class U>\ninline bool chmin(T& a, U b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\nconstexpr int INF = 1000000000;\n\
    constexpr ll llINF = 3000000000000000000;\nconstexpr int mod = 998244353;\nconstexpr\
    \ double eps = 1e-10;\nvector<int> calc_factor(int n) {\n    vector<int> least_factor(n\
    \ + 1, 0), prime_list;\n    for (int i = 2; i <= n; i++) {\n        if (least_factor[i]\
    \ == 0) {\n            least_factor[i] = i;\n            prime_list.push_back(i);\n\
    \        }\n        for (int j = 0; j < (int)prime_list.size() && i * prime_list[j]\
    \ <= n; j++) {\n            least_factor[i * prime_list[j]] = prime_list[j];\n\
    \            if (prime_list[j] == least_factor[i]) break;\n        }\n    }\n\
    \    return least_factor;\n}\nll modpow(ll a, ll b, ll m = mod) {\n    ll res\
    \ = 1;\n    while (b) {\n        if (b & 1) {\n            res *= a;\n       \
    \     res %= m;\n        }\n        a *= a;\n        a %= m;\n        b >>= 1;\n\
    \    }\n    return res;\n}\nvector<ll> inv, fact, factinv;\nvoid init_fact(int\
    \ n) {\n    inv.resize(n + 1);\n    fact.resize(n + 1);\n    factinv.resize(n\
    \ + 1);\n    inv[0] = 0;\n    inv[1] = 1;\n    fact[0] = 1;\n    factinv[0] =\
    \ 1;\n    for (ll i = 1; i <= n; i++) {\n        if (i >= 2) inv[i] = mod - ((mod\
    \ / i) * inv[mod % i] % mod);\n        fact[i] = (fact[i - 1] * i) % mod;\n  \
    \      factinv[i] = factinv[i - 1] * inv[i] % mod;\n    }\n}\nll modinv(ll a,\
    \ ll m = mod) {\n    ll b = m, u = 1, v = 0;\n    while (b) {\n        ll t =\
    \ a / b;\n        a -= t * b;\n        swap(a, b);\n        u -= t * v;\n    \
    \    swap(u, v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n\
    }\nll comb(int a, int b) {\n    if (a < b) return 0;\n    if (a < 0) return 0;\n\
    \    return fact[a] * factinv[a - b] % mod * factinv[b] % mod;\n}\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template_old.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template_old.cpp
layout: document
redirect_from:
- /library/template_old.cpp
- /library/template_old.cpp.html
title: template_old.cpp
---
