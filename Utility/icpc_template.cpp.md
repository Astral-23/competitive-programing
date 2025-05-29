---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/icpc_template.cpp\"\n#include <bits/stdc++.h>\n\
    #include <atcoder/all>\n\nusing namespace std;\nusing ll = long long;\nusing pll\
    \ = pair<ll,ll>;\nusing bint = __int128_t;\n#define rep(i, s, t) for (ll i = s;\
    \ i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\
    #define TT template<typename T>\nTT using vec = vector<T>;\nTT using minheap =\
    \ priority_queue<T, vector<T>, greater<T>>;\nTT using maxheap = priority_queue<T>;\n\
    template<class T> bool chmin(T &x, T y) { return x > y ? (x = y, true) : false;\
    \ }\ntemplate<class T> bool chmax(T &x, T y) { return x < y ? (x = y, true) :\
    \ false; }\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\nstd::ostream &operator<<(std::ostream &dest, __int128_t\
    \ value) {\n  std::ostream::sentry s(dest);\n  if (s) {\n    __uint128_t tmp =\
    \ value < 0 ? -value : value;\n    char buffer[128];\n    char *d = std::end(buffer);\n\
    \    do {\n      --d;\n      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n\
    \    } while (tmp != 0);\n    if (value < 0) {\n      --d;\n      *d = '-';\n\
    \    }\n    int len = std::end(buffer) - d;\n    if (dest.rdbuf()->sputn(d, len)\
    \ != len) {\n      dest.setstate(std::ios_base::badbit);\n    }\n  }\n  return\
    \ dest;\n}\n\n__int128 parse(string &s) {\n  __int128 ret = 0;\n  for (size_t\
    \ i = 0; i < s.length(); i++)\n    if ('0' <= s[i] && s[i] <= '9')\n      ret\
    \ = 10 * ret + s[i] - '0';\n  return ret;\n}\n\nstd::istream &operator>>(std::istream\
    \ &dest, __int128_t &value) {\n    string s;\n    dest >> s;\n    value = parse(s);\n\
    \    return dest;\n}\n\nint main() {\n\n}\n"
  code: "#include <bits/stdc++.h>\n#include <atcoder/all>\n\nusing namespace std;\n\
    using ll = long long;\nusing pll = pair<ll,ll>;\nusing bint = __int128_t;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n#define TT template<typename T>\nTT using vec =\
    \ vector<T>;\nTT using minheap = priority_queue<T, vector<T>, greater<T>>;\nTT\
    \ using maxheap = priority_queue<T>;\ntemplate<class T> bool chmin(T &x, T y)\
    \ { return x > y ? (x = y, true) : false; }\ntemplate<class T> bool chmax(T &x,\
    \ T y) { return x < y ? (x = y, true) : false; }\nstruct io_setup {\n    io_setup()\
    \ {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n  \
    \      cout << fixed << setprecision(15);\n    }\n} io_setup;\n\nstd::ostream\
    \ &operator<<(std::ostream &dest, __int128_t value) {\n  std::ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = std::end(buffer);\n    do {\n      --d;\n\
    \      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = std::end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(std::ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\n__int128 parse(string &s) {\n  __int128 ret\
    \ = 0;\n  for (size_t i = 0; i < s.length(); i++)\n    if ('0' <= s[i] && s[i]\
    \ <= '9')\n      ret = 10 * ret + s[i] - '0';\n  return ret;\n}\n\nstd::istream\
    \ &operator>>(std::istream &dest, __int128_t &value) {\n    string s;\n    dest\
    \ >> s;\n    value = parse(s);\n    return dest;\n}\n\nint main() {\n\n}"
  dependsOn:
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/internal_csr.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  isVerificationFile: false
  path: Utility/icpc_template.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:49:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/icpc_template.cpp
layout: document
redirect_from:
- /library/Utility/icpc_template.cpp
- /library/Utility/icpc_template.cpp.html
title: Utility/icpc_template.cpp
---
