#include <bits/stdc++.h>
using namespace std;
template <class T>
struct BIT2D {
    int n, m;
    vector<vector<T>> bit;
    BIT2D(int n, int m) : n(n), m(m) { bit.resize(n + 1, vector<T>(m + 1)); }
    void add(int a, int b, T w) {
        for (int x = a; x <= n; x += x & -x) {
            for (int y = b; y <= m; y += y & -y) {
                bit[x][y] += w;
            }
        }
    }
    T sum(int a, int b) {
        T res = 0;
        for (int x = a; x > 0; x -= x & -x) {
            for (int y = b; y > 0; y -= y & -y) {
                res += bit[x][y];
            }
        }
        return res;
    }
    T sum(int a, int b, int c, int d) {
        //[a,c],[b,d]
        return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
    }
};