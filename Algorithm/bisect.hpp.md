---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/bisect.test.cpp
    title: verify/bisect.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/bisect.md
    document_title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"Algorithm/bisect.hpp\"\ntemplate <typename T, typename F>\
    \ T bisect(T ok, T ng, F pred) {\n    if (ok <= ng)\n        ng++;\n    else\n\
    \        ng--;\n\n    if (!pred(ok)) {\n        if(ok <= ng) {\n            return\
    \ ok - 1;\n        }\n        else {\n            return ok + 1;\n        }\n\
    \    }\n\n    while (ng > ok + 1 || ok > ng + 1) {\n        T mid = ((ok ^ ng)\
    \ >> 1) + (ok & ng);\n        (pred(mid) ? ok : ng) = mid;\n    }\n    return\
    \ ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22\n@docs doc/bisect.md\n\
    */\n"
  code: "template <typename T, typename F> T bisect(T ok, T ng, F pred) {\n    if\
    \ (ok <= ng)\n        ng++;\n    else\n        ng--;\n\n    if (!pred(ok)) {\n\
    \        if(ok <= ng) {\n            return ok - 1;\n        }\n        else {\n\
    \            return ok + 1;\n        }\n    }\n\n    while (ng > ok + 1 || ok\
    \ > ng + 1) {\n        T mid = ((ok ^ ng) >> 1) + (ok & ng);\n        (pred(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\
    \u5206\u63A2\u7D22\n@docs doc/bisect.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/bisect.hpp
  requiredBy: []
  timestamp: '2024-09-20 18:51:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/bisect.test.cpp
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