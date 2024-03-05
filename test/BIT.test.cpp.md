---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: BIT.cpp
    title: BIT.cpp
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
  bundledCode: "#line 1 \"test/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 1 \"BIT.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <class T>\nstruct BIT {\n    // 1-indexed\n    int n, beki = 1;\n    vector<T>\
    \ bit;\n    BIT(int x) {\n        bit.resize(x + 1, 0);\n        n = x;\n    \
    \    while (beki * 2 <= n) beki *= 2;\n    }\n    T sum(int i) {\n        T res\
    \ = 0;\n        while (i > 0) {\n            res += bit[i];\n            i -=\
    \ i & -i;\n        }\n        return res;\n    }\n    T sum(int l, int r) {\n\
    \        //[l,r]\n        return sum(r) - (l == 0 ? 0 : sum(l - 1));\n    }\n\
    \    void add(int i, T x) {\n        while (i <= n) {\n            bit[i] += x;\n\
    \            i += i & -i;\n        }\n    }\n    int lowerbound(T w) {\n     \
    \   if (w <= 0) return 0;\n        int x = 0;\n        for (int k = beki; k >\
    \ 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] < w) {\n           \
    \     w -= bit[x + k];\n                x += k;\n            }\n        }\n  \
    \      return x + 1;\n    }\n};\n#line 3 \"test/BIT.test.cpp\"\nusing ll = long\
    \ long;\nint main() {\n    int n, q;\n    cin >> n >> q;\n    BIT<ll> bit(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int a;\n        cin >> a;\n      \
    \  bit.add(i + 1, a);\n    }\n    while (q--) {\n        int t;\n        cin >>\
    \ t;\n        if (t == 0) {\n            int p, x;\n            cin >> p >> x;\n\
    \            bit.add(p + 1, x);\n        } else {\n            int l, r;\n   \
    \         cin >> l >> r;\n            cout << bit.sum(l + 1, r) << endl;\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../BIT.cpp\"\nusing ll = long long;\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    BIT<ll> bit(n);\n    for (int i = 0; i < n; i++) {\n\
    \        int a;\n        cin >> a;\n        bit.add(i + 1, a);\n    }\n    while\
    \ (q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    int p, x;\n            cin >> p >> x;\n            bit.add(p + 1, x);\n \
    \       } else {\n            int l, r;\n            cin >> l >> r;\n        \
    \    cout << bit.sum(l + 1, r) << endl;\n        }\n    }\n}"
  dependsOn:
  - BIT.cpp
  isVerificationFile: true
  path: test/BIT.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/BIT.test.cpp
- /verify/test/BIT.test.cpp.html
title: test/BIT.test.cpp
---
