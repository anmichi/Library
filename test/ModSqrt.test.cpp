#include "../ModSqrt.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int64_t y, p;
        cin >> y >> p;
        cout << mod_sqrt(y, p) << "\n";
    }
}