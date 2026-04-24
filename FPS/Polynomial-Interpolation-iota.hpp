#pragma once
#include "../Binomial.hpp"
template <class mint>
mint InterpolationIota(vector<mint>& A, long long x, Binomial<mint>& bin) {
    int n = A.size() - 1;
    if (0 <= x && x <= n) return A[x];
    vector<mint> L(n + 2, 1), R(n + 2, 1);
    for (int i = 0; i <= n; i++) L[i + 1] = L[i] * (x - i);
    for (int i = n; i >= 0; i--) R[i] = R[i + 1] * (x - i);
    mint ans = 0;
    //
    for (int i = 0; i <= n; i++) ans += bin.factinv[i] * bin.factinv[n - i] * A[i] * L[i] * R[i + 1] * ((n - i) % 2 == 0 ? 1 : -1);
    return ans;
}