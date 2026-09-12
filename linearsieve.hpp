#include <bits/stdc++.h>
using namespace std;
struct LinearSieve {
    int n;
    vector<int> least_factor, prime_list;
    LinearSieve(int x) : n(x), least_factor(n + 1, 0) {
        for (int i = 2; i <= n; i++) {
            if (least_factor[i] == 0) {
                least_factor[i] = i;
                prime_list.push_back(i);
            }
            for (int p : prime_list) {
                if ((long long)(i)*p > n || p > least_factor[i]) break;
                least_factor[i * p] = p;
            }
        }
    }
    bool is_prime(int x) const { return x >= 2 && least_factor[x] == x; }
    vector<pair<int, int>> factorize(int x) const {
        vector<pair<int, int>> res;
        while (x > 1) {
            int p = least_factor[x];
            if (res.size() && res.back().first == p)
                res.back().second++;
            else
                res.push_back({p, 1});
            x /= p;
        }
        return res;
    }
    vector<int> totient() const {
        vector<int> phi(n + 1);
        phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int p = least_factor[i];
            int j = i / p;
            phi[i] = phi[j] * (j % p == 0 ? p : (p - 1));
        }
        return phi;
    }
    vector<int> mobius() const {
        vector<int> mu(n + 1);
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int p = least_factor[i];
            int j = i / p;
            mu[i] = (j % p == 0 ? 0 : -mu[j]);
        }
        return mu;
    }
};