---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':question:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':question:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':question:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':question:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':question:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':question:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':question:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':question:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':question:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':question:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':question:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':question:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':question:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':question:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':question:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':question:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':question:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Others/icpc_template.hpp\"\n#include <atcoder/all>\n#include\
    \ <boost/multiprecision/cpp_dec_float.hpp>\n#include <boost/multiprecision/cpp_int.hpp>\n\
    #include <boost/rational.hpp>\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\nTT using minheap = priority_queue<T, vector<T>,\
    \ greater<T>>;\nTT using maxheap = priority_queue<T>;\nTT T safe_floor(T a, T\
    \ b) {\n    if (b < 0) a = -a, b = -b;\n    return a >= 0 ? a / b : (a + 1) /\
    \ b - 1;\n}\nTT T safe_ceil(T a, T b) {\n    if (b < 0) a = -a, b = -b;\n    return\
    \ a > 0 ? (a - 1) / b + 1 : a / b;\n}\n\ntemplate<class T1, class T2> bool chmin(T1\
    \ &x, T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class\
    \ T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n\n// \u4EFB\u610F\u9577\u6574\u6570\u578B\nusing Bint = boost::multiprecision::cpp_int;\n\
    // \u4EEE\u6570\u90E8\u304C10\u9032\u6570\u30671024\u6841\u306E\u6D6E\u52D5\u5C0F\
    \u6570\u70B9\u6570\u578B(TLE\u3057\u305F\u3089\u5C0F\u3055\u304F\u3059\u308B)\n\
    using Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;\n\
    using Rat = boost::rational<Bint>;\n\n\n\n\n"
  code: "#include <atcoder/all>\n#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    #include <boost/multiprecision/cpp_int.hpp>\n#include <boost/rational.hpp>\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\nusing ll = long long;\n#define rep(i,\
    \ s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t)\
    \ - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x),\
    \ rend(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\nTT using\
    \ minheap = priority_queue<T, vector<T>, greater<T>>;\nTT using maxheap = priority_queue<T>;\n\
    TT T safe_floor(T a, T b) {\n    if (b < 0) a = -a, b = -b;\n    return a >= 0\
    \ ? a / b : (a + 1) / b - 1;\n}\nTT T safe_ceil(T a, T b) {\n    if (b < 0) a\
    \ = -a, b = -b;\n    return a > 0 ? (a - 1) / b + 1 : a / b;\n}\n\ntemplate<class\
    \ T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false;\
    \ }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x\
    \ = y, true) : false; }\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n\n// \u4EFB\u610F\u9577\u6574\u6570\u578B\nusing Bint =\
    \ boost::multiprecision::cpp_int;\n// \u4EEE\u6570\u90E8\u304C10\u9032\u6570\u3067\
    1024\u6841\u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B(TLE\u3057\u305F\u3089\
    \u5C0F\u3055\u304F\u3059\u308B)\nusing Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;\n\
    using Rat = boost::rational<Bint>;\n\n\n\n\n"
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
  path: Others/icpc_template.hpp
  requiredBy: []
  timestamp: '2024-12-22 14:16:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/icpc_template.hpp
layout: document
redirect_from:
- /library/Others/icpc_template.hpp
- /library/Others/icpc_template.hpp.html
title: Others/icpc_template.hpp
---
