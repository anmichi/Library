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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AuxiliaryTree.test.cpp
    title: test/AuxiliaryTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"AuxiliaryTree.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"\
    SparseTable.cpp\"\nusing namespace std;\ntemplate <class T, T (*op)(T, T), T (*e)()>\n\
    struct sparsetable {\n    vector<vector<T>> table;\n    vector<int> logtable;\n\
    \    sparsetable() = default;\n    sparsetable(vector<T> v) {\n        int len\
    \ = 0;\n        while ((1 << len) <= v.size()) len++;\n        table.assign(len,\
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
    \    }\n};\n#line 3 \"AuxiliaryTree.cpp\"\nusing namespace std;\nstruct auxiliary_tree\
    \ : lca_tree {\n    vector<vector<int>> G;\n    auxiliary_tree(vector<vector<int>>&\
    \ g) : lca_tree(g), G(n) {}\n    pair<int, vector<int>> query(vector<int> vs,\
    \ bool decending = false) {\n        // decending:\u89AA\u304B\u3089\u5B50\u306E\
    \u65B9\u5411\u306E\u307F\u8FBA\u3092\u8CBC\u308B\n        assert(!vs.empty());\n\
    \        sort(vs.begin(), vs.end(), [&](int a, int b) { return in[a] < in[b];\
    \ });\n        int m = vs.size();\n        stack<int> st;\n        st.push(vs[0]);\n\
    \        for (int i = 0; i < m - 1; i++) {\n            int w = lca(vs[i], vs[i\
    \ + 1]);\n            if (w != vs[i]) {\n                int l = st.top();\n \
    \               st.pop();\n                while (!st.empty() && depth[w] < depth[st.top()])\
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
    \ {\n        for (int v : vs) G[v].clear();\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"LCA.cpp\"\nusing namespace std;\nstruct\
    \ auxiliary_tree : lca_tree {\n    vector<vector<int>> G;\n    auxiliary_tree(vector<vector<int>>&\
    \ g) : lca_tree(g), G(n) {}\n    pair<int, vector<int>> query(vector<int> vs,\
    \ bool decending = false) {\n        // decending:\u89AA\u304B\u3089\u5B50\u306E\
    \u65B9\u5411\u306E\u307F\u8FBA\u3092\u8CBC\u308B\n        assert(!vs.empty());\n\
    \        sort(vs.begin(), vs.end(), [&](int a, int b) { return in[a] < in[b];\
    \ });\n        int m = vs.size();\n        stack<int> st;\n        st.push(vs[0]);\n\
    \        for (int i = 0; i < m - 1; i++) {\n            int w = lca(vs[i], vs[i\
    \ + 1]);\n            if (w != vs[i]) {\n                int l = st.top();\n \
    \               st.pop();\n                while (!st.empty() && depth[w] < depth[st.top()])\
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
    \ {\n        for (int v : vs) G[v].clear();\n    }\n};"
  dependsOn:
  - LCA.cpp
  - SparseTable.cpp
  isVerificationFile: false
  path: AuxiliaryTree.cpp
  requiredBy: []
  timestamp: '2024-06-25 16:25:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AuxiliaryTree.test.cpp
documentation_of: AuxiliaryTree.cpp
layout: document
redirect_from:
- /library/AuxiliaryTree.cpp
- /library/AuxiliaryTree.cpp.html
title: AuxiliaryTree.cpp
---
