---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Datastructure_fenwick_tree.test.cpp
    title: verify/Datastructure_fenwick_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/fenwick_tree.hpp\"\ntemplate <class T> struct\
    \ fenwick_tree {\n  public:\n    fenwick_tree() : n(0) {}\n    explicit fenwick_tree(int\
    \ n) : n(n), data(n), raw(n, T()), S(T()) {}\n\n    void add(int p, T x) {\n \
    \       assert(0 <= p && p < n);\n        raw[p] += x;\n        S += x;\n\n  \
    \      p++;\n        while (p <= n) {\n            data[p - 1] += x;\n       \
    \     p += p & -p;\n        }\n    }\n\n    T sum(int r) const {\n        T s\
    \ = 0;\n        while (r > 0) {\n            s += data[r - 1];\n            r\
    \ -= r & -r;\n        }\n        return s;\n    }\n\n    T prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return sum(r)\
    \ - sum(l);\n    }\n\n    T all_prod() const { return S; }\n\n    T get(int p)\
    \ const { return raw[p]; }\n\n    template <class F> int max_right(F f) const\
    \ {\n        assert(f(0));\n        T s = 0;\n        int p = 0;\n        for\
    \ (int i = 32 - __builtin_clz(n) - 1; i >= 0; i--) {\n            int k = p +\
    \ (1 << i);\n            if (k <= n && f(s + data[k - 1])) {\n               \
    \ s += data[k - 1];\n                p = k;\n            }\n        }\n      \
    \  return p;\n    }\n\n  private:\n    int n;\n    vector<T> data;\n    vector<T>\
    \ raw;\n    T S;\n};\n"
  code: "template <class T> struct fenwick_tree {\n  public:\n    fenwick_tree() :\
    \ n(0) {}\n    explicit fenwick_tree(int n) : n(n), data(n), raw(n, T()), S(T())\
    \ {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < n);\n       \
    \ raw[p] += x;\n        S += x;\n\n        p++;\n        while (p <= n) {\n  \
    \          data[p - 1] += x;\n            p += p & -p;\n        }\n    }\n\n \
    \   T sum(int r) const {\n        T s = 0;\n        while (r > 0) {\n        \
    \    s += data[r - 1];\n            r -= r & -r;\n        }\n        return s;\n\
    \    }\n\n    T prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        return sum(r) - sum(l);\n    }\n\n    T all_prod() const {\
    \ return S; }\n\n    T get(int p) const { return raw[p]; }\n\n    template <class\
    \ F> int max_right(F f) const {\n        assert(f(0));\n        T s = 0;\n   \
    \     int p = 0;\n        for (int i = 32 - __builtin_clz(n) - 1; i >= 0; i--)\
    \ {\n            int k = p + (1 << i);\n            if (k <= n && f(s + data[k\
    \ - 1])) {\n                s += data[k - 1];\n                p = k;\n      \
    \      }\n        }\n        return p;\n    }\n\n  private:\n    int n;\n    vector<T>\
    \ data;\n    vector<T> raw;\n    T S;\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2025-01-11 20:26:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Datastructure_fenwick_tree.test.cpp
documentation_of: Datastructure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/Datastructure/fenwick_tree.hpp
- /library/Datastructure/fenwick_tree.hpp.html
title: Datastructure/fenwick_tree.hpp
---
