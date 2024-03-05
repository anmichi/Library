---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: LCA.cpp
    title: LCA.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/LCA.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#line 1 \"LCA.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nstruct\
    \ lca_tree {\n    int n, size;\n    vector<vector<int>> g, par;\n    vector<int>\
    \ depth;\n    lca_tree(vector<vector<int>> g_, int root = 0)\n        : n((int)g_.size()),\
    \ size(log2(n) + 2), g(g_), par(size, vector<int>(n, -1)), depth(vector<int>(n,\
    \ n)) {\n        queue<int> que;\n        depth[root] = 0;\n        que.push(root);\n\
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
    \    }\n};\n#line 3 \"test/LCA.test.cpp\"\nint main() {\n    cin.tie(0);\n   \
    \ ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n >> q;\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    lca_tree lt(g);\n    while (q--) {\n \
    \       int u, v;\n        cin >> u >> v;\n        cout << lt.query(u, v) << \"\
    \\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../LCA.cpp\"\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    cin >> n >> q;\n    vector<vector<int>> g(n);\n    for (int i = 1; i\
    \ < n; i++) {\n        int p;\n        cin >> p;\n        g[p].push_back(i);\n\
    \    }\n    lca_tree lt(g);\n    while (q--) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        cout << lt.query(u, v) << \"\\n\";\n    }\n}"
  dependsOn:
  - LCA.cpp
  isVerificationFile: true
  path: test/LCA.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LCA.test.cpp
layout: document
redirect_from:
- /verify/test/LCA.test.cpp
- /verify/test/LCA.test.cpp.html
title: test/LCA.test.cpp
---
