#include <bits/stdc++.h>
using namespace std;
#include <atcoder/convolution>
using mint = atcoder::modint998244353;
mint Bostan_Mori(vector<mint> p, vector<mint> q, int64_t k) {
    if (k == 0) return p[0] / q[0];
    auto nq = q;
    for (int i = 1; i < nq.size(); i += 2) nq[i] = -nq[i];
    auto s = atcoder::convolution(p, nq), r = atcoder::convolution(q, nq);
    vector<mint> b((r.size() + 1) / 2);
    for (int i = 0; i * 2 < r.size(); i++) b[i] = r[i * 2];
    if (k % 2 == 0) {
        vector<mint> a((s.size() + 1) / 2);
        for (int i = 0; i * 2 < s.size(); i++) a[i] = s[i * 2];
        return Bostan_Mori(a, b, k / 2);
    } else {
        vector<mint> a(s.size() / 2);
        for (int i = 0; i * 2 + 1 < s.size(); i++) a[i] = s[i * 2 + 1];
        return Bostan_Mori(a, b, k / 2);
    }
}