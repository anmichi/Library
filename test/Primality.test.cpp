#include "../prime.hpp"
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/primality_test
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        puts(prime::is_prime(x) ? "Yes" : "No");
    }
}