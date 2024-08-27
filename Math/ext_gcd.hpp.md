---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/extgcd.test.cpp
    title: verify/extgcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: ext_ecd
    links: []
  bundledCode: "#line 1 \"Math/ext_gcd.hpp\"\nll extgcd(ll a, ll b, ll &x, ll &y)\
    \ {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n  \
    \  }\n\n    ll d = extgcd(b, a % b, y, x);\n    y -= a / b * x;\n    return d;\n\
    }\n\nll modinv(ll a, ll MOD) {\n    ll x, y;\n    extgcd(a, MOD, x, y);\n    return\
    \ (x % MOD + MOD) % MOD;\n}\n\n/*\n@brief ext_ecd\n*/\n"
  code: "ll extgcd(ll a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n        x = 1;\n\
    \        y = 0;\n        return a;\n    }\n\n    ll d = extgcd(b, a % b, y, x);\n\
    \    y -= a / b * x;\n    return d;\n}\n\nll modinv(ll a, ll MOD) {\n    ll x,\
    \ y;\n    extgcd(a, MOD, x, y);\n    return (x % MOD + MOD) % MOD;\n}\n\n/*\n\
    @brief ext_ecd\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/ext_gcd.hpp
  requiredBy: []
  timestamp: '2024-08-27 18:05:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/extgcd.test.cpp
documentation_of: Math/ext_gcd.hpp
layout: document
redirect_from:
- /library/Math/ext_gcd.hpp
- /library/Math/ext_gcd.hpp.html
title: ext_ecd
---
