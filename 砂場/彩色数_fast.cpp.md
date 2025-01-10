---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
    links: []
  bundledCode: "#line 1 \"\\u7802\\u5834/\\u5f69\\u8272\\u6570_fast.cpp\"\n#include\
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
    }\n\n\n//\u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\
    \u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate<uint32_t mod>\n\
    struct modint{\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a=0) : x((ll(a) % mod + mod) % mod){}\n\n    friend mm operator+(mm\
    \ a, mm b) {\n        a.x += b.x;\n        if(a.x >= mod) a.x -= mod;\n      \
    \  return a;\n    }\n   friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n\
    \        if(a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068\
    -\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\
    \u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm\
    \ a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm\
    \ b) { return a * b.inv(); }\n    friend mm& operator+=(mm& a, mm b) { return\
    \ a = a + b; }\n    friend mm& operator-=(mm& a, mm b) { return a = a - b; }\n\
    \    friend mm& operator*=(mm& a, mm b) { return a = a * b; }\n    friend mm&\
    \ operator/=(mm& a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const {return\
    \ pow(mod-2);}\n    mm pow(const ll& y) const {\n        if(!y) return 1;\n  \
    \      mm res = pow(y >> 1);\n        res *= res;\n        if(y & 1) res *= *this;\n\
    \        return res;\n    }\n\n    friend istream& operator>>(istream &is, mm\
    \ &a) { \n        ll t;\n        cin >> t;\n        a = mm(t);\n        return\
    \ is;\n    }\n\n    friend ostream& operator<<(ostream &os,  mm a) {\n       \
    \ return os << a.x;\n    }\n\n    bool operator==(mm a) {return x == a.x;}\n \
    \   bool operator!=(mm a) {return x != a.x;}\n\n    //bool operator<(const mm&\
    \ a) const {return x < a.x;}\n};\n\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n\n\nusing mint = modint998244353;\n\
    using S = mint;\nS op(S a, S b) { return a + b; }\nS inv(S x) { return -1*x; }\n\
    S zero() { return 0; }\n\nint chromatic_number(const vec<vec<int>> &g) {\n   \
    \ if (g.empty()) return 0;\n    int n = g.size();\n\n    vec<mint> dp(1LL << n,\
    \ -1);  // dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\n\
    \    dp[0] = 1;\n    rep(i, 0, n) dp[1LL << i] = 1;\n\n    rep(s, 0, 1LL << n)\
    \ if (dp[s] == -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i &\
    \ 1) lat = i;\n\n        ll sub = s ^ (1LL << lat);\n        if (dp[sub] == 0)\
    \ {\n            dp[s] = 0;\n            continue;\n        }\n\n        bool\
    \ ng = false;\n        for (int to : g[lat])\n            if (s >> to & 1) ng\
    \ = true;\n\n        if (ng)\n            dp[s] = 0;\n        else\n         \
    \   dp[s] = 1;\n    }\n\n    if(dp[(1 << n) - 1] != 0) {\n        return 1;\n\
    \    }\n\n    vec<mint> DP = subset_zeta_transform<S, op>(dp, n);\n    vec<mint>\
    \ DPK = DP;\n\n    rep(k, 2, n + 1) {\n        rep(i, 0, 1 << n) DPK[i] *= DP[i];\n\
    \        mint v = 0;\n        ll sup = (1LL << n) - 1;\n        ll sub = sup;\n\
    \        do {\n\n            ll diff = sup ^ sub;\n            ll p = __builtin_popcountll(diff);\n\
    \            if(p%2==0) p = 1;\n            else p = -1;\n\n            v += p\
    \ * DPK[sub];\n         \n            sub = (sub - 1) & sup;\n        } while\
    \ (sub != sup);\n\n        if(v != 0) return k;\n        else continue;\n    }\n\
    \    return -1;\n}\n\n/*\n@brief \u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)\n\
    */\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    int ans = chromatic_number(g);\n\n \
    \   vec<int> cnt(ans, 0);\n\n\n    cout << ans << endl;\n\n}\n\n"
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
    \ lg);\n    return f;\n}\n\n\n//\u52D5\u7684mod : template<int mod> \u3092\u6D88\
    \u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\n\
    template<uint32_t mod>\nstruct modint{\n    using mm = modint;\n    uint32_t x;\n\
    \    modint() : x(0) {}\n    TT modint(T a=0) : x((ll(a) % mod + mod) % mod){}\n\
    \n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n        if(a.x >=\
    \ mod) a.x -= mod;\n        return a;\n    }\n   friend mm operator-(mm a, mm\
    \ b) {\n        a.x -= b.x;\n        if(a.x >= mod) a.x += mod;\n        return\
    \ a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\
    \u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n \
    \   friend mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend\
    \ mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend mm& operator+=(mm&\
    \ a, mm b) { return a = a + b; }\n    friend mm& operator-=(mm& a, mm b) { return\
    \ a = a - b; }\n    friend mm& operator*=(mm& a, mm b) { return a = a * b; }\n\
    \    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n\n    mm\
    \ inv() const {return pow(mod-2);}\n    mm pow(const ll& y) const {\n        if(!y)\
    \ return 1;\n        mm res = pow(y >> 1);\n        res *= res;\n        if(y\
    \ & 1) res *= *this;\n        return res;\n    }\n\n    friend istream& operator>>(istream\
    \ &is, mm &a) { \n        ll t;\n        cin >> t;\n        a = mm(t);\n     \
    \   return is;\n    }\n\n    friend ostream& operator<<(ostream &os,  mm a) {\n\
    \        return os << a.x;\n    }\n\n    bool operator==(mm a) {return x == a.x;}\n\
    \    bool operator!=(mm a) {return x != a.x;}\n\n    //bool operator<(const mm&\
    \ a) const {return x < a.x;}\n};\n\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n\n\nusing mint = modint998244353;\n\
    using S = mint;\nS op(S a, S b) { return a + b; }\nS inv(S x) { return -1*x; }\n\
    S zero() { return 0; }\n\nint chromatic_number(const vec<vec<int>> &g) {\n   \
    \ if (g.empty()) return 0;\n    int n = g.size();\n\n    vec<mint> dp(1LL << n,\
    \ -1);  // dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\n\
    \    dp[0] = 1;\n    rep(i, 0, n) dp[1LL << i] = 1;\n\n    rep(s, 0, 1LL << n)\
    \ if (dp[s] == -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i &\
    \ 1) lat = i;\n\n        ll sub = s ^ (1LL << lat);\n        if (dp[sub] == 0)\
    \ {\n            dp[s] = 0;\n            continue;\n        }\n\n        bool\
    \ ng = false;\n        for (int to : g[lat])\n            if (s >> to & 1) ng\
    \ = true;\n\n        if (ng)\n            dp[s] = 0;\n        else\n         \
    \   dp[s] = 1;\n    }\n\n    if(dp[(1 << n) - 1] != 0) {\n        return 1;\n\
    \    }\n\n    vec<mint> DP = subset_zeta_transform<S, op>(dp, n);\n    vec<mint>\
    \ DPK = DP;\n\n    rep(k, 2, n + 1) {\n        rep(i, 0, 1 << n) DPK[i] *= DP[i];\n\
    \        mint v = 0;\n        ll sup = (1LL << n) - 1;\n        ll sub = sup;\n\
    \        do {\n\n            ll diff = sup ^ sub;\n            ll p = __builtin_popcountll(diff);\n\
    \            if(p%2==0) p = 1;\n            else p = -1;\n\n            v += p\
    \ * DPK[sub];\n         \n            sub = (sub - 1) & sup;\n        } while\
    \ (sub != sup);\n\n        if(v != 0) return k;\n        else continue;\n    }\n\
    \    return -1;\n}\n\n/*\n@brief \u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)\n\
    */\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    int ans = chromatic_number(g);\n\n \
    \   vec<int> cnt(ans, 0);\n\n\n    cout << ans << endl;\n\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: "\u7802\u5834/\u5F69\u8272\u6570_fast.cpp"
  requiredBy: []
  timestamp: '2025-01-10 23:59:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: "\u7802\u5834/\u5F69\u8272\u6570_fast.cpp"
layout: document
redirect_from:
- "/library/\u7802\u5834/\u5F69\u8272\u6570_fast.cpp"
- "/library/\u7802\u5834/\u5F69\u8272\u6570_fast.cpp.html"
title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
---
