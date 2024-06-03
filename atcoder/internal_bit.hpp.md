---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: FormalPowerSeries.cpp
    title: FormalPowerSeries.cpp
  - icon: ':heavy_check_mark:'
    path: TaylorShift.cpp
    title: TaylorShift.cpp
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':warning:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':warning:'
    path: test/atcoder/convolution.hpp
    title: test/atcoder/convolution.hpp
  - icon: ':warning:'
    path: test/atcoder/lazysegtree.hpp
    title: test/atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: test/atcoder/segtree.hpp
    title: test/atcoder/segtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/TaylorShift.test.cpp
    title: test/TaylorShift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param\
    \ n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n\
    \ & (1 << x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned\
    \ long index;\n    _BitScanForward(&index, n);\n    return index;\n#else\n   \
    \ return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned int n)\
    \ {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index, n);\n\
    \    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}  // namespace\
    \ internal\n\n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_bit.hpp
  requiredBy:
  - test/atcoder/lazysegtree.hpp
  - test/atcoder/convolution.hpp
  - test/atcoder/segtree.hpp
  - FormalPowerSeries.cpp
  - atcoder/lazysegtree.hpp
  - atcoder/convolution.hpp
  - atcoder/segtree.hpp
  - TaylorShift.cpp
  timestamp: '2024-05-26 13:38:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/TaylorShift.test.cpp
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
