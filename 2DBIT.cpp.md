---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2DBIT.test.cpp
    title: test/2DBIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2DBIT.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nstruct BIT2D {\n    int n, m;\n    vector<vector<T>> bit;\n\
    \    BIT2D(int n, int m) : n(n), m(m) { bit.resize(n + 1, vector<T>(m + 1)); }\n\
    \    void add(int a, int b, T w) {\n        for (int x = a; x <= n; x += x & -x)\
    \ {\n            for (int y = b; y <= m; y += y & -y) {\n                bit[x][y]\
    \ += w;\n            }\n        }\n    }\n    T sum(int a, int b) {\n        T\
    \ res = 0;\n        for (int x = a; x > 0; x -= x & -x) {\n            for (int\
    \ y = b; y > 0; y -= y & -y) {\n                res += bit[x][y];\n          \
    \  }\n        }\n        return res;\n    }\n    T sum(int a, int b, int c, int\
    \ d) {\n        //[a,c],[b,d]\n        return sum(c, d) - sum(a - 1, d) - sum(c,\
    \ b - 1) + sum(a - 1, b - 1);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T>\nstruct\
    \ BIT2D {\n    int n, m;\n    vector<vector<T>> bit;\n    BIT2D(int n, int m)\
    \ : n(n), m(m) { bit.resize(n + 1, vector<T>(m + 1)); }\n    void add(int a, int\
    \ b, T w) {\n        for (int x = a; x <= n; x += x & -x) {\n            for (int\
    \ y = b; y <= m; y += y & -y) {\n                bit[x][y] += w;\n           \
    \ }\n        }\n    }\n    T sum(int a, int b) {\n        T res = 0;\n       \
    \ for (int x = a; x > 0; x -= x & -x) {\n            for (int y = b; y > 0; y\
    \ -= y & -y) {\n                res += bit[x][y];\n            }\n        }\n\
    \        return res;\n    }\n    T sum(int a, int b, int c, int d) {\n       \
    \ //[a,c],[b,d]\n        return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a\
    \ - 1, b - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: 2DBIT.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2DBIT.test.cpp
documentation_of: 2DBIT.cpp
layout: document
redirect_from:
- /library/2DBIT.cpp
- /library/2DBIT.cpp.html
title: 2DBIT.cpp
---
