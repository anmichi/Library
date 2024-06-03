---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Modint-Binomial.test.cpp
    title: test/Modint-Binomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint_old.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <int modulo>\nstruct modint {\n    int x;\n    modint() : x(0)\
    \ {}\n    modint(int64_t y) : x(y >= 0 ? y % modulo : (modulo - (-y) % modulo)\
    \ % modulo) {}\n    modint &operator+=(const modint &p) {\n        if ((x += p.x)\
    \ >= modulo) x -= modulo;\n        return *this;\n    }\n    modint &operator-=(const\
    \ modint &p) {\n        if ((x += modulo - p.x) >= modulo) x -= modulo;\n    \
    \    return *this;\n    }\n    modint &operator*=(const modint &p) {\n       \
    \ x = (int)(1LL * x * p.x % modulo);\n        return *this;\n    }\n    modint\
    \ &operator/=(const modint &p) {\n        *this *= p.inv();\n        return *this;\n\
    \    }\n    modint operator-() const { return modint(-x); }\n    modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n    modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n    modint operator*(const\
    \ modint &p) const { return modint(*this) *= p; }\n    modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n    bool operator==(const modint\
    \ &p) const { return x == p.x; }\n    bool operator!=(const modint &p) const {\
    \ return x != p.x; }\n    modint inv() const {\n        int a = x, b = modulo,\
    \ u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n        \
    \    swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n     \
    \   return modint(u);\n    }\n    modint pow(int64_t n) const {\n        modint\
    \ ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n\
    \            mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const modint &p) { return\
    \ os << p.x; }\n    friend istream &operator>>(istream &is, modint &a) {\n   \
    \     int64_t t;\n        is >> t;\n        a = modint<modulo>(t);\n        return\
    \ (is);\n    }\n    int val() const { return x; }\n    static constexpr int mod()\
    \ { return modulo; }\n    static constexpr int half() { return (modulo + 1) >>\
    \ 1; }\n};\n"
  code: "\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <int modulo>\n\
    struct modint {\n    int x;\n    modint() : x(0) {}\n    modint(int64_t y) : x(y\
    \ >= 0 ? y % modulo : (modulo - (-y) % modulo) % modulo) {}\n    modint &operator+=(const\
    \ modint &p) {\n        if ((x += p.x) >= modulo) x -= modulo;\n        return\
    \ *this;\n    }\n    modint &operator-=(const modint &p) {\n        if ((x +=\
    \ modulo - p.x) >= modulo) x -= modulo;\n        return *this;\n    }\n    modint\
    \ &operator*=(const modint &p) {\n        x = (int)(1LL * x * p.x % modulo);\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &p) {\n   \
    \     *this *= p.inv();\n        return *this;\n    }\n    modint operator-()\
    \ const { return modint(-x); }\n    modint operator+(const modint &p) const {\
    \ return modint(*this) += p; }\n    modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n    modint operator*(const modint &p) const {\
    \ return modint(*this) *= p; }\n    modint operator/(const modint &p) const {\
    \ return modint(*this) /= p; }\n    bool operator==(const modint &p) const { return\
    \ x == p.x; }\n    bool operator!=(const modint &p) const { return x != p.x; }\n\
    \    modint inv() const {\n        int a = x, b = modulo, u = 1, v = 0, t;\n \
    \       while (b > 0) {\n            t = a / b;\n            swap(a -= t * b,\
    \ b);\n            swap(u -= t * v, v);\n        }\n        return modint(u);\n\
    \    }\n    modint pow(int64_t n) const {\n        modint ret(1), mul(x);\n  \
    \      while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }\n  \
    \  friend istream &operator>>(istream &is, modint &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = modint<modulo>(t);\n        return (is);\n    }\n\
    \    int val() const { return x; }\n    static constexpr int mod() { return modulo;\
    \ }\n    static constexpr int half() { return (modulo + 1) >> 1; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint_old.cpp
  requiredBy: []
  timestamp: '2024-05-26 13:38:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Modint-Binomial.test.cpp
documentation_of: modint_old.cpp
layout: document
redirect_from:
- /library/modint_old.cpp
- /library/modint_old.cpp.html
title: modint_old.cpp
---
