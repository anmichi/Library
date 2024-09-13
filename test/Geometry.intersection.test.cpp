#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"
#include "../Geometry.cpp"
int main() {
    using Point = Geometry::Vec2<int>;
    int q;
    cin >> q;
    while (q--) {
        Geometry::intSegment L, M;
        cin >> L.A.x >> L.A.y >> L.B.x >> L.B.y >> M.A.x >> M.A.y >> M.B.x >> M.B.y;
        cout << intersect(L, M) << endl;
    }
}