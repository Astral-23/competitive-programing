---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/manacher.hpp
    title: String/manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/manacher.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
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
    String/manacher.hpp\"\nstruct manacher {\n    string s;\n    int n, sz;\n    vec<int>\
    \ res;\n\n    manacher(string S) : s(S) {\n        n = s.size();\n        string\
    \ t = \"\";\n        rep(i, 0, n) {\n            t += s[i];\n            if(i\
    \ != n-1) t += \"$\";\n        }\n        sz = t.size();\n        res = vec<int>(sz,\
    \ 0);\n\n        int c = 0;\n        rep(i, 0, sz) {\n            int l = 2 *\
    \ c - i;\n            if(i + res[l] < c + res[c]) res[i] = res[l];\n         \
    \   else {\n                int j = c + res[c] - i;\n                while(i -\
    \ j >= 0 && i + j < sz && t[i-j] == t[i+j]) j++;\n                res[i] = j;\n\
    \                c = i;\n            }\n        }\n    }\n\n    int get(int p)\
    \ {\n        return (res[2 * p] + 1)/2;\n    }\n\n    int get(int l, int r) {\n\
    \        int m = 2 * l + 1;\n        return res[m]/2;\n    }\n\n};\n#line 4 \"\
    verify/manacher.test.cpp\"\n\nint main() {\n    string s;\n    cin >> s;\n   \
    \ manacher ma(s);\n\n    rep(i, 0, s.size()*2-1) {\n        if(i%2==0) {\n   \
    \         cout << ma.get(i/2) * 2 - 1 << \" \";\n        }\n        else {\n \
    \           cout << ma.get(i/2, i/2+1) * 2 << \" \";\n        }\n\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../String/manacher.hpp\"\n\n\
    int main() {\n    string s;\n    cin >> s;\n    manacher ma(s);\n\n    rep(i,\
    \ 0, s.size()*2-1) {\n        if(i%2==0) {\n            cout << ma.get(i/2) *\
    \ 2 - 1 << \" \";\n        }\n        else {\n            cout << ma.get(i/2,\
    \ i/2+1) * 2 << \" \";\n        }\n\n    }\n\n}"
  dependsOn:
  - Utility/template.hpp
  - String/manacher.hpp
  isVerificationFile: true
  path: verify/manacher.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/manacher.test.cpp
layout: document
redirect_from:
- /verify/verify/manacher.test.cpp
- /verify/verify/manacher.test.cpp.html
title: verify/manacher.test.cpp
---
