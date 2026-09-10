#include <bits/stdc++.h>
using namespace std;
struct linear_sieve {
    vector<int> least_factor, prime_list;
    linear_sieve(int n) : least_factor(n + 1, 0) {
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
};