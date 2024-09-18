#include "../2DBIT.cpp"
// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int n = 1001;
    BIT2D<int> bit(n, n);
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        //(a,c],(b,d]
        bit.add(c, d, 1);
        bit.add(a, d, -1);
        bit.add(c, b, -1);
        bit.add(a, b, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            chmax(ans, bit.sum(i, j));
        }
    }
    cout << ans << endl;
}