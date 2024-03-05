---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DualSegtree.test.cpp
    title: test/DualSegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DualSegtree.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct dual_segtree {\n \
    \   int sz = 1, log = 0;\n    vector<S> lz;\n    dual_segtree(vector<S> a) {\n\
    \        int n = a.size();\n        while (sz < n) {\n            sz <<= 1;\n\
    \            log++;\n        }\n        lz.assign(sz << 1, e());\n        for\
    \ (int i = 0; i < n; i++) lz[i + sz] = a[i];\n    }\n    void push(int k) {\n\
    \        int b = __builtin_ctz(k);\n        for (int d = log; d > b; d--) {\n\
    \            lz[k >> d << 1] = op(lz[k >> d << 1], lz[k >> d]);\n            lz[k\
    \ >> d << 1 | 1] = op(lz[k >> d << 1 | 1], lz[k >> d]);\n            lz[k >> d]\
    \ = e();\n        }\n    }\n    void apply(int l, int r, S x) {\n        l +=\
    \ sz, r += sz;\n        push(l);\n        push(r);\n        while (l < r) {\n\
    \            if (l & 1) {\n                lz[l] = op(lz[l], x);\n           \
    \     l++;\n            }\n            if (r & 1) {\n                r--;\n  \
    \              lz[r] = op(lz[r], x);\n            }\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n    S get(int k) {\n        k += sz;\n        S res =\
    \ e();\n        while (k) {\n            res = op(res, lz[k]);\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct dual_segtree {\n    int sz = 1, log = 0;\n    vector<S>\
    \ lz;\n    dual_segtree(vector<S> a) {\n        int n = a.size();\n        while\
    \ (sz < n) {\n            sz <<= 1;\n            log++;\n        }\n        lz.assign(sz\
    \ << 1, e());\n        for (int i = 0; i < n; i++) lz[i + sz] = a[i];\n    }\n\
    \    void push(int k) {\n        int b = __builtin_ctz(k);\n        for (int d\
    \ = log; d > b; d--) {\n            lz[k >> d << 1] = op(lz[k >> d << 1], lz[k\
    \ >> d]);\n            lz[k >> d << 1 | 1] = op(lz[k >> d << 1 | 1], lz[k >> d]);\n\
    \            lz[k >> d] = e();\n        }\n    }\n    void apply(int l, int r,\
    \ S x) {\n        l += sz, r += sz;\n        push(l);\n        push(r);\n    \
    \    while (l < r) {\n            if (l & 1) {\n                lz[l] = op(lz[l],\
    \ x);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                lz[r] = op(lz[r], x);\n            }\n       \
    \     l >>= 1, r >>= 1;\n        }\n    }\n    S get(int k) {\n        k += sz;\n\
    \        S res = e();\n        while (k) {\n            res = op(res, lz[k]);\n\
    \            k >>= 1;\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DualSegtree.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DualSegtree.test.cpp
documentation_of: DualSegtree.cpp
layout: document
redirect_from:
- /library/DualSegtree.cpp
- /library/DualSegtree.cpp.html
title: DualSegtree.cpp
---
