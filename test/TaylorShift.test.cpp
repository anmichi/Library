#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../TaylorShift.cpp"
#include "../modint_io.cpp"
int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    mint c;
    cin >> c;
    FormalPowerSeries<mint> f(n);
    for (auto &x : f) cin >> x;
    Binomial<mint> bin(n);
    FormalPowerSeries<mint> g = TaylorShift<mint>(f, c, bin);
    rep(i, n) cout << g[i] << " ";
    cout << endl;
}