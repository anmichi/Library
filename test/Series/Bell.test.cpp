// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/bell_number
#include "../../Series.cpp"
void solve() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    Binomial<mint> bin(n);
    for (auto x : bell(n, bin)) cout << x.val() << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
