---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DualSegtree.cpp
    title: DualSegtree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/DualSegtree.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#line 1 \"DualSegtree.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class S, S (*op)(S, S), S (*e)()>\nstruct dual_segtree {\n    int sz\
    \ = 1, log = 0;\n    vector<S> lz;\n    dual_segtree(vector<S> a) {\n        int\
    \ n = a.size();\n        while (sz < n) {\n            sz <<= 1;\n           \
    \ log++;\n        }\n        lz.assign(sz << 1, e());\n        for (int i = 0;\
    \ i < n; i++) lz[i + sz] = a[i];\n    }\n    void push(int k) {\n        int b\
    \ = __builtin_ctz(k);\n        for (int d = log; d > b; d--) {\n            lz[k\
    \ >> d << 1] = op(lz[k >> d << 1], lz[k >> d]);\n            lz[k >> d << 1 |\
    \ 1] = op(lz[k >> d << 1 | 1], lz[k >> d]);\n            lz[k >> d] = e();\n \
    \       }\n    }\n    void apply(int l, int r, S x) {\n        l += sz, r += sz;\n\
    \        push(l);\n        push(r);\n        while (l < r) {\n            if (l\
    \ & 1) {\n                lz[l] = op(lz[l], x);\n                l++;\n      \
    \      }\n            if (r & 1) {\n                r--;\n                lz[r]\
    \ = op(lz[r], x);\n            }\n            l >>= 1, r >>= 1;\n        }\n \
    \   }\n    S get(int k) {\n        k += sz;\n        S res = e();\n        while\
    \ (k) {\n            res = op(res, lz[k]);\n            k >>= 1;\n        }\n\
    \        return res;\n    }\n};\n#line 3 \"test/DualSegtree.test.cpp\"\nint op(int\
    \ a, int b) { return (b == -1 ? a : b); }\nint e() { return -1; }\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    dual_segtree<int, op, e> seg(vector<int>(n,\
    \ INT_MAX));\n    while (q--) {\n        int type;\n        cin >> type;\n   \
    \     if (type == 0) {\n            int s, t, x;\n            cin >> s >> t >>\
    \ x;\n            seg.apply(s, t + 1, x);\n        } else {\n            int k;\n\
    \            cin >> k;\n            cout << seg.get(k) << endl;\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include \"../DualSegtree.cpp\"\nint op(int a, int b) { return (b == -1 ? a\
    \ : b); }\nint e() { return -1; }\nint main() {\n    int n, q;\n    cin >> n >>\
    \ q;\n    dual_segtree<int, op, e> seg(vector<int>(n, INT_MAX));\n    while (q--)\
    \ {\n        int type;\n        cin >> type;\n        if (type == 0) {\n     \
    \       int s, t, x;\n            cin >> s >> t >> x;\n            seg.apply(s,\
    \ t + 1, x);\n        } else {\n            int k;\n            cin >> k;\n  \
    \          cout << seg.get(k) << endl;\n        }\n    }\n}"
  dependsOn:
  - DualSegtree.cpp
  isVerificationFile: true
  path: test/DualSegtree.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DualSegtree.test.cpp
layout: document
redirect_from:
- /verify/test/DualSegtree.test.cpp
- /verify/test/DualSegtree.test.cpp.html
title: test/DualSegtree.test.cpp
---
