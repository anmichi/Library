#include <bits/stdc++.h>
using namespace std;
template <class T>
struct BIT {
    vector<T> a;
    BIT() = default;
    BIT(int n) : a(n + 1) {}
    void add(int i, T x) {
        i++;
        while (i < (int)a.size()) a[i] += x, i += i & -i;
    }
    //[0,r)
    T sum(int r) {
        T s = 0;
        while (r) s += a[r], r -= r & -r;
        return s;
    }
    T sum(int l, int r) { return sum(r) - sum(l); }
    // minimize i s.t. sum(i) >= w
    int lower_bound(T w) {
        int x = 0, N = a.size() - 1;
        for (int k = 1 << __lg(N); k; k >>= 1) {
            if (x + k <= N && a[x + k] < w) {
                w -= a[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};