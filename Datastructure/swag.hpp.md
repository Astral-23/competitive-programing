---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/limited_knapsack.test.cpp
    title: verify/limited_knapsack.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/swag.test.cpp
    title: verify/swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/swag_more.test.cpp
    title: verify/swag_more.test.cpp
  - icon: ':heavy_check_mark:'
    path: "\u7802\u5834/swag.test.cpp"
    title: "\u7802\u5834/swag.test.cpp"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: doc/swag.md
    document_title: SWAG
    links: []
  bundledCode: "#line 1 \"Datastructure/swag.hpp\"\n\ntemplate<class S, S (*op)(S,\
    \ S)>  struct SWAG {\n    struct foldable_stack {\n        stack<S> data;\n  \
    \      stack<S> res;\n        foldable_stack(){}\n\n        void push(S a, int\
    \ type) {//type == 1 : \u914D\u5217\u306E\u53F3\u306B\u8FFD\u52A0\u3001\u3064\u307E\
    \u308AR  type == 0 : \u914D\u5217\u306E\u5DE6\u306B\u8FFD\u52A0\u3001\u3064\u307E\
    \u308AL \n            data.push(a);\n            if(!res.empty()) {\n        \
    \       if(type == 0) res.push(op(a, res.top()));//res\u304C\u7A7A\u306A\u3089\
    \u305D\u308C\u3092\u5165\u308C\u308B\n               else res.push(op(res.top(),\
    \ a));\n            }\n            else res.push(a);\n            return;\n  \
    \      }\n\n        void pop() {\n            assert(!data.empty());\n       \
    \     data.pop();\n            res.pop();\n            return;\n        }\n\n\
    \        S top() const {\n            assert(!data.empty());\n            return\
    \ data.top(); \n        }\n\n        S get() const { \n            assert(!data.empty());\n\
    \            return res.top(); \n        }\n\n        bool empty() {return data.empty();}\n\
    \        int size() {return data.size();}\n    };\n\n    \n    SWAG() {}\n   \
    \ foldable_stack L, R;\n    private:\n\n      void move(foldable_stack& s, foldable_stack&\
    \ t, int type) {//s\u306E\u8981\u7D20\u3092\u534A\u5206t\u306E\u8981\u7D20\u306B\
    \u79FB\u3059\u3002\u3053\u3053\u3067\u3001type == 0 : s = L, t = R  type == 1\
    \ s = R, t = L\n        assert(t.empty());\n        int oth = 1 - type;\n    \
    \    stack<S> tmp;\n        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()),\
    \ s.pop();\n        while(!s.empty()) t.push(s.top(), oth), s.pop(); \n      \
    \  while(!tmp.empty()) s.push(tmp.top(), type), tmp.pop(); \n      }\n    \n \
    \   public:\n      void push_front(S a) {\n          L.push(a, 0);\n      }\n\
    \  \n      void push_back(S a) {\n          R.push(a, 1);\n      }\n  \n     \
    \ void pop_front() {\n          assert(!L.empty() || !R.empty());\n          if(L.empty())\
    \ move(R, L, 1);\n          L.pop();\n      }\n  \n      void pop_back() {\n \
    \         assert(!L.empty() || !R.empty());\n          if(R.empty()) move(L, R,\
    \ 0);\n          R.pop();\n      }\n  \n\n      S get()  {\n        assert(!L.empty()\
    \ || !R.empty());\n        if(L.empty()) return R.get();\n        if(R.empty())\
    \ return L.get();\n        return op(L.get(), R.get());\n      }\n\n      int\
    \ size() {\n        return L.size() + R.size();\n      }\n\n      bool empty()\
    \ {\n        return size() == 0;\n      }\n};\n\n\n/*\n@brief SWAG\n@docs doc/swag.md\n\
    */\n"
  code: "\ntemplate<class S, S (*op)(S, S)>  struct SWAG {\n    struct foldable_stack\
    \ {\n        stack<S> data;\n        stack<S> res;\n        foldable_stack(){}\n\
    \n        void push(S a, int type) {//type == 1 : \u914D\u5217\u306E\u53F3\u306B\
    \u8FFD\u52A0\u3001\u3064\u307E\u308AR  type == 0 : \u914D\u5217\u306E\u5DE6\u306B\
    \u8FFD\u52A0\u3001\u3064\u307E\u308AL \n            data.push(a);\n          \
    \  if(!res.empty()) {\n               if(type == 0) res.push(op(a, res.top()));//res\u304C\
    \u7A7A\u306A\u3089\u305D\u308C\u3092\u5165\u308C\u308B\n               else res.push(op(res.top(),\
    \ a));\n            }\n            else res.push(a);\n            return;\n  \
    \      }\n\n        void pop() {\n            assert(!data.empty());\n       \
    \     data.pop();\n            res.pop();\n            return;\n        }\n\n\
    \        S top() const {\n            assert(!data.empty());\n            return\
    \ data.top(); \n        }\n\n        S get() const { \n            assert(!data.empty());\n\
    \            return res.top(); \n        }\n\n        bool empty() {return data.empty();}\n\
    \        int size() {return data.size();}\n    };\n\n    \n    SWAG() {}\n   \
    \ foldable_stack L, R;\n    private:\n\n      void move(foldable_stack& s, foldable_stack&\
    \ t, int type) {//s\u306E\u8981\u7D20\u3092\u534A\u5206t\u306E\u8981\u7D20\u306B\
    \u79FB\u3059\u3002\u3053\u3053\u3067\u3001type == 0 : s = L, t = R  type == 1\
    \ s = R, t = L\n        assert(t.empty());\n        int oth = 1 - type;\n    \
    \    stack<S> tmp;\n        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()),\
    \ s.pop();\n        while(!s.empty()) t.push(s.top(), oth), s.pop(); \n      \
    \  while(!tmp.empty()) s.push(tmp.top(), type), tmp.pop(); \n      }\n    \n \
    \   public:\n      void push_front(S a) {\n          L.push(a, 0);\n      }\n\
    \  \n      void push_back(S a) {\n          R.push(a, 1);\n      }\n  \n     \
    \ void pop_front() {\n          assert(!L.empty() || !R.empty());\n          if(L.empty())\
    \ move(R, L, 1);\n          L.pop();\n      }\n  \n      void pop_back() {\n \
    \         assert(!L.empty() || !R.empty());\n          if(R.empty()) move(L, R,\
    \ 0);\n          R.pop();\n      }\n  \n\n      S get()  {\n        assert(!L.empty()\
    \ || !R.empty());\n        if(L.empty()) return R.get();\n        if(R.empty())\
    \ return L.get();\n        return op(L.get(), R.get());\n      }\n\n      int\
    \ size() {\n        return L.size() + R.size();\n      }\n\n      bool empty()\
    \ {\n        return size() == 0;\n      }\n};\n\n\n/*\n@brief SWAG\n@docs doc/swag.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/swag.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/swag_more.test.cpp
  - verify/swag.test.cpp
  - verify/limited_knapsack.test.cpp
  - "\u7802\u5834/swag.test.cpp"
documentation_of: Datastructure/swag.hpp
layout: document
redirect_from:
- /library/Datastructure/swag.hpp
- /library/Datastructure/swag.hpp.html
title: SWAG
---
## 概要
値の集約ができるdeque。
名称について、SWAGと呼ばれる事が多い？
参考 : https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1

## コンストラクタ
**SWAG\<S, op\> swag** ... 空のswagを生成する。セグ木における単位元が必要無いことに注意。計算量 $O(1)$
- **S**
モノイドの型。

- **op**
S (*op) (S, S)
モノイドを2つ受け取り、その演算結果を返す関数を渡す。なお、演算に可換性は要求しない。

## 関数
全て、計算量は償却 $O(1)$
- dequeのpush/pop/size/empty... popは、要素数が0だとassertで落ちる。

- **S get()**... swagに入っているモノイドの集約結果を返す。要素数が0だとassertで落ちる。


