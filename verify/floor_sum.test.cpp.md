---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/floor_sum.hpp
    title: floor_sum
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/floor_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Math/floor_sum.hpp\"\nll floor_sum(ll\
    \ n, ll m, ll a, ll b) {\n    assert(0 <= n && n < (1LL << 32));\n    assert(1\
    \ <= m && m < (1LL << 32));\n    using ull = unsigned long long;\n\n    ull ans\
    \ = 0;\n    if (a < 0) {\n        ull a2 = (a % m + m) % m;\n        ans -= 1ULL\
    \ * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n    if (b < 0)\
    \ {\n        ull b2 = (b % m + m) % m;\n        ans -= 1ULL * n * ((b2 - b) /\
    \ m);\n        b = b2;\n    }\n\n    auto uns_fl = [](ull n, ull m, ull a, ull\
    \ b) {\n        ull res = 0;\n        while (1) {\n            if (a >= m) {\n\
    \                res += n * (n - 1) / 2 * (a / m);\n                a %= m;\n\
    \            }\n            if (b >= m) {\n                res += n * (b / m);\n\
    \                b %= m;\n            }\n\n            ull y = a * n + b;\n  \
    \          if (y < m) break;\n            n = (ull)(y / m);\n            b = (ull)(y\
    \ % m);\n            swap(m, a);\n        }\n        return res;\n    };\n\n \
    \   return ans + uns_fl(n, m, a, b);\n}\n\n/*\n@brief floor_sum\n@docs doc/floor_sum.md\n\
    */\n#line 4 \"verify/floor_sum.test.cpp\"\n\nint main() {\n    int T;\n    cin\
    \ >> T;\n    while(T--) {\n        ll N, M, A, B;\n        cin >> N >> M >> A\
    \ >> B;\n        cout << floor_sum(N, M, A, B) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Math/floor_sum.hpp\"\n\n\
    int main() {\n    int T;\n    cin >> T;\n    while(T--) {\n        ll N, M, A,\
    \ B;\n        cin >> N >> M >> A >> B;\n        cout << floor_sum(N, M, A, B)\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Math/floor_sum.hpp
  isVerificationFile: true
  path: verify/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/floor_sum.test.cpp
- /verify/verify/floor_sum.test.cpp.html
title: verify/floor_sum.test.cpp
---
