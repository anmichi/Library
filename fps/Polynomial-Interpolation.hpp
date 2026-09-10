#pragma once
#include "ProductTree.hpp"
template <class mint>
FormalPowerSeries<mint> Interpolation(const vector<mint>& xs, const vector<mint>& ys) {
    assert(xs.size() == ys.size());
    using fps = FormalPowerSeries<mint>;
    auto prod = ProductTree(xs);
    int n = xs.size(), siz = prod.size() / 2;
    vector<fps> g(siz * 2);
    g[0] = fps(prod[1]).diff();
    for (int i = 1; i < siz + n; i++) g[i] = g[i >> 1] % prod[i];
    for (int i = 0; i < n; i++) g[siz + i] = {ys[i] / g[siz + i][0]};

    for (int i = siz - 1; i >= 1; i--) g[i] = g[i * 2] * prod[i * 2 + 1] + g[i * 2 + 1] * prod[i * 2];
    return g[1];
}