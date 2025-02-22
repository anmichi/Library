#include "../Graph-RangeEdge.cpp"
// verified with "https://codeforces.com/contest/786/problem/B"
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q, s;
    cin >> n >> q >> s;
    RangeEdgeGraph<ll> g(n);
    rep(i, q) {
        int t, v, l, r, w;
        cin >> t;
        if (t == 1) {
            cin >> v >> l >> w;
            v--, l--;
            g.add_edge(v, v + 1, l, l + 1, w);
        } else {
            cin >> v >> l >> r >> w;
            v--, l--;
            if (t == 2)
                g.add_edge(v, v + 1, l, r, w);
            else
                g.add_edge(l, r, v, v + 1, w);
        }
    }
    auto dp = g.dijkstra({s - 1});
    for (ll &x : dp) {
        if (x == numeric_limits<ll>::max()) x = -1;
    }
    cout << dp << endl;
}