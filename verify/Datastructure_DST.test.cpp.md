---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/disjoint_sparse_table.hpp
    title: disjoint_sparse_table
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/Datastructure_DST.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"Utility/template.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Datastructure/disjoint_sparse_table.hpp\"\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()> struct disjoint_sparse_table {\n    vector<vector<S>>\
    \ d;\n    bool built = false;\n    int n, lg;\n    vector<S> v;\n\n  private:\n\
    \    int msb(int x) const { return x == 0 ? -1 : 32 - __builtin_clz(x) - 1; }\n\
    \n    // \u6F70\u308C\u305F\u533A\u9593\u3082\u30C0\u30E1\n    S prod_assertless(int\
    \ l, int r) const {\n        if (r - l == 1) return v[l];\n        r--;\n    \
    \    int k = msb(l ^ r);\n        return op(d[k][l], d[k][r]);\n    }\n\n  public:\n\
    \    disjoint_sparse_table(){}\n    disjoint_sparse_table(int n) : disjoint_sparse_table(vector<S>(n,\
    \ e())) {}\n    disjoint_sparse_table(vector<S> const &dat)\n        : n(int(dat.size())),\
    \ lg(0), v(dat) {\n        while ((1 << lg) < n) {\n            lg++;\n      \
    \  }\n        v.resize(1 << lg, e());\n    }\n\n    void build() {\n        built\
    \ = true;\n        int sz = 1 << lg;\n        d.resize(lg, vector<S>(sz, e()));\n\
    \        for (int k = 0; k < lg; k++) {\n            int b = 1 << k;\n       \
    \     for (int mid = b; mid + b <= sz; mid += 2 * b) {\n                S sml\
    \ = e(), smr = e();\n                for (int l = mid - 1; l >= mid - b; l--)\
    \ {\n                    sml = op(v[l], sml);\n                    d[k][l] = sml;\n\
    \                }\n                for (int r = mid; r < mid + b; r++) {\n  \
    \                  smr = op(smr, v[r]);\n                    d[k][r] = smr;\n\
    \                }\n            }\n        }\n    }\n\n    void set(int i, S const\
    \ &value) {\n        assert(built == false);\n        assert(0 <= i && i < n);\n\
    \        v[i] = value;\n    }\n\n    S get(int i) const {\n        assert(built);\n\
    \        return v[i];\n    }\n    S prod(int l, int r) const {\n        assert(built);\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (r == l) return e();\n\
    \        if (r - l == 1) return v[l];\n        r--;\n        int k = msb(l ^ r);\n\
    \        return op(d[k][l], d[k][r]);\n    }\n\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(built);\n        assert(f(e()));\n        if\
    \ (l == n) return n;\n        int ok = l;\n        int ng = n;\n        while\
    \ ((ng - ok) > 1) {\n            int mi = (ok + ng) / 2;\n            if (f(prod_assertless(l,\
    \ mi))) {\n                ok = mi;\n            } else {\n                ng\
    \ = mi;\n            }\n        }\n        return ok;\n    };\n\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(built == true);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        int ok = r;\n\
    \        int ng = -1;\n        while ((ok - ng) > 1) {\n            int mi = (ok\
    \ + ng) / 2;\n            if (f(prod_assertless(mi, r))) {\n                ok\
    \ = mi;\n            } else {\n                ng = mi;\n            }\n     \
    \   }\n        return ok;\n    }\n};\n/*\n@brief disjoint_sparse_table\n*/\n#line\
    \ 4 \"verify/Datastructure_DST.test.cpp\"\n\nusing S = int;\nS op(S l, S r) {\
    \ return min(l, r); }\nS e() { return INT_MAX; }\nusing stable = disjoint_sparse_table<S,\
    \ op, e>;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vec<S> A(n);\n\
    \    rep(i, 0, n) cin >> A[i];\n    stable st(A);\n    stable st2(n);\n    rep(i,\
    \ 0, n) st2.set(i, A[i]);\n    st.build(); st2.build();\n    while(q--) {\n  \
    \      int l, r;\n        cin >> l >> r;\n        assert(st.prod(l, r) == st2.prod(l,\
    \ r));\n        cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../Utility/template.hpp\"\n#include \"../Datastructure/disjoint_sparse_table.hpp\"\
    \n\nusing S = int;\nS op(S l, S r) { return min(l, r); }\nS e() { return INT_MAX;\
    \ }\nusing stable = disjoint_sparse_table<S, op, e>;\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    vec<S> A(n);\n    rep(i, 0, n) cin >> A[i];\n\
    \    stable st(A);\n    stable st2(n);\n    rep(i, 0, n) st2.set(i, A[i]);\n \
    \   st.build(); st2.build();\n    while(q--) {\n        int l, r;\n        cin\
    \ >> l >> r;\n        assert(st.prod(l, r) == st2.prod(l, r));\n        cout <<\
    \ st.prod(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: verify/Datastructure_DST.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 10:35:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Datastructure_DST.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_DST.test.cpp
- /verify/verify/Datastructure_DST.test.cpp.html
title: verify/Datastructure_DST.test.cpp
---
