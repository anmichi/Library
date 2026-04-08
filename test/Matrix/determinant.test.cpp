// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det
#include "../../Matrix.hpp"
#include "../../modint.hpp"
#include "../../template.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    cout << a.determinant() << endl;
}