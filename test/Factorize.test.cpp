#include "../prime.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        auto pf = prime::factorize(x);
        sort(pf.begin(), pf.end());
        cout << pf.size();
        for (ll p : pf) cout << " " << p;
        cout << "\n";
    }
}