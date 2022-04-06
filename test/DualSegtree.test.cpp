#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include "../DualSegtree.cpp"
int op(int a, int b) { return (b == -1 ? a : b); }
int e() { return -1; }
int main() {
    int n, q;
    cin >> n >> q;
    dual_segtree<int, op, e> seg(vector<int>(n, INT_MAX));
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.apply(s, t + 1, x);
        } else {
            int k;
            cin >> k;
            cout << seg.get(k) << endl;
        }
    }
}