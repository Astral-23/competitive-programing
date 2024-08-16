---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/manacher.test.cpp
    title: verify/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/manacher.hpp\"\nstruct manacher {\n    string s;\n\
    \    int n, sz;\n    vec<int> res;\n\n    manacher(string S) : s(S) {\n      \
    \  n = s.size();\n        string t = \"\";\n        rep(i, 0, n) {\n         \
    \   t += s[i];\n            if(i != n-1) t += \"$\";\n        }\n        sz =\
    \ t.size();\n        res = vec<int>(sz, 0);\n\n        int c = 0;\n        rep(i,\
    \ 0, sz) {\n            int l = 2 * c - i;\n            if(i + res[l] < c + res[c])\
    \ res[i] = res[l];\n            else {\n                int j = c + res[c] - i;\n\
    \                while(i - j >= 0 && i + j < sz && t[i-j] == t[i+j]) j++;\n  \
    \              res[i] = j;\n                c = i;\n            }\n        }\n\
    \    }\n\n    int get(int p) {\n        return (res[2 * p] + 1)/2;\n    }\n\n\
    \    int get(int l, int r) {\n        int m = 2 * l + 1;\n        return res[m]/2;\n\
    \    }\n\n};\n"
  code: "struct manacher {\n    string s;\n    int n, sz;\n    vec<int> res;\n\n \
    \   manacher(string S) : s(S) {\n        n = s.size();\n        string t = \"\"\
    ;\n        rep(i, 0, n) {\n            t += s[i];\n            if(i != n-1) t\
    \ += \"$\";\n        }\n        sz = t.size();\n        res = vec<int>(sz, 0);\n\
    \n        int c = 0;\n        rep(i, 0, sz) {\n            int l = 2 * c - i;\n\
    \            if(i + res[l] < c + res[c]) res[i] = res[l];\n            else {\n\
    \                int j = c + res[c] - i;\n                while(i - j >= 0 &&\
    \ i + j < sz && t[i-j] == t[i+j]) j++;\n                res[i] = j;\n        \
    \        c = i;\n            }\n        }\n    }\n\n    int get(int p) {\n   \
    \     return (res[2 * p] + 1)/2;\n    }\n\n    int get(int l, int r) {\n     \
    \   int m = 2 * l + 1;\n        return res[m]/2;\n    }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: String/manacher.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/manacher.test.cpp
documentation_of: String/manacher.hpp
layout: document
redirect_from:
- /library/String/manacher.hpp
- /library/String/manacher.hpp.html
title: String/manacher.hpp
---
