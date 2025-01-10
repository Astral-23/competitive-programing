---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"\\u7802\\u5834/\\u5f69\\u8272\\u6570_slow.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define rep(i,\
    \ s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t)\
    \ - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\ntemplate<class\
    \ S, S (*op)(S, S)> vector<S> subset_zeta_transform (vector<S> f, int n) {\n \
    \   rep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 << i))\
    \ != 0) { // if i in s\n                f[s] = op(f[s], f[s ^ (1 << i)]);\n  \
    \          }\n        }\n    }\n    return f;\n}\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*inv)(S)> vector<S> subset_mobius_transform (vector<S> f, int n) {\n\
    \    rrep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n            if((s & (1 <<\
    \ i)) != 0) { // if i in s\n                f[s] = op(f[s], inv(f[s ^ (1 << i)]));\n\
    \            }\n        }\n    }\n    return f;\n}\n\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S> A, vec<S>\
    \ B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n    while(B.size()\
    \ > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n    B.resize(1LL <<\
    \ lg, zero());\n\n    vec<S> FA = subset_zeta_transform<S, op>(A, lg);\n    vec<S>\
    \ FB = subset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1 << lg) FA[i] *= FB[i];\n\
    \    vec<S> f = subset_mobius_transform<S, op, inv>(FA, lg);\n    return f;\n\
    }\n\n\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    auto [ans, col] = chromatic_number(g);\n\
    \n    vec<int> cnt(ans, 0);\n\n    rep(i, 0, n) {\n        assert(0 <= col[i]);\n\
    \        assert(col[i] < ans);\n        cnt[col[i]]++;\n        for(int to : g[i])\
    \ {\n            assert(col[i] != col[to]);\n        }\n    }\n\n    rep(i, 0,\
    \ ans) assert(cnt[i] != 0);\n\n    cout << ans << endl;\n\n}\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template<typename T>\nTT using vec = vector<T>;\ntemplate<class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class\
    \ T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false;\
    \ }\n\ntemplate<class S, S (*op)(S, S)> vector<S> subset_zeta_transform (vector<S>\
    \ f, int n) {\n    rep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n           \
    \ if((s & (1 << i)) != 0) { // if i in s\n                f[s] = op(f[s], f[s\
    \ ^ (1 << i)]);\n            }\n        }\n    }\n    return f;\n}\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*inv)(S)> vector<S> subset_mobius_transform (vector<S>\
    \ f, int n) {\n    rrep(i, 0, n) {\n        rep(s, 0, 1LL << n) {\n          \
    \  if((s & (1 << i)) != 0) { // if i in s\n                f[s] = op(f[s], inv(f[s\
    \ ^ (1 << i)]));\n            }\n        }\n    }\n    return f;\n}\n\n\ntemplate<class\
    \ S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S>\
    \ A, vec<S> B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n  \
    \  while(B.size() > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n   \
    \ B.resize(1LL << lg, zero());\n\n    vec<S> FA = subset_zeta_transform<S, op>(A,\
    \ lg);\n    vec<S> FB = subset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1\
    \ << lg) FA[i] *= FB[i];\n    vec<S> f = subset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n\n\n\nint main() {\n    int n, m;\n    cin >> n >> m;\n\
    \    vec<vec<int>> g(n);\n    rep(i, 0, m) {\n        int u, v;\n        cin >>\
    \ u >> v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n \
    \   auto [ans, col] = chromatic_number(g);\n\n    vec<int> cnt(ans, 0);\n\n  \
    \  rep(i, 0, n) {\n        assert(0 <= col[i]);\n        assert(col[i] < ans);\n\
    \        cnt[col[i]]++;\n        for(int to : g[i]) {\n            assert(col[i]\
    \ != col[to]);\n        }\n    }\n\n    rep(i, 0, ans) assert(cnt[i] != 0);\n\n\
    \    cout << ans << endl;\n\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: "\u7802\u5834/\u5F69\u8272\u6570_slow.cpp"
  requiredBy: []
  timestamp: '2025-01-10 23:59:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: "\u7802\u5834/\u5F69\u8272\u6570_slow.cpp"
layout: document
redirect_from:
- "/library/\u7802\u5834/\u5F69\u8272\u6570_slow.cpp"
- "/library/\u7802\u5834/\u5F69\u8272\u6570_slow.cpp.html"
title: "\u7802\u5834/\u5F69\u8272\u6570_slow.cpp"
---
