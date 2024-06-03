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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modsqrt.cpp: line\
    \ -1: no such header\n"
  code: "#include \"Binomial.cpp\"\n#include \"FormalPowerSeries.cpp\"\n// calculate\
    \ F(x + a)\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a, Binomial<mint>& bin) {\n    int n = f.size();\n    for (int i = 0;\
    \ i < n; i++) f[i] *= bin.fact[i];\n    f = f.rev();\n    FormalPowerSeries<mint>\
    \ g(n, mint(1));\n    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * bin.inv[i];\n\
    \    f = (f * g).pre(n);\n    f = f.rev();\n    for (int i = 0; i < n; i++) f[i]\
    \ *= bin.factinv[i];\n    return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: TaylorShift.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: TaylorShift.cpp
layout: document
redirect_from:
- /library/TaylorShift.cpp
- /library/TaylorShift.cpp.html
title: TaylorShift.cpp
---
