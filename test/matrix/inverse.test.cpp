// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix
#include "../../matrix.hpp"
#include "../../modint.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    if (a.determinant() == 0)
        cout << -1 << endl;
    else
        cout << a.inverse() << endl;
}