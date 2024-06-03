---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Binomial.cpp
    title: Binomial.cpp
  - icon: ':heavy_check_mark:'
    path: modint_old.cpp
    title: modint_old.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/Modint-Binomial.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#line 1 \"Binomial.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate\
    \ <typename T>\nstruct Binomial {\n    vector<T> inv, fact, factinv;\n    Binomial(int\
    \ n) {\n        inv.resize(n + 1);\n        fact.resize(n + 1);\n        factinv.resize(n\
    \ + 1);\n        inv[0] = fact[0] = factinv[0] = 1;\n        for (int i = 1; i\
    \ <= n; i++) fact[i] = fact[i - 1] * i;\n        factinv[n] = fact[n].inv();\n\
    \        inv[n] = fact[n - 1] * factinv[n];\n        for (int i = n - 1; i >=\
    \ 1; i--) {\n            factinv[i] = factinv[i + 1] * (i + 1);\n            inv[i]\
    \ = fact[i - 1] * factinv[i];\n        }\n    }\n    T C(int n, int r) {\n   \
    \     if (n < 0 || n < r || r < 0) return 0;\n        return fact[n] * factinv[n\
    \ - r] * factinv[r];\n    }\n    T P(int n, int r) {\n        if (n < 0 || n <\
    \ r || r < 0) return 0;\n        return fact[n] * factinv[n - r];\n    }\n   \
    \ T H(int n, int r) {\n        if (n == 0 && r == 0) return 1;\n        if (n\
    \ < 0 || r < 0) return 0;\n        return r == 0 ? 1 : C(n + r - 1, r);\n    }\n\
    };\n#line 1 \"modint_old.cpp\"\n\n#line 3 \"modint_old.cpp\"\nusing namespace\
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
    \ 1; }\n};\n#line 4 \"test/Modint-Binomial.test.cpp\"\nint main() {\n    Binomial<modint<1000000007>>\
    \ bin(2000000);\n    int t;\n    scanf(\"%d\", &t);\n    while (t--) {\n     \
    \   char op;\n        int n, k;\n        scanf(\"\\n%c(%d,%d)\", &op, &n, &k);\n\
    \        if (op == 'C') printf(\"%d\\n\", bin.C(n, k).val());\n        if (op\
    \ == 'P') printf(\"%d\\n\", bin.P(n, k).val());\n        if (op == 'H') printf(\"\
    %d\\n\", bin.H(n, k).val());\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include \"../Binomial.cpp\"\
    \n#include \"../modint_old.cpp\"\nint main() {\n    Binomial<modint<1000000007>>\
    \ bin(2000000);\n    int t;\n    scanf(\"%d\", &t);\n    while (t--) {\n     \
    \   char op;\n        int n, k;\n        scanf(\"\\n%c(%d,%d)\", &op, &n, &k);\n\
    \        if (op == 'C') printf(\"%d\\n\", bin.C(n, k).val());\n        if (op\
    \ == 'P') printf(\"%d\\n\", bin.P(n, k).val());\n        if (op == 'H') printf(\"\
    %d\\n\", bin.H(n, k).val());\n    }\n}"
  dependsOn:
  - Binomial.cpp
  - modint_old.cpp
  isVerificationFile: true
  path: test/Modint-Binomial.test.cpp
  requiredBy: []
  timestamp: '2024-06-03 20:31:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Modint-Binomial.test.cpp
layout: document
redirect_from:
- /verify/test/Modint-Binomial.test.cpp
- /verify/test/Modint-Binomial.test.cpp.html
title: test/Modint-Binomial.test.cpp
---
