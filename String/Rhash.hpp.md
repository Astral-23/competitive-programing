---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/rhash.example.cpp
    title: example/rhash.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Rhash.test.cpp
    title: verify/Rhash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Rhash_more.test.cpp
    title: verify/Rhash_more.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/Rhash.hpp\"\nnamespace rolling_hash {\nstruct rhash\
    \ {\n    static const uint64_t mod = (1LL << 61) - 1;\n    using mm = rhash;\n\
    \    uint64_t x;\n\n    rhash() : x(0) {}\n    TT rhash(T a = 0) : x((__int128_t(a)\
    \ % mod + mod)) {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm\
    \ a, mm b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n     \
    \   return a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n\
    \        if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    friend mm\
    \ operator*(mm a, mm b) {\n        __uint128_t t = (__uint128_t)(a.x) * b.x;\n\
    \        t = (t >> 61) + (t & mod);\n        return (t >= mod) ? t - mod : t;\n\
    \    }\n    friend mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend\
    \ mm &operator-=(mm &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm\
    \ &a, mm b) { return a = a * b; }\n\n    mm pow(ll y) const {\n        mm res\
    \ = 1;\n        mm v = *this;\n        while (y) {\n            if (y & 1) res\
    \ *= v;\n            v *= v;\n            y /= 2;\n        }\n        return res;\n\
    \    }\n\n    friend istream &operator>>(istream &is, mm &a) {\n        ll t;\n\
    \n        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, mm a) { return os << a.x; }\n\n    bool operator==(mm\
    \ a) { return x == a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n  \
    \  bool operator<(const mm &a) const { return x < a.x; }\n};\n\nconst rhash brh\
    \ = 200224;\nconst int MAX_SIZE = 500000;\narray<rhash, MAX_SIZE + 1> pw;\n\n\
    struct Initializer {\n    Initializer() {\n        pw[0] = 1;\n        rep(i,\
    \ 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }\n    }\n};\nInitializer initializer;\n\
    \nstruct Rhash {\n    int n;\n    vec<rhash> H;\n\n    Rhash() {}\n\n    Rhash(string\
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
    }  // namespace rolling_hash\n"
  code: "namespace rolling_hash {\nstruct rhash {\n    static const uint64_t mod =\
    \ (1LL << 61) - 1;\n    using mm = rhash;\n    uint64_t x;\n\n    rhash() : x(0)\
    \ {}\n    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {\n        if (x\
    \ >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x\
    \ += b.x;\n        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n   \
    \ friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod)\
    \ a.x += mod;\n        return a;\n    }\n\n    friend mm operator*(mm a, mm b)\
    \ {\n        __uint128_t t = (__uint128_t)(a.x) * b.x;\n        t = (t >> 61)\
    \ + (t & mod);\n        return (t >= mod) ? t - mod : t;\n    }\n    friend mm\
    \ &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v\
    \ = *this;\n        while (y) {\n            if (y & 1) res *= v;\n          \
    \  v *= v;\n            y /= 2;\n        }\n        return res;\n    }\n\n   \
    \ friend istream &operator>>(istream &is, mm &a) {\n        ll t;\n\n        cin\
    \ >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\n\nconst rhash brh = 200224;\nconst int\
    \ MAX_SIZE = 500000;\narray<rhash, MAX_SIZE + 1> pw;\n\nstruct Initializer {\n\
    \    Initializer() {\n        pw[0] = 1;\n        rep(i, 1, MAX_SIZE + 1) { pw[i]\
    \ = pw[i - 1] * brh; }\n    }\n};\nInitializer initializer;\n\nstruct Rhash {\n\
    \    int n;\n    vec<rhash> H;\n\n    Rhash() {}\n\n    Rhash(string S) : n(S.size())\
    \ {\n        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n            H[i]\
    \ += S[i];\n            if (i) {\n                H[i] += H[i - 1] * brh;\n  \
    \          }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n        assert(0\
    \ <= l && r <= n);\n        if (l >= r) return 0;\n        rhash res = H[r - 1];\n\
    \        if (l) res -= H[l - 1] * pw[r - l];\n        return res;\n    }\n\n \
    \   rhash get(int p) { return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l,\
    \ ll r) { return make_pair(n - r, n - l); }\n};\n\nrhash cal_rhash(string S) {\
    \ return Rhash(S).prod(0, S.size()); }\n\nrhash connect(rhash mae, rhash usiro,\
    \ ll len_of_usiro) {\n    if (len_of_usiro <= MAX_SIZE) {\n        return mae\
    \ * pw[len_of_usiro] + usiro;\n    } else {\n        return mae * brh.pow(len_of_usiro)\
    \ + usiro;\n    }\n}\n\nrhash rhash_pow(rhash x, ll y, ll len) {\n    rhash res\
    \ = 0;\n    rhash len_pw;\n    if (len <= MAX_SIZE)\n        len_pw = pw[len];\n\
    \    else\n        len_pw = brh.pow(len);\n\n    while (y) {\n        if (y &\
    \ 1) {\n            res = res * len_pw + x;\n        }\n        x = x * len_pw\
    \ + x;\n        y /= 2;\n        len_pw *= len_pw;\n    }\n    return res;\n}\n\
    }  // namespace rolling_hash\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Rhash.hpp
  requiredBy:
  - example/rhash.example.cpp
  timestamp: '2024-08-14 19:19:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Rhash.test.cpp
  - verify/Rhash_more.test.cpp
documentation_of: String/Rhash.hpp
layout: document
redirect_from:
- /library/String/Rhash.hpp
- /library/String/Rhash.hpp.html
title: String/Rhash.hpp
---
