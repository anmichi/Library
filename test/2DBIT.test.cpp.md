---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 2DBIT.cpp
    title: 2DBIT.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B
  bundledCode: "#line 1 \"2DBIT.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    template <class T>\nstruct BIT2D {\n    int n, m;\n    vector<vector<T>> bit;\n\
    \    BIT2D(int n, int m) : n(n), m(m) { bit.resize(n + 1, vector<T>(m + 1)); }\n\
    \    void add(int a, int b, T w) {\n        for (int x = a; x <= n; x += x & -x)\
    \ {\n            for (int y = b; y <= m; y += y & -y) {\n                bit[x][y]\
    \ += w;\n            }\n        }\n    }\n    T sum(int a, int b) {\n        T\
    \ res = 0;\n        for (int x = a; x > 0; x -= x & -x) {\n            for (int\
    \ y = b; y > 0; y -= y & -y) {\n                res += bit[x][y];\n          \
    \  }\n        }\n        return res;\n    }\n    T sum(int a, int b, int c, int\
    \ d) {\n        //[a,c],[b,d]\n        return sum(c, d) - sum(a - 1, d) - sum(c,\
    \ b - 1) + sum(a - 1, b - 1);\n    }\n};\n#line 2 \"test/2DBIT.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B\"\ntemplate <class\
    \ T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    const int n = 1001;\n    BIT2D<int> bit(n,\
    \ n);\n    int q;\n    cin >> q;\n    while (q--) {\n        int a, b, c, d;\n\
    \        cin >> a >> b >> c >> d;\n        a++, b++, c++, d++;\n        //(a,c],(b,d]\n\
    \        bit.add(c, d, 1);\n        bit.add(a, d, -1);\n        bit.add(c, b,\
    \ -1);\n        bit.add(a, b, 1);\n    }\n    int ans = 0;\n    for (int i = 1;\
    \ i <= n; i++) {\n        for (int j = 1; j <= n; j++) {\n            chmax(ans,\
    \ bit.sum(i, j));\n        }\n    }\n    cout << ans << endl;\n}\n"
  code: "#include \"../2DBIT.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B\"\
    \ntemplate <class T, class U>\ninline bool chmax(T &a, U b) {\n    if (a < b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    const int n = 1001;\n\
    \    BIT2D<int> bit(n, n);\n    int q;\n    cin >> q;\n    while (q--) {\n   \
    \     int a, b, c, d;\n        cin >> a >> b >> c >> d;\n        a++, b++, c++,\
    \ d++;\n        //(a,c],(b,d]\n        bit.add(c, d, 1);\n        bit.add(a, d,\
    \ -1);\n        bit.add(c, b, -1);\n        bit.add(a, b, 1);\n    }\n    int\
    \ ans = 0;\n    for (int i = 1; i <= n; i++) {\n        for (int j = 1; j <= n;\
    \ j++) {\n            chmax(ans, bit.sum(i, j));\n        }\n    }\n    cout <<\
    \ ans << endl;\n}"
  dependsOn:
  - 2DBIT.cpp
  isVerificationFile: true
  path: test/2DBIT.test.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2DBIT.test.cpp
layout: document
redirect_from:
- /verify/test/2DBIT.test.cpp
- /verify/test/2DBIT.test.cpp.html
title: test/2DBIT.test.cpp
---
