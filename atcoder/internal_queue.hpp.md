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
  - icon: ':question:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':question:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':warning:'
    path: verify/Convolution_gcd_convolution_test.cpp
    title: verify/Convolution_gcd_convolution_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Convolution_gcd_convolution.test.cpp
    title: verify/Convolution_gcd_convolution.test.cpp
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/internal_queue.hpp\"\n\n\n\n#include <vector>\n\n\
    namespace atcoder {\n\nnamespace internal {\n\ntemplate <class T> struct simple_queue\
    \ {\n    std::vector<T> payload;\n    int pos = 0;\n    void reserve(int n) {\
    \ payload.reserve(n); }\n    int size() const { return int(payload.size()) - pos;\
    \ }\n    bool empty() const { return pos == int(payload.size()); }\n    void push(const\
    \ T& t) { payload.push_back(t); }\n    T& front() { return payload[pos]; }\n \
    \   void clear() {\n        payload.clear();\n        pos = 0;\n    }\n    void\
    \ pop() { pos++; }\n};\n\n}  // namespace internal\n\n}  // namespace atcoder\n\
    \n\n"
  code: "#ifndef ATCODER_INTERNAL_QUEUE_HPP\n#define ATCODER_INTERNAL_QUEUE_HPP 1\n\
    \n#include <vector>\n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate\
    \ <class T> struct simple_queue {\n    std::vector<T> payload;\n    int pos =\
    \ 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size() const {\
    \ return int(payload.size()) - pos; }\n    bool empty() const { return pos ==\
    \ int(payload.size()); }\n    void push(const T& t) { payload.push_back(t); }\n\
    \    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace atcoder\n\n#endif  // ATCODER_INTERNAL_QUEUE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_queue.hpp
  requiredBy:
  - Others/icpc_template.hpp
  - verify/Convolution_gcd_convolution_test.cpp
  - atcoder/maxflow.hpp
  - atcoder/mincostflow.hpp
  - Math/sieve2.hpp
  timestamp: '2024-12-22 14:16:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/fps_pow.test.cpp
  - verify/fps_exp.test.cpp
  - verify/Math_combination.test.cpp
  - verify/fps_inv.test.cpp
  - verify/Math_combination_more.test.cpp
  - verify/fps_count_subset_sum.test.cpp
  - verify/fps_log.test.cpp
  - verify/Convolution_gcd_convolution.test.cpp
documentation_of: atcoder/internal_queue.hpp
layout: document
redirect_from:
- /library/atcoder/internal_queue.hpp
- /library/atcoder/internal_queue.hpp.html
title: atcoder/internal_queue.hpp
---
