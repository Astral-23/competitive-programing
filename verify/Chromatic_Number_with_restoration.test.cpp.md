---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/subset_transform.hpp
    title: Algorithm/subset_transform.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/bitwise_or_convolution.hpp
    title: Convolution/bitwise_or_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/Chromatic_Number_with_restoration.hpp
    title: Graph/Chromatic_Number_with_restoration.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"verify/Chromatic_Number_with_restoration.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Algorithm/subset_transform.hpp\"\ntemplate<class S, S (*op)(S,\
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
    0\u3067\u3042\u308B\u3002\n#line 2 \"Graph/Chromatic_Number_with_restoration.hpp\"\
    \n\nusing S = ll;\nS op(S a, S b) {\n    return a + b;\n}\nS inv(S x) {\n    return\
    \ -x;\n}\nS zero() {\n    return 0;\n}\n\npair<int, vec<int>> chromatic_number(const\
    \ vec<vec<int>> &g) {\n    if (g.empty()) return {0, {}};\n    int n = g.size();\n\
    \n    vec<vec<ll>> dps(1, vec<ll>(1 << n, 0));\n    dps[0][0] = 1;\n\n    vec<ll>\
    \ dp(1 << n, -1);  // dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\
    \uFF1F\n    dp[0] = 1;\n    rep(i, 0, n) dp[1 << i] = 1;\n\n    rep(s, 0, 1 <<\
    \ n) if (dp[s] == -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >>\
    \ i & 1) lat = i;\n\n        int sub = s ^ (1 << lat);\n        if (dp[sub] ==\
    \ 0) {\n            dp[s] = 0;\n            continue;\n        }\n\n        bool\
    \ ng = false;\n        for (int to : g[lat])\n            if (s >> to & 1) ng\
    \ = true;\n\n        if (ng)\n            dp[s] = 0;\n        else\n         \
    \   dp[s] = 1;\n    }\n\n    dps.push_back(dp);\n\n    while (dps.back()[(1 <<\
    \ n) - 1] == 0) {\n        dps.push_back(bitwise_or_convolution<S, op, inv, zero>(\n\
    \            dps[1], dps[dps.size() - 1]));\n        rep(i, 0, n) if (dps[dps.size()\
    \ - 1][i] != 0) dps[dps.size() - 1][i] =\n            1;\n    }\n\n    int K =\
    \ dps.size() - 1;\n    vec<int> res(n, -1);\n\n    auto dfs = [&](auto f, int\
    \ S,\n                   int l) -> void {  // \u96C6\u5408 S\u3092\u3001 [l, K)\u3092\
    \u4F7F\u3063\u3066\u5F69\u8272\u3002\n        if (S == 0) return;\n        int\
    \ sub = S;\n        do {\n            if (dps[1][sub] && dps[K - l - 1][S ^ sub])\
    \ {\n                rep(i, 0, n) if (sub >> i & 1) res[i] = l;\n\n          \
    \      f(f, S ^ sub, l + 1);\n                break;\n            }\n\n      \
    \      sub = (sub - 1) & S;\n        } while (sub != S);\n    };\n\n    dfs(dfs,\
    \ (1 << n) - 1, 0);\n\n    return {K, res};\n}\n#line 4 \"verify/Chromatic_Number_with_restoration.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    auto [ans, col] = chromatic_number(g);\n\
    \n    vec<int> cnt(ans, 0);\n\n    rep(i, 0, n) {\n        assert(0 <= col[i]);\n\
    \        assert(col[i] < ans);\n        cnt[col[i]]++;\n        for(int to : g[i])\
    \ {\n            assert(col[i] != col[to]);\n        }\n    }\n\n    rep(i, 0,\
    \ ans) assert(cnt[i] != 0);\n\n    cout << ans << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Graph/Chromatic_Number_with_restoration.hpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    auto [ans, col] = chromatic_number(g);\n\
    \n    vec<int> cnt(ans, 0);\n\n    rep(i, 0, n) {\n        assert(0 <= col[i]);\n\
    \        assert(col[i] < ans);\n        cnt[col[i]]++;\n        for(int to : g[i])\
    \ {\n            assert(col[i] != col[to]);\n        }\n    }\n\n    rep(i, 0,\
    \ ans) assert(cnt[i] != 0);\n\n    cout << ans << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Graph/Chromatic_Number_with_restoration.hpp
  - Convolution/bitwise_or_convolution.hpp
  - Algorithm/subset_transform.hpp
  isVerificationFile: true
  path: verify/Chromatic_Number_with_restoration.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Chromatic_Number_with_restoration.test.cpp
layout: document
redirect_from:
- /verify/verify/Chromatic_Number_with_restoration.test.cpp
- /verify/verify/Chromatic_Number_with_restoration.test.cpp.html
title: verify/Chromatic_Number_with_restoration.test.cpp
---
