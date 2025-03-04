// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/aplusb
#include "../Quotient-Range.cpp"
#define rep(i, n) for (int i = 0; i < n; i++)
set<int> enum_ceil(int n) {
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert((n + i - 1) / i);
    }
    return st;
}
void solve() {
    for (int i = 1; i <= 10000; i++) {
        auto qr = quotient_range_ceil(i);
        set<int> st;
        for (auto [rng, z] : qr) st.insert(z);
        assert(st == enum_ceil(i));
    }
    cerr << "quotients ok" << endl;
    for (int i = 1; i <= 10000; i++) {
        auto qr = quotient_range_ceil(i);
        rep(j, qr.size() - 1) {
            assert(qr[j].first.second == qr[j + 1].first.first);
            assert(qr[j].second > qr[j + 1].second);
        }
        assert(qr[0].first.first == 1);
        assert(qr.back().first.second == numeric_limits<int>::max());
    }
    cerr << "coverage ok" << endl;
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}