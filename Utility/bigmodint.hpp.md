---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: Rolling_hash
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
    document_title: big_modint
    links: []
  bundledCode: "#line 1 \"Utility/bigmodint.hpp\"\n\n/*\nmodint\u304B\u3089\u306E\u5909\
    \u66F4\u70B9:\n[1] 1\u884C\u76EE(template\u306E\u4E2D\u8EAB)\nuint32_t mod \u2192\
    \ uint64_t mod\n\n[2] 4\u884C\u76EE(\u5909\u6570x\u306E\u578B)\nuint32_t x \u2192\
    \ uint64_t x\n\n[3]friend mm operator*\u306B\u3064\u3044\u3066\u3001\n(uint64_t)(a.x)\
    \ * b.x; \u2192 (__uint128_t)(a.x) * b.x;\n*/\n\n//\u52D5\u7684mod : template<int\
    \ mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\
    \u5BA3\u8A00\ntemplate<uint64_t mod>\nstruct modint{\n    using mm = modint;\n\
    \    uint64_t x;\n\n    modint() : x(0){}\n    TT modint(T a=0) : x((__int128_t(a)\
    \ % mod + mod) % mod){}\n\n    friend mm operator+(mm a, mm b) {\n        a.x\
    \ += b.x;\n        if(a.x >= mod) a.x -= mod;\n        return a;\n    }\n   friend\
    \ mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if(a.x >= mod) a.x\
    \ += mod;\n        return a;\n    }\n\n    // + \u3068 -\u3060\u3051\u306A\u3089\
    \u3053\u3053\u307E\u3067\n\n    friend mm operator*(mm a, mm b) { return (__uint128_t)(a.x)\
    \ * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend\
    \ mm& operator+=(mm& a, mm b) { return a = a + b; }\n    friend mm& operator-=(mm&\
    \ a, mm b) { return a = a - b; }\n    friend mm& operator*=(mm& a, mm b) { return\
    \ a = a * b; }\n    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv();\
    \ }\n\n    //\u30ED\u30EA\u30CF\u306A\u3089\u3053\u3053\u307E\u3067(/\u6F14\u7B97\
    \u3068 /= \u6F14\u7B97\u306F\u3044\u3089\u306A\u3044)\n\n    mm inv() const {return\
    \ pow(mod-2);}\n    mm pow(const ll& y) const {\n        if(!y) return 1;\n  \
    \      mm res = pow(y >> 1);\n        res *= res;\n        if(y & 1) res *= *this;\n\
    \        return res;\n    }\n\n    friend istream& operator>>(istream &is, mm\
    \ &a) { \n        ll t;\n        cin >> t;\n        a = mm(t);\n        return\
    \ is;\n    }\n\n    friend ostream& operator<<(ostream &os, mm a) {\n        return\
    \ os << a.x;\n    }\n\n    bool operator==(mm a) {return x == a.x;}\n    bool\
    \ operator!=(mm a) {return x != a.x;}\n    //bool operator<(const mm& a) const\
    \ {return x < a.x;}\n};\n\nusing rhash = modint<(1LL << 61) - 1>;\n/*\n@brief\
    \ big_modint\n*/\n"
  code: "\n/*\nmodint\u304B\u3089\u306E\u5909\u66F4\u70B9:\n[1] 1\u884C\u76EE(template\u306E\
    \u4E2D\u8EAB)\nuint32_t mod \u2192 uint64_t mod\n\n[2] 4\u884C\u76EE(\u5909\u6570\
    x\u306E\u578B)\nuint32_t x \u2192 uint64_t x\n\n[3]friend mm operator*\u306B\u3064\
    \u3044\u3066\u3001\n(uint64_t)(a.x) * b.x; \u2192 (__uint128_t)(a.x) * b.x;\n\
    */\n\n//\u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\
    \u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate<uint64_t mod>\n\
    struct modint{\n    using mm = modint;\n    uint64_t x;\n\n    modint() : x(0){}\n\
    \    TT modint(T a=0) : x((__int128_t(a) % mod + mod) % mod){}\n\n    friend mm\
    \ operator+(mm a, mm b) {\n        a.x += b.x;\n        if(a.x >= mod) a.x -=\
    \ mod;\n        return a;\n    }\n   friend mm operator-(mm a, mm b) {\n     \
    \   a.x -= b.x;\n        if(a.x >= mod) a.x += mod;\n        return a;\n    }\n\
    \n    // + \u3068 -\u3060\u3051\u306A\u3089\u3053\u3053\u307E\u3067\n\n    friend\
    \ mm operator*(mm a, mm b) { return (__uint128_t)(a.x) * b.x; }\n    friend mm\
    \ operator/(mm a, mm b) { return a * b.inv(); }\n    friend mm& operator+=(mm&\
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
    };\n\nusing rhash = modint<(1LL << 61) - 1>;\n/*\n@brief big_modint\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utility/bigmodint.hpp
  requiredBy:
  - example/rhash.example.cpp
  - String/Rhash.hpp
  timestamp: '2024-07-29 21:23:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Rhash.test.cpp
  - verify/Rhash_more.test.cpp
documentation_of: Utility/bigmodint.hpp
layout: document
redirect_from:
- /library/Utility/bigmodint.hpp
- /library/Utility/bigmodint.hpp.html
title: big_modint
---
