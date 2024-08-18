---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: doc/offset_manager.md
    document_title: offset_manager
    links: []
  bundledCode: "#line 1 \"Datastructure/offset_manager.hpp\"\nTT struct offset_manager\
    \ {\n    T offset;\n\n    offset_manager() {\n        offset = T();\n    }\n\n\
    \    void add_all(T x) {\n        offset += x;\n    }\n\n    T push(T x) {// \u751F\
    \u306E\u5024 \u2192 \u88DC\u6B63\u5024\n        return x - offset;\n    }\n\n\
    \    T pop(T x) {// \u88DC\u6B63\u5024 \u2192 \u751F\u306E\u5024\n        return\
    \ x + offset;\n    }\n};\n\n/*\n@brief offset_manager\n@docs doc/offset_manager.md\n\
    */\n"
  code: "TT struct offset_manager {\n    T offset;\n\n    offset_manager() {\n   \
    \     offset = T();\n    }\n\n    void add_all(T x) {\n        offset += x;\n\
    \    }\n\n    T push(T x) {// \u751F\u306E\u5024 \u2192 \u88DC\u6B63\u5024\n \
    \       return x - offset;\n    }\n\n    T pop(T x) {// \u88DC\u6B63\u5024 \u2192\
    \ \u751F\u306E\u5024\n        return x + offset;\n    }\n};\n\n/*\n@brief offset_manager\n\
    @docs doc/offset_manager.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/offset_manager.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Datastructure/offset_manager.hpp
layout: document
redirect_from:
- /library/Datastructure/offset_manager.hpp
- /library/Datastructure/offset_manager.hpp.html
title: offset_manager
---
## 概要
データ構造に対し、登録されている値全体へのaddをO(1)で可能にするための補助構造体。<br>
offset(補正値)を管理する。

## 注意
inf(10 ^ 18)を 10 ^ 5回add とかするとオーバーフロウで壊れる

## 集約値への反映
sum ... 変換値のsum + offset * データ個数

max ... 変換値のmax + offset
-  個数制限付きナップザック(limited_knapsack)はこれを用いた。

