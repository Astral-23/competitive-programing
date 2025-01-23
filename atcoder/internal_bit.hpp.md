---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/sieve2.hpp
    title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
  - icon: ':warning:'
    path: Others/icpc_template.hpp
    title: Others/icpc_template.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':warning:'
    path: verify/Convolution_gcd_convolution_test.cpp
    title: verify/Convolution_gcd_convolution_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Convolution_gcd_convolution.test.cpp
    title: verify/Convolution_gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination.test.cpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination_more.test.cpp
    title: verify/Math_combination_more.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_count_subset_sum.test.cpp
    title: verify/fps_count_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_exp.test.cpp
    title: verify/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_inv.test.cpp
    title: verify/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_log.test.cpp
    title: verify/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps_pow.test.cpp
    title: verify/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus\
    \ >= 202002L\n\nusing std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\n\
    unsigned int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x\
    \ < (unsigned int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <=\
    \ n`\n// @return same with std::bit::countr_zero\nint countr_zero(unsigned int\
    \ n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n//\
    \ @param n `1 <= n`\n// @return same with std::bit::countr_zero\nconstexpr int\
    \ countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1\
    \ << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_bit.hpp
  requiredBy:
  - Math/sieve2.hpp
  - verify/Convolution_gcd_convolution_test.cpp
  - atcoder/convolution.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/segtree.hpp
  - Others/icpc_template.hpp
  timestamp: '2024-12-22 14:16:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps_count_subset_sum.test.cpp
  - verify/fps_pow.test.cpp
  - verify/fps_inv.test.cpp
  - verify/fps_exp.test.cpp
  - verify/Math_combination.test.cpp
  - verify/Math_combination_more.test.cpp
  - verify/fps_log.test.cpp
  - verify/Convolution_gcd_convolution.test.cpp
documentation_of: atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/atcoder/internal_bit.hpp
- /library/atcoder/internal_bit.hpp.html
title: atcoder/internal_bit.hpp
---
