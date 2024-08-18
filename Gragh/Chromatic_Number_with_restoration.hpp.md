---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/subset_transform.hpp
    title: Algorithm/subset_transform.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/bitwise_or_convolution.hpp
    title: Convolution/bitwise_or_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Chromatic_Number_with_restoration.test.cpp.cpp
    title: verify/Chromatic_Number_with_restoration.test.cpp.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
    links: []
  bundledCode: "#line 1 \"Algorithm/subset_transform.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S)> vector<S> subset_zeta_transform (vector<S> f, int n) {\n    rep(i, 0, n)\
    \ {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) != 0) { // if\
    \ i in s\n                f[s] = op(f[s], f[s ^ (1 << i)]);\n            }\n \
    \       }\n    }\n    return f;\n}\n\ntemplate<class S, S (*op)(S, S), S (*inv)(S)>\
    \ vector<S> subset_mobius_transform (vector<S> f, int n) {\n    rrep(i, 0, n)\
    \ {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) != 0) { // if\
    \ i in s\n                f[s] = op(f[s], inv(f[s ^ (1 << i)]));\n           \
    \ }\n        }\n    }\n    return f;\n}\n#line 2 \"Convolution/bitwise_or_convolution.hpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S>\
    \ A, vec<S> B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n  \
    \  while(B.size() > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n   \
    \ B.resize(1LL << lg, zero());\n\n    vec<S> FA = subset_zeta_transform<S, op>(A,\
    \ lg);\n    vec<S> FB = subset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1\
    \ << lg) FA[i] *= FB[i];\n    vec<S> f = subset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u3001\
    0\u3067\u3042\u308B\u3002\n#line 2 \"Gragh/Chromatic_Number_with_restoration.hpp\"\
    \n\nusing S = ll;\nS op(S a, S b) { return a + b; }\nS inv(S x) { return -x; }\n\
    S zero() { return 0; }\n\npair<int, vec<int>> chromatic_number(const vec<vec<int>>\
    \ &g) {\n    if (g.empty()) return {0, {}};\n    int n = g.size();\n\n    vec<vec<ll>>\
    \ dps(1, vec<ll>(1 << n, 0));\n    dps[0][0] = 1;\n\n    vec<ll> dp(1 << n, -1);\
    \  // dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\n    dp[0]\
    \ = 1;\n    rep(i, 0, n) dp[1 << i] = 1;\n\n    rep(s, 0, 1 << n) if (dp[s] ==\
    \ -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i & 1) lat = i;\n\
    \n        int sub = s ^ (1 << lat);\n        if (dp[sub] == 0) {\n           \
    \ dp[s] = 0;\n            continue;\n        }\n\n        bool ng = false;\n \
    \       for (int to : g[lat])\n            if (s >> to & 1) ng = true;\n\n   \
    \     if (ng)\n            dp[s] = 0;\n        else\n            dp[s] = 1;\n\
    \    }\n\n    dps.push_back(dp);\n\n    while (dps.back()[(1 << n) - 1] == 0)\
    \ {\n        dps.push_back(bitwise_or_convolution<S, op, inv, zero>(\n       \
    \     dps[1], dps[dps.size() - 1]));\n        rep(i, 0, n) if (dps[dps.size()\
    \ - 1][i] != 0) dps[dps.size() - 1][i] =\n            1;\n    }\n\n    int K =\
    \ dps.size() - 1;\n    vec<int> res(n, -1);\n\n    auto dfs = [&](auto f, int\
    \ sup,\n                   int l) -> void {  // \u96C6\u5408 S\u3092\u3001 [l,\
    \ K)\u3092\u4F7F\u3063\u3066\u5F69\u8272\u3002\n        if (sup == 0) return;\n\
    \        int sub = sup;\n        do {\n            if (dps[1][sub] && dps[K -\
    \ l - 1][sup ^ sub]) {\n                rep(i, 0, n) if (sub >> i & 1) res[i]\
    \ = l;\n\n                f(f, sup ^ sub, l + 1);\n                break;\n  \
    \          }\n\n            sub = (sub - 1) & sup;\n        } while (sub != sup);\n\
    \    };\n\n    dfs(dfs, (1 << n) - 1, 0);\n\n    return {K, res};\n}\n/*\n@brief\
    \ \u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)\n*/\n"
  code: "#include \"../Convolution/bitwise_or_convolution.hpp\"\n\nusing S = ll;\n\
    S op(S a, S b) { return a + b; }\nS inv(S x) { return -x; }\nS zero() { return\
    \ 0; }\n\npair<int, vec<int>> chromatic_number(const vec<vec<int>> &g) {\n   \
    \ if (g.empty()) return {0, {}};\n    int n = g.size();\n\n    vec<vec<ll>> dps(1,\
    \ vec<ll>(1 << n, 0));\n    dps[0][0] = 1;\n\n    vec<ll> dp(1 << n, -1);  //\
    \ dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\n    dp[0]\
    \ = 1;\n    rep(i, 0, n) dp[1 << i] = 1;\n\n    rep(s, 0, 1 << n) if (dp[s] ==\
    \ -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i & 1) lat = i;\n\
    \n        int sub = s ^ (1 << lat);\n        if (dp[sub] == 0) {\n           \
    \ dp[s] = 0;\n            continue;\n        }\n\n        bool ng = false;\n \
    \       for (int to : g[lat])\n            if (s >> to & 1) ng = true;\n\n   \
    \     if (ng)\n            dp[s] = 0;\n        else\n            dp[s] = 1;\n\
    \    }\n\n    dps.push_back(dp);\n\n    while (dps.back()[(1 << n) - 1] == 0)\
    \ {\n        dps.push_back(bitwise_or_convolution<S, op, inv, zero>(\n       \
    \     dps[1], dps[dps.size() - 1]));\n        rep(i, 0, n) if (dps[dps.size()\
    \ - 1][i] != 0) dps[dps.size() - 1][i] =\n            1;\n    }\n\n    int K =\
    \ dps.size() - 1;\n    vec<int> res(n, -1);\n\n    auto dfs = [&](auto f, int\
    \ sup,\n                   int l) -> void {  // \u96C6\u5408 S\u3092\u3001 [l,\
    \ K)\u3092\u4F7F\u3063\u3066\u5F69\u8272\u3002\n        if (sup == 0) return;\n\
    \        int sub = sup;\n        do {\n            if (dps[1][sub] && dps[K -\
    \ l - 1][sup ^ sub]) {\n                rep(i, 0, n) if (sub >> i & 1) res[i]\
    \ = l;\n\n                f(f, sup ^ sub, l + 1);\n                break;\n  \
    \          }\n\n            sub = (sub - 1) & sup;\n        } while (sub != sup);\n\
    \    };\n\n    dfs(dfs, (1 << n) - 1, 0);\n\n    return {K, res};\n}\n/*\n@brief\
    \ \u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)\n*/"
  dependsOn:
  - Convolution/bitwise_or_convolution.hpp
  - Algorithm/subset_transform.hpp
  isVerificationFile: false
  path: Gragh/Chromatic_Number_with_restoration.hpp
  requiredBy: []
  timestamp: '2024-08-18 17:09:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Chromatic_Number_with_restoration.test.cpp.cpp
documentation_of: Gragh/Chromatic_Number_with_restoration.hpp
layout: document
redirect_from:
- /library/Gragh/Chromatic_Number_with_restoration.hpp
- /library/Gragh/Chromatic_Number_with_restoration.hpp.html
title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
---
