---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: Series.cpp
    title: Series.cpp
  - icon: ':question:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Modint-Binomial.test.cpp
    title: test/Modint-Binomial.test.cpp
  - icon: ':x:'
    path: test/Series/Bernoulli.test.cpp
    title: test/Series/Bernoulli.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Series/StirlingFirst.test.cpp
    title: test/Series/StirlingFirst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Series/StirlingSecond.test.cpp
    title: test/Series/StirlingSecond.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Series/StirlingSecondFixedK.test.cpp
    title: test/Series/StirlingSecondFixedK.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/TaylorShift.test.cpp
    title: test/TaylorShift.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
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
  - TaylorShift.cpp
  - Series.cpp
  timestamp: '2024-06-03 20:31:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/TaylorShift.test.cpp
  - test/Series/StirlingSecond.test.cpp
  - test/Series/StirlingFirst.test.cpp
  - test/Series/StirlingSecondFixedK.test.cpp
  - test/Series/Bernoulli.test.cpp
  - test/Modint-Binomial.test.cpp
documentation_of: Binomial.cpp
layout: document
redirect_from:
- /library/Binomial.cpp
- /library/Binomial.cpp.html
title: Binomial.cpp
---
