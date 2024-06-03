---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TaylorShift.test.cpp
    title: test/TaylorShift.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint_io.cpp\"\n#include <atcoder/modint>\n#include <iostream>\n\
    template <int T>\ninline std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<T>\
    \ &p) {\n    return os << p.val();\n}\ntemplate <int T>\ninline std::istream &operator>>(std::istream\
    \ &is, atcoder::static_modint<T> &a) {\n    int64_t t;\n    is >> t;\n    a =\
    \ t;\n    return is;\n}\n"
  code: "#include <atcoder/modint>\n#include <iostream>\ntemplate <int T>\ninline\
    \ std::ostream &operator<<(std::ostream &os, const atcoder::static_modint<T> &p)\
    \ {\n    return os << p.val();\n}\ntemplate <int T>\ninline std::istream &operator>>(std::istream\
    \ &is, atcoder::static_modint<T> &a) {\n    int64_t t;\n    is >> t;\n    a =\
    \ t;\n    return is;\n}"
  dependsOn:
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: modint_io.cpp
  requiredBy: []
  timestamp: '2024-05-26 13:38:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TaylorShift.test.cpp
documentation_of: modint_io.cpp
layout: document
redirect_from:
- /library/modint_io.cpp
- /library/modint_io.cpp.html
title: modint_io.cpp
---
