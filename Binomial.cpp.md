---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Series.cpp
    title: Series.cpp
  - icon: ':heavy_check_mark:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Modint-Binomial.test.cpp
    title: test/Modint-Binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/StirlingFirst.test.cpp
    title: test/StirlingFirst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/StirlingSecond.test.cpp
    title: test/StirlingSecond.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/TaylorShift.test.cpp
    title: test/TaylorShift.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Binomial.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <typename T>\nstruct Binomial {\n    vector<T> inv, fact, factinv;\n\
    \    Binomial(int n) {\n        inv.resize(n + 1);\n        fact.resize(n + 1);\n\
    \        factinv.resize(n + 1);\n        inv[0] = fact[0] = factinv[0] = 1;\n\
    \        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        factinv[n]\
    \ = fact[n].inv();\n        inv[n] = fact[n - 1] * factinv[n];\n        for (int\
    \ i = n - 1; i >= 1; i--) {\n            factinv[i] = factinv[i + 1] * (i + 1);\n\
    \            inv[i] = fact[i - 1] * factinv[i];\n        }\n    }\n    T C(int\
    \ n, int r) {\n        if (n < 0 || n < r || r < 0) return 0;\n        return\
    \ fact[n] * factinv[n - r] * factinv[r];\n    }\n    T P(int n, int r) {\n   \
    \     if (n < 0 || n < r || r < 0) return 0;\n        return fact[n] * factinv[n\
    \ - r];\n    }\n    T H(int n, int r) {\n        if (n == 0 && r == 0) return\
    \ 1;\n        if (n < 0 || r < 0) return 0;\n        return r == 0 ? 1 : C(n +\
    \ r - 1, r);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <typename T>\nstruct\
    \ Binomial {\n    vector<T> inv, fact, factinv;\n    Binomial(int n) {\n     \
    \   inv.resize(n + 1);\n        fact.resize(n + 1);\n        factinv.resize(n\
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
    };"
  dependsOn: []
  isVerificationFile: false
  path: Binomial.cpp
  requiredBy:
  - Series.cpp
  - TaylorShift.cpp
  timestamp: '2024-06-03 20:31:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Modint-Binomial.test.cpp
  - test/StirlingSecond.test.cpp
  - test/StirlingFirst.test.cpp
  - test/TaylorShift.test.cpp
documentation_of: Binomial.cpp
layout: document
redirect_from:
- /library/Binomial.cpp
- /library/Binomial.cpp.html
title: Binomial.cpp
---
