#pragma once
#include "FormalPowerSeries.hpp"
template <typename mint>
pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>> RationalSum(vector<FormalPowerSeries<mint>> ps, vector<FormalPowerSeries<mint>> qs) {
    int n = (int)ps.size();
    function<pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>>(int, int)> calc = [&](int l, int r) {
        if (r - l == 1) return pair{ps[l], qs[l]};
        int m = (l + r) / 2;
        auto [pl, ql] = calc(l, m);
        auto [pr, qr] = calc(m, r);
        return pair{pl * qr + pr * ql, ql * qr};
    };
    return calc(0, n);
}