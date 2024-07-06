---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: "\u884C\u5217\u306E\u578B"
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"example/matrix.example.cpp\"\n\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n\n#define TT template<typename T>\nTT using vec\
    \ = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x, T2 y) { return\
    \ x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2> bool chmax(T1\
    \ &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct io_setup {\n \
    \   io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n\
    //\u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\
    \u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate<uint32_t mod>\nstruct\
    \ modint{\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n \
    \   TT modint(T a=0) : x((a % mod + mod) % mod){}\n\n    friend mm operator+(mm\
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
    using modint1000000007 = modint<1'000'000'007>;\n\n/*\n@brief modint\n*/\n#line\
    \ 1 \"Math/matrix.hpp\"\ntemplate<typename T>\nstruct Matrix  {\n    int h, w;\n\
    \    vector<vector<T>> d;\n    Matrix() {}\n    Matrix(int h, int w, T val = 0):\
    \ h(h), w(w), d(h, vector<T>(w, val)){}\n    Matrix& unit() {\n        assert(h\
    \ == w);\n        rep(i, 0, h) {\n            d[i][i] = 1;\n        }\n     return\
    \ *this;\n    }\n    const vector<T>& operator[](int i) const{return d[i];}\n\
    \    vector<T>& operator[](int i) {return d[i];}\n    Matrix operator*(const Matrix&a)\
    \ const{\n        assert(w == a.h);\n        Matrix r(h, a.w);\n        rep(i,\
    \ 0, h) {\n            rep(k, 0, w) {\n                rep(j, 0, a.w) {\n    \
    \                r[i][j] += d[i][k] * a[k][j];\n                }\n          \
    \  }\n        }\n        return r;\n    }\n    Matrix pow(ll t) const {\n    \
    \    assert(h == w);\n        if(!t) return Matrix(h, h).unit();\n        if(t\
    \ == 1) return *this;\n        Matrix r = pow(t >> 1);\n        r = r * r;\n \
    \       if(t&1) r = r*(*this);\n        return r;\n    }\n\n    vec<vec<T>> dump()\
    \ const {\n        return d;\n    }\n};\n/*\n@brief \u884C\u5217\u306E\u578B\n\
    @docs doc/matrix.md\n*/\n#line 5 \"example/matrix.example.cpp\"\nusing mint =\
    \ modint998244353;\n\nint main() {\n    int n = 3; \n    Matrix<mint>  mat(n,\
    \ n, 3); // n * n\u3067\u521D\u671F\u5024\u304C mint(0) \u306E\u884C\u5217\u3092\
    \u751F\u6210\n\n    mat[0][0] = 1; // (0, 0)\u6210\u5206\u3092 1 \u306B\u5909\u66F4\
    \n    mat[0][1] += 10; //(0, 1)\u6210\u5206\u306B 10\u3000\u52A0\u7B97\n    //mat[3][3]\
    \ = 100; //\u914D\u5217\u5916\u53C2\u7167 assert \u7121\u3057\n\n    auto pow_mat\
    \ = mat.pow(5); // mat\u306E 100 \u4E57\u3092\u53D7\u3051\u53D6\u308B\u3002 mat\u306F\
    \u7834\u58CA\u3055\u308C\u306A\u3044\u3002\n\n    auto print_vec = [](vec<vec<mint>>\
    \ v) {\n        rep(i, 0, v.size()) {\n            rep(j, 0, v[i].size()) cout\
    \ << v[i][j] << \" \";\n            cout << endl;\n        }\n    };\n\n    print_vec(mat.dump());//\
    \ dump\u3067\u8FD4\u3055\u308C\u305F\u4E8C\u6B21\u5143\u914D\u5217\u3092\u51FA\
    \u529B\n    print_vec(pow_mat.dump());// 5\u4E57\u3055\u308C\u3066\u3044\u308B\
    \u3002\n\n    Matrix<mint> v(n, 1, 1); //n * 1\u306E\u884C\u5217\u3002\u64EC\u4F3C\
    \u7684\u306A\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3048\u308B\u3002\
    \n\n    Matrix<mint> res = mat * v;//\u884C\u5217\u540C\u58EB\u306E\u639B\u3051\
    \u7B97\u3002\u884C\u5217\u7D2F\u4E57\u306E\u969B\u3001\u3053\u306E\u3088\u3046\
    \u306A\u51E6\u7406\u3092\u66F8\u304F\u304B\u3082\u3057\u308C\u306A\u3044\u3002\
    \n    print_vec(res.dump());\n    cout << res[0][0] << endl;\n\n}\n"
  code: "\n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\
    \n#include \"../Math/matrix.hpp\"\nusing mint = modint998244353;\n\nint main()\
    \ {\n    int n = 3; \n    Matrix<mint>  mat(n, n, 3); // n * n\u3067\u521D\u671F\
    \u5024\u304C mint(0) \u306E\u884C\u5217\u3092\u751F\u6210\n\n    mat[0][0] = 1;\
    \ // (0, 0)\u6210\u5206\u3092 1 \u306B\u5909\u66F4\n    mat[0][1] += 10; //(0,\
    \ 1)\u6210\u5206\u306B 10\u3000\u52A0\u7B97\n    //mat[3][3] = 100; //\u914D\u5217\
    \u5916\u53C2\u7167 assert \u7121\u3057\n\n    auto pow_mat = mat.pow(5); // mat\u306E\
    \ 100 \u4E57\u3092\u53D7\u3051\u53D6\u308B\u3002 mat\u306F\u7834\u58CA\u3055\u308C\
    \u306A\u3044\u3002\n\n    auto print_vec = [](vec<vec<mint>> v) {\n        rep(i,\
    \ 0, v.size()) {\n            rep(j, 0, v[i].size()) cout << v[i][j] << \" \"\
    ;\n            cout << endl;\n        }\n    };\n\n    print_vec(mat.dump());//\
    \ dump\u3067\u8FD4\u3055\u308C\u305F\u4E8C\u6B21\u5143\u914D\u5217\u3092\u51FA\
    \u529B\n    print_vec(pow_mat.dump());// 5\u4E57\u3055\u308C\u3066\u3044\u308B\
    \u3002\n\n    Matrix<mint> v(n, 1, 1); //n * 1\u306E\u884C\u5217\u3002\u64EC\u4F3C\
    \u7684\u306A\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u6271\u3048\u308B\u3002\
    \n\n    Matrix<mint> res = mat * v;//\u884C\u5217\u540C\u58EB\u306E\u639B\u3051\
    \u7B97\u3002\u884C\u5217\u7D2F\u4E57\u306E\u969B\u3001\u3053\u306E\u3088\u3046\
    \u306A\u51E6\u7406\u3092\u66F8\u304F\u304B\u3082\u3057\u308C\u306A\u3044\u3002\
    \n    print_vec(res.dump());\n    cout << res[0][0] << endl;\n\n}\n"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Math/matrix.hpp
  isVerificationFile: false
  path: example/matrix.example.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: example/matrix.example.cpp
layout: document
redirect_from:
- /library/example/matrix.example.cpp
- /library/example/matrix.example.cpp.html
title: example/matrix.example.cpp
---
