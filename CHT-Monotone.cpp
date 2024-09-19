#include <bits/stdc++.h>
using namespace std;
template <class T>
struct CHT_Monotone {
    // 追加クエリの傾き：単調減少
    // 取得クエリのx座標：単調増加
    // 最小値を返す
    // 最大値のとき：a,b -1倍
    // (単調増加,単調減少)のとき：a,x -1倍
    struct Line {
        T a, b;
        T y(T x) { return a * x + b; }
    };
    deque<Line> q;
    bool noneed(Line a, Line b, Line c) { return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a); }
    void add(T a, T b) {
        Line l = {a, b};
        while (q.size() > 1 && noneed(q[q.size() - 2], q[q.size() - 1], l)) {
            q.pop_back();
        }
        q.push_back(l);
    }
    T query(T x) {
        if (q.empty()) return numeric_limits<T>::max() / 2;
        while (q.size() > 1 && q[0].y(x) >= q[1].y(x)) {
            q.pop_front();
        }
        return q[0].y(x);
    }
};