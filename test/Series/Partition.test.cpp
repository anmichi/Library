// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/partition_function
#include "../../Series.cpp"
void solve() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    for (auto x : partition<mint>(n)) cout << x.val() << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
