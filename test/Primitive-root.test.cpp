#include "../prime.cpp"
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << primitive_root(x) << "\n";
    }
}