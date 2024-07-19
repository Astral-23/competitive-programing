---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/combination.hpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/4020
    document_title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/4020
  bundledCode: "#line 1 \"verify/combination.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4020\"\
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
    \n/*\n@brief modint\n*/\n#line 1 \"Math/combination.hpp\"\nstruct CMB {//must\u7D20\
    \u6570\n    using vl = vec<ll>;\n    vl fac;\n    vl ifac;\n    vl inv;\n    ll\
    \ mb = 0;\n    int N;\n  \n    CMB (int r, ll _mod) : mb(_mod), N(r+1), fac(r+1,\
    \ 1), ifac(r+1, 1), inv(r+1, 1) {\n        rep(i, 2, N) {\n            fac[i]\
    \ = fac[i-1] * i % mb;\n            inv[i] = mb - inv[mb%i]*(mb/i) % mb;\n   \
    \         ifac[i] = ifac[i-1] * inv[i] % mb;\n        }\n    }\n\n    ll C(int\
    \ n, int k) { \n        if(n < k) return 0LL;\n        if(n < 0 || k < 0) return\
    \ 0LL;\n        return fac[n] * (ifac[k] * ifac[n-k]%mb)%mb;\n    }\n  \n\n  \
    \  ll B(int n) { \n      return fac[n];\n    }\n  \n    ll invB(int n) {\n   \
    \     return ifac[n];\n    }\n  \n    ll H(int n, int k) { \n        return C(n+k-1,\
    \ k);\n    }\n  \n    ll Cn(int n) { \n        return C(2*n, n) * inv[n+1] % mb;\n\
    \    }\n};\n\n/*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs\
    \ doc/cmb.md\n*/\n#line 5 \"verify/combination.test.cpp\"\n\n\n/*\n@brief \u30B3\
    \u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n*/\nusing mint = modint998244353;\n\
    CMB cmb(1000000, 998244353);\n\nint main() {\n\tll N, M, T;\n\tcin >> N >> M >>\
    \ T;\n\n\tmint p = 0;\n\n\n\trep(k, 1, N+1) {\n\t\tmint s = 1;\n\t\tmint ue =\
    \ M * N - k * M;\n\n\n\t\trep(t, 1, T+1) {\n\t\t\tmint rev = M*N - (t-1);\n\t\t\
    \ts *= ue * (rev.inv());\n\t\t\tue -= 1;\n\t\t}\n\n        s *= cmb.C(N, k);\n\
    \t\tif(k%2==1) p += s;\n\t\telse p -= s;\n\n\t}\n\n\tcout << (1 - p).x << endl;\n\
    \n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4020\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include \"\
    ../Math/combination.hpp\"\n\n\n/*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\
    \u30E7\u30F3\n*/\nusing mint = modint998244353;\nCMB cmb(1000000, 998244353);\n\
    \nint main() {\n\tll N, M, T;\n\tcin >> N >> M >> T;\n\n\tmint p = 0;\n\n\n\t\
    rep(k, 1, N+1) {\n\t\tmint s = 1;\n\t\tmint ue = M * N - k * M;\n\n\n\t\trep(t,\
    \ 1, T+1) {\n\t\t\tmint rev = M*N - (t-1);\n\t\t\ts *= ue * (rev.inv());\n\t\t\
    \tue -= 1;\n\t\t}\n\n        s *= cmb.C(N, k);\n\t\tif(k%2==1) p += s;\n\t\telse\
    \ p -= s;\n\n\t}\n\n\tcout << (1 - p).x << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Math/combination.hpp
  isVerificationFile: true
  path: verify/combination.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/combination.test.cpp
layout: document
redirect_from:
- /verify/verify/combination.test.cpp
- /verify/verify/combination.test.cpp.html
title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
---
