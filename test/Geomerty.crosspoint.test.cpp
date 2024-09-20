// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
// competitive-verifier: ERROR 1e-8
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        Geometry::Line L, M;
        cin >> L >> M;
        auto res = crosspoint(L, M);
        printf("%.12lf %.12lf\n", res.x, res.y);
    }
}