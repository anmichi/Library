#include <bits/stdc++.h>
using namespace std;

// minを返す
template <class T, bool isMax = false>
struct CHT {
    struct Line {
        T a, b;
        T y(T x) { return a * x + b; }
    };
    deque<Line> q;
    bool noneed(Line a, Line b, Line c) { return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a); }
    // 傾き: 単調減少 xor isMax
    // 逆のとき: a,x -1倍する
    void add(T a, T b) {
        Line l = {a, b};
        if (isMax) a = -a, b = -b;
        while (q.size() > 1 && noneed(q[q.size() - 2], q[q.size() - 1], l)) {
            q.pop_back();
        }
        q.push_back(l);
    }
    // x: 単調増加
    T query(T x) {
        if (q.empty()) return numeric_limits<T>::max() / 2 * (isMax ? -1 : 1);
        while (q.size() > 1 && q[0].y(x) > q[1].y(x)) {
            q.pop_front();
        }
        return q[0].y(x) * (isMax ? -1 : 1);
    }
    T query_arbitary(T x) {
        if (q.empty()) return numeric_limits<T>::max() / 2 * (isMax ? -1 : 1);
        int ok = q.size() - 1, ng = -1;
        while (ok - ng > 1) {
            int m = (ok + ng) / 2;
            if (q[m + 1].y(x) > q[m].y(x))
                ok = m;
            else
                ng = m;
        }
        return q[ok].y(x) * (isMax ? -1 : 1);
    }
};