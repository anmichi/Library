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