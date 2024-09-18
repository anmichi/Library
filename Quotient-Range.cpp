#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<pair<pair<T, T>, T>> quotient_range(T n) {
    //[l,r]:quotient=z
    //[l,r]:increasing
    // z:decreasing
    T m = 1;
    vector<pair<pair<T, T>, T>> ret;
    while (m * m <= n) {
        ret.emplace_back(make_pair(m, m), n / m);
        m++;
    }
    for (T i = m; i >= 1; i--) {
        T L = n / (i + 1) + 1;
        T R = n / i;
        if (L <= R && ret.back().first.second < L) ret.emplace_back(make_pair(L, R), n / L);
    }
    return ret;
}