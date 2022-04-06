#include <bits/stdc++.h>
using namespace std;
template <class S, S (*op)(S, S), S (*e)()>
struct dual_segtree {
    int sz = 1, log = 0;
    vector<S> lz;
    dual_segtree(vector<S> a) {
        int n = a.size();
        while (sz < n) {
            sz <<= 1;
            log++;
        }
        lz.assign(sz << 1, e());
        for (int i = 0; i < n; i++) lz[i + sz] = a[i];
    }
    void push(int k) {
        int b = __builtin_ctz(k);
        for (int d = log; d > b; d--) {
            lz[k >> d << 1] = op(lz[k >> d << 1], lz[k >> d]);
            lz[k >> d << 1 | 1] = op(lz[k >> d << 1 | 1], lz[k >> d]);
            lz[k >> d] = e();
        }
    }
    void apply(int l, int r, S x) {
        l += sz, r += sz;
        push(l);
        push(r);
        while (l < r) {
            if (l & 1) {
                lz[l] = op(lz[l], x);
                l++;
            }
            if (r & 1) {
                r--;
                lz[r] = op(lz[r], x);
            }
            l >>= 1, r >>= 1;
        }
    }
    S get(int k) {
        k += sz;
        S res = e();
        while (k) {
            res = op(res, lz[k]);
            k >>= 1;
        }
        return res;
    }
};