// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        Geometry::intSegment L, M;
        cin >> L.A.x >> L.A.y >> L.B.x >> L.B.y >> M.A.x >> M.A.y >> M.B.x >> M.B.y;
        if (L.isParallelTo(M))
            cout << 2 << endl;
        else if (L.isOrthogonalTo(M))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}