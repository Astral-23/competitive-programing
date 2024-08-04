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
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/Rhash_more.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/bigmodint.hpp\"\n\n/*\nmodint\u304B\u3089\
    \u306E\u5909\u66F4\u70B9:\n[1] 1\u884C\u76EE(template\u306E\u4E2D\u8EAB)\nuint32_t\
    \ mod \u2192 uint64_t mod\n\n[2] 4\u884C\u76EE(\u5909\u6570x\u306E\u578B)\nuint32_t\
    \ x \u2192 uint64_t x\n\n[3]friend mm operator*\u306B\u3064\u3044\u3066\u3001\n\
    (uint64_t)(a.x) * b.x; \u2192 (__uint128_t)(a.x) * b.x;\n*/\n\n//\u52D5\u7684\
    mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\
    \u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate<uint64_t mod>\nstruct modint{\n  \
    \  using mm = modint;\n    uint64_t x;\n\n    modint() : x(0){}\n    TT modint(T\
    \ a=0) : x((__int128_t(a) % mod + mod) % mod){}\n\n    friend mm operator+(mm\
    \ a, mm b) {\n        a.x += b.x;\n        if(a.x >= mod) a.x -= mod;\n      \
    \  return a;\n    }\n   friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n\
    \        if(a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    // + \u3068\
    \ -\u3060\u3051\u306A\u3089\u3053\u3053\u307E\u3067\n\n    friend mm operator*(mm\
    \ a, mm b) { return (__uint128_t)(a.x) * b.x; }\n    friend mm operator/(mm a,\
    \ mm b) { return a * b.inv(); }\n    friend mm& operator+=(mm& a, mm b) { return\
    \ a = a + b; }\n    friend mm& operator-=(mm& a, mm b) { return a = a - b; }\n\
    \    friend mm& operator*=(mm& a, mm b) { return a = a * b; }\n    friend mm&\
    \ operator/=(mm& a, mm b) { return a = a * b.inv(); }\n\n    //\u30ED\u30EA\u30CF\
    \u306A\u3089\u3053\u3053\u307E\u3067(/\u6F14\u7B97\u3068 /= \u6F14\u7B97\u306F\
    \u3044\u3089\u306A\u3044)\n\n    mm inv() const {return pow(mod-2);}\n    mm pow(const\
    \ ll& y) const {\n        if(!y) return 1;\n        mm res = pow(y >> 1);\n  \
    \      res *= res;\n        if(y & 1) res *= *this;\n        return res;\n   \
    \ }\n\n    friend istream& operator>>(istream &is, mm &a) { \n        ll t;\n\
    \        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend\
    \ ostream& operator<<(ostream &os, mm a) {\n        return os << a.x;\n    }\n\
    \n    bool operator==(mm a) {return x == a.x;}\n    bool operator!=(mm a) {return\
    \ x != a.x;}\n    //bool operator<(const mm& a) const {return x < a.x;}\n};\n\n\
    using rhash = modint<(1LL << 61) - 1>;\n/*\n@brief big_modint\n*/\n#line 2 \"\
    String/Rhash.hpp\"\n\nstruct Rhash {\n    static const rhash brh;\n    static\
    \ vec<rhash> pw;\n    static const int MAX_SIZE;\n    int n;\n    vec<rhash> H;\n\
    \n    static void initialize_pow() {\n        pw.resize(MAX_SIZE + 1);\n     \
    \   pw[0] = 1;\n        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }\n\
    \    }\n\n    Rhash() {\n        if (pw.empty()) initialize_pow();\n    }\n\n\
    \    Rhash(string S) : n(S.size()) {\n        if (pw.empty()) initialize_pow();\n\
    \        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n            H[i] +=\
    \ S[i];\n            if (i) {\n                H[i] += H[i - 1] * brh;\n     \
    \       }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n        assert(0\
    \ <= l && r <= n);\n        if (l >= r) return 0;\n        rhash res = H[r - 1];\n\
    \        if (l) res -= H[l - 1] * pw[r - l];\n        return res;\n    }\n\n \
    \   rhash get(int p) {\n        return prod(p, p + 1);\n    }\n\n    pair<ll,\
    \ ll> conv(ll l, ll r) {\n        return make_pair(n - r, n - l);\n    }\n};\n\
    \nconst rhash Rhash::brh = 200224;\nconst int Rhash::MAX_SIZE = 500000;\nvec<rhash>\
    \ Rhash::pw;\n\nrhash connect(rhash mae, rhash usiro, ll len_of_usiro) {\n   \
    \ if (len_of_usiro <= Rhash::MAX_SIZE) {\n        return mae * Rhash::pw[len_of_usiro]\
    \ + usiro;\n    } else {\n        return mae * Rhash::brh.pow(len_of_usiro) +\
    \ usiro;\n    }\n}\n\nrhash rhash_pow(const rhash &x, const ll &y, ll len) {\n\
    \    if (!y) return 0;\n    rhash res = rhash_pow(x, y / 2, len);\n    res = connect(res,\
    \ res, (y / 2) * len);\n    if(y & 1) res = connect(res, x, len);\n    return\
    \ res;\n}\n\n/*\n@brief Rolling_hash\n@docs doc/Rhash.md\n*/\n#line 4 \"verify/Rhash_more.test.cpp\"\
    \n\nint main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n    reverse(all(S));\n\
    \    Rhash rev(S);\n    reverse(all(S));\n\n    rep(ti, 0, ll(S.size()) * 2 -\
    \ 1) {\n        if(ti%2==0) {//\u6587\u5B57\n            int i = ti/2;\n     \
    \       ll li = 1;\n            ll ri = min<int>(i+1, (ll)S.size() - i);\n   \
    \         while(li < ri) {//oooxxx\n                ll mid = (li + ri + 1) >>\
    \ 1;\n                auto [l, r] = rs.conv(i - mid + 1, i + mid);\n         \
    \       if(rs.prod(i - mid + 1, i + mid).x == rev.prod(l, r).x) {\n          \
    \          li = mid;\n                }\n                else {\n            \
    \        ri = mid - 1;\n                }\n            }\n            cout <<\
    \ li*2-1 << \" \";\n        }\n        else {\n            int i = ti/2;\n   \
    \         ll li = 0;\n            ll ri = min<int>(i+1, (ll)S.size() - i - 1);\n\
    \            while(li < ri) {\n                ll mid = (li + ri + 1) >> 1;\n\
    \                auto [l, r] = rs.conv(i - mid + 1, i + mid + 1);\n          \
    \      if(rs.prod(i - mid + 1, i + mid + 1).x == rev.prod(l, r).x) {\n       \
    \             li = mid;\n                }\n                else {\n         \
    \           ri = mid - 1;\n                }\n            }\n            cout\
    \ << li*2 << \" \";\n        }\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\n\nint\
    \ main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n    reverse(all(S));\n\
    \    Rhash rev(S);\n    reverse(all(S));\n\n    rep(ti, 0, ll(S.size()) * 2 -\
    \ 1) {\n        if(ti%2==0) {//\u6587\u5B57\n            int i = ti/2;\n     \
    \       ll li = 1;\n            ll ri = min<int>(i+1, (ll)S.size() - i);\n   \
    \         while(li < ri) {//oooxxx\n                ll mid = (li + ri + 1) >>\
    \ 1;\n                auto [l, r] = rs.conv(i - mid + 1, i + mid);\n         \
    \       if(rs.prod(i - mid + 1, i + mid).x == rev.prod(l, r).x) {\n          \
    \          li = mid;\n                }\n                else {\n            \
    \        ri = mid - 1;\n                }\n            }\n            cout <<\
    \ li*2-1 << \" \";\n        }\n        else {\n            int i = ti/2;\n   \
    \         ll li = 0;\n            ll ri = min<int>(i+1, (ll)S.size() - i - 1);\n\
    \            while(li < ri) {\n                ll mid = (li + ri + 1) >> 1;\n\
    \                auto [l, r] = rs.conv(i - mid + 1, i + mid + 1);\n          \
    \      if(rs.prod(i - mid + 1, i + mid + 1).x == rev.prod(l, r).x) {\n       \
    \             li = mid;\n                }\n                else {\n         \
    \           ri = mid - 1;\n                }\n            }\n            cout\
    \ << li*2 << \" \";\n        }\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  - Utility/bigmodint.hpp
  isVerificationFile: true
  path: verify/Rhash_more.test.cpp
  requiredBy: []
  timestamp: '2024-08-05 00:16:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Rhash_more.test.cpp
layout: document
redirect_from:
- /verify/verify/Rhash_more.test.cpp
- /verify/verify/Rhash_more.test.cpp.html
title: verify/Rhash_more.test.cpp
---
