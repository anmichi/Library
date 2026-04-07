#pragma once
#include "FormalPowerSeries.cpp"
template <class mint>
vector<FormalPowerSeries<mint>> ProductTree(const vector<mint>& xs) {
    // product of (x - xs[i])
    int n = xs.size();
    int siz = 1;
    while (siz < n) siz <<= 1;
    vector<FormalPowerSeries<mint>> f(siz * 2, {1});
    for (int i = 0; i < n; i++) f[siz + i] = {-xs[i], 1};
    for (int i = siz - 1; i >= 1; i--) f[i] = f[i * 2] * f[i * 2 + 1];
    return f;
}