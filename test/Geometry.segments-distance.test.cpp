#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"
#define ERROR "1e-8"
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        Geometry::Segment L, M;
        cin >> L.A.x >> L.A.y >> L.B.x >> L.B.y >> M.A.x >> M.A.y >> M.B.x >> M.B.y;
        printf("%.12lf\n", L.distanceFrom(M));
    }
}
