#include <bits/stdc++.h>
using namespace std;
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
    int siz = 1;
    vector<S> dat;
    segtree(int n) : segtree(vector<S>(n, e())) {}
    segtree(const vector<S>& a) {
        while (siz < a.size()) siz <<= 1;
        dat = vector<S>(siz << 1, e());
        for (int i = 0; i < a.size(); i++) dat[siz + i] = a[i];
        for (int i = siz - 1; i >= 1; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);
    }
    void set(int p, S x) {
        p += siz;
        dat[p] = x;
        while (p > 0) {
            p >>= 1;
            dat[p] = op(dat[2 * p], dat[2 * p + 1]);
        }
    }
    void add(int p, S x) { set(p, get(p) + x); }
    S get(int p) { return dat[p + siz]; }
    S prod(int l, int r) {
        S vl = e(), vr = e();
        l += siz, r += siz;
        while (l < r) {
            if (l & 1) vl = op(vl, dat[l++]);
            if (r & 1) vr = op(dat[--r], vr);
            l >>= 1, r >>= 1;
        }
        return op(vl, vr);
    }
    S all_prod() { return dat[1]; }
};