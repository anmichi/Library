#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR "1e-8"
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        line L(A, B), M(C, D);
        point res = crosspoint(L, M);
        printf("%.12lf %.12lf\n", res.x, res.y);
    }
}