---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: LCA.cpp
    title: LCA.cpp
  - icon: ':heavy_check_mark:'
    path: SparseTable.cpp
    title: SparseTable.cpp
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
    \n#line 1 \"LCA.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"SparseTable.cpp\"\n\
    using namespace std;\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct sparsetable\
    \ {\n    vector<vector<T>> table;\n    vector<int> logtable;\n    sparsetable()\
    \ = default;\n    sparsetable(vector<T> v) {\n        int len = 0;\n        while\
    \ ((1 << len) <= v.size()) len++;\n        table.assign(len, vector<T>(1 << len));\n\
    \        for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];\n       \
    \ for (int i = 1; i < len; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << len); j++) {\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n        logtable.resize(v.size()\
    \ + 1);\n        for (int i = 2; i < logtable.size(); i++) {\n            logtable[i]\
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
    \    };\n};\n#line 3 \"LCA.cpp\"\nusing namespace std;\npair<int, int> lcatree_op(pair<int,\
    \ int> a, pair<int, int> b) { return min(a, b); }\npair<int, int> lcatree_e()\
    \ { return {1000000000, -1}; }\nstruct lca_tree {\n    int n, size;\n    vector<int>\
    \ in, ord, depth;\n    sparsetable<pair<int, int>, lcatree_op, lcatree_e> st;\n\
    \    lca_tree(vector<vector<int>> g, int root = 0) : n((int)g.size()), size(log2(n)\
    \ + 2), in(n), depth(n, n) {\n        depth[root] = 0;\n        function<void(int,\
    \ int)> dfs = [&](int v, int p) {\n            in[v] = (int)ord.size();\n    \
    \        ord.push_back(v);\n            for (int u : g[v]) {\n               \
    \ if (u == p) continue;\n                if (depth[u] > depth[v] + 1) {\n    \
    \                depth[u] = depth[v] + 1;\n                    dfs(u, v);\n  \
    \                  ord.push_back(v);\n                }\n            }\n     \
    \   };\n        dfs(root, -1);\n        vector<pair<int, int>> vec((int)ord.size());\n\
    \        for (int i = 0; i < (int)ord.size(); i++) {\n            vec[i] = make_pair(depth[ord[i]],\
    \ ord[i]);\n        }\n        st = vec;\n    }\n    int lca(int u, int v) {\n\
    \        if (in[u] > in[v]) swap(u, v);\n        if (u == v) return u;\n     \
    \   return st.query(in[u], in[v]).second;\n    }\n    int dist(int u, int v) {\n\
    \        int l = lca(u, v);\n        return depth[u] + depth[v] - 2 * depth[l];\n\
    \    }\n};\n#line 3 \"test/LCA.test.cpp\"\nint main() {\n    cin.tie(0);\n   \
    \ ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n >> q;\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    lca_tree lt(g);\n    while (q--) {\n \
    \       int u, v;\n        cin >> u >> v;\n        cout << lt.lca(u, v) << \"\\\
    n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"../LCA.cpp\"\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    cin >> n >> q;\n    vector<vector<int>> g(n);\n    for (int i = 1; i\
    \ < n; i++) {\n        int p;\n        cin >> p;\n        g[p].push_back(i);\n\
    \    }\n    lca_tree lt(g);\n    while (q--) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        cout << lt.lca(u, v) << \"\\n\";\n    }\n}"
  dependsOn:
  - LCA.cpp
  - SparseTable.cpp
  isVerificationFile: true
  path: test/LCA.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 16:25:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LCA.test.cpp
layout: document
redirect_from:
- /verify/test/LCA.test.cpp
- /verify/test/LCA.test.cpp.html
title: test/LCA.test.cpp
---