---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SparseTable.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T, T (*op)(T, T)>\nstruct SparseTable {\n    vector<vector<T>>\
    \ table;\n    vector<int> logtable;\n    SparseTable(vector<T> v) {\n        int\
    \ len = 0;\n        while ((1 << len) <= v.size()) len++;\n        table.assign(len,\
    \ vector<T>(1 << len));\n        for (int i = 0; i < (int)v.size(); i++) table[0][i]\
    \ = v[i];\n        for (int i = 1; i < len; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << len); j++) {\n                table[i][j] = op(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    logtable.resize(v.size() + 1);\n        for (int i = 2; i < logtable.size();\
    \ i++) {\n            logtable[i] = logtable[(i >> 1)] + 1;\n        }\n    }\n\
    \    T query(int l, int r) {\n        assert(l < r);\n        int len = logtable[r\
    \ - l];\n        return op(table[len][l], table[len][r - (1 << len)]);\n    }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T, T (*op)(T,\
    \ T)>\nstruct SparseTable {\n    vector<vector<T>> table;\n    vector<int> logtable;\n\
    \    SparseTable(vector<T> v) {\n        int len = 0;\n        while ((1 << len)\
    \ <= v.size()) len++;\n        table.assign(len, vector<T>(1 << len));\n     \
    \   for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n        for (int\
    \ i = 1; i < len; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << len);\
    \ j++) {\n                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1\
    \ << (i - 1))]);\n            }\n        }\n        logtable.resize(v.size() +\
    \ 1);\n        for (int i = 2; i < logtable.size(); i++) {\n            logtable[i]\
    \ = logtable[(i >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n \
    \       assert(l < r);\n        int len = logtable[r - l];\n        return op(table[len][l],\
    \ table[len][r - (1 << len)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SparseTable.cpp
  requiredBy: []
  timestamp: '2021-09-18 01:51:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/SparseTable.test.cpp
documentation_of: SparseTable.cpp
layout: document
redirect_from:
- /library/SparseTable.cpp
- /library/SparseTable.cpp.html
title: SparseTable.cpp
---
