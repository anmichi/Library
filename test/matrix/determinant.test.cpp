// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det
#include "../../matrix.hpp"
#include "../../modint.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    cout << a.determinant() << endl;
}