#include "../prime.cpp"
// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/primitive_root
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << prime::primitive_root(x) << "\n";
    }
}