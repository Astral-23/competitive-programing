---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Algorithm_bisect_max_right.test.cpp
    title: verify/Algorithm_bisect_max_right.test.cpp
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
documentation_of: Algorithm/bisect.hpp
layout: document
redirect_from:
- /library/Algorithm/bisect.hpp
- /library/Algorithm/bisect.hpp.html
title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
---
## 概要
抽象化二分探索。  
[ok, ng] 或いは [ng, ok] の **閉区間** に対して行う。

## 関数
- `template <typename T, typename F> T bisect(T ok, T ng, F pred) 
`
    - **計算量**
        - $O(\log \|ok - ng\|)$

    - **渡す関数**
        - `pred(T x)` ... xが条件を満たすならばtrue,でなければfalseを返す関数

    - **説明**

    - ok < ngの時 : [ok, ng] で [oooxxxx]
        - 一番右のoを返す。ただし、
            - (1-1)[xxxx]の時
                - ok-1を返す。
            - (1-2)[oooo]の時
                - ngを返す。
    - ok > ngの時 : [ng, ok] で [xxxooo]
        - 一番左のoを返す。ただし、
            - (2-1)[xxxx]の時
                - ok+1を返す。
            - (2-2)[oooo]の時
                - ngを返す。
    - ok = ngの時: [ok, ok]で [x] or [o]
            - (3-1)[x]の時
                - ok - 1 または ok + 1を返す
                    - 範囲から外れる事は保証されるが、どちらに外れるかは未定義
            - (3-2)[o]の時
                - okを返す
    - 総じて、[xxxx]の場合、返り値 x は [ok, ng] or [ng, ok]から外れる
        - 返り値が区間に入っているか確認すると良い
            - 逆に、[xxxx]でなければ、戻り値 x は [ok, ng] or [ng, ok]に入る。
        - 区間に入らない場合も「都合が良い」値が戻ってくることが多いが、区間長が1の時どちらに補正されるかわからないので、丁寧に書く