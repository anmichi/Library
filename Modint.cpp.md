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
  bundledCode: "#line 1 \"Modint.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <int mod>\nstruct modint {\n    int x;\n    modint() : x(0) {}\n\
    \    modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n \
    \   modint &operator+=(const modint &p) {\n        if ((x += p.x) >= mod) x -=\
    \ mod;\n        return *this;\n    }\n    modint &operator-=(const modint &p)\
    \ {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n \
    \   }\n    modint &operator*=(const modint &p) {\n        x = (int)(1LL * x *\
    \ p.x % mod);\n        return *this;\n    }\n    modint &operator/=(const modint\
    \ &p) {\n        *this *= p.inverse();\n        return *this;\n    }\n    modint\
    \ operator-() const { return modint(-x); }\n    modint operator+(const modint\
    \ &p) const { return modint(*this) += p; }\n    modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n    modint operator*(const modint\
    \ &p) const { return modint(*this) *= p; }\n    modint operator/(const modint\
    \ &p) const { return modint(*this) /= p; }\n    bool operator==(const modint &p)\
    \ const { return x == p.x; }\n    bool operator!=(const modint &p) const { return\
    \ x != p.x; }\n    modint inv() const {\n        int a = x, b = mod, u = 1, v\
    \ = 0, t;\n        while (b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return modint(u);\n\
    \    }\n    modint pow(int64_t n) const {\n        modint ret(1), mul(x);\n  \
    \      while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }\n  \
    \  friend istream &operator>>(istream &is, modint &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = modint<mod>(t);\n        return (is);\n    }\n\
    \    int val() const { return x; }\n    static constexpr int mod() { return mod;\
    \ }\n};\n"
  code: "\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <int mod>\nstruct\
    \ modint {\n    int x;\n    modint() : x(0) {}\n    modint(int64_t y) : x(y >=\
    \ 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n    modint &operator+=(const modint\
    \ &p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n   \
    \ }\n    modint &operator-=(const modint &p) {\n        if ((x += mod - p.x) >=\
    \ mod) x -= mod;\n        return *this;\n    }\n    modint &operator*=(const modint\
    \ &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n    }\n\
    \    modint &operator/=(const modint &p) {\n        *this *= p.inverse();\n  \
    \      return *this;\n    }\n    modint operator-() const { return modint(-x);\
    \ }\n    modint operator+(const modint &p) const { return modint(*this) += p;\
    \ }\n    modint operator-(const modint &p) const { return modint(*this) -= p;\
    \ }\n    modint operator*(const modint &p) const { return modint(*this) *= p;\
    \ }\n    modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n    bool operator==(const modint &p) const { return x == p.x; }\n    bool\
    \ operator!=(const modint &p) const { return x != p.x; }\n    modint inv() const\
    \ {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n \
    \           t = a / b;\n            swap(a -= t * b, b);\n            swap(u -=\
    \ t * v, v);\n        }\n        return modint(u);\n    }\n    modint pow(int64_t\
    \ n) const {\n        modint ret(1), mul(x);\n        while (n > 0) {\n      \
    \      if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, const modint &p) { return os << p.x; }\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        int64_t t;\n        is >> t;\n        a = modint<mod>(t);\n\
    \        return (is);\n    }\n    int val() const { return x; }\n    static constexpr\
    \ int mod() { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Modint.cpp
  requiredBy: []
  timestamp: '2024-03-05 22:13:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Modint.cpp
layout: document
redirect_from:
- /library/Modint.cpp
- /library/Modint.cpp.html
title: Modint.cpp
---
