// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/characteristic_polynomial
#include "matrix.hpp"
#include "modint.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    for (auto x : a.characteristic_polynomial()) cout << x << ' ';
    cout << endl;
}