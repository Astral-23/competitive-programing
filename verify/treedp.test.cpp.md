---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/treedp.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP"
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"verify/treedp.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\u52D5\u7684mod :\
    \ template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\
    \u6570mod\u3092\u5BA3\u8A00\ntemplate<uint32_t mod>\nstruct modint{\n    using\
    \ mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n    TT modint(T a=0)\
    \ : x((a % mod + mod) % mod){}\n\n    friend mm operator+(mm a, mm b) {\n    \
    \    a.x += b.x;\n        if(a.x >= mod) a.x -= mod;\n        return a;\n    }\n\
    \   friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if(a.x >=\
    \ mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\
    \u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\
    \u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return\
    \ (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv();\
    \ }\n    friend mm& operator+=(mm& a, mm b) { return a = a + b; }\n    friend\
    \ mm& operator-=(mm& a, mm b) { return a = a - b; }\n    friend mm& operator*=(mm&\
    \ a, mm b) { return a = a * b; }\n    friend mm& operator/=(mm& a, mm b) { return\
    \ a = a * b.inv(); }\n\n    mm inv() const {return pow(mod-2);}\n    mm pow(const\
    \ ll& y) const {\n        if(!y) return 1;\n        mm res = pow(y >> 1);\n  \
    \      res *= res;\n        if(y & 1) res *= *this;\n        return res;\n   \
    \ }\n\n    friend istream& operator>>(istream &is, mm &a) { \n        ll t;\n\
    \        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend\
    \ ostream& operator<<(ostream &os,  mm a) {\n        return os << a.x;\n    }\n\
    \n    bool operator==(mm a) {return x == a.x;}\n    bool operator!=(mm a) {return\
    \ x != a.x;}\n\n    //bool operator<(const mm& a) const {return x < a.x;}\n};\n\
    \nusing modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\
    \n/*\n@brief modint\n*/\n#line 1 \"Algorithm/treedp.hpp\"\ntemplate<class S, S\
    \ (*op)(S, S), S (*e)(), S (*addroot)(S, int),  class F, S (*mp)(F, S)> struct\
    \ TDP {\n    using pif = pair<int, F>;\n    using vs = vec<S>;\n    using vvs\
    \ = vec<vs>;\n\n    int n;\n    vec<vec<pif>> g;\n    vvs dp; //dp[now][i] :=\
    \  (now \u2192 g[r][i])\u306E\u8FBA\u306B\u3064\u3044\u3066\u3001 g[r][i]\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u7D50\u679C\n    vs ans; \n\n\
    \    TDP(int N) : n(N) {\n        g.resize(n);\n        dp = vvs(n);\n       \
    \ ans = vs(n, e());\n    }\n    \n    //1\u304B\u3089\u66F8\u304F\u5834\u5408\u306B\
    \u5FC5\u8981\u306A\u90E8\u5206\u2193\n    S dfs(int v, int p) {//\u666E\u901A\u306B\
    \u6728DP\u3059\u308B\u30D1\u30FC\u30C8\n        S res = e();//\n        int d\
    \ = g[v].size();\n        dp[v].resize(d);\n        rep(i, 0, d) {\n         \
    \   int to = g[v][i].first;\n            if(to == p) continue;\n            dp[v][i]\
    \ = dfs(to, v);\n            res = op(res, mp(g[v][i].second, dp[v][i])); //\u90E8\
    \u5206\u6728\u306E\u7D50\u679C\u3092\u96C6\u7D04\u3002\n            //\u672C\u5B9F\
    \u88C5\u3067\u306F\u3053\u306E\u6BB5\u968E\u3067\u8FBA\u306E\u5F71\u97FF\u3092\
    \u52A0\u7B97\u3057\u3066\u3044\u308B\u304C\u3001\u8FBB\u8904\u304C\u5408\u3046\
    \u306A\u3089\u3044\u3064\u3067\u3082\u826F\u3044\u3002\n        }\n        //\u8FBA\
    \u30FB\u9802\u70B9\u3092add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\
    \u3082\u306E\u3092\u8FD4\u3059\u3002\u3064\u307E\u308A\u3001\u300C\uFF56\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728 / v\u3092lca\u3068\u3059\u308B\u30D1\
    \u30B9\u306E\u7D50\u679C\u300D\u3092\u8FD4\u3059\u3002\n        return addroot(res,\
    \ v);\n    }\n\n    void bfs(int v, S par, int p) {\n        int d = g[v].size();\n\
    \        rep(i, 0, d) if(g[v][i].first == p) dp[v][i] = par;//\u89AA\u306E\u7D50\
    \u679C\u3092\u6E21\u3057\u3066\u304A\u304F\u3002\n\n        vs L (d + 1, e());\n\
    \        vs R (d + 1, e());\n\n        rep(i, 0, d) L[i+1] = op(L[i], mp(g[v][i].second,\
    \ dp[v][i])); //\u672C\u5B9F\u88C5\u3067\u306F\u3053\u306E\u6BB5\u968E\u3067\u8FBA\
    \u306E\u5F71\u97FF\u3092\u52A0\u7B97\u3057\u3066\u3044\u308B\u304C\u3001\u8FBB\
    \u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\u3067\u3082\u826F\u3044\u3002\
    \n        rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i+1]);\n\n \
    \       ans[v] = addroot(L[d], v);//\u8FBA\u30FB\u9802\u70B9\u3092add\u3057\u305F\
    \u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\u3002\
    \u3064\u307E\u308A\u3001\u300C\uFF56\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\
    \u6728 / v\u3092lca\u3068\u3059\u308B\u30D1\u30B9\u306E\u7D50\u679C\u300D\u3092\
    \u8FD4\u3059\u3002\n\n        rep(i, 0, d) {\n            int to = g[v][i].first;\n\
    \            if(to == p) continue;\n            S nx = op(L[i], R[i+1]);//\u672C\
    \u5B9F\u88C5\u3067\u306F\u3053\u306E\u6BB5\u968E\u3067\u8FBA\u306E\u5F71\u97FF\
    \u3092\u52A0\u7B97\u3057\u3066\u3044\u308B\u304C\u3001\u8FBB\u8904\u304C\u5408\
    \u3046\u306A\u3089\u3044\u3064\u3067\u3082\u826F\u3044\u3002\n            bfs(to,\
    \ addroot(nx, v), v);//\u8FBA\u30FB\u9802\u70B9\u3092add\u3057\u305F\u5F71\u97FF\
    \u3092\u53CD\u6620\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\u3002\u3064\u307E\
    \u308A\u3001\u300Cto\u2192\uFF56\u306B\u3064\u3044\u3066\u3001v\u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728 / v\u3092lca\u3068\u3059\u308B\u30D1\u30B9\u306E\
    \u7D50\u679C\u300D\u3092\u8FD4\u3059\u3002\n        }\n\n    }\n\n    //1\u304B\
    \u3089\u66F8\u304F\u5834\u5408\u306B\u5FC5\u8981\u306A\u90E8\u5206\n\n    void\
    \ add_edge(int s, int t, F f) {\n        g[s].emplace_back(t, f);\n    }\n   \
    \ \n    vec<S> exe() {\n        dfs(0, -1); \n        bfs(0, e(), -1);\n     \
    \   return ans;\n    }\n};\n\n\n\n\n/*\n@brief \u5168\u65B9\u4F4D\u6728DP\n@docs\
    \ doc/treedp.md\n*/\n#line 5 \"verify/treedp.test.cpp\"\nvec<ll> A;\n\nusing mint\
    \ = modint998244353;\n\nstruct S {\n    mint val; int siz;\n    S(){}\n    S(mint\
    \ v, int s) : val(v), siz(s){}\n};\n\nS op(S l, S r) {\n    l.val += r.val;\n\
    \    l.siz += r.siz;\n    return l;\n}\n\nS e() {\n    return S(0, 0);\n}\n\n\
    S addroot(S res, int v) {\n    res.val += A[v];\n    res.siz += 1;\n    return\
    \ res;\n}\n\nstruct F{\n    mint b, c;\n    F(){}\n    F(mint t, mint y) : b(t),\
    \ c(y) {}\n};\n\nS mp(F f, S s) {\n    s.val = s.val * f.b + f.c * s.siz;\n  \
    \  return s;\n}\n\nint main() {\n    int n;\n    cin >> n;\n    A = vec<ll>(n,\
    \ 0);\n    rep(i, 0, n) cin >> A[i];\n\n    TDP<S, op, e, addroot, F, mp> tdp(n);\n\
    \    rep(i, 0, n-1) {\n        int u, v, b, c;\n        cin >> u >> v >> b >>\
    \ c;\n        tdp.add_edge(u, v, F(b, c));\n        tdp.add_edge(v, u, F(b, c));\n\
    \    }\n\n    auto ans = tdp.exe();\n    rep(i, 0, n) cout << ans[i].val.x <<\
    \ '\\n';\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include\
    \ \"../Algorithm/treedp.hpp\"\nvec<ll> A;\n\nusing mint = modint998244353;\n\n\
    struct S {\n    mint val; int siz;\n    S(){}\n    S(mint v, int s) : val(v),\
    \ siz(s){}\n};\n\nS op(S l, S r) {\n    l.val += r.val;\n    l.siz += r.siz;\n\
    \    return l;\n}\n\nS e() {\n    return S(0, 0);\n}\n\nS addroot(S res, int v)\
    \ {\n    res.val += A[v];\n    res.siz += 1;\n    return res;\n}\n\nstruct F{\n\
    \    mint b, c;\n    F(){}\n    F(mint t, mint y) : b(t), c(y) {}\n};\n\nS mp(F\
    \ f, S s) {\n    s.val = s.val * f.b + f.c * s.siz;\n    return s;\n}\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    A = vec<ll>(n, 0);\n    rep(i, 0, n) cin >>\
    \ A[i];\n\n    TDP<S, op, e, addroot, F, mp> tdp(n);\n    rep(i, 0, n-1) {\n \
    \       int u, v, b, c;\n        cin >> u >> v >> b >> c;\n        tdp.add_edge(u,\
    \ v, F(b, c));\n        tdp.add_edge(v, u, F(b, c));\n    }\n\n    auto ans =\
    \ tdp.exe();\n    rep(i, 0, n) cout << ans[i].val.x << '\\n';\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Algorithm/treedp.hpp
  isVerificationFile: true
  path: verify/treedp.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/treedp.test.cpp
layout: document
redirect_from:
- /verify/verify/treedp.test.cpp
- /verify/verify/treedp.test.cpp.html
title: verify/treedp.test.cpp
---
