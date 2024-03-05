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
  bundledCode: "#line 1 \"MaxFlow.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// int to;Cap cap:int rev;\nstruct edge {\n    int to, cap, rev;\n};\n\
    \ntemplate <class Cap>\nstruct mf_graph {\n    int N;\n    vector<vector<edge>>\
    \ g;\n    vector<int> level, iter;\n    mf_graph(int n) : N(n), level(n), iter(n),\
    \ g(n) {}\n    void add_edge(int from, int to, Cap cap) {\n        g[from].push_back(edge{to,\
    \ cap, (int)g[to].size()});\n        g[to].push_back(edge{from, 0, (int)g[from].size()\
    \ - 1});\n    }\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<int> que;\n        level[s] = 0;\n        que.push(0);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (int i = 0; i < g[v].size(); i++) {\n         \
    \       edge &e = g[v][i];\n                if (e.cap > 0 && level[e.to] < 0)\
    \ {\n                    level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n    Cap dfs(int v, int t,\
    \ Cap f) {\n        if (v == t) return f;\n        for (int &i = iter[v]; i <\
    \ g[v].size(); i++) {\n            edge &e = g[v][i];\n            if (e.cap >\
    \ 0 && level[v] < level[e.to]) {\n                Cap d = dfs(e.to, t, min(f,\
    \ e.cap));\n                if (d > 0) {\n                    e.cap -= d;\n  \
    \                  g[e.to][e.rev].cap += d;\n                    return d;\n \
    \               }\n            }\n        }\n        return 0;\n    }\n    Cap\
    \ max_flow(int s, int t) {\n        Cap flow = 0;\n        while (1) {\n     \
    \       bfs(s);\n            if (level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            Cap f;\n            while ((f = dfs(s, t, 1e9))\
    \ > 0) {\n                flow += f;\n            }\n            // s/1e9/1e18\
    \ if Cap=long long\n        }\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// int to;Cap cap:int rev;\n\
    struct edge {\n    int to, cap, rev;\n};\n\ntemplate <class Cap>\nstruct mf_graph\
    \ {\n    int N;\n    vector<vector<edge>> g;\n    vector<int> level, iter;\n \
    \   mf_graph(int n) : N(n), level(n), iter(n), g(n) {}\n    void add_edge(int\
    \ from, int to, Cap cap) {\n        g[from].push_back(edge{to, cap, (int)g[to].size()});\n\
    \        g[to].push_back(edge{from, 0, (int)g[from].size() - 1});\n    }\n   \
    \ void bfs(int s) {\n        fill(level.begin(), level.end(), -1);\n        queue<int>\
    \ que;\n        level[s] = 0;\n        que.push(0);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (int i = 0; i < g[v].size(); i++) {\n                edge &e = g[v][i];\n  \
    \              if (e.cap > 0 && level[e.to] < 0) {\n                    level[e.to]\
    \ = level[v] + 1;\n                    que.push(e.to);\n                }\n  \
    \          }\n        }\n    }\n    Cap dfs(int v, int t, Cap f) {\n        if\
    \ (v == t) return f;\n        for (int &i = iter[v]; i < g[v].size(); i++) {\n\
    \            edge &e = g[v][i];\n            if (e.cap > 0 && level[v] < level[e.to])\
    \ {\n                Cap d = dfs(e.to, t, min(f, e.cap));\n                if\
    \ (d > 0) {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    Cap max_flow(int s, int t) {\n        Cap\
    \ flow = 0;\n        while (1) {\n            bfs(s);\n            if (level[t]\
    \ < 0) return flow;\n            fill(iter.begin(), iter.end(), 0);\n        \
    \    Cap f;\n            while ((f = dfs(s, t, 1e9)) > 0) {\n                flow\
    \ += f;\n            }\n            // s/1e9/1e18 if Cap=long long\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: MaxFlow.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: MaxFlow.cpp
layout: document
redirect_from:
- /library/MaxFlow.cpp
- /library/MaxFlow.cpp.html
title: MaxFlow.cpp
---
