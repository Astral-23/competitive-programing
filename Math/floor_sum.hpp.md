---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/floor_sum.test.cpp
    title: verify/floor_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/floor_sum.md
    document_title: floor_sum
    links: []
  bundledCode: "#line 1 \"Math/floor_sum.hpp\"\nll floor_sum(ll n, ll m, ll a, ll\
    \ b) {\n    assert(0 <= n && n < (1LL << 32));\n    assert(1 <= m && m < (1LL\
    \ << 32));\n    using ull = unsigned long long;\n\n    ull ans = 0;\n    if (a\
    \ < 0) {\n        ull a2 = (a % m + m) % m;\n        ans -= 1ULL * n * (n - 1)\
    \ / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n    if (b < 0) {\n        ull\
    \ b2 = (b % m + m) % m;\n        ans -= 1ULL * n * ((b2 - b) / m);\n        b\
    \ = b2;\n    }\n\n    auto uns_fl = [](ull n, ull m, ull a, ull b) {\n       \
    \ ull res = 0;\n        while (1) {\n            if (a >= m) {\n             \
    \   res += n * (n - 1) / 2 * (a / m);\n                a %= m;\n            }\n\
    \            if (b >= m) {\n                res += n * (b / m);\n            \
    \    b %= m;\n            }\n\n            ull y = a * n + b;\n            if\
    \ (y < m) break;\n            n = (ull)(y / m);\n            b = (ull)(y % m);\n\
    \            swap(m, a);\n        }\n        return res;\n    };\n\n    return\
    \ ans + uns_fl(n, m, a, b);\n}\n\n/*\n@brief floor_sum\n@docs doc/floor_sum.md\n\
    */\n"
  code: "ll floor_sum(ll n, ll m, ll a, ll b) {\n    assert(0 <= n && n < (1LL <<\
    \ 32));\n    assert(1 <= m && m < (1LL << 32));\n    using ull = unsigned long\
    \ long;\n\n    ull ans = 0;\n    if (a < 0) {\n        ull a2 = (a % m + m) %\
    \ m;\n        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n\
    \    }\n    if (b < 0) {\n        ull b2 = (b % m + m) % m;\n        ans -= 1ULL\
    \ * n * ((b2 - b) / m);\n        b = b2;\n    }\n\n    auto uns_fl = [](ull n,\
    \ ull m, ull a, ull b) {\n        ull res = 0;\n        while (1) {\n        \
    \    if (a >= m) {\n                res += n * (n - 1) / 2 * (a / m);\n      \
    \          a %= m;\n            }\n            if (b >= m) {\n               \
    \ res += n * (b / m);\n                b %= m;\n            }\n\n            ull\
    \ y = a * n + b;\n            if (y < m) break;\n            n = (ull)(y / m);\n\
    \            b = (ull)(y % m);\n            swap(m, a);\n        }\n        return\
    \ res;\n    };\n\n    return ans + uns_fl(n, m, a, b);\n}\n\n/*\n@brief floor_sum\n\
    @docs doc/floor_sum.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/floor_sum.test.cpp
documentation_of: Math/floor_sum.hpp
layout: document
redirect_from:
- /library/Math/floor_sum.hpp
- /library/Math/floor_sum.hpp.html
title: floor_sum
---
## 概要
ACLのfloor_sumと同じ。
参考 : https://github.com/atcoder/ac-library

## 関数
- **floor_sum(ll n, ll m, ll a, ll b)** ... $\sum_{i=0}^{n-1} floor((a \times i + b) / m)$
    - 計算量 $O(log{m})$

