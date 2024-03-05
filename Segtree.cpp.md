---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Segtree.test.cpp
    title: test/Segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Segtree.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct segtree {\n    int\
    \ siz = 1;\n    vector<S> dat;\n    segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n    segtree(const vector<S>& a) {\n        while (siz < a.size()) siz <<=\
    \ 1;\n        dat = vector<S>(siz << 1, e());\n        for (int i = 0; i < a.size();\
    \ i++) dat[siz + i] = a[i];\n        for (int i = siz - 1; i >= 1; i--) dat[i]\
    \ = op(dat[2 * i], dat[2 * i + 1]);\n    }\n    void set(int p, S x) {\n     \
    \   p += siz;\n        dat[p] = x;\n        while (p > 0) {\n            p >>=\
    \ 1;\n            dat[p] = op(dat[2 * p], dat[2 * p + 1]);\n        }\n    }\n\
    \    void add(int p, S x) { set(p, get(p) + x); }\n    S get(int p) { return dat[p\
    \ + siz]; }\n    S prod(int l, int r) {\n        S vl = e(), vr = e();\n     \
    \   l += siz, r += siz;\n        while (l < r) {\n            if (l & 1) vl =\
    \ op(vl, dat[l++]);\n            if (r & 1) vr = op(dat[--r], vr);\n         \
    \   l >>= 1, r >>= 1;\n        }\n        return op(vl, vr);\n    }\n    S all_prod()\
    \ { return dat[1]; }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct segtree {\n    int siz = 1;\n    vector<S> dat;\n    segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n    segtree(const vector<S>& a) {\n    \
    \    while (siz < a.size()) siz <<= 1;\n        dat = vector<S>(siz << 1, e());\n\
    \        for (int i = 0; i < a.size(); i++) dat[siz + i] = a[i];\n        for\
    \ (int i = siz - 1; i >= 1; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);\n  \
    \  }\n    void set(int p, S x) {\n        p += siz;\n        dat[p] = x;\n   \
    \     while (p > 0) {\n            p >>= 1;\n            dat[p] = op(dat[2 * p],\
    \ dat[2 * p + 1]);\n        }\n    }\n    void add(int p, S x) { set(p, get(p)\
    \ + x); }\n    S get(int p) { return dat[p + siz]; }\n    S prod(int l, int r)\
    \ {\n        S vl = e(), vr = e();\n        l += siz, r += siz;\n        while\
    \ (l < r) {\n            if (l & 1) vl = op(vl, dat[l++]);\n            if (r\
    \ & 1) vr = op(dat[--r], vr);\n            l >>= 1, r >>= 1;\n        }\n    \
    \    return op(vl, vr);\n    }\n    S all_prod() { return dat[1]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Segtree.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Segtree.test.cpp
documentation_of: Segtree.cpp
layout: document
redirect_from:
- /library/Segtree.cpp
- /library/Segtree.cpp.html
title: Segtree.cpp
---
