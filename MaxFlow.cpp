#include <bits/stdc++.h>
using namespace std;

// int to;Cap cap:int rev;
struct edge {
    int to, cap, rev;
};

template <class Cap>
struct mf_graph {
    int N;
    vector<vector<edge>> g;
    vector<int> level, iter;
    mf_graph(int n) : N(n), level(n), iter(n), g(n) {}
    void add_edge(int from, int to, Cap cap) {
        g[from].push_back(edge{to, cap, (int)g[to].size()});
        g[to].push_back(edge{from, 0, (int)g[from].size() - 1});
    }
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(0);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < g[v].size(); i++) {
                edge &e = g[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    Cap dfs(int v, int t, Cap f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < g[v].size(); i++) {
            edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                Cap d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    Cap max_flow(int s, int t) {
        Cap flow = 0;
        while (1) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            Cap f;
            while ((f = dfs(s, t, 1e9)) > 0) {
                flow += f;
            }
            // s/1e9/1e18 if Cap=long long
        }
    }
};