#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "graph.hpp"
template <class T>
vector<T> dijkstra(Graph<T>& g, int s = 0) {
    using P = pair<T, int>;
    vector<T> dp(g.size(), numeric_limits<T>::max());
    priority_queue<P, vector<P>, greater<P>> que;
    dp[s] = 0;
    que.push({0, s});
    while (que.size()) {
        auto [d, v] = que.top();
        que.pop();
        if (dp[v] != d) continue;
        for (auto e : g[v]) {
            if (dp[e.to] > d + e.cost) {
                dp[e.to] = d + e.cost;
                que.push({dp[e.to], e.to});
            }
        }
    }
    return dp;
}
template <class T>
vector<int> BFS(Graph<T>& g, int s = 0) {  // 01
    vector<int> dp(g.size(), numeric_limits<int>::max());
    deque<int> que;
    dp[s] = 0;
    que.push_front(s);
    while (que.size()) {
        auto v = que.front();
        que.pop_front();
        for (auto e : g[v]) {
            if (chmin(dp[e.to], dp[v] + e.cost)) {
                if (e.cost == 0)
                    que.push_front(e.to);
                else
                    que.push_back(e.to);
            }
        }
    }
    return dp;
}

template <class T, bool Weighted = false>
pair<vector<int>, T> Diameter(Graph<T>& g) {
    auto d = (Weighted ? dijkstra(g, 0) : BFS(g, 0));
    int u = max_element(d.begin(), d.end()) - d.begin();
    d = (Weighted ? dijkstra(g, u) : BFS(g, u));
    int v = max_element(d.begin(), d.end()) - d.begin();
    vector<int> path{v};
    int D = d[v];
    if (!Weighted) path.reserve(d[v] + 1);
    while (v != u) {
        for (auto e : g[v]) {
            if (d[e.to] + e.cost == d[v]) {
                path.push_back(e.to);
                v = e.to;
                break;
            }
        }
    }
    return make_pair(path, D);
}
template <typename G>
vector<int> Path(G& g, int u, int v) {
    vector<int> path;
    vector<bool> vis(g.size());
    bool found = false;
    function<void(int, int)> dfs = [&](int cur, int par) {
        path.push_back(cur);
        vis[cur] = true;
        if (cur == v) {
            found = true;
            return;
        }
        for (int nxt : g[cur]) {
            if (nxt == par) continue;
            if (vis[nxt]) continue;
            dfs(nxt, cur);
            if (found) return;
        }
        if (found) return;
        path.pop_back();
    };
    dfs(u, -1);
    return path;
}