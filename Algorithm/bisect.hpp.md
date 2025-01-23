---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Algorithm_bisect_max_right.test.cpp
    title: verify/Algorithm_bisect_max_right.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Algorithm_bisect_min_left.test.cpp
    title: verify/Algorithm_bisect_min_left.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/bisect.md
    document_title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"Algorithm/bisect.hpp\"\n\ntemplate <typename T, typename\
    \ F> T max_right(T l, T max_r_plus_one, F pred) {\n    assert(l < max_r_plus_one);\n\
    \n    if (!pred(l)) return l;\n\n    while (max_r_plus_one > l + 1) {\n      \
    \  T mid = ((l ^ max_r_plus_one) >> 1) + (l & max_r_plus_one);\n        (pred(mid)\
    \ ? l : max_r_plus_one) = mid;\n    }\n    return max_r_plus_one;\n};\n\ntemplate\
    \ <typename T, typename F> T min_left(T min_l, T r, F pred) {\n    assert(min_l\
    \ < r);\n\n    if (pred(min_l)) return min_l;\n\n    while (r > min_l + 1) {\n\
    \        T mid = ((min_l ^ r) >> 1) + (min_l & r);\n        (pred(mid) ? r : min_l)\
    \ = mid;\n    }\n    return r;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\
    \u7D22\n@docs doc/bisect.md\n*/\n"
  code: "\ntemplate <typename T, typename F> T max_right(T l, T max_r_plus_one, F\
    \ pred) {\n    assert(l < max_r_plus_one);\n\n    if (!pred(l)) return l;\n\n\
    \    while (max_r_plus_one > l + 1) {\n        T mid = ((l ^ max_r_plus_one) >>\
    \ 1) + (l & max_r_plus_one);\n        (pred(mid) ? l : max_r_plus_one) = mid;\n\
    \    }\n    return max_r_plus_one;\n};\n\ntemplate <typename T, typename F> T\
    \ min_left(T min_l, T r, F pred) {\n    assert(min_l < r);\n\n    if (pred(min_l))\
    \ return min_l;\n\n    while (r > min_l + 1) {\n        T mid = ((min_l ^ r) >>\
    \ 1) + (min_l & r);\n        (pred(mid) ? r : min_l) = mid;\n    }\n    return\
    \ r;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22\n@docs doc/bisect.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/bisect.hpp
  requiredBy: []
  timestamp: '2025-01-11 20:14:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Algorithm_bisect_max_right.test.cpp
  - verify/Algorithm_bisect_min_left.test.cpp
documentation_of: Algorithm/bisect.hpp
layout: document
redirect_from:
- /library/Algorithm/bisect.hpp
- /library/Algorithm/bisect.hpp.html
title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
---
## 概要
抽象化二分探索。  
[l, r)の **半開区間** に対して行う

## max_right
`[l, max_r_plus_one)` について、[oooxxx)を想定して二分探索
okになる右端 **+ 1**を返す(全部okならmax_r_plus_oneが帰る)  
- なので、「条件を満たす最大値」が欲しい場合、戻り値から-1する必要がある  

[使用例](https://judge.yosupo.jp/submission/258880)
## min_left 
`[min_l, r)`について、[xxxoooo)を想定して二分探索
okになる左端を返す
(全部ngならrを返す)
[使用例](https://atcoder.jp/contests/abc312/submissions/61216108)


イメージ: l,rがoとxの境目になっている。ただし、半開区間を加味しても、探索範囲内が全てo/xになっていた場合、ifで分岐している
両者とも、半開区間に含まれないところにはクエリが来ない