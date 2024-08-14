---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: String/Rhash.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i\
    \ < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT\
    \ using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x, T2 y)\
    \ { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2> bool\
    \ chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"String/Rhash.hpp\"\nnamespace\
    \ rolling_hash {\nstruct rhash {\n    static const uint64_t mod = (1LL << 61)\
    \ - 1;\n    using mm = rhash;\n    uint64_t x;\n\n    rhash() : x(0) {}\n    TT\
    \ rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    friend mm operator*(mm a, mm b) {\n  \
    \      __uint128_t t = (__uint128_t)(a.x) * b.x;\n        t = (t >> 61) + (t &\
    \ mod);\n        return (t >= mod) ? t - mod : t;\n    }\n    friend mm &operator+=(mm\
    \ &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return\
    \ a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n\
    \n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n     \
    \   while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n     \
    \       y /= 2;\n        }\n        return res;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, mm &a) {\n        ll t;\n\n        cin >> t;\n        a = mm(t);\n    \
    \    return is;\n    }\n\n    friend ostream &operator<<(ostream &os, mm a) {\
    \ return os << a.x; }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool\
    \ operator!=(mm a) { return x != a.x; }\n    bool operator<(const mm &a) const\
    \ { return x < a.x; }\n};\n\nconst rhash brh = 200224;\nconst int MAX_SIZE = 500000;\n\
    vec<rhash> pw(MAX_SIZE + 1);\n\nstruct Initializer {\n    Initializer() {\n  \
    \      pw.resize(MAX_SIZE + 1);\n        pw[0] = 1;\n        rep(i, 1, MAX_SIZE\
    \ + 1) { pw[i] = pw[i - 1] * brh; }\n    }\n};\nInitializer initializer;\n\nstruct\
    \ Rhash {\n    int n;\n    vec<rhash> H;\n\n    Rhash() {}\n\n    Rhash(string\
    \ S) : n(S.size()) {\n        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n\
    \            H[i] += S[i];\n            if (i) {\n                H[i] += H[i\
    \ - 1] * brh;\n            }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n\
    \        assert(0 <= l && r <= n);\n        if (l >= r) return 0;\n        rhash\
    \ res = H[r - 1];\n        if (l) res -= H[l - 1] * pw[r - l];\n        return\
    \ res;\n    }\n\n    rhash get(int p) { return prod(p, p + 1); }\n\n    pair<ll,\
    \ ll> conv(ll l, ll r) { return make_pair(n - r, n - l); }\n};\n\nrhash cal_rhash(string\
    \ S) { return Rhash(S).prod(0, S.size()); }\n\nrhash connect(rhash mae, rhash\
    \ usiro, ll len_of_usiro) {\n    if (len_of_usiro <= MAX_SIZE) {\n        return\
    \ mae * pw[len_of_usiro] + usiro;\n    } else {\n        return mae * brh.pow(len_of_usiro)\
    \ + usiro;\n    }\n}\n\nrhash rhash_pow(rhash x, ll y, ll len) {\n    rhash res\
    \ = 0;\n    rhash len_pw;\n    if (len <= MAX_SIZE)\n        len_pw = pw[len];\n\
    \    else\n        len_pw = brh.pow(len);\n\n    while (y) {\n        if (y &\
    \ 1) {\n            res = res * len_pw + x;\n        }\n        x = x * len_pw\
    \ + x;\n        y /= 2;\n        len_pw *= len_pw;\n    }\n    return res;\n}\n\
    }  // namespace rolling_hash\n#line 3 \"example/rhash.example.cpp\"\n\nint main()\
    \ {\n    string s = \"abc\";\n    Rhash S(s); //s\u306E\u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6301\u3064\u69CB\u9020\u4F53\u3092\u5BA3\
    \u8A00\u3057\u305F\u3002\n\n    string t = \"abcde\";\n    Rhash T(t);\n    \n\
    \    cout << S.get(0, 2) << endl; //s \u306E [0, 2)\u3001\u3064\u307E\u308A\"\
    ab\"\u306B\u5BFE\u5FDC\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u3092\u51FA\u529B\n\
    \n    if(S.get(0, 3) == T.get(0, 3)) {\n        cout << \"\u4E00\u81F4\" << endl;\n\
    \    }\n\n    if(S.get(0, 3) != T.get(2, 5)) {\n        cout << \"\u4E0D\u4E00\
    \u81F4\" << endl;\n    }\n\n    if(S.get(0) == T.get(0)) {\n        cout << \"\
    \u4E00\u81F4\" << endl;\n    }\n\n    if(S.get(0) != T.get(1)) {\n        cout\
    \ << \"\u4E0D\u4E00\u81F4\" << endl;\n    }\n\n    string k = \"abcbd\";\n   \
    \ string reverse_k = \"dbcba\";\n\n    Rhash K(k);\n    Rhash RK(reverse_k);\n\
    \n    auto[rl, rr] = K.conv(1, 4);//K\u306E[1, 4)\u306F\u3001\u305D\u306Ereverse\u6587\
    \u5B57\u5217\u306E\u3069\u3053\u306B\u5BFE\u5FDC\u3059\u308B\u304B\n\n    if(K.get(1,\
    \ 4) == RK.get(rl, rr)) {\n        cout << \"bcb\u306F\u56DE\u6587\" << endl;\n\
    \    }\n}\n"
  code: "#include \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\n\n\
    int main() {\n    string s = \"abc\";\n    Rhash S(s); //s\u306E\u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u3092\u6301\u3064\u69CB\u9020\u4F53\u3092\
    \u5BA3\u8A00\u3057\u305F\u3002\n\n    string t = \"abcde\";\n    Rhash T(t);\n\
    \    \n    cout << S.get(0, 2) << endl; //s \u306E [0, 2)\u3001\u3064\u307E\u308A\
    \"ab\"\u306B\u5BFE\u5FDC\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u3092\u51FA\u529B\
    \n\n    if(S.get(0, 3) == T.get(0, 3)) {\n        cout << \"\u4E00\u81F4\" <<\
    \ endl;\n    }\n\n    if(S.get(0, 3) != T.get(2, 5)) {\n        cout << \"\u4E0D\
    \u4E00\u81F4\" << endl;\n    }\n\n    if(S.get(0) == T.get(0)) {\n        cout\
    \ << \"\u4E00\u81F4\" << endl;\n    }\n\n    if(S.get(0) != T.get(1)) {\n    \
    \    cout << \"\u4E0D\u4E00\u81F4\" << endl;\n    }\n\n    string k = \"abcbd\"\
    ;\n    string reverse_k = \"dbcba\";\n\n    Rhash K(k);\n    Rhash RK(reverse_k);\n\
    \n    auto[rl, rr] = K.conv(1, 4);//K\u306E[1, 4)\u306F\u3001\u305D\u306Ereverse\u6587\
    \u5B57\u5217\u306E\u3069\u3053\u306B\u5BFE\u5FDC\u3059\u308B\u304B\n\n    if(K.get(1,\
    \ 4) == RK.get(rl, rr)) {\n        cout << \"bcb\u306F\u56DE\u6587\" << endl;\n\
    \    }\n}\n"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  isVerificationFile: false
  path: example/rhash.example.cpp
  requiredBy: []
  timestamp: '2024-08-14 19:14:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: example/rhash.example.cpp
layout: document
redirect_from:
- /library/example/rhash.example.cpp
- /library/example/rhash.example.cpp.html
title: example/rhash.example.cpp
---
