---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: AuxiliaryTree.cpp
    title: AuxiliaryTree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AuxiliaryTree.test.cpp
    title: test/AuxiliaryTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LCA.test.cpp
    title: test/LCA.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"LCA.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    struct lca_tree {\n    int n, size;\n    vector<vector<int>> par;\n    vector<int>\
    \ depth;\n    lca_tree(vector<vector<int>> g, int root = 0) : n((int)g.size()),\
    \ size(log2(n) + 2), par(size, vector<int>(n, -1)), depth(vector<int>(n, n)) {\n\
    \        queue<int> que;\n        depth[root] = 0;\n        que.push(root);\n\
    \        while (!que.empty()) {\n            int p = que.front();\n          \
    \  que.pop();\n            for (int i : g[p]) {\n                if (depth[i]\
    \ > depth[p] + 1) {\n                    depth[i] = depth[p] + 1;\n          \
    \          par[0][i] = p;\n                    que.push(i);\n                }\n\
    \            }\n        }\n        for (int k = 0; k < size - 1; k++) {\n    \
    \        for (int i = 0; i < n; i++) {\n                if (par[k][i] == -1)\n\
    \                    par[k + 1][i] = -1;\n                else\n             \
    \       par[k + 1][i] = par[k][par[k][i]];\n            }\n        }\n    }\n\
    \    int query(int u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n\
    \        for (int k = size - 1; k >= 0; k--) {\n            if (((depth[v] - depth[u])\
    \ >> k) & 1) v = par[k][v];\n            if (u == v) return u;\n        }\n  \
    \      for (int k = size - 1; k >= 0; k--) {\n            if (par[k][u] != par[k][v])\
    \ {\n                u = par[k][u];\n                v = par[k][v];\n        \
    \    }\n        }\n        return par[0][u];\n    }\n    int dist(int u, int v)\
    \ {\n        int l = query(u, v);\n        return depth[u] + depth[v] - 2 * depth[l];\n\
    \    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nstruct lca_tree {\n    int\
    \ n, size;\n    vector<vector<int>> par;\n    vector<int> depth;\n    lca_tree(vector<vector<int>>\
    \ g, int root = 0) : n((int)g.size()), size(log2(n) + 2), par(size, vector<int>(n,\
    \ -1)), depth(vector<int>(n, n)) {\n        queue<int> que;\n        depth[root]\
    \ = 0;\n        que.push(root);\n        while (!que.empty()) {\n            int\
    \ p = que.front();\n            que.pop();\n            for (int i : g[p]) {\n\
    \                if (depth[i] > depth[p] + 1) {\n                    depth[i]\
    \ = depth[p] + 1;\n                    par[0][i] = p;\n                    que.push(i);\n\
    \                }\n            }\n        }\n        for (int k = 0; k < size\
    \ - 1; k++) {\n            for (int i = 0; i < n; i++) {\n                if (par[k][i]\
    \ == -1)\n                    par[k + 1][i] = -1;\n                else\n    \
    \                par[k + 1][i] = par[k][par[k][i]];\n            }\n        }\n\
    \    }\n    int query(int u, int v) {\n        if (depth[u] > depth[v]) swap(u,\
    \ v);\n        for (int k = size - 1; k >= 0; k--) {\n            if (((depth[v]\
    \ - depth[u]) >> k) & 1) v = par[k][v];\n            if (u == v) return u;\n \
    \       }\n        for (int k = size - 1; k >= 0; k--) {\n            if (par[k][u]\
    \ != par[k][v]) {\n                u = par[k][u];\n                v = par[k][v];\n\
    \            }\n        }\n        return par[0][u];\n    }\n    int dist(int\
    \ u, int v) {\n        int l = query(u, v);\n        return depth[u] + depth[v]\
    \ - 2 * depth[l];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: LCA.cpp
  requiredBy:
  - AuxiliaryTree.cpp
  timestamp: '2024-03-07 04:25:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AuxiliaryTree.test.cpp
  - test/LCA.test.cpp
documentation_of: LCA.cpp
layout: document
redirect_from:
- /library/LCA.cpp
- /library/LCA.cpp.html
title: LCA.cpp
---
