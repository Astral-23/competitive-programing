---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/superset_transform.hpp
    title: Algorithm/superset_transform.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"verify/superset_transform.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n// \u52D5\u7684mod : template<int\
    \ mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\
    \u5BA3\u8A00\ntemplate <uint32_t mod> struct modint {\n    using mm = modint;\n\
    \    uint32_t x;\n    modint() : x(0) {}\n    TT modint(T a = 0) : x((ll(a) %\
    \ mod + mod)) {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm\
    \ a, mm b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n     \
    \   return a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n\
    \        if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068\
    -\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\
    \u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm\
    \ a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm\
    \ b) { return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const { return pow(mod\
    \ - 2); }\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n\
    \        while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n\
    \            y /= 2;\n        }\n        return res;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mm &a) {\n        ll t;\n        cin >> t;\n      \
    \  a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line\
    \ 1 \"Algorithm/superset_transform.hpp\"\ntemplate<class S, S (*op)(S, S)> vector<S>\
    \ superset_zeta_transform (vector<S> f, int n) {\n    rep(i, 0, n) {\n       \
    \ rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) == 0) { // if i in s\n\
    \                f[s] = op(f[s], f[s ^ (1 << i)]);\n            }\n        }\n\
    \    }\n    return f;\n}\n\ntemplate<class S, S (*op)(S, S), S (*inv)(S)> vector<S>\
    \ superset_mobius_transform (vector<S> f, int n) {\n    rrep(i, 0, n) {\n    \
    \    rep(s, 0, 1LL << n) {\n            if((s & (1 << i)) == 0) { // if i in s\n\
    \                f[s] = op(f[s], inv(f[s ^ (1 << i)]));\n                //f[s]\
    \ = f[s] -  f[s ^ (1 << i)];\n            }\n        }\n    }\n    return f;\n\
    }\n#line 5 \"verify/superset_transform.test.cpp\"\n\nusing mint = modint998244353;\n\
    \nusing S = mint;\nS op(S l, S r) {\n    return l + r;\n}\n\nS inv(S x) {\n  \
    \  return -1 * x;\n}\n\nS zero() {\n    return 0;\n}\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_and_convolution(vec<S> A, vec<S>\
    \ B) {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n    while(B.size()\
    \ > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n    B.resize(1LL <<\
    \ lg, zero());\n\n    vec<mint> FA = superset_zeta_transform<S, op>(A, lg);\n\
    \    vec<mint> FB = superset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1 <<\
    \ lg) FA[i] *= FB[i];\n    vec<mint> f = superset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u3001\
    0\u3067\u3042\u308B\u3002\n\nint main() {\n    int n;\n    cin >> n;\n    vec<mint>\
    \ A(1 << n), B(1 << n);\n    rep(i, 0, 1 << n) cin >> A[i];\n    rep(i, 0, 1 <<\
    \ n) cin >> B[i];\n\n    auto f = bitwise_and_convolution<S, op, inv, zero>(A,\
    \ B);\n    rep(i, 0, 1 << n) cout << f[i] << \" \";\n    cout << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include\
    \ \"../Algorithm/superset_transform.hpp\"\n\nusing mint = modint998244353;\n\n\
    using S = mint;\nS op(S l, S r) {\n    return l + r;\n}\n\nS inv(S x) {\n    return\
    \ -1 * x;\n}\n\nS zero() {\n    return 0;\n}\n\ntemplate<class S, S (*op)(S, S),\
    \ S (*inv)(S),  S(*zero)()> vec<S> bitwise_and_convolution(vec<S> A, vec<S> B)\
    \ {\n    ll lg = 1;\n    while(A.size() > (1LL << lg)) lg++;\n    while(B.size()\
    \ > (1LL << lg)) lg++;\n    A.resize(1LL << lg, zero());\n    B.resize(1LL <<\
    \ lg, zero());\n\n    vec<mint> FA = superset_zeta_transform<S, op>(A, lg);\n\
    \    vec<mint> FB = superset_zeta_transform<S, op>(B, lg);\n    rep(i, 0, 1 <<\
    \ lg) FA[i] *= FB[i];\n    vec<mint> f = superset_mobius_transform<S, op, inv>(FA,\
    \ lg);\n    return f;\n}\n//\u4EE5\u964D\u306E\u9805\u306B\u3064\u3044\u3066\u3001\
    0\u3067\u3042\u308B\u3002\n\nint main() {\n    int n;\n    cin >> n;\n    vec<mint>\
    \ A(1 << n), B(1 << n);\n    rep(i, 0, 1 << n) cin >> A[i];\n    rep(i, 0, 1 <<\
    \ n) cin >> B[i];\n\n    auto f = bitwise_and_convolution<S, op, inv, zero>(A,\
    \ B);\n    rep(i, 0, 1 << n) cout << f[i] << \" \";\n    cout << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Algorithm/superset_transform.hpp
  isVerificationFile: true
  path: verify/superset_transform.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/superset_transform.test.cpp
layout: document
redirect_from:
- /verify/verify/superset_transform.test.cpp
- /verify/verify/superset_transform.test.cpp.html
title: verify/superset_transform.test.cpp
---
