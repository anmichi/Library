---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod_sqrt.cpp
    title: mod_sqrt.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, n) for (int i = 0; i < n; i++)\n\
    #define all(v) v.begin(), v.end()\ntemplate <class T, class U>\ninline bool chmax(T\
    \ &a, U b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T, class U>\ninline bool chmin(T &a, U\
    \ b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\nconstexpr int INF = 1000000000;\nconstexpr int64_t llINF = 3000000000000000000;\n\
    constexpr double eps = 1e-10;\nconst double pi = acos(-1);\nvector<int> calc_factor(int\
    \ n) {\n    vector<int> least_factor(n + 1, 0), prime_list;\n    for (int i =\
    \ 2; i <= n; i++) {\n        if (least_factor[i] == 0) {\n            least_factor[i]\
    \ = i;\n            prime_list.push_back(i);\n        }\n        for (int j =\
    \ 0; j < (int)prime_list.size() && i * prime_list[j] <= n; j++) {\n          \
    \  least_factor[i * prime_list[j]] = prime_list[j];\n            if (prime_list[j]\
    \ == least_factor[i]) break;\n        }\n    }\n    return least_factor;\n}\n\
    ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n        x = 1;\n   \
    \     y = 0;\n        return a;\n    }\n    ll d = extgcd(b, a % b, y, x);\n \
    \   y -= a / b * x;\n    return d;\n}\nll modpow(ll a, ll b, ll m) {\n    ll res\
    \ = 1;\n    while (b) {\n        if (b & 1) {\n            res *= a;\n       \
    \     res %= m;\n        }\n        a *= a;\n        a %= m;\n        b >>= 1;\n\
    \    }\n    return res;\n}\n#line 2 \"mod_sqrt.cpp\"\nint64_t mod_sqrt(const int64_t&\
    \ a, const int64_t& p) {\n    assert(0 <= a && a < p);\n    if (a < 2) return\
    \ a;\n    if (modpow(a, (p - 1) >> 1, p) != 1) return -1;\n    int64_t q = p -\
    \ 1, m = 0;\n    while (!(q & 1)) {\n        q >>= 1;\n        m++;\n    }\n \
    \   int64_t z = 1;\n    while (modpow(z, (p - 1) >> 1, p) == 1) z++;\n    int64_t\
    \ c = modpow(z, q, p);\n    int64_t t = modpow(a, q, p);\n    int64_t r = modpow(a,\
    \ (q + 1) >> 1, p);\n    if (t == 0) return 0;\n    m -= 2;\n    while (t != 1)\
    \ {\n        while (modpow(t, int64_t(1) << m, p) == 1) {\n            c = c *\
    \ c % p;\n            m--;\n        }\n        r = r * c % p;\n        c = c *\
    \ c % p;\n        t = t * c % p;\n        m--;\n    }\n    return r;\n}\n#line\
    \ 2 \"test/ModSqrt.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int t;\n\
    \    cin >> t;\n    while (t--) {\n        int64_t y, p;\n        cin >> y >>\
    \ p;\n        cout << mod_sqrt(y, p) << \"\\n\";\n    }\n}\n"
  code: "#include \"../mod_sqrt.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int t;\n\
    \    cin >> t;\n    while (t--) {\n        int64_t y, p;\n        cin >> y >>\
    \ p;\n        cout << mod_sqrt(y, p) << \"\\n\";\n    }\n}"
  dependsOn:
  - mod_sqrt.cpp
  - template.cpp
  isVerificationFile: true
  path: test/ModSqrt.test.cpp
  requiredBy: []
  timestamp: '2024-06-03 20:36:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ModSqrt.test.cpp
layout: document
redirect_from:
- /verify/test/ModSqrt.test.cpp
- /verify/test/ModSqrt.test.cpp.html
title: test/ModSqrt.test.cpp
---
