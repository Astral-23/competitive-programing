---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/sieve2.hpp
    title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
  - icon: ':warning:'
    path: Others/icpc_template.hpp
    title: Others/icpc_template.hpp
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
  bundledCode: "#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
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
    \ atcoder\n\n\n#line 10 \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\n#if\
    \ __cplusplus >= 201703L\n\ntemplate <class S, auto op, auto e> struct segtree\
    \ {\n    static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>,\n                  \"op must work as S(S, S)\");\n    static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                  \"e must work as S()\");\n\n#else\n\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n\n#endif\n\n  public:\n\
    \    segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)internal::bit_ceil((unsigned int)(_n));\n        log\
    \ = internal::countr_zero((unsigned int)size);\n        d = std::vector<S>(2 *\
    \ size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    \
    \    for (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n\
    \    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n    \
    \    p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) const {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n \
    \       l += size;\n        r += size;\n\n        while (l < r) {\n          \
    \  if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n    template <class F> int max_right(int l, F\
    \ f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n  \
    \      if (l == _n) return _n;\n        l += size;\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_SEGTREE_HPP\n#define ATCODER_SEGTREE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\n#include \"atcoder/internal_bit\"\
    \n\nnamespace atcoder {\n\n#if __cplusplus >= 201703L\n\ntemplate <class S, auto\
    \ op, auto e> struct segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n\n#else\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n\n#endif\n\n  public:\n    segtree() : segtree(0)\
    \ {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        size = (int)internal::bit_ceil((unsigned\
    \ int)(_n));\n        log = internal::countr_zero((unsigned int)size);\n     \
    \   d = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    template <bool (*f)(S)> int max_right(int l) const {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = e();\n  \
    \      do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n#endif  // ATCODER_SEGTREE_HPP\n"
  dependsOn:
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: atcoder/segtree.hpp
  requiredBy:
  - Math/sieve2.hpp
  - verify/Convolution_gcd_convolution_test.cpp
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
documentation_of: atcoder/segtree.hpp
layout: document
redirect_from:
- /library/atcoder/segtree.hpp
- /library/atcoder/segtree.hpp.html
title: atcoder/segtree.hpp
---
