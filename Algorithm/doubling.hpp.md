---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Algorithm_doubling.test.cpp
    title: verify/Algorithm_doubling.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Algorithm/doubling.hpp\"\nstruct doubling {\n    int lg_t;\n\
    \    static const int null = -1;\n    vector<vector<int>> table;\n\n    template\
    \ <typename T> doubling(vector<T> nx, ll lim_t) {\n        static_assert(std::is_arithmetic<T>::value,\n\
    \                      \"Error: T must be a numeric type\");\n        int n =\
    \ nx.size();\n        lg_t = 0;\n        while (1LL << lg_t <= lim_t) lg_t++;\n\
    \        table.resize(lg_t, vector<int>(n, -1));\n        for (int i = 0; i <\
    \ n; i++) {\n            table[0][i] = nx[i];\n        }\n\n        for (int k\
    \ = 1; k < lg_t; k++) {\n            for (int i = 0; i < n; i++) {\n         \
    \       if (table[k - 1][i] == null)\n                    table[k][i] = null;\n\
    \                else\n                    table[k][i] = table[k - 1][table[k\
    \ - 1][i]];\n            }\n        }\n    }\n\n    int jump(int k, ll t) const\
    \ {\n        for (int i = lg_t - 1; i >= 0; i--) {\n            if ((t >> i) &\
    \ 1 && k != null) k = table[i][k];\n        }\n        return k;\n    }\n\n  \
    \  template <class F> pair<int, ll> max_right(int k, F pred) const {\n       \
    \ ll sum_t = 0;\n        for (int i = lg_t - 1; i >= 0; i--) {\n            int\
    \ to = table[i][k];\n            if (to == null) continue;\n            if (pred(to)\
    \ == true) {\n                k = to;\n                sum_t += 1LL << i;\n  \
    \          }\n        }\n        return make_pair(k, sum_t);\n    }\n};\n"
  code: "struct doubling {\n    int lg_t;\n    static const int null = -1;\n    vector<vector<int>>\
    \ table;\n\n    template <typename T> doubling(vector<T> nx, ll lim_t) {\n   \
    \     static_assert(std::is_arithmetic<T>::value,\n                      \"Error:\
    \ T must be a numeric type\");\n        int n = nx.size();\n        lg_t = 0;\n\
    \        while (1LL << lg_t <= lim_t) lg_t++;\n        table.resize(lg_t, vector<int>(n,\
    \ -1));\n        for (int i = 0; i < n; i++) {\n            table[0][i] = nx[i];\n\
    \        }\n\n        for (int k = 1; k < lg_t; k++) {\n            for (int i\
    \ = 0; i < n; i++) {\n                if (table[k - 1][i] == null)\n         \
    \           table[k][i] = null;\n                else\n                    table[k][i]\
    \ = table[k - 1][table[k - 1][i]];\n            }\n        }\n    }\n\n    int\
    \ jump(int k, ll t) const {\n        for (int i = lg_t - 1; i >= 0; i--) {\n \
    \           if ((t >> i) & 1 && k != null) k = table[i][k];\n        }\n     \
    \   return k;\n    }\n\n    template <class F> pair<int, ll> max_right(int k,\
    \ F pred) const {\n        ll sum_t = 0;\n        for (int i = lg_t - 1; i >=\
    \ 0; i--) {\n            int to = table[i][k];\n            if (to == null) continue;\n\
    \            if (pred(to) == true) {\n                k = to;\n              \
    \  sum_t += 1LL << i;\n            }\n        }\n        return make_pair(k, sum_t);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/doubling.hpp
  requiredBy: []
  timestamp: '2025-02-02 06:02:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Algorithm_doubling.test.cpp
documentation_of: Algorithm/doubling.hpp
layout: document
redirect_from:
- /library/Algorithm/doubling.hpp
- /library/Algorithm/doubling.hpp.html
title: Algorithm/doubling.hpp
---
