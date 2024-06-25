---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: AuxiliaryTree.cpp
    title: AuxiliaryTree.cpp
  - icon: ':heavy_check_mark:'
    path: LCA.cpp
    title: LCA.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AuxiliaryTree.test.cpp
    title: test/AuxiliaryTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LCA.test.cpp
    title: test/LCA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SparseTableDisjoint.test.cpp
    title: test/SparseTableDisjoint.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SparseTable.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct sparsetable {\n  \
    \  vector<vector<T>> table;\n    vector<int> logtable;\n    sparsetable() = default;\n\
    \    sparsetable(vector<T> v) {\n        int len = 0;\n        while ((1 << len)\
    \ <= v.size()) len++;\n        table.assign(len, vector<T>(1 << len));\n     \
    \   for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n        for (int\
    \ i = 1; i < len; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << len);\
    \ j++) {\n                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1\
    \ << (i - 1))]);\n            }\n        }\n        logtable.resize(v.size() +\
    \ 1);\n        for (int i = 2; i < logtable.size(); i++) {\n            logtable[i]\
    \ = logtable[(i >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n \
    \       assert(l <= r);\n        if (l == r) return e();\n        int len = logtable[r\
    \ - l];\n        return op(table[len][l], table[len][r - (1 << len)]);\n    }\n\
    };\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct disjointsparsetable {\n\
    \    vector<vector<T>> table;\n    vector<int> logtable;\n    disjointsparsetable()\
    \ = default;\n    disjointsparsetable(vector<T> v) {\n        int len = 0;\n \
    \       while ((1 << len) <= v.size()) len++;\n        table.assign(len, vector<T>(1\
    \ << len, e()));\n        for (int i = 0; i < (int)v.size(); i++) table[0][i]\
    \ = v[i];\n        for (int i = 1; i < len; i++) {\n            int shift = 1\
    \ << i;\n            for (int j = 0; j < (int)v.size(); j += shift << 1) {\n \
    \               int t = min(j + shift, (int)v.size());\n                table[i][t\
    \ - 1] = v[t - 1];\n                for (int k = t - 2; k >= j; k--) table[i][k]\
    \ = op(v[k], table[i][k + 1]);\n                if (v.size() <= t) break;\n  \
    \              table[i][t] = v[t];\n                int r = min(t + shift, (int)v.size());\n\
    \                for (int k = t + 1; k < r; k++) table[i][k] = op(table[i][k -\
    \ 1], v[k]);\n            }\n        }\n        logtable.resize(1 << len);\n \
    \       for (int i = 2; i < logtable.size(); i++) {\n            logtable[i] =\
    \ logtable[(i >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n   \
    \     if (l == r) return e();\n        if (l >= --r) return table[0][l];\n   \
    \     int len = logtable[l ^ r];\n        return op(table[len][l], table[len][r]);\n\
    \    };\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()>\nstruct sparsetable {\n    vector<vector<T>> table;\n    vector<int>\
    \ logtable;\n    sparsetable() = default;\n    sparsetable(vector<T> v) {\n  \
    \      int len = 0;\n        while ((1 << len) <= v.size()) len++;\n        table.assign(len,\
    \ vector<T>(1 << len));\n        for (int i = 0; i < (int)v.size(); i++) table[0][i]\
    \ = v[i];\n        for (int i = 1; i < len; i++) {\n            for (int j = 0;\
    \ j + (1 << i) <= (1 << len); j++) {\n                table[i][j] = op(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    logtable.resize(v.size() + 1);\n        for (int i = 2; i < logtable.size();\
    \ i++) {\n            logtable[i] = logtable[(i >> 1)] + 1;\n        }\n    }\n\
    \    T query(int l, int r) {\n        assert(l <= r);\n        if (l == r) return\
    \ e();\n        int len = logtable[r - l];\n        return op(table[len][l], table[len][r\
    \ - (1 << len)]);\n    }\n};\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct\
    \ disjointsparsetable {\n    vector<vector<T>> table;\n    vector<int> logtable;\n\
    \    disjointsparsetable() = default;\n    disjointsparsetable(vector<T> v) {\n\
    \        int len = 0;\n        while ((1 << len) <= v.size()) len++;\n       \
    \ table.assign(len, vector<T>(1 << len, e()));\n        for (int i = 0; i < (int)v.size();\
    \ i++) table[0][i] = v[i];\n        for (int i = 1; i < len; i++) {\n        \
    \    int shift = 1 << i;\n            for (int j = 0; j < (int)v.size(); j +=\
    \ shift << 1) {\n                int t = min(j + shift, (int)v.size());\n    \
    \            table[i][t - 1] = v[t - 1];\n                for (int k = t - 2;\
    \ k >= j; k--) table[i][k] = op(v[k], table[i][k + 1]);\n                if (v.size()\
    \ <= t) break;\n                table[i][t] = v[t];\n                int r = min(t\
    \ + shift, (int)v.size());\n                for (int k = t + 1; k < r; k++) table[i][k]\
    \ = op(table[i][k - 1], v[k]);\n            }\n        }\n        logtable.resize(1\
    \ << len);\n        for (int i = 2; i < logtable.size(); i++) {\n            logtable[i]\
    \ = logtable[(i >> 1)] + 1;\n        }\n    }\n    T query(int l, int r) {\n \
    \       if (l == r) return e();\n        if (l >= --r) return table[0][l];\n \
    \       int len = logtable[l ^ r];\n        return op(table[len][l], table[len][r]);\n\
    \    };\n};"
  dependsOn: []
  isVerificationFile: false
  path: SparseTable.cpp
  requiredBy:
  - LCA.cpp
  - AuxiliaryTree.cpp
  timestamp: '2024-06-25 16:25:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LCA.test.cpp
  - test/AuxiliaryTree.test.cpp
  - test/SparseTable.test.cpp
  - test/SparseTableDisjoint.test.cpp
documentation_of: SparseTable.cpp
layout: document
redirect_from:
- /library/SparseTable.cpp
- /library/SparseTable.cpp.html
title: SparseTable.cpp
---