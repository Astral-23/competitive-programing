---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/bisect.test.cpp
    title: verify/bisect.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/bisect.md
    document_title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"Algorithm/bisect.hpp\"\ntemplate <typename T, typename F>\
    \ T bisect(T ok, T ng, F pred) {\n    if(ok <= ng) ng++;\n    else ng--;\n   \
    \ \n    if (!pred(ok)) return ok;\n\n    while (ng > ok + 1 || ok > ng + 1) {\n\
    \        T mid = midpoint(ok, ng);\n        (pred(mid) ? ok : ng) = mid;\n   \
    \ }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22\n\
    @docs doc/bisect.md\n*/\n"
  code: "template <typename T, typename F> T bisect(T ok, T ng, F pred) {\n    if(ok\
    \ <= ng) ng++;\n    else ng--;\n    \n    if (!pred(ok)) return ok;\n\n    while\
    \ (ng > ok + 1 || ok > ng + 1) {\n        T mid = midpoint(ok, ng);\n        (pred(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\
    \u5206\u63A2\u7D22\n@docs doc/bisect.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/bisect.hpp
  requiredBy: []
  timestamp: '2024-08-16 18:17:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

    - ok <= ngの時 : [ok, ng] で [oooxxxx]
        - 一番右のoを返す。
            - (1-1)[xxxx]の時
                - okを返す。
            - (1-2)[oooo]の時
                - ngを返す。
    - ok > ngの時 : [ng, ok]で[xxxooo]
        - 一番左のoを返す。ただし、
            - (2-1)[xxxx]の時
                - okを返す。
            - (2-2)[oooo]の時
                - ngを返す。
    - 総じて、[xxxx]の可能性がある場合、返り値をpredに入れて再度その値が有効か判定すると良い。逆に、[xxxx]でなければ、返り値は有効な値。