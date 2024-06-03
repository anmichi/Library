#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Binomial {
    vector<T> inv, fact, factinv;
    Binomial(int n) {
        inv.resize(n + 1);
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv[0] = fact[0] = factinv[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        factinv[n] = fact[n].inv();
        inv[n] = fact[n - 1] * factinv[n];
        for (int i = n - 1; i >= 1; i--) {
            factinv[i] = factinv[i + 1] * (i + 1);
            inv[i] = fact[i - 1] * factinv[i];
        }
    }
    T C(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r] * factinv[r];
    }
    T P(int n, int r) {
        if (n < 0 || n < r || r < 0) return 0;
        return fact[n] * factinv[n - r];
    }
    T H(int n, int r) {
        if (n == 0 && r == 0) return 1;
        if (n < 0 || r < 0) return 0;
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};