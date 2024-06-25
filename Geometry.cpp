#include <bits/stdc++.h>
using namespace std;
namespace geometry {

constexpr double eps = 1e-10;
template <class T, class U>
constexpr bool equal(const T &a, const U &b) {
    return fabs(a - b) < eps;
}
template <class T>
constexpr bool isZero(const T &a) {
    return fabs(a) < eps;
}
template <class T>
struct Vec2 {
    T x, y;
    Vec2() = default;
    Vec2(T x, T y) : x(x), y(y) {};
    constexpr Vec2 &operator+=(const Vec2 &P) const {
        x += P.x, y += P.y;
        return (*this);
    }
    constexpr Vec2 &operator-=(const Vec2 &P) const {
        x -= P.x, y -= P.y;
        return (*this);
    }
    constexpr Vec2 &operator*=(const T &k) const {
        x *= k, y *= k;
        return (*this);
    }
    constexpr Vec2 &operator/=(const T &k) const {
        x /= k, y /= k;
        return (*this);
    }
    constexpr Vec2 operator+() const { return *this; }
    constexpr Vec2 operator-() const { return {-x, -y}; }
    constexpr Vec2 operator+(const Vec2 &P) const { return {x + P.x, y + P.y}; }
    constexpr Vec2 operator-(const Vec2 &P) const { return {x - P.x, y - P.y}; }
    constexpr Vec2 operator*(const T &k) const { return {x * k, y * k}; }
    constexpr Vec2 operator/(const T &k) const { return {x / k, y / k}; }
    constexpr bool operator==(const Vec2 &P) const { return isZero(x - P.x) && isZero(y - P.y); }
    constexpr bool operator!=(const Vec2 &P) const { return !(*this == P); }
    constexpr bool operator<(const Vec2 &P) const {
        if (!isZero(x - P.x)) return x < P.x;
        return y < P.y;
    }
    constexpr bool operator>(const Vec2 &P) const { return P < *this; }
    constexpr bool isZeroVec() const { return x == T(0) && y == T(0); }
    constexpr T abs2() const { return x * x + y * y; }
    constexpr T abs() const { return sqrt(abs2()); }
    constexpr T dot(const Vec2 &v) const { return x * v.x + y * v.y; }
    constexpr T cross(const Vec2 &v) const { return x * v.y - y * v.x; }
    constexpr T dist(const Vec2 &P) const { return abs(P - (*this)); }
    constexpr T hypot(const Vec2 &P) const { return abs2(P - (*this)); }
    constexpr T unitVec() const { return (*this) / abs(); }
    Vec2 &unitize() { return *this /= abs(); }
    friend constexpr T dot(const Vec2 &P, const Vec2 &Q) { return P.dot(Q); }
    friend constexpr T dot(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).dot(C - A); }
    friend constexpr T cross(const Vec2 &P, const Vec2 &Q) { return P.cross(Q); }
    friend constexpr T cross(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).cross(C - A); }
};
int ccw(auto &A, auto &B, auto &C) {
    if (cross(B - A, C - A) > eps) return +1;
    if (cross(B - A, C - A) < -eps) return -1;
    if (dot(B - A, C - A) < -eps) return +2;
    if (abs2(B - A) + eps < abs2(C - A)) return -2;
    return 0;
}
using T = long double;
using Point = Vec2<T>;
struct Line {
    Point A, B;
    Line() = default;
    Line(Point A, Point B) : A(A), B(B) {}
    constexpr Point vec() const { return B - A; }
    constexpr bool isParallelTo(const Line &L) const { return isZero(cross(vec(), L.vec())); }
    constexpr bool isOrthogonalTo(const Line &L) const { return isZero(dot(vec(), L.vec())); }
    constexpr T distanceFrom(const Point &P) const { return abs(cross(P - A, vec())) / vec().abs(); }
    constexpr Point crosspoint(const Line &L) const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec()); }
};
template <class T>
struct Segment : Line {
    constexpr bool intersect(const Line &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B, L.A) * ccw(A, B, L.B) <= 0; }
    constexpr T distanceFrom(const Point &P) const {
        if (dot(P - A, vec()) < 0) return P.dist(A);
        if (dot(P - B, vec()) > 0) return P.dist(B);
        return Line::distanceFrom(P);
    }
    constexpr T distanceFrom(const Segment &L) const {
        if (intersect(L)) return 0;
        return min({Line::distanceFrom(L.A), Line::distanceFrom(L.B), Line(L).distanceFrom(A), Line(L).distanceFrom(B)});
    }
};
template <class T>
vector<T> convex_hull(vector<T> ps) {
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int n = ps.size();
    if (n <= 2) return ps;
    vector<T> qs;
    for (auto &p : ps) {
        //<=0 if want to remove "3 points on the same line"
        while (qs.size() > 1 && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {
            qs.pop_back();
        }
        qs.push_back(p);
    }
    int t = qs.size();
    for (int i = n - 2; i >= 0; i--) {
        T &p = ps[i];
        while ((int)qs.size() > t && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {
            qs.pop_back();
        }
        if (i) qs.push_back(p);
    }
    return qs;
}
};  // namespace geometry