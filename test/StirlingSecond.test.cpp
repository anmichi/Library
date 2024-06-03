#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "../Series.cpp"
using mint = atcoder::modint998244353;
void solve() {
    int n;
    cin >> n;
    Binomial<mint> bin(n);
    auto f = stirling_second(n, bin);
    for (auto x : f) cout << x.val() << " ";
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    /*int t;
    cin >> t;
    while (t--)*/
    solve();
}
