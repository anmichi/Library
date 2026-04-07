#include "../../FPS/Polynomial-Interpolation.hpp"
using mint = atcoder::modint998244353;
void solve() {
    int n;
    cin >> n;
    vector<mint> x(n), y(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x[i] = a;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        y[i] = a;
    }
    vector<mint> ans = Interpolation(x, y);
    for (auto& x : ans) cout << x.val() << " ";
    cout << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}