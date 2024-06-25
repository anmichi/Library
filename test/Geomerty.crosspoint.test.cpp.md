---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Geometry.cpp
    title: Geometry.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
  bundledCode: "#line 1 \"test/Geomerty.crosspoint.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C\"\n#define ERROR\
    \ \"1e-8\"\n#line 1 \"Geometry.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nnamespace geometry {\n\nconstexpr double eps = 1e-10;\ntemplate <class\
    \ T, class U>\nconstexpr bool equal(const T &a, const U &b) {\n    return fabs(a\
    \ - b) < eps;\n}\ntemplate <class T>\nconstexpr bool isZero(const T &a) {\n  \
    \  return fabs(a) < eps;\n}\ntemplate <class T>\nstruct Vec2 {\n    T x, y;\n\
    \    Vec2() = default;\n    Vec2(T x, T y) : x(x), y(y) {};\n    constexpr Vec2\
    \ &operator+=(const Vec2 &P) const {\n        x += P.x, y += P.y;\n        return\
    \ (*this);\n    }\n    constexpr Vec2 &operator-=(const Vec2 &P) const {\n   \
    \     x -= P.x, y -= P.y;\n        return (*this);\n    }\n    constexpr Vec2\
    \ &operator*=(const T &k) const {\n        x *= k, y *= k;\n        return (*this);\n\
    \    }\n    constexpr Vec2 &operator/=(const T &k) const {\n        x /= k, y\
    \ /= k;\n        return (*this);\n    }\n    constexpr Vec2 operator+() const\
    \ { return *this; }\n    constexpr Vec2 operator-() const { return {-x, -y}; }\n\
    \    constexpr Vec2 operator+(const Vec2 &P) const { return {x + P.x, y + P.y};\
    \ }\n    constexpr Vec2 operator-(const Vec2 &P) const { return {x - P.x, y -\
    \ P.y}; }\n    constexpr Vec2 operator*(const T &k) const { return {x * k, y *\
    \ k}; }\n    constexpr Vec2 operator/(const T &k) const { return {x / k, y / k};\
    \ }\n    constexpr bool operator==(const Vec2 &P) const { return isZero(x - P.x)\
    \ && isZero(y - P.y); }\n    constexpr bool operator!=(const Vec2 &P) const {\
    \ return !(*this == P); }\n    constexpr bool operator<(const Vec2 &P) const {\n\
    \        if (!isZero(x - P.x)) return x < P.x;\n        return y < P.y;\n    }\n\
    \    constexpr bool operator>(const Vec2 &P) const { return P < *this; }\n   \
    \ constexpr bool isZeroVec() const { return x == T(0) && y == T(0); }\n    constexpr\
    \ T abs2() const { return x * x + y * y; }\n    constexpr T abs() const { return\
    \ sqrt(abs2()); }\n    constexpr T dot(const Vec2 &v) const { return x * v.x +\
    \ y * v.y; }\n    constexpr T cross(const Vec2 &v) const { return x * v.y - y\
    \ * v.x; }\n    constexpr T dist(const Vec2 &P) const { return abs(P - (*this));\
    \ }\n    constexpr T hypot(const Vec2 &P) const { return abs2(P - (*this)); }\n\
    \    constexpr T unitVec() const { return (*this) / abs(); }\n    Vec2 &unitize()\
    \ { return *this /= abs(); }\n    friend constexpr T dot(const Vec2 &P, const\
    \ Vec2 &Q) { return P.dot(Q); }\n    friend constexpr T dot(const Vec2 &A, const\
    \ Vec2 &B, const Vec2 &C) { return (B - A).dot(C - A); }\n    friend constexpr\
    \ T cross(const Vec2 &P, const Vec2 &Q) { return P.cross(Q); }\n    friend constexpr\
    \ T cross(const Vec2 &A, const Vec2 &B, const Vec2 &C) { return (B - A).cross(C\
    \ - A); }\n};\nint ccw(auto &A, auto &B, auto &C) {\n    if (cross(B - A, C -\
    \ A) > eps) return +1;\n    if (cross(B - A, C - A) < -eps) return -1;\n    if\
    \ (dot(B - A, C - A) < -eps) return +2;\n    if (abs2(B - A) + eps < abs2(C -\
    \ A)) return -2;\n    return 0;\n}\nusing T = long double;\nusing Point = Vec2<T>;\n\
    struct Line {\n    Point A, B;\n    Line() = default;\n    Line(Point A, Point\
    \ B) : A(A), B(B) {}\n    constexpr Point vec() const { return B - A; }\n    constexpr\
    \ bool isParallelTo(const Line &L) const { return isZero(cross(vec(), L.vec()));\
    \ }\n    constexpr bool isOrthogonalTo(const Line &L) const { return isZero(dot(vec(),\
    \ L.vec())); }\n    constexpr T distanceFrom(const Point &P) const { return abs(cross(P\
    \ - A, vec())) / vec().abs(); }\n    constexpr Point crosspoint(const Line &L)\
    \ const { return A + vec() * (cross(A - L.A, L.vec())) / cross(L.vec(), vec());\
    \ }\n};\ntemplate <class T>\nstruct Segment : Line {\n    constexpr bool intersect(const\
    \ Line &L) const { return ccw(L.A, L.B, A) * ccw(L.A, L.B, B) <= 0 && ccw(A, B,\
    \ L.A) * ccw(A, B, L.B) <= 0; }\n    constexpr T distanceFrom(const Point &P)\
    \ const {\n        if (dot(P - A, vec()) < 0) return P.dist(A);\n        if (dot(P\
    \ - B, vec()) > 0) return P.dist(B);\n        return Line::distanceFrom(P);\n\
    \    }\n    constexpr T distanceFrom(const Segment &L) const {\n        if (intersect(L))\
    \ return 0;\n        return min({Line::distanceFrom(L.A), Line::distanceFrom(L.B),\
    \ Line(L).distanceFrom(A), Line(L).distanceFrom(B)});\n    }\n};\ntemplate <class\
    \ T>\nvector<T> convex_hull(vector<T> ps) {\n    sort(ps.begin(), ps.end());\n\
    \    ps.erase(unique(ps.begin(), ps.end()), ps.end());\n    int n = ps.size();\n\
    \    if (n <= 2) return ps;\n    vector<T> qs;\n    for (auto &p : ps) {\n   \
    \     //<=0 if want to remove \"3 points on the same line\"\n        while (qs.size()\
    \ > 1 && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {\n            qs.pop_back();\n\
    \        }\n        qs.push_back(p);\n    }\n    int t = qs.size();\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        T &p = ps[i];\n        while ((int)qs.size()\
    \ > t && cross(qs[qs.size() - 2], qs[qs.size() - 1], p) <= 0) {\n            qs.pop_back();\n\
    \        }\n        if (i) qs.push_back(p);\n    }\n    return qs;\n}\n};  //\
    \ namespace geometry\n#line 4 \"test/Geomerty.crosspoint.test.cpp\"\nint main()\
    \ {\n    int q;\n    cin >> q;\n    while (q--) {\n        point A, B, C, D;\n\
    \        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;\n      \
    \  line L(A, B), M(C, D);\n        point res = crosspoint(L, M);\n        printf(\"\
    %.12lf %.12lf\\n\", res.x, res.y);\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C\"\
    \n#define ERROR \"1e-8\"\n#include \"../Geometry.cpp\"\nint main() {\n    int\
    \ q;\n    cin >> q;\n    while (q--) {\n        point A, B, C, D;\n        cin\
    \ >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;\n        line L(A,\
    \ B), M(C, D);\n        point res = crosspoint(L, M);\n        printf(\"%.12lf\
    \ %.12lf\\n\", res.x, res.y);\n    }\n}"
  dependsOn:
  - Geometry.cpp
  isVerificationFile: true
  path: test/Geomerty.crosspoint.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 16:25:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Geomerty.crosspoint.test.cpp
layout: document
redirect_from:
- /verify/test/Geomerty.crosspoint.test.cpp
- /verify/test/Geomerty.crosspoint.test.cpp.html
title: test/Geomerty.crosspoint.test.cpp
---
