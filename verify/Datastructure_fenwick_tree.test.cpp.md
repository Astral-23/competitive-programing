---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/fenwick_tree.hpp
    title: Datastructure/fenwick_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/Datastructure_fenwick_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Datastructure/fenwick_tree.hpp\"\ntemplate <class T> struct fenwick_tree\
    \ {\n  public:\n    fenwick_tree() : n(0) {}\n    explicit fenwick_tree(int n)\
    \ : n(n), data(n), raw(n, T()), S(T()) {}\n\n    void add(int p, T x) {\n    \
    \    assert(0 <= p && p < n);\n        raw[p] += x;\n        S += x;\n\n     \
    \   p++;\n        while (p <= n) {\n            data[p - 1] += x;\n          \
    \  p += p & -p;\n        }\n    }\n\n    T sum(int r) const {\n        T s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n\n    T prod(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        return sum(r) - sum(l);\n\
    \    }\n\n    T all_prod() const { return S; }\n\n    T get(int p) const { return\
    \ raw[p]; }\n\n    template <class F> int max_right(F f) const {\n        assert(f(0));\n\
    \        T s = 0;\n        int p = 0;\n        for (int i = 32 - __builtin_clz(n)\
    \ - 1; i >= 0; i--) {\n            int k = p + (1 << i);\n            if (k <=\
    \ n && f(s + data[k - 1])) {\n                s += data[k - 1];\n            \
    \    p = k;\n            }\n        }\n        return p;\n    }\n\n  private:\n\
    \    int n;\n    vector<T> data;\n    vector<T> raw;\n    T S;\n};\n#line 4 \"\
    verify/Datastructure_fenwick_tree.test.cpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n    int N;\n\
    \    cin >> N;\n    int Q;\n    cin >> Q;\n    fenwick_tree<ll> fw(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        fw.add(i, a);\n\
    \    }\n\n\twhile(Q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif(t==0) {\n\t\t\tll\
    \ p, x;\n\t\t\tcin >> p >> x;\n            fw.add(p, x);\n\t\t}\n\t\telse {\n\t\
    \t\tll l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << fw.prod(l, r) << '\\n';\n\t\t\
    }\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/fenwick_tree.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n    int N;\n    cin >> N;\n    int Q;\n\
    \    cin >> Q;\n    fenwick_tree<ll> fw(N);\n    for(int i = 0; i < N; i++) {\n\
    \        int a;\n        cin >> a;\n        fw.add(i, a);\n    }\n\n\twhile(Q--)\
    \ {\n\t\tint t;\n\t\tcin >> t;\n\t\tif(t==0) {\n\t\t\tll p, x;\n\t\t\tcin >> p\
    \ >> x;\n            fw.add(p, x);\n\t\t}\n\t\telse {\n\t\t\tll l, r;\n\t\t\t\
    cin >> l >> r;\n\t\t\tcout << fw.prod(l, r) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/Datastructure_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 20:28:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Datastructure_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_fenwick_tree.test.cpp
- /verify/verify/Datastructure_fenwick_tree.test.cpp.html
title: verify/Datastructure_fenwick_tree.test.cpp
---
