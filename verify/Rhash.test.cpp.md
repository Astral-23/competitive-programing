---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: Rolling_hash
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/Rhash.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"String/Rhash.hpp\"\nstruct rhash {\n    static\
    \ const uint64_t mod = (1LL << 61) - 1;\n    using mm = rhash;\n    uint64_t x;\n\
    \n    rhash() : x(0) {}\n    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod))\
    \ {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm a, mm\
    \ b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n        return\
    \ a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n    \
    \    if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    friend mm operator*(mm\
    \ a, mm b) {\n        __uint128_t t = (__uint128_t)(a.x) * b.x;\n        t = (t\
    \ >> 61) + (t & mod);\n        return (t >= mod) ? t - mod : t;\n    }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n\n    mm pow(const ll &y) const {\n        if (!y) return 1;\n\
    \        mm res = pow(y >> 1);\n        res *= res;\n        if (y & 1) res *=\
    \ *this;\n        return res;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, mm &a) {\n        ll t;\n\n        cin >> t;\n        a = mm(t);\n    \
    \    return is;\n    }\n\n    friend ostream &operator<<(ostream &os, mm a) {\
    \ return os << a.x; }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool\
    \ operator!=(mm a) { return x != a.x; }\n    bool operator<(const mm &a) const\
    \ { return x < a.x; }\n};\n\nstruct Rhash {\n    static const rhash brh;\n   \
    \ static vec<rhash> pw;\n    static const int MAX_SIZE;\n    int n;\n    vec<rhash>\
    \ H;\n\n    static void initialize_pow() {\n        pw.resize(MAX_SIZE + 1);\n\
    \        pw[0] = 1;\n        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh;\
    \ }\n    }\n\n    Rhash() {\n        if (pw.empty()) initialize_pow();\n    }\n\
    \n    Rhash(string S) : n(S.size()) {\n        if (pw.empty()) initialize_pow();\n\
    \        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n            H[i] +=\
    \ S[i];\n            if (i) {\n                H[i] += H[i - 1] * brh;\n     \
    \       }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n        assert(0\
    \ <= l && r <= n);\n        if (l >= r) return 0;\n        rhash res = H[r - 1];\n\
    \        if (l) res -= H[l - 1] * pw[r - l];\n        return res;\n    }\n\n \
    \   rhash get(int p) { return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l,\
    \ ll r) { return make_pair(n - r, n - l); }\n};\n\nconst rhash Rhash::brh = 200224;\n\
    const int Rhash::MAX_SIZE = 500000;\nvec<rhash> Rhash::pw;\n\nrhash connect(rhash\
    \ mae, rhash usiro, ll len_of_usiro) {\n    if (len_of_usiro <= Rhash::MAX_SIZE)\
    \ {\n        return mae * Rhash::pw[len_of_usiro] + usiro;\n    } else {\n   \
    \     return mae * Rhash::brh.pow(len_of_usiro) + usiro;\n    }\n}\n\nrhash rhash_pow(rhash\
    \ x, ll y, ll len) {\n    rhash res = 0;\n    rhash len_pw;\n    if (len <= Rhash::MAX_SIZE)\n\
    \        len_pw = Rhash::pw[len];\n    else\n        len_pw = Rhash::brh.pow(len);\n\
    \n    while (y) {\n        if (y & 1) {\n            res = res * len_pw + x;\n\
    \        }\n        x = x * len_pw + x;\n        y /= 2;\n        len_pw *= len_pw;\n\
    \    }\n    return res;\n}\n\n/*\n@brief Rolling_hash\n@docs doc/Rhash.md\n*/\n\
    #line 4 \"verify/Rhash.test.cpp\"\n\nint main() {\n    string S;\n    cin >> S;\n\
    \n    Rhash rs(S);\n\n    rep(i, 0, S.size()) {\n        int li = 0;\n       \
    \ int ri = int(S.size()) - i;\n\n        while(li < ri) {//ooxxxx   \n       \
    \     int mid = (li + ri + 1) >> 1;\n            if(rs.prod(i, i + mid) == rs.prod(0,\
    \ mid)) {\n                li = mid;\n            }\n            else {\n    \
    \            ri = mid - 1;\n            }\n        }\n\n        cout << li <<\
    \ \" \";\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\n\nint main()\
    \ {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n\n    rep(i, 0, S.size())\
    \ {\n        int li = 0;\n        int ri = int(S.size()) - i;\n\n        while(li\
    \ < ri) {//ooxxxx   \n            int mid = (li + ri + 1) >> 1;\n            if(rs.prod(i,\
    \ i + mid) == rs.prod(0, mid)) {\n                li = mid;\n            }\n \
    \           else {\n                ri = mid - 1;\n            }\n        }\n\n\
    \        cout << li << \" \";\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  isVerificationFile: true
  path: verify/Rhash.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 18:04:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Rhash.test.cpp
layout: document
redirect_from:
- /verify/verify/Rhash.test.cpp
- /verify/verify/Rhash.test.cpp.html
title: verify/Rhash.test.cpp
---
