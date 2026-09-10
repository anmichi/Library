#pragma once
#include "ProductTree.hpp"
template <class mint>
vector<mint> MultiEval(vector<mint> c, vector<mint> p) {
    // c: polynomial
    // p: evaluation point
    auto g = ProductTree(p);
    int m = p.size(), siz = g.size() / 2;
    g[0] = c;
    vector<mint> ans(m);
    for (int i = 1; i < siz + m; i++) g[i] = g[i >> 1] % g[i];
    for (int i = 0; i < m; i++)
        if (g[siz + i].size()) ans[i] = g[siz + i][0];
    return ans;
}