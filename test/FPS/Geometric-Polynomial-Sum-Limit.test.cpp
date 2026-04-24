// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
#include "../../FPS/Geometric-Polynomial-Sum.hpp"
#include "../../modint.hpp"
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int r, d;
    cin >> r >> d;
    cout << sum_of_exponential_times_polynomial(modint<998244353>(r), d, -1) << endl;
}