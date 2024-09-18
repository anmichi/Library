// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
// competitive-verifier: ERROR 1e-8
#include "../Geometry.cpp"
int main() {
    using Point = Geometry::Vec2<long long>;
    int q;
    cin >> q;
    while (q--) {
        Geometry::Line L, M;
        cin >> L.A.x >> L.A.y >> L.B.x >> L.B.y >> M.A.x >> M.A.y >> M.B.x >> M.B.y;
        auto res = crosspoint(L, M);
        printf("%.12lf %.12lf\n", res.x, res.y);
    }
}