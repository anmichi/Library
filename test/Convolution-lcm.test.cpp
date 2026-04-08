// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lcm_convolution
#include <atcoder/modint>
#include "../Convolution_GCD_LCM.hpp"
int main() {
    int n;
    cin >> n;
    vector<atcoder::modint998244353> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[i] = x;
    }
    auto c = lcm_convolution(a, b);
    for (int i = 1; i <= n; i++) cout << c[i].val() << " ";
    cout << endl;
}