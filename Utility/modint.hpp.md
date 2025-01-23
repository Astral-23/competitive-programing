---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Chromatic_Number.hpp
    title: "\u5F69\u8272\u6570"
  - icon: ':warning:'
    path: example/matrix.example.cpp
    title: example/matrix.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Chromatic_Number.test.cpp
    title: verify/Chromatic_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Convolution_lcm_convolution.test.cpp
    title: verify/Convolution_lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_dynamicseg.test.cpp
    title: verify/Datastructure_dynamicseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_lazysegtree.test.cpp
    title: verify/Datastructure_lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_seg_prod.test.cpp
    title: verify/Datastructure_seg_prod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_swag.test.cpp
    title: verify/Datastructure_swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_swag_more.test.cpp
    title: verify/Datastructure_swag_more.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_treap.test.cpp
    title: verify/Datastructure_treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination_more.test.cpp
    title: verify/Math_combination_more.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_det.test.cpp
    title: verify/Math_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_inv.test.cpp
    title: verify/Math_matrix_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_pow.test.cpp
    title: verify/Math_matrix_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_matrix_rank.test.cpp
    title: verify/Math_matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/bellman_ford.test.cpp
    title: verify/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/bitwise_and_convolution.test.cpp
    title: verify/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/dijkstra.test.cpp
    title: verify/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/mat_det.test.cpp
    title: verify/mat_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/matrix.test.cpp
    title: verify/matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/superset_transform.test.cpp
    title: verify/superset_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/treedp.test.cpp
    title: verify/treedp.test.cpp
  - icon: ':heavy_check_mark:'
    path: "\u7802\u5834/swag.test.cpp"
    title: "\u7802\u5834/swag.test.cpp"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: modint
    links: []
  bundledCode: "#line 1 \"Utility/modint.hpp\"\n\n// \u52D5\u7684mod : template<int\
    \ mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\
    \u5BA3\u8A00\ntemplate <uint32_t mod> struct modint {\n    using mm = modint;\n\
    \    uint32_t x;\n    modint() : x(0) {}\n    TT modint(T a = 0) : x((ll(a) %\
    \ mod + mod)) {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm\
    \ a, mm b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n     \
    \   return a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n\
    \        if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    mm operator-()\
    \ const { return mod - x; }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\
    \u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\
    \u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x) *\
    \ b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n    friend mm &operator/=(mm &a, mm b) { return a = a * b.inv();\
    \ }\n\n    mm inv() const {\n        assert(x != 0);\n        return pow(mod -\
    \ 2);\n    }\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n\
    \        while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n\
    \            y /= 2;\n        }\n        return res;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mm &a) {\n        ll t;\n        cin >> t;\n      \
    \  a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n"
  code: "\n// \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\
    \u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    mm operator-() const { return mod - x;\
    \ }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\
    \u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend\
    \ mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const {\n        assert(x\
    \ != 0);\n        return pow(mod - 2);\n    }\n    mm pow(ll y) const {\n    \
    \    mm res = 1;\n        mm v = *this;\n        while (y) {\n            if (y\
    \ & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n      \
    \  return res;\n    }\n\n    friend istream &operator>>(istream &is, mm &a) {\n\
    \        ll t;\n        cin >> t;\n        a = mm(t);\n        return is;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os << a.x;\
    \ }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utility/modint.hpp
  requiredBy:
  - Graph/Chromatic_Number.hpp
  - example/matrix.example.cpp
  timestamp: '2024-12-03 09:45:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Math_matrix_inv.test.cpp
  - verify/Chromatic_Number.test.cpp
  - verify/Datastructure_dynamicseg.test.cpp
  - verify/superset_transform.test.cpp
  - verify/Datastructure_swag.test.cpp
  - verify/dijkstra.test.cpp
  - verify/Math_matrix_pow.test.cpp
  - verify/Convolution_lcm_convolution.test.cpp
  - verify/Datastructure_lazysegtree.test.cpp
  - verify/bellman_ford.test.cpp
  - verify/Math_matrix_det.test.cpp
  - verify/Math_combination_more.test.cpp
  - verify/mat_det.test.cpp
  - verify/bitwise_and_convolution.test.cpp
  - verify/matrix.test.cpp
  - verify/Datastructure_seg_prod.test.cpp
  - verify/treedp.test.cpp
  - verify/Math_matrix_rank.test.cpp
  - verify/Datastructure_swag_more.test.cpp
  - verify/Datastructure_treap.test.cpp
  - "\u7802\u5834/swag.test.cpp"
documentation_of: Utility/modint.hpp
layout: document
redirect_from:
- /library/Utility/modint.hpp
- /library/Utility/modint.hpp.html
title: modint
---
