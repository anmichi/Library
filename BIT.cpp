#include <bits/stdc++.h>
using namespace std;
template <class T>
struct BIT {
    // 1-indexed
    int n, beki = 1;
    vector<T> bit;
    BIT(int x) {
        bit.resize(x + 1, 0);
        n = x;
        while (beki * 2 <= n) beki *= 2;
    }
    T sum(int i) {
        T res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    T sum(int l, int r) {
        //[l,r]
        return sum(r) - (l == 0 ? 0 : sum(l - 1));
    }
    void add(int i, T x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
    int lowerbound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = beki; k > 0; k >>= 1) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};