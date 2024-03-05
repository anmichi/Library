---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Geomerty.crosspoint.test.cpp
    title: test/Geomerty.crosspoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometry.ccw.test.cpp
    title: test/Geometry.ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometry.intersection.test.cpp
    title: test/Geometry.intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometry.pararell-orthogonal.test.cpp
    title: test/Geometry.pararell-orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Geometry.segments-distance.test.cpp
    title: test/Geometry.segments-distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nconstexpr double eps = 1e-10;\nstruct point {\n    double x, y;\n    point()\
    \ : x(0), y(0){};\n    point(double x, double y) : x(x), y(y){};\n    point operator+(point\
    \ P) { return point(x + P.x, y + P.y); }\n    point operator-(point P) { return\
    \ point(x - P.x, y - P.y); }\n    point operator*(double a) { return point(x *\
    \ a, y * a); }\n    double abs2() { return x * x + y * y; }\n    double abs()\
    \ { return sqrt(abs2()); }\n};\ndouble abs2(point P) { return P.abs2(); }\ndouble\
    \ abs(point P) { return P.abs(); }\ndouble dist(point P, point Q) { return abs(Q\
    \ - P); }\ndouble dot(point P, point Q) { return P.x * Q.x + P.y * Q.y; }\ndouble\
    \ cross(point P, point Q) { return P.x * Q.y - P.y * Q.x; }\nstruct line {\n \
    \   point A, B;\n    line() {}\n    line(point A, point B) : A(A), B(B) {}\n};\n\
    point vec(line L) { return L.B - L.A; }\nbool isParallel(line L, line M) { return\
    \ abs(cross(vec(L), vec(M))) < eps; }\nbool isOrthogonal(line L, line M) { return\
    \ abs(dot(vec(L), vec(M))) < eps; }\nint ccw(point A, point B, point C) {\n  \
    \  if (cross(B - A, C - A) > eps) return +1;\n    if (cross(B - A, C - A) < -eps)\
    \ return -1;\n    if (dot(B - A, C - A) < -eps) return +2;\n    if (abs2(B - A)\
    \ + eps < abs2(C - A)) return -2;\n    return 0;\n}\nbool intersect(line L, line\
    \ M) { return ccw(L.A, L.B, M.A) * ccw(L.A, L.B, M.B) <= 0 && ccw(M.A, M.B, L.A)\
    \ * ccw(M.A, M.B, L.B) <= 0; }\ndouble p_l_d(point P, line L) { return abs(cross(P\
    \ - L.A, vec(L))) / vec(L).abs(); }\ndouble p_s_d(point P, line L) {\n    if (dot(P\
    \ - L.A, vec(L)) < 0) return dist(P, L.A);\n    if (dot(P - L.B, vec(L)) > 0)\
    \ return dist(P, L.B);\n    return p_l_d(P, L);\n}\ndouble s_s_d(line L, line\
    \ M) {\n    if (intersect(L, M)) return 0;\n    return min({p_s_d(L.A, M), p_s_d(L.B,\
    \ M), p_s_d(M.A, L), p_s_d(M.B, L)});\n}\npoint crosspoint(line L, line M) { return\
    \ L.A + vec(L) * (cross(L.A - M.A, vec(M)) / cross(vec(M), vec(L))); }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nconstexpr double eps = 1e-10;\n\
    struct point {\n    double x, y;\n    point() : x(0), y(0){};\n    point(double\
    \ x, double y) : x(x), y(y){};\n    point operator+(point P) { return point(x\
    \ + P.x, y + P.y); }\n    point operator-(point P) { return point(x - P.x, y -\
    \ P.y); }\n    point operator*(double a) { return point(x * a, y * a); }\n   \
    \ double abs2() { return x * x + y * y; }\n    double abs() { return sqrt(abs2());\
    \ }\n};\ndouble abs2(point P) { return P.abs2(); }\ndouble abs(point P) { return\
    \ P.abs(); }\ndouble dist(point P, point Q) { return abs(Q - P); }\ndouble dot(point\
    \ P, point Q) { return P.x * Q.x + P.y * Q.y; }\ndouble cross(point P, point Q)\
    \ { return P.x * Q.y - P.y * Q.x; }\nstruct line {\n    point A, B;\n    line()\
    \ {}\n    line(point A, point B) : A(A), B(B) {}\n};\npoint vec(line L) { return\
    \ L.B - L.A; }\nbool isParallel(line L, line M) { return abs(cross(vec(L), vec(M)))\
    \ < eps; }\nbool isOrthogonal(line L, line M) { return abs(dot(vec(L), vec(M)))\
    \ < eps; }\nint ccw(point A, point B, point C) {\n    if (cross(B - A, C - A)\
    \ > eps) return +1;\n    if (cross(B - A, C - A) < -eps) return -1;\n    if (dot(B\
    \ - A, C - A) < -eps) return +2;\n    if (abs2(B - A) + eps < abs2(C - A)) return\
    \ -2;\n    return 0;\n}\nbool intersect(line L, line M) { return ccw(L.A, L.B,\
    \ M.A) * ccw(L.A, L.B, M.B) <= 0 && ccw(M.A, M.B, L.A) * ccw(M.A, M.B, L.B) <=\
    \ 0; }\ndouble p_l_d(point P, line L) { return abs(cross(P - L.A, vec(L))) / vec(L).abs();\
    \ }\ndouble p_s_d(point P, line L) {\n    if (dot(P - L.A, vec(L)) < 0) return\
    \ dist(P, L.A);\n    if (dot(P - L.B, vec(L)) > 0) return dist(P, L.B);\n    return\
    \ p_l_d(P, L);\n}\ndouble s_s_d(line L, line M) {\n    if (intersect(L, M)) return\
    \ 0;\n    return min({p_s_d(L.A, M), p_s_d(L.B, M), p_s_d(M.A, L), p_s_d(M.B,\
    \ L)});\n}\npoint crosspoint(line L, line M) { return L.A + vec(L) * (cross(L.A\
    \ - M.A, vec(M)) / cross(vec(M), vec(L))); }\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Geometry.ccw.test.cpp
  - test/Geometry.pararell-orthogonal.test.cpp
  - test/Geomerty.crosspoint.test.cpp
  - test/Geometry.segments-distance.test.cpp
  - test/Geometry.intersection.test.cpp
documentation_of: Geometry.cpp
layout: document
redirect_from:
- /library/Geometry.cpp
- /library/Geometry.cpp.html
title: Geometry.cpp
---
