---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: TwoEdgeConnectedComponents.cpp
    title: TwoEdgeConnectedComponents.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/TwoEdgeConnectedComponents.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n#line 1 \"\
    TwoEdgeConnectedComponents.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, n) for (int i = 0; i < n; i++)\nstruct TwoEdgeConnectedComponents\
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
    \  vector<vector<int>> directed_forest() { return new_g; }\n};\n#line 3 \"test/TwoEdgeConnectedComponents.test.cpp\"\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ m;\n    cin >> n >> m;\n    vector<vector<int>> g(n);\n    rep(i, m) {\n   \
    \     int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \    }\n    TwoEdgeConnectedComponents G(g);\n    auto components = G.components();\n\
    \    cout << components.size() << endl;\n    for (auto vec : components) {\n \
    \       cout << vec.size();\n        for (auto v : vec) cout << \" \" << v;\n\
    \        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include \"../TwoEdgeConnectedComponents.cpp\"\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n, m;\n    cin >> n >> m;\n    vector<vector<int>>\
    \ g(n);\n    rep(i, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n    TwoEdgeConnectedComponents G(g);\n   \
    \ auto components = G.components();\n    cout << components.size() << endl;\n\
    \    for (auto vec : components) {\n        cout << vec.size();\n        for (auto\
    \ v : vec) cout << \" \" << v;\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - TwoEdgeConnectedComponents.cpp
  isVerificationFile: true
  path: test/TwoEdgeConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/TwoEdgeConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/test/TwoEdgeConnectedComponents.test.cpp
- /verify/test/TwoEdgeConnectedComponents.test.cpp.html
title: test/TwoEdgeConnectedComponents.test.cpp
---
