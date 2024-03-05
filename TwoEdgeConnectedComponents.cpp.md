---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TwoEdgeConnectedComponents.test.cpp
    title: test/TwoEdgeConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"TwoEdgeConnectedComponents.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, n) for (int i = 0; i < n; i++)\nstruct TwoEdgeConnectedComponents\
    \ {\n    int V;\n    vector<vector<int>> g, new_g;\n    vector<int> depth, imos,\
    \ comp;\n    vector<vector<int>> comps;\n    TwoEdgeConnectedComponents(vector<vector<int>>\
    \ g_) : V((int)g_.size()), g(g_), depth(V, -1), imos(V), comp(V, -1) {\n     \
    \   int t = -1;\n        rep(i, V) {\n            if (depth[i] == -1) {\n    \
    \            depth[i] = 0;\n                dfs_init(i);\n                comp[i]\
    \ = ++t;\n                comps.push_back({});\n                new_g.push_back({});\n\
    \                dfs(i, t);\n            }\n        }\n    }\n    void dfs_init(int\
    \ v) {\n        for (int u : g[v]) {\n            if (depth[u] == -1) {\n    \
    \            depth[u] = depth[v] + 1;\n                dfs_init(u);\n        \
    \        imos[v] += imos[u];\n            } else if (depth[u] < depth[v])\n  \
    \              imos[u]--, imos[v]++;\n        }\n    }\n    void dfs(int v, int\
    \ &t) {\n        comps[comp[v]].push_back(v);\n        for (int u : g[v]) {\n\
    \            if (depth[u] == depth[v] + 1 && comp[u] == -1) {\n              \
    \  if (imos[u] <= 1) {\n                    comp[u] = ++t;\n                 \
    \   comps.push_back({});\n                    new_g.push_back({});\n         \
    \           new_g[comp[v]].push_back(comp[u]);\n                } else\n     \
    \               comp[u] = comp[v];\n                dfs(u, t);\n            }\n\
    \        }\n    }\n    vector<vector<int>> components() { return comps; }\n  \
    \  vector<vector<int>> directed_forest() { return new_g; }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define rep(i, n) for (int\
    \ i = 0; i < n; i++)\nstruct TwoEdgeConnectedComponents {\n    int V;\n    vector<vector<int>>\
    \ g, new_g;\n    vector<int> depth, imos, comp;\n    vector<vector<int>> comps;\n\
    \    TwoEdgeConnectedComponents(vector<vector<int>> g_) : V((int)g_.size()), g(g_),\
    \ depth(V, -1), imos(V), comp(V, -1) {\n        int t = -1;\n        rep(i, V)\
    \ {\n            if (depth[i] == -1) {\n                depth[i] = 0;\n      \
    \          dfs_init(i);\n                comp[i] = ++t;\n                comps.push_back({});\n\
    \                new_g.push_back({});\n                dfs(i, t);\n          \
    \  }\n        }\n    }\n    void dfs_init(int v) {\n        for (int u : g[v])\
    \ {\n            if (depth[u] == -1) {\n                depth[u] = depth[v] +\
    \ 1;\n                dfs_init(u);\n                imos[v] += imos[u];\n    \
    \        } else if (depth[u] < depth[v])\n                imos[u]--, imos[v]++;\n\
    \        }\n    }\n    void dfs(int v, int &t) {\n        comps[comp[v]].push_back(v);\n\
    \        for (int u : g[v]) {\n            if (depth[u] == depth[v] + 1 && comp[u]\
    \ == -1) {\n                if (imos[u] <= 1) {\n                    comp[u] =\
    \ ++t;\n                    comps.push_back({});\n                    new_g.push_back({});\n\
    \                    new_g[comp[v]].push_back(comp[u]);\n                } else\n\
    \                    comp[u] = comp[v];\n                dfs(u, t);\n        \
    \    }\n        }\n    }\n    vector<vector<int>> components() { return comps;\
    \ }\n    vector<vector<int>> directed_forest() { return new_g; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: TwoEdgeConnectedComponents.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TwoEdgeConnectedComponents.test.cpp
documentation_of: TwoEdgeConnectedComponents.cpp
layout: document
redirect_from:
- /library/TwoEdgeConnectedComponents.cpp
- /library/TwoEdgeConnectedComponents.cpp.html
title: TwoEdgeConnectedComponents.cpp
---
