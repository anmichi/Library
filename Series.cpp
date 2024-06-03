#include "TaylorShift.cpp"
template <typename mint>
FormalPowerSeries<mint> stirling_first(int n, Binomial<mint>& bin) {
    if (n == 0) return FormalPowerSeries<mint>{1};
    auto f = stirling1(n >> 1, bin);
    f *= TaylorShift(f, -mint(n >> 1), bin);
    if (n & 1) f = (f << 1) - f * (n - 1);  // multiply x-(n-1)
    return f;
}
template <typename mint>
vector<mint> stirling_second(int n, Binomial<mint>& bin) {
    vector<mint> f(n + 1), g(n + 1);
    mint sgn = 1;
    for (int i = 0; i <= n; i++) {
        f[i] = mint(i).pow(n) * bin.factinv[i];
        g[i] = sgn * bin.factinv[i];
        sgn = -sgn;
    }
    auto h = atcoder::convolution(f, g);
    h.resize(n + 1);
    return h;
}