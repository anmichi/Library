#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"
#include "../Geometry.cpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        line L(A, B), M(C, D);
        if (isParallel(L, M))
            cout << 2 << endl;
        else if (isOrthogonal(L, M))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}