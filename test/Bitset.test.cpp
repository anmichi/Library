// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product_mod_2
#include "bitset.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
constexpr int mod = 998244353;
BitSet<4096> a[4096], b[4096], c[4096];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, m) a[i].set(j, s[j] - '0');
    }
    rep(i, m) {
        string s;
        cin >> s;
        rep(j, k) b[j].set(i, s[j] - '0');
    }
    rep(i, n) {
        rep(j, k) { cout << ((a[i] & b[j]).count() & 1); }
        cout << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}