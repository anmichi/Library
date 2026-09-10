#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, bool isMax = false>
struct CHT_Arbitary {
    static const T inf = numeric_limits<T>::max();
    struct Line {
        mutable T k, m, p;
        bool operator<(const Line &o) const {
            if (k == o.k) return (m > o.m) ^ isMax;
            return (k > o.k) ^ isMax;
        }
        bool operator<(T x) const { return p < x; }
    };
    multiset<Line, less<>> st;
    T div_floor(T a, T b) {
        if (is_integral_v<T>) return a / b - ((a ^ b) < 0 && a % b);
        return a / b;
    }
    bool intersect(multiset<Line, less<>>::iterator x, multiset<Line, less<>>::iterator y) {
        if (y == st.end()) return x->p = inf, 0;
        if (x->k == y->k)
            x->p = -inf;
        else
            x->p = div_floor(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(T k, T m) {
        auto z = st.insert({k, m, 0}), y = z++, x = y;
        while (intersect(y, z)) z = st.erase(z);
        if (x != st.begin() && intersect(--x, y)) intersect(x, y = st.erase(y));
        while ((y = x) != st.begin() && (--x)->p >= y->p) intersect(x, st.erase(y));
    }
    T query(T x) {
        assert(!st.empty());
        auto l = *st.lower_bound(x);
        return l.k * x + l.m;
    }
};