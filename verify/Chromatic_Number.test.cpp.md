---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Gragh/Chromatic_Number.hpp
    title: "\u5F69\u8272\u6570"
  - icon: ':question:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"verify/Chromatic_Number.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\
    \ \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\
    \u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\
    \u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\
    \u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x)\
    \ * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n    friend mm &operator/=(mm &a, mm b) { return a = a * b.inv();\
    \ }\n\n    mm inv() const { return pow(mod - 2); }\n    mm pow(ll y) const {\n\
    \        mm res = 1;\n        mm v = *this;\n        while (y) {\n           \
    \ if (y & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n\
    \        return res;\n    }\n\n    friend istream &operator>>(istream &is, mm\
    \ &a) {\n        ll t;\n        cin >> t;\n        a = mm(t);\n        return\
    \ is;\n    }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os\
    \ << a.x; }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line 2 \"Gragh/Chromatic_Number.hpp\"\
    \n\nusing mint = modint998244353;\nint chromatic_number(const vec<vec<int>> &g)\
    \ {\n    if (g.empty()) return 0;\n    int n = g.size();\n\n    vec<mint> dp(1LL\
    \ << n, -1);  // dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\
    \n    dp[0] = 1;\n    rep(i, 0, n) dp[1LL << i] = 1;\n\n    rep(s, 0, 1LL << n)\
    \ if (dp[s] == -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i &\
    \ 1) lat = i;\n\n        ll sub = s ^ (1LL << lat);\n        if (dp[sub] == 0)\
    \ {\n            dp[s] = 0;\n            continue;\n        }\n\n        bool\
    \ ng = false;\n        for (int to : g[lat])\n            if (s >> to & 1) ng\
    \ = true;\n\n        if (ng)\n            dp[s] = 0;\n        else\n         \
    \   dp[s] = 1;\n    }\n\n    if (dp[(1 << n) - 1] != 0) {\n        return 1;\n\
    \    }\n\n    vec<mint> DP = dp;\n\n    rep(i, 0, n) {\n        rep(s, 0, 1LL\
    \ << n) {\n            if ((s & (1 << i)) != 0) {  // if i in s\n            \
    \    DP[s] += DP[s ^ (1 << i)];\n            }\n        }\n    }\n\n    vec<mint>\
    \ DPK = DP;\n\n    rep(k, 2, n + 1) {\n        rep(i, 0, 1 << n) DPK[i] *= DP[i];\n\
    \        mint v = 0;\n        ll sup = (1LL << n) - 1;\n        ll sub = sup;\n\
    \        do {\n            ll diff = sup ^ sub;\n            ll p = __builtin_popcountll(diff);\n\
    \            if (p % 2 == 0)\n                p = 1;\n            else\n     \
    \           p = -1;\n\n            v += p * DPK[sub];\n\n            sub = (sub\
    \ - 1) & sup;\n        } while (sub != sup);\n\n        if (v != 0)\n        \
    \    return k;\n        else\n            continue;\n    }\n    return -1;\n}\n\
    /*\n@brief \u5F69\u8272\u6570\n*/\n#line 4 \"verify/Chromatic_Number.test.cpp\"\
    \nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n \
    \   rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    int ans = chromatic_number(g);\n\n \
    \   cout << ans << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Gragh/Chromatic_Number.hpp\"\nint\
    \ main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n    rep(i,\
    \ 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    int ans = chromatic_number(g);\n\n \
    \   cout << ans << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Gragh/Chromatic_Number.hpp
  - Utility/modint.hpp
  isVerificationFile: true
  path: verify/Chromatic_Number.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 17:09:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Chromatic_Number.test.cpp
layout: document
redirect_from:
- /verify/verify/Chromatic_Number.test.cpp
- /verify/verify/Chromatic_Number.test.cpp.html
title: verify/Chromatic_Number.test.cpp
---
