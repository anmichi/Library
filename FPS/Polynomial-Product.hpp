#pragma once
#include <atcoder/convolution>
using namespace std;
template <typename mint>
vector<mint> PolyProd(vector<vector<mint>> f) {
    int n = (int)f.size();
    if (n == 0) return {1};
    function<vector<mint>(int, int)> calc = [&](int l, int r) {
        if (r - l == 1) return f[l];
        int m = (l + r) / 2;
        return atcoder::convolution(calc(l, m), calc(m, r));
    };
    return calc(0, n);
}