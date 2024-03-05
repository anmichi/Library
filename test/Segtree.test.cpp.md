---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Segtree.cpp
    title: Segtree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/Segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 1 \"Segtree.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n    int siz = 1;\n   \
    \ vector<S> dat;\n    segtree(int n) : segtree(vector<S>(n, e())) {}\n    segtree(const\
    \ vector<S>& a) {\n        while (siz < a.size()) siz <<= 1;\n        dat = vector<S>(siz\
    \ << 1, e());\n        for (int i = 0; i < a.size(); i++) dat[siz + i] = a[i];\n\
    \        for (int i = siz - 1; i >= 1; i--) dat[i] = op(dat[2 * i], dat[2 * i\
    \ + 1]);\n    }\n    void set(int p, S x) {\n        p += siz;\n        dat[p]\
    \ = x;\n        while (p > 0) {\n            p >>= 1;\n            dat[p] = op(dat[2\
    \ * p], dat[2 * p + 1]);\n        }\n    }\n    void add(int p, S x) { set(p,\
    \ get(p) + x); }\n    S get(int p) { return dat[p + siz]; }\n    S prod(int l,\
    \ int r) {\n        S vl = e(), vr = e();\n        l += siz, r += siz;\n     \
    \   while (l < r) {\n            if (l & 1) vl = op(vl, dat[l++]);\n         \
    \   if (r & 1) vr = op(dat[--r], vr);\n            l >>= 1, r >>= 1;\n       \
    \ }\n        return op(vl, vr);\n    }\n    S all_prod() { return dat[1]; }\n\
    };\n#line 3 \"test/Segtree.test.cpp\"\nlong long op(long long a, long long b)\
    \ { return a + b; }\nlong long e() { return 0; }\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    vector<long long> a(n);\n    for (long long &x : a) cin\
    \ >> x;\n    segtree<long long, op, e> seg(a);\n    while (q--) {\n        int\
    \ t, x, y;\n        cin >> t >> x >> y;\n        if (t == 0)\n            seg.add(x,\
    \ y);\n        else\n            cout << seg.prod(x, y) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../Segtree.cpp\"\nlong long op(long long a, long long b) { return a\
    \ + b; }\nlong long e() { return 0; }\nint main() {\n    int n, q;\n    cin >>\
    \ n >> q;\n    vector<long long> a(n);\n    for (long long &x : a) cin >> x;\n\
    \    segtree<long long, op, e> seg(a);\n    while (q--) {\n        int t, x, y;\n\
    \        cin >> t >> x >> y;\n        if (t == 0)\n            seg.add(x, y);\n\
    \        else\n            cout << seg.prod(x, y) << endl;\n    }\n}"
  dependsOn:
  - Segtree.cpp
  isVerificationFile: true
  path: test/Segtree.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/Segtree.test.cpp
- /verify/test/Segtree.test.cpp.html
title: test/Segtree.test.cpp
---
