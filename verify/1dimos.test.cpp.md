---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/imos1d.hpp
    title: "1\u6B21\u5143imos\u6CD5"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0360?year=2017
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0360?year=2017
  bundledCode: "#line 1 \"verify/1dimos.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0360?year=2017\"\
    \n\n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/imos1d.hpp\"\
    \nTT struct imos1d {\n    int n;\n    vec<T> dat;\n    bool built = false;\n\n\
    \    imos1d(int n = 0) : n(n) { dat.resize(n, T()); }\n\n    void imos_add(int\
    \ i, T x) {\n        assert(built == false);\n        assert(0 <= i && i < n);\n\
    \        dat[i] += x;\n        if(i + 1 < n) dat[i + 1] -= x;\n    }\n\n    void\
    \ imos_add(int l, int r, T x) {\n        assert(0 <= l && r <= n && l <= r);\n\
    \        dat[l] += x;\n        if (r < n) dat[r] -= x;\n    }\n\n    void build()\
    \ {\n        rep(i, 0, n - 1) dat[i + 1] += dat[i];\n        built = true;\n \
    \   }\n\n    T operator[](int i) const {\n        assert(built == true);\n   \
    \     assert(0 <= i && i < n);\n        return dat[i];\n    }\n};\n\n/*\n@brief\
    \ 1\u6B21\u5143imos\u6CD5\n*/\n#line 5 \"verify/1dimos.test.cpp\"\n\n\nint main()\
    \ {\n    imos1d<ll> imos(1001);\n    int a, b;\n    cin >> a >> b;\n    imos.imos_add(a,\
    \ b, 1);\n\n    int n;\n    cin >> n;\n    while(n--) {\n        int s, f;\n \
    \       cin >> s >> f;\n        imos.imos_add(s, f, 1);\n    }\n\n    imos.build();\n\
    \n    rep(i, 0, 1001) {\n        if(imos[i] > 1) {\n            cout << 1 << endl;\n\
    \            exit(0);\n        }\n    }\n    cout << 0 << endl;\n    exit(0);\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0360?year=2017\"\
    \n\n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/imos1d.hpp\"\
    \n\n\nint main() {\n    imos1d<ll> imos(1001);\n    int a, b;\n    cin >> a >>\
    \ b;\n    imos.imos_add(a, b, 1);\n\n    int n;\n    cin >> n;\n    while(n--)\
    \ {\n        int s, f;\n        cin >> s >> f;\n        imos.imos_add(s, f, 1);\n\
    \    }\n\n    imos.build();\n\n    rep(i, 0, 1001) {\n        if(imos[i] > 1)\
    \ {\n            cout << 1 << endl;\n            exit(0);\n        }\n    }\n\
    \    cout << 0 << endl;\n    exit(0);\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/imos1d.hpp
  isVerificationFile: true
  path: verify/1dimos.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/1dimos.test.cpp
layout: document
redirect_from:
- /verify/verify/1dimos.test.cpp
- /verify/verify/1dimos.test.cpp.html
title: verify/1dimos.test.cpp
---
