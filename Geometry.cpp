#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-10;
struct point {
    double x, y;
    point() : x(0), y(0){};
    point(double x, double y) : x(x), y(y){};
    point operator-(point P) { return point(x - P.x, y - P.y); }
};
double abs(point P) { return sqrt(P.x * P.x + P.y * P.y); }
double dist(point P, point Q) { return abs(Q - P); }
double dot(point P, point Q) { return P.x * Q.x + P.y * Q.y; }
double cross(point P, point Q) { return P.x * Q.y - P.y * Q.x; }
int ccw(point A, point B, point C) {
    if (cross(B - A, C - A) > eps) return +1;
    if (cross(B - A, C - A) < -eps) return -1;
    if (dot(B - A, C - A) < -eps) return +2;
    if (abs(B - A) + eps < abs(C - A)) return -2;
    return 0;
}
bool intersect(point P, point Q, point R, point S) { return ccw(P, Q, R) * ccw(P, Q, S) <= 0 && ccw(R, S, P) * ccw(R, S, Q) <= 0; }
double p_l_d(point P, point A, point B) { return abs(cross(P - A, B - A)) / abs(B - A); }
double p_s_d(point P, point A, point B) {
    if (dot(P - A, B - A) < 0) return dist(P, A);
    if (dot(P - B, B - A) > 0) return dist(P, B);
    return p_l_d(P, A, B);
}
double s_s_d(point P, point Q, point R, point S) {
    if (intersect(P, Q, R, S)) return 0;
    return min({p_s_d(P, R, S), p_s_d(Q, R, S), p_s_d(R, P, Q), p_s_d(S, P, Q)});
}