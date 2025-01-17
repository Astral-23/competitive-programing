---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_DST.test.cpp
    title: verify/Datastructure_DST.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: disjoint_sparse_table
    links: []
  bundledCode: "#line 1 \"Datastructure/disjoint_sparse_table.hpp\"\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct disjoint_sparse_table {\n    vector<vector<S>>\
    \ d;\n    bool built = false;\n    int n, lg;\n    vector<S> v;\n\n  private:\n\
    \    int msb(int x) const { return x == 0 ? -1 : 32 - __builtin_clz(x) - 1; }\n\
    \n    // \u6F70\u308C\u305F\u533A\u9593\u3082\u30C0\u30E1\n    S prod_assertless(int\
    \ l, int r) const {\n        if (r - l == 1) return v[l];\n        r--;\n    \
    \    int k = msb(l ^ r);\n        return op(d[k][l], d[k][r]);\n    }\n\n  public:\n\
    \    disjoint_sparse_table(int n) : disjoint_sparse_table(vector<S>(n, e())) {}\n\
    \    disjoint_sparse_table(vector<S> const &dat)\n        : n(int(dat.size())),\
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
    \   }\n        return ok;\n    }\n};\n/*\n@brief disjoint_sparse_table\n*/\n"
  code: "template <class S, S (*op)(S, S), S (*e)()> struct disjoint_sparse_table\
    \ {\n    vector<vector<S>> d;\n    bool built = false;\n    int n, lg;\n    vector<S>\
    \ v;\n\n  private:\n    int msb(int x) const { return x == 0 ? -1 : 32 - __builtin_clz(x)\
    \ - 1; }\n\n    // \u6F70\u308C\u305F\u533A\u9593\u3082\u30C0\u30E1\n    S prod_assertless(int\
    \ l, int r) const {\n        if (r - l == 1) return v[l];\n        r--;\n    \
    \    int k = msb(l ^ r);\n        return op(d[k][l], d[k][r]);\n    }\n\n  public:\n\
    \    disjoint_sparse_table(int n) : disjoint_sparse_table(vector<S>(n, e())) {}\n\
    \    disjoint_sparse_table(vector<S> const &dat)\n        : n(int(dat.size())),\
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
    \   }\n        return ok;\n    }\n};\n/*\n@brief disjoint_sparse_table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2025-01-18 06:13:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_DST.test.cpp
documentation_of: Datastructure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/Datastructure/disjoint_sparse_table.hpp
- /library/Datastructure/disjoint_sparse_table.hpp.html
title: disjoint_sparse_table
---
