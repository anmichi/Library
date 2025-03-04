#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<pair<pair<T, T>, T>> quotient_range(T n) {
    //[l,r]:quotient=z
    //[l,r]:increasing
    // z:decreasing
    // z=0 is not included
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
template <class T>
vector<pair<pair<T, T>, T>> quotient_range_ceil(T n) {
    const T inf = numeric_limits<T>::max();
    vector<pair<pair<T, T>, T>> res;
    if (n == 1) {
        res.push_back({{1, inf}, 1});
        return res;
    }
    T m = 1;
    while (m * m < n) {
        res.push_back({{m, m + 1}, (n + m - 1) / m});
        m++;
    }
    m = res.back().second - 1;
    while (m >= 1) {
        T l = (n + m - 1) / m;
        T r = m > 1 ? (n + m - 2) / (m - 1) : inf;
        if (l < r) res.push_back({{l, r}, m});
        m--;
    }
    return res;
}