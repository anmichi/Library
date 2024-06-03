#include "Binomial.cpp"
#include "FormalPowerSeries.cpp"
// f(x + a)
template <typename mint>
FormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a, Binomial<mint>& bin) {
    int n = f.size();
    for (int i = 0; i < n; i++) f[i] *= bin.fact[i];
    f = f.rev();
    FormalPowerSeries<mint> g(n, mint(1));
    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * bin.inv[i];
    f = (f * g).pre(n);
    f = f.rev();
    for (int i = 0; i < n; i++) f[i] *= bin.factinv[i];
    return f;
}