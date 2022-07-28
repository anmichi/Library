#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../SparseTable.cpp"
int op(int a, int b) { return min(a, b); }
int e() { return INT_MAX; }
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sparsetable<int, op, e> st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }
}