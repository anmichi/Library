#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-10;
struct point {
    double x, y;
    point() : x(0), y(0){};
    point(double x, double y) : x(x), y(y){};
    point operator+(point P) { return point(x + P.x, y + P.y); }
    point operator-(point P) { return point(x - P.x, y - P.y); }
    point operator*(double a) { return point(x * a, y * a); }
    double abs2() { return x * x + y * y; }
    double abs() { return sqrt(abs2()); }
};
double abs2(point P) { return P.abs2(); }
double abs(point P) { return P.abs(); }
double dist(point P, point Q) { return abs(Q - P); }
double dot(point P, point Q) { return P.x * Q.x + P.y * Q.y; }
double cross(point P, point Q) { return P.x * Q.y - P.y * Q.x; }
struct line {
    point A, B;
    line() {}
    line(point A, point B) : A(A), B(B) {}
};
point vec(line L) { return L.B - L.A; }
bool isParallel(line L, line M) { return abs(cross(vec(L), vec(M))) < eps; }
bool isOrthogonal(line L, line M) { return abs(dot(vec(L), vec(M))) < eps; }
int ccw(point A, point B, point C) {
    if (cross(B - A, C - A) > eps) return +1;
    if (cross(B - A, C - A) < -eps) return -1;
    if (dot(B - A, C - A) < -eps) return +2;
    if (abs2(B - A) + eps < abs2(C - A)) return -2;
    return 0;
}
bool intersect(line L, line M) { return ccw(L.A, L.B, M.A) * ccw(L.A, L.B, M.B) <= 0 && ccw(M.A, M.B, L.A) * ccw(M.A, M.B, L.B) <= 0; }
double p_l_d(point P, line L) { return abs(cross(P - L.A, vec(L))) / vec(L).abs(); }
double p_s_d(point P, line L) {
    if (dot(P - L.A, vec(L)) < 0) return dist(P, L.A);
    if (dot(P - L.B, vec(L)) > 0) return dist(P, L.B);
    return p_l_d(P, L);
}
double s_s_d(line L, line M) {
    if (intersect(L, M)) return 0;
    return min({p_s_d(L.A, M), p_s_d(L.B, M), p_s_d(M.A, L), p_s_d(M.B, L)});
}
point crosspoint(line L, line M) { return L.A + vec(L) * (cross(L.A - M.A, vec(M)) / cross(vec(M), vec(L))); }
