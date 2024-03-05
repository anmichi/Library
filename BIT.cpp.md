---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"BIT.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nstruct BIT {\n    // 1-indexed\n    int n, beki = 1;\n   \
    \ vector<T> bit;\n    BIT(int x) {\n        bit.resize(x + 1, 0);\n        n =\
    \ x;\n        while (beki * 2 <= n) beki *= 2;\n    }\n    T sum(int i) {\n  \
    \      T res = 0;\n        while (i > 0) {\n            res += bit[i];\n     \
    \       i -= i & -i;\n        }\n        return res;\n    }\n    T sum(int l,\
    \ int r) {\n        //[l,r]\n        return sum(r) - (l == 0 ? 0 : sum(l - 1));\n\
    \    }\n    void add(int i, T x) {\n        while (i <= n) {\n            bit[i]\
    \ += x;\n            i += i & -i;\n        }\n    }\n    int lowerbound(T w) {\n\
    \        if (w <= 0) return 0;\n        int x = 0;\n        for (int k = beki;\
    \ k > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] < w) {\n       \
    \         w -= bit[x + k];\n                x += k;\n            }\n        }\n\
    \        return x + 1;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T>\nstruct\
    \ BIT {\n    // 1-indexed\n    int n, beki = 1;\n    vector<T> bit;\n    BIT(int\
    \ x) {\n        bit.resize(x + 1, 0);\n        n = x;\n        while (beki * 2\
    \ <= n) beki *= 2;\n    }\n    T sum(int i) {\n        T res = 0;\n        while\
    \ (i > 0) {\n            res += bit[i];\n            i -= i & -i;\n        }\n\
    \        return res;\n    }\n    T sum(int l, int r) {\n        //[l,r]\n    \
    \    return sum(r) - (l == 0 ? 0 : sum(l - 1));\n    }\n    void add(int i, T\
    \ x) {\n        while (i <= n) {\n            bit[i] += x;\n            i += i\
    \ & -i;\n        }\n    }\n    int lowerbound(T w) {\n        if (w <= 0) return\
    \ 0;\n        int x = 0;\n        for (int k = beki; k > 0; k >>= 1) {\n     \
    \       if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n\
    \                x += k;\n            }\n        }\n        return x + 1;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: BIT.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BIT.test.cpp
documentation_of: BIT.cpp
layout: document
redirect_from:
- /library/BIT.cpp
- /library/BIT.cpp.html
title: BIT.cpp
---
