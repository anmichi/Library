#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1001001001;
constexpr ll llINF = 3000000000000000010;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) (v).begin(), (v).end()
template <class T, class U>
inline bool chmax(T& a, U b) {
    return (a < b ? a = b, 1 : 0);
}
template <class T, class U>
inline bool chmin(T& a, U b) {
    return (a > b ? a = b, 1 : 0);
}
#include "Polynomial-Interpolation-iota.hpp"
template <class mint>
mint sum_of_exponential_times_polynomial(mint r, int d, ll n = -1) {
    // n = -1 : n = infinity
    if (r == 0) {
        if (n == 0)
            return 0;
        else
            return mint(0).pow(d);
    }
    vector<mint> A(d + 2);
    {
        mint cur = 1;
        for (int i = 0; i <= d; i++) {
            A[i + 1] = A[i] + mint(i).pow(d) * cur;
            cur *= r;
        }
    }
    Binomial<mint> bin(d + 1);
    if (r == 1) {
        assert(n != -1);
        return InterpolationIota(A, n, bin);
    }
    mint c = 0;
    mint cur = 1;
    for (int i = 0; i <= d + 1; i++) {
        c += A[d + 1 - i] * bin.C(d + 1, i) * cur;
        cur *= -r;
    }
    c /= (mint(1) - r).pow(d + 1);
    if (n == -1) return c;
    for (int i = 0; i <= d + 1; i++) A[i] -= c;
    mint ir = r.inv();
    mint p = 1;
    for (auto& x : A) {
        x *= p;
        p *= ir;
    }
    return InterpolationIota(A, n, bin) * r.pow(n) + c;
}