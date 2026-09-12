#include <bits/stdc++.h>
using namespace std;
#include "atcoder/convolution"
template <class mint>
vector<mint> convolution_auto(const vector<mint>& a, const vector<mint>& b) {
    if (a.empty() || b.empty()) return {};
    if constexpr (is_same_v<mint, long long>) return atcoder::convolution_ll(a, b);
    if constexpr (atcoder::internal::is_static_modint<mint>::value) {
        int z = bit_ceil(a.size() + b.size() - 1);
        int mod = mint::mod();
        if (atcoder::internal::is_prime_constexpr(mod) && (mod - 1) % z == 0)
            return atcoder::convolution(a, b);
    }
    return atcoder::internal::convolution_naive(a, b);
}