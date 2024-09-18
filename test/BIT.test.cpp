// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "../BIT.cpp"
using ll = long long;
int main() {
    int n, q;
    cin >> n >> q;
    BIT<ll> bit(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bit.add(i + 1, a);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p + 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l + 1, r) << endl;
        }
    }
}