---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/ext_gcd.hpp
    title: ext_ecd
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja
  bundledCode: "#line 1 \"verify/extgcd.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"\
    Math/ext_gcd.hpp\"\nll extgcd(ll a, ll b, ll &x, ll &y) {\n    if(b == 0) {\n\
    \        x = 1;\n        y = 0;\n        return a;\n    }\n\n    ll d = extgcd(b,\
    \ a%b, y, x);\n    y -= a / b * x;\n    return d;\n}\n\nll modinv(ll a,ll MOD)\
    \ {\n    ll x, y;\n    extgcd(a, MOD, x, y);\n    return (x%MOD + MOD)%MOD;\n\
    }\n\n/*\n@brief ext_ecd\n*/\n#line 4 \"verify/extgcd.test.cpp\"\n\nint main()\
    \ {\n    ll a, b;\n    cin >> a >> b;\n    ll x, y;\n    extgcd(a, b, x, y);\n\
    \    cout << x << \" \" << y << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Math/ext_gcd.hpp\"\n\nint\
    \ main() {\n    ll a, b;\n    cin >> a >> b;\n    ll x, y;\n    extgcd(a, b, x,\
    \ y);\n    cout << x << \" \" << y << endl;\n}"
  dependsOn:
  - Utility/template.hpp
  - Math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/extgcd.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/extgcd.test.cpp
layout: document
redirect_from:
- /verify/verify/extgcd.test.cpp
- /verify/verify/extgcd.test.cpp.html
title: verify/extgcd.test.cpp
---
