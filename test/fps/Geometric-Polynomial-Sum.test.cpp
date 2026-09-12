// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
#include "fps/geometric-polynomial-sum.hpp"
#include "modint.hpp"
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int r, d;
    ll n;
    cin >> r >> d >> n;
    cout << sum_of_exponential_times_polynomial(modint<998244353>(r), d, n) << endl;
}