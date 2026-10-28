// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product
#include "matrix.hpp"
#include "modint.hpp"
using mint = modint<998244353>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Matrix<mint, 1024> a, b;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) cin >> b[i][j];
    }
    a *= b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << a[i][j] << (j + 1 == k ? "\n" : " ");
    }
}
