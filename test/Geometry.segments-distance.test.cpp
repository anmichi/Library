// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
// competitive-verifier: ERROR 1e-8
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        Geometry::Segment L, M;
        cin >> L >> M;
        printf("%.12lf\n", L.distanceFrom(M));
    }
}
