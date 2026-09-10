#include <bits/stdc++.h>
using namespace std;
template <class T>
struct BinomialTable {
    vector<T> fact;
    vector<vector<T>> C;
    BinomialTable(int n) : fact(n + 1), C(n + 1, vector<T>(n + 1, T(0))) {
        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    }
};