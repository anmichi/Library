---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: AuxiliaryTree.cpp
    title: AuxiliaryTree.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0439
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0439
  bundledCode: "#line 1 \"test/AuxiliaryTree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0439\"\
    \n#line 1 \"AuxiliaryTree.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"LCA.cpp\"\
    \nusing namespace std;\nstruct lca_tree {\n    int n, size;\n    vector<vector<int>>\
    \ g, par;\n    vector<int> depth;\n    lca_tree(vector<vector<int>> g_, int root\
    \ = 0)\n        : n((int)g_.size()), size(log2(n) + 2), g(g_), par(size, vector<int>(n,\
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
    \ - 2 * depth[l];\n    }\n};\n#line 3 \"AuxiliaryTree.cpp\"\nusing namespace std;\n\
    struct auxiliary_tree : lca_tree {\n    vector<int> in;\n    vector<vector<int>>\
    \ G;\n    auxiliary_tree(vector<vector<int>>& g) : lca_tree(g), in((int)g.size()),\
    \ G((int)g.size()) {\n        int t = 0;\n        dfs(0, -1, t, g);\n    }\n \
    \   void dfs(int v, int p, int& t, vector<vector<int>>& g) {\n        in[v] =\
    \ t++;\n        for (auto u : g[v]) {\n            if (u != p) dfs(u, v, t, g);\n\
    \        }\n    }\n    using lca_tree::depth;\n    pair<int, vector<int>> query(vector<int>\
    \ vs, bool decending = false) {\n        // decending:\u89AA\u304B\u3089\u5B50\
    \u306E\u65B9\u5411\u306E\u307F\u8FBA\u3092\u8CBC\u308B\n        assert(!vs.empty());\n\
    \        sort(vs.begin(), vs.end(), [&](int a, int b) { return in[a] < in[b];\
    \ });\n        int m = vs.size();\n        stack<int> st;\n        st.push(vs[0]);\n\
    \        for (int i = 0; i < m - 1; i++) {\n            int w = lca_tree::query(vs[i],\
    \ vs[i + 1]);\n            if (w != vs[i]) {\n                int l = st.top();\n\
    \                st.pop();\n                while (!st.empty() && depth[w] < depth[st.top()])\
    \ {\n                    if (!decending) G[l].push_back(st.top());\n         \
    \           G[st.top()].push_back(l);\n                    l = st.top();\n   \
    \                 st.pop();\n                }\n                if (st.empty()\
    \ || st.top() != w) {\n                    st.push(w);\n                    vs.push_back(w);\n\
    \                }\n                if (!decending) G[l].push_back(w);\n     \
    \           G[w].push_back(l);\n            }\n            st.push(vs[i + 1]);\n\
    \        }\n        while (st.size() > 1) {\n            int x = st.top();\n \
    \           st.pop();\n            if (!decending) G[x].push_back(st.top());\n\
    \            G[st.top()].push_back(x);\n        }\n        // {root,vertex_list}\n\
    \        return make_pair(st.top(), vs);\n    }\n    void clear(vector<int> vs)\
    \ {\n        for (int v : vs) G[v].clear();\n    }\n};\n#line 3 \"test/AuxiliaryTree.test.cpp\"\
    \n\n#define rep(i, n) for (int i = 0; i < n; i++)\ntemplate <class T, class U>\n\
    inline bool chmin(T& a, U b) {\n    if (a > b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n    vector<int> a(n);\n    rep(i, n) {\n        cin\
    \ >> a[i];\n        a[i]--;\n    }\n    vector<vector<int>> g(n);\n    rep(i,\
    \ n - 1) {\n        int u, v;\n        cin >> u >> v;\n        u--, v--;\n   \
    \     g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    auxiliary_tree\
    \ aux_tree(g);\n    vector<vector<int>> vec(n);\n    rep(i, n) vec[a[i]].push_back(i);\n\
    \    vector<int> dist(n), idx(n);\n    vector<int> ans(n, 1000000000);\n    rep(color,\
    \ n) {\n        if (vec[color].empty()) continue;\n        auto [root, vs] = aux_tree.query(vec[color]);\n\
    \        using P = pair<int, int>;\n        priority_queue<P, vector<P>, greater<P>>\
    \ que;\n        for (auto v : vs) dist[v] = n, idx[v] = -1;\n        for (int\
    \ s : vec[color]) dist[s] = 0, idx[s] = s, que.push({dist[s], s});\n        while\
    \ (!que.empty()) {\n            auto [d, v] = que.top();\n            que.pop();\n\
    \            if (dist[v] != d) continue;\n            for (auto u : aux_tree.G[v])\
    \ {\n                int c = abs(aux_tree.depth[u] - aux_tree.depth[v]);\n   \
    \             if (chmin(dist[u], d + c)) {\n                    idx[u] = idx[v];\n\
    \                    que.push({dist[u], u});\n                }\n            }\n\
    \        }\n        for (int v : vs) {\n            for (int u : aux_tree.G[v])\
    \ {\n                if (idx[v] == idx[u]) continue;\n                chmin(ans[idx[v]],\
    \ aux_tree.dist(idx[v], idx[u]));\n                chmin(ans[idx[u]], aux_tree.dist(idx[v],\
    \ idx[u]));\n            }\n        }\n        aux_tree.clear(vs);\n    }\n  \
    \  rep(i, n) cout << ans[i] << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0439\"\n#include\
    \ \"../AuxiliaryTree.cpp\"\n\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    template <class T, class U>\ninline bool chmin(T& a, U b) {\n    if (a > b) {\n\
    \        a = b;\n        return true;\n    }\n    return false;\n}\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\n    cin >>\
    \ n;\n    vector<int> a(n);\n    rep(i, n) {\n        cin >> a[i];\n        a[i]--;\n\
    \    }\n    vector<vector<int>> g(n);\n    rep(i, n - 1) {\n        int u, v;\n\
    \        cin >> u >> v;\n        u--, v--;\n        g[u].push_back(v);\n     \
    \   g[v].push_back(u);\n    }\n    auxiliary_tree aux_tree(g);\n    vector<vector<int>>\
    \ vec(n);\n    rep(i, n) vec[a[i]].push_back(i);\n    vector<int> dist(n), idx(n);\n\
    \    vector<int> ans(n, 1000000000);\n    rep(color, n) {\n        if (vec[color].empty())\
    \ continue;\n        auto [root, vs] = aux_tree.query(vec[color]);\n        using\
    \ P = pair<int, int>;\n        priority_queue<P, vector<P>, greater<P>> que;\n\
    \        for (auto v : vs) dist[v] = n, idx[v] = -1;\n        for (int s : vec[color])\
    \ dist[s] = 0, idx[s] = s, que.push({dist[s], s});\n        while (!que.empty())\
    \ {\n            auto [d, v] = que.top();\n            que.pop();\n          \
    \  if (dist[v] != d) continue;\n            for (auto u : aux_tree.G[v]) {\n \
    \               int c = abs(aux_tree.depth[u] - aux_tree.depth[v]);\n        \
    \        if (chmin(dist[u], d + c)) {\n                    idx[u] = idx[v];\n\
    \                    que.push({dist[u], u});\n                }\n            }\n\
    \        }\n        for (int v : vs) {\n            for (int u : aux_tree.G[v])\
    \ {\n                if (idx[v] == idx[u]) continue;\n                chmin(ans[idx[v]],\
    \ aux_tree.dist(idx[v], idx[u]));\n                chmin(ans[idx[u]], aux_tree.dist(idx[v],\
    \ idx[u]));\n            }\n        }\n        aux_tree.clear(vs);\n    }\n  \
    \  rep(i, n) cout << ans[i] << endl;\n}"
  dependsOn:
  - AuxiliaryTree.cpp
  - LCA.cpp
  isVerificationFile: true
  path: test/AuxiliaryTree.test.cpp
  requiredBy: []
  timestamp: '2024-03-07 03:29:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AuxiliaryTree.test.cpp
layout: document
redirect_from:
- /verify/test/AuxiliaryTree.test.cpp
- /verify/test/AuxiliaryTree.test.cpp.html
title: test/AuxiliaryTree.test.cpp
---
