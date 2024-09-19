// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/703
#include "../CHT-Monotone.cpp"
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), x(n), y(n), dp(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    dp[0] = 0;
    CHT_Monotone<ll> cht;
    for (int i = 0; i < n; i++) {
        cht.add(-2 * x[i], dp[i] + x[i] * x[i] + y[i] * y[i]);
        dp[i + 1] = a[i] * a[i] + cht.query(a[i]);
    }
    cout << dp[n] << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}