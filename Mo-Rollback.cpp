#include <bits/stdc++.h>
using namespace std;
struct Mo {
    int n;
    vector<pair<int, int>> lr;
    Mo(int n) : n(n) {}
    void add(int l, int r) { /* [l, r) */ lr.emplace_back(l, r); }
    template <typename A, typename S, typename R, typename C, typename O>
    void build(const A& add, const S& snapshot, const R& rollback, const C& clear, const O& out) {
        int q = lr.size();
        int bs = max<int>(1, sqrt(n));
        vector<int> ord(q);
        iota(all(ord), 0);
        sort(all(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return lr[a].second < lr[b].second;
        });
        int l = bs, r = bs;
        for (auto idx : ord) {
            while (lr[idx].first >= l) {
                clear();
                l += bs;
                r = l;
            }
            if (lr[idx].second < l) {
                clear();
                for (int i = lr[idx].first; i < lr[idx].second; i++) add(i);
                out(idx);
                for (int i = lr[idx].first; i < lr[idx].second; i++) rollback();
                continue;
            }
            while (r < lr[idx].second) add(r++);
            snapshot();
            for (int i = l - 1; i >= lr[idx].first; i--) add(i);
            out(idx);
            rollback();
        }
    }
};