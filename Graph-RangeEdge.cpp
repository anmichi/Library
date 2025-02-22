#include "template.cpp"
template <class T>
struct RangeEdgeGraph {
    int n, sz;
    vector<vector<pair<int, T>>> g;
    RangeEdgeGraph(int _n) : n(_n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        g.resize(sz * 3);
        for (int v = 2; v < sz + n; v++) {
            g[v >> 1].push_back({v, 0});
            g[v >= sz ? v : v + sz * 2].push_back({sz * 2 + (v >> 1), 0});
        }
    }
    void add_edge(int l1, int r1, int l2, int r2, T cost) {
        //[l1,r1)->[l2,r2)
        int id = g.size();
        g.push_back({});
        {
            int l = l1, r = r1;
            l += sz, r += sz;
            while (l < r) {
                if (l & 1) {
                    g[(l < sz ? l + sz * 2 : l)].push_back({id, cost});
                    l++;
                }
                if (r & 1) {
                    r--;
                    g[(r < sz ? r + sz * 2 : r)].push_back({id, cost});
                }
                l >>= 1, r >>= 1;
            }
        }
        {
            int l = l2, r = r2;
            l += sz, r += sz;
            while (l < r) {
                if (l & 1) {
                    g[id].push_back({l, 0});
                    l++;
                }
                if (r & 1) {
                    r--;
                    g[id].push_back({r, 0});
                }
                l >>= 1, r >>= 1;
            }
        }
    }
    vector<T> dijkstra(vector<int> start) {
        using P = pair<T, int>;
        vector<T> dp(g.size(), numeric_limits<T>::max());
        priority_queue<P, vector<P>, greater<P>> que;
        for (int s : start) {
            s += sz;
            dp[s] = 0;
            que.push({0, s});
        }
        while (que.size()) {
            auto [d, v] = que.top();
            que.pop();
            if (dp[v] != d) continue;
            for (auto [u, c] : g[v]) {
                if (chmin(dp[u], d + c)) que.push({dp[u], u});
            }
        }
        return vector(dp.begin() + sz, dp.begin() + sz + n);
    }
};