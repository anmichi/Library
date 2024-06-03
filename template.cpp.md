---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: FormalPowerSeries.cpp
    title: FormalPowerSeries.cpp
  - icon: ':x:'
    path: Series.cpp
    title: Series.cpp
  - icon: ':question:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  - icon: ':question:'
    path: mod_sqrt.cpp
    title: mod_sqrt.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/StirlingFirst.test.cpp
    title: test/StirlingFirst.test.cpp
  - icon: ':x:'
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
    \    }\n    return res;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, n) for (int i = 0; i < n; i++)\n#define all(v) v.begin(), v.end()\ntemplate\
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
    \ a *= a;\n        a %= m;\n        b >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy:
  - Series.cpp
  - mod_sqrt.cpp
  - FormalPowerSeries.cpp
  - TaylorShift.cpp
  timestamp: '2024-05-26 13:38:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/StirlingSecond.test.cpp
  - test/StirlingFirst.test.cpp
  - test/TaylorShift.test.cpp
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---
