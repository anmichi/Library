#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../SparseTable.cpp"
int op(int a, int b) { return min(a, b); }
int e() { return 1000000000; }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    disjointsparsetable<int, op, e> st(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
}
