// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/product_of_polynomial_sequence
#include "../../FPS/Polynomial-Product.hpp"
using mint = atcoder::modint998244353;
int main() {
    int n;
    cin >> n;
    vector<vector<mint>> f(n);
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        f[i].resize(d + 1);
        for (auto& x : f[i]) {
            int a;
            cin >> a;
            x = a;
        }
    }
    auto g = PolyProd(f);
    for (mint x : g) cout << x.val() << " ";
    cout << endl;
}