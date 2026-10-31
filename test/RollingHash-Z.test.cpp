// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/zalgorithm
#include "rolling_hash.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    RollingHash rh(s);
    for (int i = 0; i < s.size(); i++) cout << rh.lcp(0, rh, i) << ' ';
}