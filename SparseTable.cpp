#include <bits/stdc++.h>
using namespace std;
template <class T, T (*op)(T, T), T (*e)()>
struct sparsetable {
    vector<vector<T>> table;
    vector<int> logtable;
    sparsetable(vector<T> v) {
        int len = 0;
        while ((1 << len) <= v.size()) len++;
        table.assign(len, vector<T>(1 << len));
        for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];
        for (int i = 1; i < len; i++) {
            for (int j = 0; j + (1 << i) <= (1 << len); j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        logtable.resize(v.size() + 1);
        for (int i = 2; i < logtable.size(); i++) {
            logtable[i] = logtable[(i >> 1)] + 1;
        }
    }
    T query(int l, int r) {
        assert(l <= r);
        if (l == r) return e();
        int len = logtable[r - l];
        return op(table[len][l], table[len][r - (1 << len)]);
    }
};
template <class T, T (*op)(T, T), T (*e)()>
struct disjointsparsetable {
    vector<vector<T>> table;
    vector<int> logtable;
    disjointsparsetable(vector<T> v) {
        int len = 0;
        while ((1 << len) <= v.size()) len++;
        table.assign(len, vector<T>(1 << len, e()));
        for (int i = 0; i < (int)v.size(); i++) table[0][i] = v[i];
        for (int i = 1; i < len; i++) {
            int shift = 1 << i;
            for (int j = 0; j < (int)v.size(); j += shift << 1) {
                int t = min(j + shift, (int)v.size());
                table[i][t - 1] = v[t - 1];
                for (int k = t - 2; k >= j; k--) table[i][k] = op(v[k], table[i][k + 1]);
                if (v.size() <= t) break;
                table[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for (int k = t + 1; k < r; k++) table[i][k] = op(table[i][k - 1], v[k]);
            }
        }
        logtable.resize(1 << len);
        for (int i = 2; i < logtable.size(); i++) {
            logtable[i] = logtable[(i >> 1)] + 1;
        }
    }
    T query(int l, int r) {
        if (l >= --r) return table[0][l];
        int len = logtable[l ^ r];
        return op(table[len][l], table[len][r]);
    };
};