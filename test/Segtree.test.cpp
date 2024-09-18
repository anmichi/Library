// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "../Segtree.cpp"
long long op(long long a, long long b) { return a + b; }
long long e() { return 0; }
int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    segtree<long long, op, e> seg(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
            seg.add(x, y);
        else
            cout << seg.prod(x, y) << endl;
    }
}