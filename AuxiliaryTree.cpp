#include <bits/stdc++.h>
#include "LCA.cpp"
using namespace std;
struct auxiliary_tree : lca_tree {
    vector<int> in;
    vector<vector<int>> G;
    auxiliary_tree(vector<vector<int>>& g) : lca_tree(g), in((int)g.size()), G((int)g.size()) {
        int t = 0;
        dfs(0, -1, t, g);
    }
    void dfs(int v, int p, int& t, vector<vector<int>>& g) {
        in[v] = t++;
        for (auto u : g[v]) {
            if (u != p) dfs(u, v, t, g);
        }
    }
    using lca_tree::depth;
    pair<int, vector<int>> query(vector<int> vs, bool decending = false) {
        // decending:親から子の方向のみ辺を貼る
        assert(!vs.empty());
        sort(vs.begin(), vs.end(), [&](int a, int b) { return in[a] < in[b]; });
        int m = vs.size();
        stack<int> st;
        st.push(vs[0]);
        for (int i = 0; i < m - 1; i++) {
            int w = lca_tree::query(vs[i], vs[i + 1]);
            if (w != vs[i]) {
                int l = st.top();
                st.pop();
                while (!st.empty() && depth[w] < depth[st.top()]) {
                    if (!decending) G[l].push_back(st.top());
                    G[st.top()].push_back(l);
                    l = st.top();
                    st.pop();
                }
                if (st.empty() || st.top() != w) {
                    st.push(w);
                    vs.push_back(w);
                }
                if (!decending) G[l].push_back(w);
                G[w].push_back(l);
            }
            st.push(vs[i + 1]);
        }
        while (st.size() > 1) {
            int x = st.top();
            st.pop();
            if (!decending) G[x].push_back(st.top());
            G[st.top()].push_back(x);
        }
        // {root,vertex_list}
        return make_pair(st.top(), vs);
    }
    void clear(vector<int> vs) {
        for (int v : vs) G[v].clear();
    }
};