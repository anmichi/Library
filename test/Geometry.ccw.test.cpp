// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
#include "../Geometry.cpp"
int main() {
    using Point = Geometry::Vec2<long long>;
    Point A, B;
    cin >> A >> B;
    int q;
    cin >> q;
    while (q--) {
        Point C;
        cin >> C;
        int res = ccw(A, B, C);
        if (res == 1) cout << "COUNTER_CLOCKWISE" << endl;
        if (res == -1) cout << "CLOCKWISE" << endl;
        if (res == 2) cout << "ONLINE_BACK" << endl;
        if (res == -2) cout << "ONLINE_FRONT" << endl;
        if (res == 0) cout << "ON_SEGMENT" << endl;
    }
}