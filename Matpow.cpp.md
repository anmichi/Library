---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Matpow.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <class T>\nstruct Matrix {\n    int n;\n    vector<vector<T>>\
    \ m;\n    Matrix() : Matrix(0) {}\n    Matrix(int x) : Matrix(vector<vector<T>>(x,\
    \ vector<T>(x, 0))) {}\n    Matrix(const vector<vector<T>>& a) {\n        n =\
    \ a.size();\n        m = a;\n    }\n    vector<T>& operator[](int i) { return\
    \ m[i]; }\n    const vector<T>& operator[](int i) const { return m[i]; }\n   \
    \ static Matrix identity(int x) {\n        Matrix res(x);\n        for (int i\
    \ = 0; i < x; i++) res[i][i] = 1;\n        return res;\n    }\n    Matrix operator+(const\
    \ Matrix& a) const {\n        Matrix x = (*this);\n        return x += a;\n  \
    \  }\n    Matrix operator*(const Matrix& a) const {\n        Matrix x = (*this);\n\
    \        return x *= a;\n    }\n    Matrix& operator+=(const Matrix& a) {\n  \
    \      Matrix res(n);\n        for (int i = 0; i < n; i++) {\n            for\
    \ (int j = 0; j < n; j++) {\n                res[i][j] = (m[i][j] + a[i][j]) %\
    \ mod;\n            }\n        }\n        m = res.m;\n        return *this;\n\
    \    }\n    Matrix& operator*=(const Matrix& a) {\n        Matrix res(n);\n  \
    \      for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++)\
    \ {\n                for (int k = 0; k < n; k++) {\n                    res[i][j]\
    \ += m[i][k] * a[k][j];\n                    res[i][j] %= mod;\n             \
    \   }\n            }\n        }\n        m = res.m;\n        return *this;\n \
    \   }\n    Matrix pow(ll b) const {\n        Matrix x = *this, res = identity(n);\n\
    \        while (b) {\n            if (b & 1) {\n                res *= x;\n  \
    \          }\n            x *= x;\n            b >>= 1;\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class T>\nstruct\
    \ Matrix {\n    int n;\n    vector<vector<T>> m;\n    Matrix() : Matrix(0) {}\n\
    \    Matrix(int x) : Matrix(vector<vector<T>>(x, vector<T>(x, 0))) {}\n    Matrix(const\
    \ vector<vector<T>>& a) {\n        n = a.size();\n        m = a;\n    }\n    vector<T>&\
    \ operator[](int i) { return m[i]; }\n    const vector<T>& operator[](int i) const\
    \ { return m[i]; }\n    static Matrix identity(int x) {\n        Matrix res(x);\n\
    \        for (int i = 0; i < x; i++) res[i][i] = 1;\n        return res;\n   \
    \ }\n    Matrix operator+(const Matrix& a) const {\n        Matrix x = (*this);\n\
    \        return x += a;\n    }\n    Matrix operator*(const Matrix& a) const {\n\
    \        Matrix x = (*this);\n        return x *= a;\n    }\n    Matrix& operator+=(const\
    \ Matrix& a) {\n        Matrix res(n);\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < n; j++) {\n                res[i][j] = (m[i][j]\
    \ + a[i][j]) % mod;\n            }\n        }\n        m = res.m;\n        return\
    \ *this;\n    }\n    Matrix& operator*=(const Matrix& a) {\n        Matrix res(n);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++)\
    \ {\n                for (int k = 0; k < n; k++) {\n                    res[i][j]\
    \ += m[i][k] * a[k][j];\n                    res[i][j] %= mod;\n             \
    \   }\n            }\n        }\n        m = res.m;\n        return *this;\n \
    \   }\n    Matrix pow(ll b) const {\n        Matrix x = *this, res = identity(n);\n\
    \        while (b) {\n            if (b & 1) {\n                res *= x;\n  \
    \          }\n            x *= x;\n            b >>= 1;\n        }\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Matpow.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Matpow.cpp
layout: document
redirect_from:
- /library/Matpow.cpp
- /library/Matpow.cpp.html
title: Matpow.cpp
---
