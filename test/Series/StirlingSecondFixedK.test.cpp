#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"
#include "../../Series.cpp"
void solve() {
    using mint = atcoder::modint998244353;
    int n, k;
    cin >> n >> k;
    Binomial<mint> bin(n);
    auto f = stirling_second_fixedK(n, k, bin);
    for (auto x : f) cout << x.val() << " ";
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
