// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        Geometry::intSegment L, M;
        cin >> L >> M;
        if (L.isParallelTo(M))
            cout << 2 << endl;
        else if (L.isOrthogonalTo(M))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}