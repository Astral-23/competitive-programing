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
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
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
  bundledCode: "#line 1 \"atcoder/internal_csr.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\nnamespace atcoder {\nnamespace internal\
    \ {\n\ntemplate <class E> struct csr {\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)\n\
    \        : start(n + 1), elist(edges.size()) {\n        for (auto e : edges) {\n\
    \            start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n;\
    \ i++) {\n            start[i] += start[i - 1];\n        }\n        auto counter\
    \ = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_CSR_HPP\n#define ATCODER_INTERNAL_CSR_HPP 1\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace atcoder\
    \ {\nnamespace internal {\n\ntemplate <class E> struct csr {\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_INTERNAL_CSR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/internal_csr.hpp
  requiredBy:
  - Others/icpc_template.hpp
  - verify/Convolution_gcd_convolution_test.cpp
  - atcoder/internal_scc.hpp
  - atcoder/mincostflow.hpp
  - atcoder/twosat.hpp
  - atcoder/scc.hpp
  - Math/sieve2.hpp
  timestamp: '2024-12-22 14:16:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Convolution_gcd_convolution.test.cpp
  - verify/Math_combination_more.test.cpp
  - verify/Math_combination.test.cpp
  - verify/fps_log.test.cpp
  - verify/fps_count_subset_sum.test.cpp
  - verify/fps_exp.test.cpp
  - verify/fps_pow.test.cpp
  - verify/fps_inv.test.cpp
documentation_of: atcoder/internal_csr.hpp
layout: document
redirect_from:
- /library/atcoder/internal_csr.hpp
- /library/atcoder/internal_csr.hpp.html
title: atcoder/internal_csr.hpp
---
