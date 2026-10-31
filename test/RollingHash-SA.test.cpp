// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/zalgorithm
#include "rolling_hash.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> sa(s.size());
    for (int i = 0; i < s.size(); i++) sa[i] = i;
    RollingHash rh(s + char(123));
    sort(sa.begin(), sa.end(), [&](int i, int j) {
        int l = rh.lcp(i, rh, j);
        return s[i + l] < s[j + l];
    });
    for (int i = 0; i < s.size(); i++) cout << sa[i] << ' ';
}