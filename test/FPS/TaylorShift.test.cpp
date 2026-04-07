// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift
#include "../../FPS/TaylorShift.cpp"
#include "../../modint_acl_io.cpp"
int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    mint c;
    cin >> c;
    FormalPowerSeries<mint> f(n);
    for (auto& x : f) cin >> x;
    Binomial<mint> bin(n);
    FormalPowerSeries<mint> g = TaylorShift<mint>(f, c, bin);
    for (int i = 0; i < n; i++) cout << g[i] << " ";
    cout << endl;
}