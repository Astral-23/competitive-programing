---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/sparse_table.hpp
    title: sparse_table
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/sprase_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/sparse_table.hpp\"\
    \ntemplate <class S, S (*op)(S, S), S (*e)()> struct sparse_table {\n    vector<vector<S>>\
    \ d;\n    vector<int> lookup;\n    bool built = false;\n    int n, lg;\n    vector<S>\
    \ v;\n\n    sparse_table(int n) : n(n), v(n, e()) {}\n\n    sparse_table(const\
    \ vector<S> &v) : n(v.size()), v(v) {}\n\n    void set(int i, S x) {\n       \
    \ assert(0 <= i && i < n);\n        assert(built == false);\n        v[i] = x;\n\
    \    }\n\n    void build() {\n        n = v.size();\n        lg = 0;\n       \
    \ while ((1LL << lg) <= n) lg++;\n        d.resize(lg, vector<S>(1LL << lg, e()));\n\
    \        for (int i = 0; i < n; i++) {\n            d[0][i] = v[i];\n        }\n\
    \        for (int i = 1; i < lg; i++) {\n            for (int j = 0; j + (1LL\
    \ << i) <= (1LL << lg); j++) {\n                d[i][j] = op(d[i - 1][j], d[i\
    \ - 1][j + (1LL << (i - 1))]);\n            }\n        }\n        lookup.resize(n\
    \ + 1);\n        for (int i = 2; i < int(lookup.size()); i++) {\n            lookup[i]\
    \ = lookup[i >> 1] + 1;\n        }\n        built = true;\n    }\n\n    S get(int\
    \ i) {\n        assert(0 <= i && i < n);\n        return v[i];\n    }\n\n    S\
    \ prod(int l, int r) {\n        assert(built == true);\n        assert(0 <= l\
    \ && r <= n);\n        if (l >= r) return e();\n        int LG = lookup[r - l];\n\
    \        return op(d[LG][l], d[LG][r - (1LL << LG)]);\n    }\n};\n\n/*\n@brief\
    \ sparse_table\n*/\n#line 4 \"verify/sprase_table.test.cpp\"\n\nusing S = int;\n\
    S op(S l, S r) { return min(l, r); }\nS e() { return INT_MAX; }\nusing stable\
    \ = sparse_table<S, op, e>;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\
    \    vec<S> A(n);\n    rep(i, 0, n) cin >> A[i];\n    stable st(A);\n    stable\
    \ st2(n);\n    rep(i, 0, n) st2.set(i, A[i]);\n    st.build(); st2.build();\n\
    \    while(q--) {\n        int l, r;\n        cin >> l >> r;\n        assert(st.prod(l,\
    \ r) == st2.prod(l, r));\n        cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../Utility/template.hpp\"\n#include \"../Datastructure/sparse_table.hpp\"\n\n\
    using S = int;\nS op(S l, S r) { return min(l, r); }\nS e() { return INT_MAX;\
    \ }\nusing stable = sparse_table<S, op, e>;\n\nint main() {\n    int n, q;\n \
    \   cin >> n >> q;\n    vec<S> A(n);\n    rep(i, 0, n) cin >> A[i];\n    stable\
    \ st(A);\n    stable st2(n);\n    rep(i, 0, n) st2.set(i, A[i]);\n    st.build();\
    \ st2.build();\n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n\
    \        assert(st.prod(l, r) == st2.prod(l, r));\n        cout << st.prod(l,\
    \ r) << '\\n';\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/sparse_table.hpp
  isVerificationFile: true
  path: verify/sprase_table.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/sprase_table.test.cpp
layout: document
redirect_from:
- /verify/verify/sprase_table.test.cpp
- /verify/verify/sprase_table.test.cpp.html
title: verify/sprase_table.test.cpp
---
