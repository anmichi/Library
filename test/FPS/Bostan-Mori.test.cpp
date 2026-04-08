// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
#include "../../FPS/Bostan-Mori.hpp"
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
void solve() {
    int d;
    ll k;
    cin >> d >> k;
    vector<mint> p(d), q(d + 1);
    rep(i, d) {
        int x;
        cin >> x;
        p[i] = x;
    }
    q[0] = 1;
    rep(i, d) {
        int x;
        cin >> x;
        q[i + 1] = -x;
    }
    p = atcoder::convolution(p, q);
    p.resize(d);
    cout << Bostan_Mori(p, q, k).val() << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}