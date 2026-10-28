#include <bits/stdc++.h>
using namespace std;
struct MoRollback {
    int n;
    vector<pair<int, int>> lr;

    explicit MoRollback(int n) : n(n) {}
    // [l, r)
    void add(int l, int r) { lr.emplace_back(l, r); }

    template <typename A, typename S, typename R, typename C, typename O>
    void build(const A& add, const S& snapshot, const R& rollback, const C& clear, const O& out) {
        int q = lr.size();
        if (q == 0) return;
        int bs = max<int>(1, int(n / sqrt(q)));
        vector<int> ord(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return lr[a].second < lr[b].second;
        });
        int block = -1, l = 0, r = 0;
        for (auto idx : ord) {
            auto [ql, qr] = lr[idx];
            if (ql / bs != block) {
                clear();
                block = ql / bs;
                l = r = (block + 1) * bs;
            }
            if (qr <= l) {
                snapshot();
                for (int i = ql; i < qr; i++) add(i);
                out(idx);
                rollback();
                continue;
            }
            while (r < qr) add(r++);
            snapshot();
            for (int i = l - 1; i >= ql; i--) add(i);
            out(idx);
            rollback();
        }
    }
};