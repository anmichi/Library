template <class S, auto op>
struct segtree {
    using D = optional<S>;
    D op_D(const D& a, const D& b) {
        if (!a) return b;
        if (!b) return a;
        return op(*a, *b);
    }
    int siz = 1;
    vector<D> dat;
    segtree(int n) {
        while (siz < n) siz <<= 1;
        dat.resize(siz << 1);
    }
    segtree(const vector<S>& a) {
        while (siz < a.size()) siz <<= 1;
        dat = vector<D>(siz << 1, nullopt);
        for (int i = 0; i < a.size(); i++) dat[siz + i] = a[i];
        for (int i = siz - 1; i >= 1; i--) {
            dat[i] = op_D(dat[2 * i], dat[2 * i + 1]);
        }
    }
    void set(int p, const S& x) {
        p += siz;
        dat[p] = x;
        while (p > 1) {
            p >>= 1;
            dat[p] = op_D(dat[2 * p], dat[2 * p + 1]);
        }
    }
    S get(int p) { return *dat[p + siz]; }
    S prod(int l, int r) {
        assert(l < r);
        D vl, vr;
        l += siz, r += siz;
        while (l < r) {
            if (l & 1) vl = op_D(vl, dat[l++]);
            if (r & 1) vr = op_D(dat[--r], vr);
            l >>= 1, r >>= 1;
        }
        return *op_D(vl, vr);
    }
    S all_prod() { return *dat[1]; }
};
