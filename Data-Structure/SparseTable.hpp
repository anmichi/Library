#include <bits/stdc++.h>
using namespace std;
template <class T, T (*op)(T, T)>
struct sparsetable {
    vector<vector<T>> table;
    vector<int> logtable;
    sparsetable() = default;
    sparsetable(vector<T>& a) {
        int n = a.size();
        int len = 0;
        while ((1 << len) <= n) len++;
        table.resize(len, a);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        logtable.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            logtable[i] = logtable[i >> 1] + 1;
        }
    }
    T query(int l, int r) {
        assert(l < r);
        int len = logtable[r - l];
        return op(table[len][l], table[len][r - (1 << len)]);
    }
};
template <class T, T (*op)(T, T)>
struct disjointsparsetable {
    vector<vector<T>> table;
    vector<int> logtable;
    disjointsparsetable() = default;
    disjointsparsetable(vector<T>& a) {
        int n = a.size();
        int len = 0;
        while ((1 << len) <= n) len++;
        table.resize(len, a);
        for (int i = 0; i < len; i++) {
            int w = 1 << i;
            for (int j = 0; j + w < n; j += w * 2) {
                int t = j + w, r = min(j + w + w, n);
                for (int k = t - 2; k >= j; k--) table[i][k] = op(a[k], table[i][k + 1]);
                for (int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], a[k]);
            }
        }
        logtable.resize(1 << len);
        for (int i = 0; i < len; i++) {
            for (int j = (1 << i); j < (1 << (i + 1)); j++) logtable[j] = i;
        }
    }
    T query(int l, int r) {
        assert(l < r);
        r--;
        int len = logtable[l ^ r];
        return op(table[len][l], table[len][r]);
    };
};