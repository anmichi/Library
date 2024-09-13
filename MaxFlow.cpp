#include <bits/stdc++.h>
using namespace std;

template <class Cap>
struct Dinic {
    struct edge {
        int to, rev;
        Cap cap;
    };

    int N;
    vector<vector<edge>> g;
    vector<int> level, iter;
    Dinic() = default;
    Dinic(int n) : N(n), level(n), iter(n), g(n) {}
    void add_edge(int from, int to, Cap cap) {
        g[from].push_back(edge{to, (int)g[to].size(), cap});
        g[to].push_back(edge{from, (int)g[from].size() - 1, (Cap)0});
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
        for (int &i = iter[v]; i < (int)g[v].size(); i++) {
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
    Cap max_flow(int s, int t) { return max_flow(s, t, numeric_limits<Cap>::max()); }
    Cap max_flow(int s, int t, Cap flow_limit) {
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs(s);
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f;
            while (flow < flow_limit) {
                Cap f = dfs(s, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }
};