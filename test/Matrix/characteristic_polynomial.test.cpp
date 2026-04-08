// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/characteristic_polynomial
#include "../../Matrix.hpp"
#include "../../modint.hpp"
#include "../../template.hpp"
int main() {
    int n;
    cin >> n;
    Matrix<modint<998244353>> a(n);
    cin >> a;
    cout << a.characteristic_polynomial() << endl;
}