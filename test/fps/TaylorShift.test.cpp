// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift
#include "fps/TaylorShift.hpp"
int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    int c;
    cin >> c;
    FormalPowerSeries<mint> f(n);
    for (auto& x : f) {
        int a;
        cin >> a;
        x = a;
    }
    Binomial<mint> bin(n);
    FormalPowerSeries<mint> g = TaylorShift<mint>(f, c, bin);
    for (int i = 0; i < n; i++) cout << g[i].val() << " ";
    cout << endl;
}