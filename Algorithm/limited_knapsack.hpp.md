---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/limited_knapsack.test.cpp
    title: verify/limited_knapsack.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Algorithm/limited_knapsack.hpp\"\n// O(nw)\n// require :\
    \ offset_manager / swag\n// constrains : V[i] >= 0, W[i] > 0 \n// if 0 >= W[i]\
    \ && V[i] >= 0  \u5168\u3066\u4F7F\u3046\u3002\n// if 0 >= V[i] && W[i] >= 0 \
    \ \u4F7F\u308F\u306A\u3044\n// if 0 >= V[i] && 0 >= W[i]  \u8CA0\u306E\u65B9\u5411\
    \u3092\u6301\u3064\u3002 mod\u3092 abs\u3067\u3084\u308B\u3002\u4ED6\u306B\u3042\
    \u308B\uFF1F\n\n\nll op_knapsack(ll l, ll r) {return max(l, r);}\nconst ll INF_k\
    \ = 1001001001001001001;\n\nll limited_knapsack(vec<ll> V, vec<ll> W, vec<ll>\
    \ M, ll w) {\n    int n = V.size();\n    vec<ll> dp(w + 1, -INF_k);\n    dp[0]\
    \ = 0;\n    rep(i, 0, n) {\n        assert(W[i] > 0);\n        //assert(V[i] >\
    \ 0);\n    }\n\n    rep(i, 0, n) {\n        vec<ll> pre(w + 1, -INF_k);\n    \
    \    swap(dp, pre);\n        rep(mod, 0, W[i]) {\n            offset_manager<ll>\
    \ ofs;\n            SWAG<ll, op_knapsack> swag; \n\n            rep(bi, 0, w +\
    \ 1) {//\u4F7F\u3046\u500B\u6570\u306Emax\n                ll si = bi * W[i] +\
    \ mod;\n                if(si > w) break;\n\n                ofs.add_all(V[i]);\n\
    \                ll v = pre[si];\n                v = ofs.push(v); \n        \
    \        swag.push_back(v);\n                if(bi > M[i]) swag.pop_front();\n\
    \                if(swag.empty() == false) chmax(dp[si], ofs.pop(swag.get()));\n\
    \            }\n        }\n    }\n\n\n    ll res = -1;\n    rep(i, 0, w + 1) chmax(res,\
    \ dp[i]);\n\n    return res;\n}\n\n"
  code: "// O(nw)\n// require : offset_manager / swag\n// constrains : V[i] >= 0,\
    \ W[i] > 0 \n// if 0 >= W[i] && V[i] >= 0  \u5168\u3066\u4F7F\u3046\u3002\n//\
    \ if 0 >= V[i] && W[i] >= 0  \u4F7F\u308F\u306A\u3044\n// if 0 >= V[i] && 0 >=\
    \ W[i]  \u8CA0\u306E\u65B9\u5411\u3092\u6301\u3064\u3002 mod\u3092 abs\u3067\u3084\
    \u308B\u3002\u4ED6\u306B\u3042\u308B\uFF1F\n\n\nll op_knapsack(ll l, ll r) {return\
    \ max(l, r);}\nconst ll INF_k = 1001001001001001001;\n\nll limited_knapsack(vec<ll>\
    \ V, vec<ll> W, vec<ll> M, ll w) {\n    int n = V.size();\n    vec<ll> dp(w +\
    \ 1, -INF_k);\n    dp[0] = 0;\n    rep(i, 0, n) {\n        assert(W[i] > 0);\n\
    \        //assert(V[i] > 0);\n    }\n\n    rep(i, 0, n) {\n        vec<ll> pre(w\
    \ + 1, -INF_k);\n        swap(dp, pre);\n        rep(mod, 0, W[i]) {\n       \
    \     offset_manager<ll> ofs;\n            SWAG<ll, op_knapsack> swag; \n\n  \
    \          rep(bi, 0, w + 1) {//\u4F7F\u3046\u500B\u6570\u306Emax\n          \
    \      ll si = bi * W[i] + mod;\n                if(si > w) break;\n\n       \
    \         ofs.add_all(V[i]);\n                ll v = pre[si];\n              \
    \  v = ofs.push(v); \n                swag.push_back(v);\n                if(bi\
    \ > M[i]) swag.pop_front();\n                if(swag.empty() == false) chmax(dp[si],\
    \ ofs.pop(swag.get()));\n            }\n        }\n    }\n\n\n    ll res = -1;\n\
    \    rep(i, 0, w + 1) chmax(res, dp[i]);\n\n    return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/limited_knapsack.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/limited_knapsack.test.cpp
documentation_of: Algorithm/limited_knapsack.hpp
layout: document
redirect_from:
- /library/Algorithm/limited_knapsack.hpp
- /library/Algorithm/limited_knapsack.hpp.html
title: Algorithm/limited_knapsack.hpp
---
