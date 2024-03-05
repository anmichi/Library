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
  bundledCode: "#line 1 \"UnionFind.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nstruct UnionFind {\n    vector<int> par, siz, es;\n    UnionFind(int x)\
    \ {\n        par.resize(x);\n        siz.resize(x);\n        es.resize(x);\n \
    \       for (int i = 0; i < x; i++) {\n            par[i] = i;\n            siz[i]\
    \ = 1;\n            es[i] = 0;\n        }\n    }\n    int find(int x) {\n    \
    \    if (par[x] == x) return x;\n        return par[x] = find(par[x]);\n    }\n\
    \    void unite(int x, int y) {\n        x = find(x), y = find(y);\n        if\
    \ (x == y) {\n            es[x]++;\n            return;\n        }\n        if\
    \ (siz[x] < siz[y]) swap(x, y);\n        par[y] = x;\n        siz[x] += siz[y];\n\
    \        es[x] += es[y] + 1;\n    }\n    bool same(int x, int y) { return find(x)\
    \ == find(y); }\n    int size(int x) { return siz[find(x)]; }\n    int edges(int\
    \ x) { return es[find(x)]; }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nstruct UnionFind {\n    vector<int>\
    \ par, siz, es;\n    UnionFind(int x) {\n        par.resize(x);\n        siz.resize(x);\n\
    \        es.resize(x);\n        for (int i = 0; i < x; i++) {\n            par[i]\
    \ = i;\n            siz[i] = 1;\n            es[i] = 0;\n        }\n    }\n  \
    \  int find(int x) {\n        if (par[x] == x) return x;\n        return par[x]\
    \ = find(par[x]);\n    }\n    void unite(int x, int y) {\n        x = find(x),\
    \ y = find(y);\n        if (x == y) {\n            es[x]++;\n            return;\n\
    \        }\n        if (siz[x] < siz[y]) swap(x, y);\n        par[y] = x;\n  \
    \      siz[x] += siz[y];\n        es[x] += es[y] + 1;\n    }\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n    int size(int x) { return siz[find(x)];\
    \ }\n    int edges(int x) { return es[find(x)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind.cpp
layout: document
redirect_from:
- /library/UnionFind.cpp
- /library/UnionFind.cpp.html
title: UnionFind.cpp
---
