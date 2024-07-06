---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: Rolling_hash
  - icon: ':heavy_check_mark:'
    path: Utility/bigmodint.hpp
    title: big_modint
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/Rhash.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    Utility/bigmodint.hpp\"\n\n/*\nmodint\u304B\u3089\u306E\u5909\u66F4\u70B9:\n[1]\
    \ 1\u884C\u76EE(template\u306E\u4E2D\u8EAB)\nuint32_t mod \u2192 uint64_t mod\n\
    \n[2] 4\u884C\u76EE(\u5909\u6570x\u306E\u578B)\nuint32_t x \u2192 uint64_t x\n\
    \n[3]friend mm operator*\u306B\u3064\u3044\u3066\u3001\n(uint64_t)(a.x) * b.x;\
    \ \u2192 (__uint128_t)(a.x) * b.x;\n*/\n\n//\u52D5\u7684mod : template<int mod>\
    \ \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\
    \u8A00\ntemplate<uint64_t mod>\nstruct modint{\n    using mm = modint;\n    uint64_t\
    \ x;\n\n    modint() : x(0){}\n    TT modint(T a=0) : x((a % mod + mod) % mod){}\n\
    \n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n        if(a.x >=\
    \ mod) a.x -= mod;\n        return a;\n    }\n   friend mm operator-(mm a, mm\
    \ b) {\n        a.x -= b.x;\n        if(a.x >= mod) a.x += mod;\n        return\
    \ a;\n    }\n\n    // + \u3068 -\u3060\u3051\u306A\u3089\u3053\u3053\u307E\u3067\
    \n\n    friend mm operator*(mm a, mm b) { return (__uint128_t)(a.x) * b.x; }\n\
    \    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend mm& operator+=(mm&\
    \ a, mm b) { return a = a + b; }\n    friend mm& operator-=(mm& a, mm b) { return\
    \ a = a - b; }\n    friend mm& operator*=(mm& a, mm b) { return a = a * b; }\n\
    \    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n\n    //\u30ED\
    \u30EA\u30CF\u306A\u3089\u3053\u3053\u307E\u3067(/\u6F14\u7B97\u3068 /= \u6F14\
    \u7B97\u306F\u3044\u3089\u306A\u3044)\n\n    mm inv() const {return pow(mod-2);}\n\
    \    mm pow(const ll& y) const {\n        if(!y) return 1;\n        mm res = pow(y\
    \ >> 1);\n        res *= res;\n        if(y & 1) res *= *this;\n        return\
    \ res;\n    }\n\n    friend istream& operator>>(istream &is, mm &a) { \n     \
    \   ll t;\n        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n\
    \    friend ostream& operator<<(ostream &os, mm a) {\n        return os << a.x;\n\
    \    }\n\n    bool operator==(mm a) {return x == a.x;}\n    bool operator!=(mm\
    \ a) {return x != a.x;}\n    //bool operator<(const mm& a) const {return x < a.x;}\n\
    };\n\nusing rhash = modint<(1LL << 61) - 1>;\n/*\n@brief big_modint\n*/\n#line\
    \ 2 \"String/Rhash.hpp\"\n\n\nconst ll brh = 2312312;\nvec<rhash> pw(5000001,\
    \ 1);\n\nstruct Rhash {\n    int n;\n    vec<rhash> H;\n\n    TT Rhash(T S) :\
    \ n(S.size()) {\n        H = vec<rhash>(n, 0);\n        pw[0] = 1;\n\n       \
    \ rep(i, 0, n) {\n            H[i] += S[i];\n            if(i) {\n           \
    \     H[i] += H[i-1] * brh;\n                pw[i] = pw[i-1] * brh;\n        \
    \    }\n        }\n    }\n\n    rhash get(int l, int r) {\n        assert(0 <=\
    \ l && r <= n);\n        if(l >= r) return 0;\n        rhash res = H[r-1];\n \
    \       if(l) res -= H[l-1] * pw[r-l];\n        return res;\n    }\n\n    rhash\
    \ get(int p) {\n        return get(p, p+1);\n    }\n\n    //reverse\u3057\u305F\
    \u30CF\u30C3\u30B7\u30E5\u3092\u9006\u65B9\u5411\u3068\u3057\u3066\u3001\u6B63\
    \u65B9\u5411\u306E[l, r)\u3068\u5BFE\u5FDC\u3059\u308B\u9006\u65B9\u5411\u306E\
    \u533A\u9593\u3092\u8FD4\u3059\u3002\n    //\u56DE\u6587\u5224\u5B9A\u306B\u4F7F\
    \u3046\u3002\n\n    pair<int, int> conv(int l, int r) {\n        return make_pair(n\
    \ - r, n - l);\n    }\n\n\n    //\u8981\u7D20\u8FFD\u52A0\u3057\u305F\u3044\u6642\
    \n    TT void push_back(T &h) {\n        n++;\n        H.resize(n);\n        pw[n-1]\
    \ = pw[n-2] * brh;\n        H[n-1] = h + H[n-2] * brh;\n    }\n    \n};\n\n\n\
    //\u30CF\u30C3\u30B7\u30E5\u306E\u7D50\u5408\nrhash unit(rhash mae, rhash usiro,\
    \ int len_of_usiro) {\n    return mae * pw[len_of_usiro] + usiro;\n}\n\n/*\n@brief\
    \ Rolling_hash\n@docs doc/Rhash.md\n*/\n#line 4 \"verify/Rhash.test.cpp\"\n\n\
    int main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n\n    rep(i, 0,\
    \ S.size()) {\n        int li = 0;\n        int ri = int(S.size()) - i;\n\n  \
    \      while(li < ri) {//ooxxxx   \n            int mid = (li + ri + 1) >> 1;\n\
    \            if(rs.get(i, i + mid).x == rs.get(0, mid).x) {\n                li\
    \ = mid;\n            }\n            else {\n                ri = mid - 1;\n \
    \           }\n        }\n\n        cout << li << \" \";\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\n\nint main()\
    \ {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n\n    rep(i, 0, S.size())\
    \ {\n        int li = 0;\n        int ri = int(S.size()) - i;\n\n        while(li\
    \ < ri) {//ooxxxx   \n            int mid = (li + ri + 1) >> 1;\n            if(rs.get(i,\
    \ i + mid).x == rs.get(0, mid).x) {\n                li = mid;\n            }\n\
    \            else {\n                ri = mid - 1;\n            }\n        }\n\
    \n        cout << li << \" \";\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  - Utility/bigmodint.hpp
  isVerificationFile: true
  path: verify/Rhash.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Rhash.test.cpp
layout: document
redirect_from:
- /verify/verify/Rhash.test.cpp
- /verify/verify/Rhash.test.cpp.html
title: verify/Rhash.test.cpp
---
