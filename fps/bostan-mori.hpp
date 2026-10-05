#include <bits/stdc++.h>
using namespace std;
#include "convolution.hpp"
template <class mint>
mint Bostan_Mori(vector<mint> p, vector<mint> q, ll k) {
    while (k > 0) {
        auto nq = q;
        for (int i = 1; i < (int)nq.size(); i += 2) nq[i] = -nq[i];
        auto s = convolution_auto(p, nq), r = convolution_auto(q, nq);
        vector<mint> b((r.size() + 1) / 2);
        for (int i = 0; i * 2 < (int)r.size(); i++) b[i] = r[i * 2];
        if (k % 2 == 0) {
            vector<mint> a((s.size() + 1) / 2);
            for (int i = 0; i * 2 < (int)s.size(); i++) a[i] = s[i * 2];
            swap(a, p);
        } else {
            vector<mint> a(s.size() / 2);
            for (int i = 0; i * 2 + 1 < (int)s.size(); i++) a[i] = s[i * 2 + 1];
            swap(a, p);
        }
        swap(b, q);
        k >>= 1;
    }
    return p[0] / q[0];
}