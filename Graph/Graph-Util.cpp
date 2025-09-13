#include "../Graph-Template.cpp"
template <class T>
vector<T> dijkstra(Graph<T> &g, int s = 0) {
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
            if (chmin(dp[e.to], d + e.cost)) que.push({dp[e.to], e.to});
        }
    }
    return dp;
}
template <class T>
vector<int> BFS(Graph<T> &g, int s = 0) {  // 01
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
template <class T>
tuple<int, int, T> Diameter(Graph<T> &g) {
    auto d = dijkstra(g, 0);
    int u = max_element(d.begin(), d.end()) - d.begin();
    d = dijkstra(g, u);
    int v = max_element(d.begin(), d.end()) - d.begin();
    return make_tuple(u, v, d[v]);
}
template <typename G>
vector<int> Path(G &g, int u, int v) {
    vector<int> path;
    bool found = false;
    function<void(int, int)> dfs = [&](int cur, int par) {
        path.push_back(cur);
        if (cur == v) {
            found = true;
            return;
        }
        for (int nxt : g[cur]) {
            if (nxt == par) continue;
            dfs(nxt, cur);
            if (found) return;
        }
        if (found) return;
        path.pop_back();
    };
    dfs(u, -1);
    return path;
}