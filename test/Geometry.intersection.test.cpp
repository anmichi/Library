// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
#include "../Geometry.cpp"
int main() {
    using Point = Geometry::Vec2<int>;
    int q;
    cin >> q;
    while (q--) {
        Geometry::intSegment L, M;
        cin >> L >> M;
        cout << intersect(L, M) << endl;
    }
}