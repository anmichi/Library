#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"
#include "../../Series.cpp"
void solve() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    Binomial<mint> bin(n);
    auto f = stirling_first(n, bin);
    for (auto x : f) cout << x.val() << " ";
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
