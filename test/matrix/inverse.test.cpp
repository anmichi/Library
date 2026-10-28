// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix
#include "matrix.hpp"
#include "modint.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    if (auto b = a.inverse())
        cout << *b << endl;
    else
        cout << -1 << endl;
}