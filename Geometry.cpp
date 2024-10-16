#include <bits/stdc++.h>
using namespace std;
namespace Geometry {

constexpr double eps = 1e-10;
template <class T>
constexpr int sign(const T &a) {
    if (fabs(a) < eps) return 0;
    if (a > 0) return 1;
    return -1;
}
template <class T, class U>
constexpr bool equal(const T &a, const U &b) {
    return sign(a - b) == 0;
}
template <class T>
constexpr bool isZero(const T &a) {
    return sign(a) == 0;
}
template <class T>
constexpr T square(const T &a) {
    return a * a;
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
    constexpr T dist(const Vec2 &P) const { return (P - (*this)).abs(); }
    constexpr T distSq(const Vec2 &P) const { return (P - (*this)).abs2(); }
    constexpr T unitVec() const { return (*this) / abs(); }
    Vec2 &unitize() { return *this /= abs(); }
    friend constexpr T abs2(const Vec2 &P) { return P.abs2(); }
    friend constexpr T abs(const Vec2 &P) { return P.abs(); }
    friend constexpr T dot(const Vec2 &P, const Vec2 &Q) { return P.dot(Q); }
    friend constexpr T dot(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).dot(C - A); }
    friend constexpr T cross(const Vec2 &P, const Vec2 &Q) { return P.cross(Q); }
    friend constexpr T cross(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).cross(C - A); }
    friend constexpr T dist(const Vec2 &P, const Vec2 &Q) { return P.dist(Q); }
    friend constexpr T distSq(const Vec2 &P, const Vec2 &Q) { return P.distSq(Q); }
};
template <class T>
constexpr int ccw(const Vec2<T> &A, const Vec2<T> &B, const Vec2<T> &C) {
    if (cross(B - A, C - A) > eps) return +1;
    if (cross(B - A, C - A) < -eps) return -1;
    if (dot(B - A, C - A) < -eps) return +2;
    if (abs2(B - A) + eps < abs2(C - A)) return -2;
    return 0;
}
struct Line {
    using T = double;
    using Point = Vec2<T>;
    Point A, B;
    Line() = default;
    Line(Point A, Point B) : A(A), B(B) {}
    constexpr Point vec() const { return B - A; }
    constexpr bool isParallelTo(const Line &L) const { return isZero(cross(vec(), L.vec())); }
    constexpr bool isOrthogonalTo(const Line &L) const { return isZero(dot(vec(), L.vec())); }
    constexpr T distanceFrom(const Point &P) const { return abs(cross(P - A, vec())) / vec().abs(); }
    constexpr Point crosspoint(const Line &L) const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec()); }
    friend constexpr Point crosspoint(const Line &L, const Line &M) { return L.crosspoint(M); }
};
struct Segment : Line {
    Segment() = default;
    Segment(Point A, Point B) : Line(A, B) {}
    constexpr bool intersect(const Segment &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B, L.A) * ccw(A, B, L.B) <= 0; }
    constexpr T distanceFrom(const Point &P) const {
        if (dot(P - A, vec()) < 0) return P.dist(A);
        if (dot(P - B, vec()) > 0) return P.dist(B);
        return Line::distanceFrom(P);
    }
    constexpr T distanceFrom(const Segment &L) const {
        if (intersect(L)) return 0;
        return min({Segment::distanceFrom(L.A), Segment::distanceFrom(L.B), Segment(L).distanceFrom(A), Segment(L).distanceFrom(B)});
    }
};
struct intLine {
    using T = long long;
    using Point = Vec2<T>;
    Point A, B;
    intLine() = default;
    intLine(Point A, Point B) : A(A), B(B) {}
    constexpr Point vec() const { return B - A; }
    constexpr bool isParallelTo(const intLine &L) const { return isZero(cross(vec(), L.vec())); }
    constexpr bool isOrthogonalTo(const intLine &L) const { return isZero(dot(vec(), L.vec())); }
    constexpr T distanceSqFrom(const Point &P) const { return square(cross(P - A, vec())) / vec().abs2(); }
    // constexpr Point crosspoint(const intLine &L) const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec()); }
};
struct intSegment : intLine {
    intSegment() = default;
    intSegment(Point A, Point B) : intLine(A, B) {}
    constexpr bool intersect(const intSegment &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B, L.A) * ccw(A, B, L.B) <= 0; }
    constexpr T distanceSqFrom(const Point &P) {
        if (dot(P - A, vec()) < 0) return P.distSq(A);
        if (dot(P - B, vec()) > 0) return P.distSq(B);
        return intLine::distanceSqFrom(P);
    }
    constexpr T distanceSqFrom(const intSegment &L) {
        if (intersect(L)) return 0;
        return min(
            {intSegment::distanceSqFrom(L.A), intSegment::distanceSqFrom(L.B), intSegment(L).distanceSqFrom(A), intSegment(L).distanceSqFrom(B)});
    }
    friend constexpr bool intersect(const intSegment &L, const intSegment &M) { return L.intersect(M); }
};
template <class T>
vector<T> convex_hull(vector<T> ps) {
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    int n = ps.size();
    if (n <= 2) return ps;
    vector<T> qs;
    for (auto &p : ps) {
        //<=0 if want to remove "3 points on a same line"
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

template <typename T>
inline istream &operator>>(istream &is, Vec2<T> &rhs) {
    return is >> rhs.x >> rhs.y;
}
template <typename T>
inline ostream &operator<<(ostream &os, Vec2<T> &rhs) {
    return os << rhs.x << " " << rhs.y;
}
inline istream &operator>>(istream &is, Line &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, Line &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, Segment &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, Segment &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, intLine &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, intLine &rhs) { return os << rhs.A << rhs.B; }
inline istream &operator>>(istream &is, intSegment &rhs) { return is >> rhs.A >> rhs.B; }
inline ostream &operator<<(ostream &os, intSegment &rhs) { return os << rhs.A << rhs.B; }
};  // namespace Geometry