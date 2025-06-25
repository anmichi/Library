// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/line_add_get_min
#include "../CHT-Arbitary.cpp"
using ll = long long;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    CHT_Arbitary<ll, true> cht;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cht.add(-a, -b);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            cht.add(-a, -b);
        } else {
            ll p;
            cin >> p;
            cout << -cht.query(p) << "\n";
        }
    }
}