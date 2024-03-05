---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry.cpp
    title: Geometry.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
  bundledCode: "#line 1 \"test/Geomerty.crosspoint.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C\"\n#define ERROR\
    \ \"1e-8\"\n#line 1 \"Geometry.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ L.A + vec(L) * (cross(L.A - M.A, vec(M)) / cross(vec(M), vec(L))); }\n#line\
    \ 4 \"test/Geomerty.crosspoint.test.cpp\"\nint main() {\n    int q;\n    cin >>\
    \ q;\n    while (q--) {\n        point A, B, C, D;\n        cin >> A.x >> A.y\
    \ >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;\n        line L(A, B), M(C, D);\n\
    \        point res = crosspoint(L, M);\n        printf(\"%.12lf %.12lf\\n\", res.x,\
    \ res.y);\n    }\n}\n"
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
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Geomerty.crosspoint.test.cpp
layout: document
redirect_from:
- /verify/test/Geomerty.crosspoint.test.cpp
- /verify/test/Geomerty.crosspoint.test.cpp.html
title: test/Geomerty.crosspoint.test.cpp
---
