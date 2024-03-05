---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SparseTable.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct sparsetable {\n  \
    \  vector<vector<T>> table;\n    vector<int> logtable;\n    sparsetable(vector<T>\
    \ v) {\n        int len = 0;\n        while ((1 << len) <= v.size()) len++;\n\
    \        table.assign(len, vector<T>(1 << len));\n        for (int i = 0; i <\
    \ (int)v.size(); i++) table[0][i] = v[i];\n        for (int i = 1; i < len; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <= (1 << len); j++) {\n        \
    \        table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n        logtable.resize(v.size() + 1);\n        for\
    \ (int i = 2; i < logtable.size(); i++) {\n            logtable[i] = logtable[(i\
    \ >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n        assert(l\
    \ <= r);\n        if (l == r) return e();\n        int len = logtable[r - l];\n\
    \        return op(table[len][l], table[len][r - (1 << len)]);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()>\nstruct sparsetable {\n    vector<vector<T>> table;\n    vector<int>\
    \ logtable;\n    sparsetable(vector<T> v) {\n        int len = 0;\n        while\
    \ ((1 << len) <= v.size()) len++;\n        table.assign(len, vector<T>(1 << len));\n\
    \        for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n       \
    \ for (int i = 1; i < len; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << len); j++) {\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n        logtable.resize(v.size()\
    \ + 1);\n        for (int i = 2; i < logtable.size(); i++) {\n            logtable[i]\
    \ = logtable[(i >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n \
    \       assert(l <= r);\n        if (l == r) return e();\n        int len = logtable[r\
    \ - l];\n        return op(table[len][l], table[len][r - (1 << len)]);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: SparseTable.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SparseTable.test.cpp
documentation_of: SparseTable.cpp
layout: document
redirect_from:
- /library/SparseTable.cpp
- /library/SparseTable.cpp.html
title: SparseTable.cpp
---
