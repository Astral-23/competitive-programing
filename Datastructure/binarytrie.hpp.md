---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: "\u7802\u5834/binarytrie.example.cpp"
    title: "\u7802\u5834/binarytrie.example.cpp"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/binary_trie.test.cpp
    title: verify/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/binary_trie_xor.test.cpp
    title: verify/binary_trie_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/binarytrie.md
    document_title: binary_trie
    links: []
  bundledCode: "#line 1 \"Datastructure/binarytrie.hpp\"\ntemplate<typename X, typename\
    \ S, int W>\nstruct binary_trie {\n    struct Node {\n          Node* l = nullptr;\n\
    \          Node* r = nullptr;\n          S s = 0; \n          X lazy = 0;\n  \
    \        Node (){}\n    };\n\n\tbinary_trie(){}\n\n    using np = Node*;\n\t\n\
    \    np root = new Node;//Binary_Trie_Tree\u306E\u6839\u3092\u8868\u3059\u30CE\
    \u30FC\u30C9\u3002\n\n    private:\n        void eval(np t, int d) {\n       \
    \     X x = t -> lazy;\n            if(d != W && x != 0) {\n                if(t\
    \ -> l)t -> l -> lazy ^= x;\n                if(t -> r)t -> r -> lazy ^= x;\n\
    \          \n                if(x >> (W - d - 1) & 1) {\n\t\t\t\t    swap(t ->\
    \ l, t -> r);\n\t\t\t    }\n\t\t\t}\n            t -> lazy = 0;\n            return\
    \ ;\n        }    \n    \n        void search_ie(np &t, S c, ll x, int d) {\n\t\
    \t    if(!t) t = new Node;\n            eval(t, d);\n            t -> s += c;\n\
    \            assert(t -> s >= 0);\n            if(d != W) {\n                if(x\
    \ >> (W - d - 1) & 1) search_ie(t -> r, c, x, d + 1);\n                else search_ie(t\
    \ -> l,  c, x, d + 1);\n\t\t\t}\n            return ;\n        }\n\n        ll\
    \ search_maix(np t, bool M, int d) {\n\t\t    ll res = 0;\n\t\t    while(d < W)\
    \ {\n                eval(t, d);\n                if(M) {\n\t\t\t\t\tif(t -> r\
    \ && t -> r -> s != 0) {\n\t\t\t\t\t\tres += 1LL << (W - d - 1);\n\t\t\t\t\t\t\
    t = t -> r;\n\t\t\t\t\t}\n\t\t\t\t\telse t = t -> l;\n                }\n    \
    \            else {\n                    if(t -> l && t -> l -> s != 0) {\n\t\t\
    \t\t\t\tt = t -> l;\n\t\t\t\t\t}\n                    else {\n\t\t\t\t\t\tres\
    \ += 1LL << (W - d - 1);\n\t\t\t\t\t\tt = t -> r;\n\t\t\t\t\t} \n            \
    \    }\n                ++d;\n\t\t\t}\n\t\t\treturn res;\n        }\n        \n\
    \    \n    public:\n        void insert(ll x, S cnt) {\n            if(cnt) search_ie(root,\
    \ cnt, x, 0);\n        }\n    \n        void erase(ll x, S cnt) {\n          \
    \  if(cnt) search_ie(root, cnt * -1, x, 0);\n        }\n        \n        S count(ll\
    \ x) {\n            np t = root;\n            int d = 0;\n            while(d\
    \ < W) {\n                if(!t) break;\n                eval(t, d);\n       \
    \         if(t -> s == 0) break;\n                if(x >> (W - d - 1) & 1) t =\
    \ t -> r;\n                else t = t -> l;\n                d++;\n          \
    \  }\n            if(t) return t -> s;\n            else return 0;\n        }\n\
    \    \n        ll max_element() {\n            assert(root -> s > 0);\n      \
    \      return search_maix(root, 1, 0);\n        }\n    \n        ll min_element()\
    \ {\n            assert(root -> s > 0);\n            return search_maix(root,\
    \ 0, 0);\n        }\n    \n        ll kth_element(S k) {\n            assert(k\
    \ < size());\n            np t = root;\n            int d = 0;\n            ll\
    \ res = 0;\n\t\t\twhile(d < W) {\n\t\t\t\teval(t, d);\n                if(t ->\
    \ l && t -> l -> s >= k + 1) {\n\t\t\t\t\tt = t -> l;\n\t\t\t\t}\n           \
    \     else {\n\t\t\t\t\tif(t -> l) k -= t -> l -> s;\n\t\t\t\t\tres += 1LL <<\
    \ (W - d - 1);\n\t\t\t\t\tt = t -> r;\n                }\n\t\t\t\t++d;\n\t\t\t\
    }\n\t\t\treturn res;\n        }\n\n        S order_of_key(ll key) {//key\u672A\
    \u6E80\u306E\u6570\u5B57\u306E\u500B\u6570\n            np t = root;\n       \
    \     int d = 0;\n            S res = 0;\n            while(d < W) {\n       \
    \         if(!t) break;\n                eval(t, d);\n                if(key >>\
    \ (W - d - 1) & 1) {\n                    if(t -> l) res += t -> l -> s;\n   \
    \                 t = t -> r;\n                }\n                else {\n   \
    \                 t = t -> l;\n                }\n                d++;\n     \
    \       }\n            return res;\n        }\n\n        ll upper_bound(ll x)\
    \ {\n            S p = order_of_key(x+1);\n            if(p >= size()) return\
    \ -1;\n            else return kth_element(p);\n        }\n\n        ll lower_bound(ll\
    \ x) {\n            return upper_bound(--x);\n        }\n\n        ll upper_left_bound(ll\
    \ x) {\n            if(empty()) return -1;\n            if(min_element() >= x)\
    \ return -1;\n            S p = order_of_key(x);\n            return kth_element(--p);\n\
    \        }\n\n        ll lower_left_bound(ll x) {\n            if(empty()) return\
    \ -1;\n            return upper_left_bound(++x);\n        }\n    \n        void\
    \ all_xor(X x) {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u5168\
    \u3066\u306Bx\u3092xor\u4F5C\u7528\u3055\u305B\u308B\n            if(root -> s\
    \ == 0) return;//\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\u3044\n          \
    \  root -> lazy ^= x;\n            eval(root, 0);\n        }\n        \n     \
    \   S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u306E\u7DCF\
    \u6570\n            return root -> s;\n        }\n\n        bool empty() {\n \
    \           return size() == 0;\n        }\n};    \n/*\n@brief binary_trie\n@docs\
    \ doc/binarytrie.md\n*/\n"
  code: "template<typename X, typename S, int W>\nstruct binary_trie {\n    struct\
    \ Node {\n          Node* l = nullptr;\n          Node* r = nullptr;\n       \
    \   S s = 0; \n          X lazy = 0;\n          Node (){}\n    };\n\n\tbinary_trie(){}\n\
    \n    using np = Node*;\n\t\n    np root = new Node;//Binary_Trie_Tree\u306E\u6839\
    \u3092\u8868\u3059\u30CE\u30FC\u30C9\u3002\n\n    private:\n        void eval(np\
    \ t, int d) {\n            X x = t -> lazy;\n            if(d != W && x != 0)\
    \ {\n                if(t -> l)t -> l -> lazy ^= x;\n                if(t -> r)t\
    \ -> r -> lazy ^= x;\n          \n                if(x >> (W - d - 1) & 1) {\n\
    \t\t\t\t    swap(t -> l, t -> r);\n\t\t\t    }\n\t\t\t}\n            t -> lazy\
    \ = 0;\n            return ;\n        }    \n    \n        void search_ie(np &t,\
    \ S c, ll x, int d) {\n\t\t    if(!t) t = new Node;\n            eval(t, d);\n\
    \            t -> s += c;\n            assert(t -> s >= 0);\n            if(d\
    \ != W) {\n                if(x >> (W - d - 1) & 1) search_ie(t -> r, c, x, d\
    \ + 1);\n                else search_ie(t -> l,  c, x, d + 1);\n\t\t\t}\n    \
    \        return ;\n        }\n\n        ll search_maix(np t, bool M, int d) {\n\
    \t\t    ll res = 0;\n\t\t    while(d < W) {\n                eval(t, d);\n   \
    \             if(M) {\n\t\t\t\t\tif(t -> r && t -> r -> s != 0) {\n\t\t\t\t\t\t\
    res += 1LL << (W - d - 1);\n\t\t\t\t\t\tt = t -> r;\n\t\t\t\t\t}\n\t\t\t\t\telse\
    \ t = t -> l;\n                }\n                else {\n                   \
    \ if(t -> l && t -> l -> s != 0) {\n\t\t\t\t\t\tt = t -> l;\n\t\t\t\t\t}\n   \
    \                 else {\n\t\t\t\t\t\tres += 1LL << (W - d - 1);\n\t\t\t\t\t\t\
    t = t -> r;\n\t\t\t\t\t} \n                }\n                ++d;\n\t\t\t}\n\t\
    \t\treturn res;\n        }\n        \n    \n    public:\n        void insert(ll\
    \ x, S cnt) {\n            if(cnt) search_ie(root, cnt, x, 0);\n        }\n  \
    \  \n        void erase(ll x, S cnt) {\n            if(cnt) search_ie(root, cnt\
    \ * -1, x, 0);\n        }\n        \n        S count(ll x) {\n            np t\
    \ = root;\n            int d = 0;\n            while(d < W) {\n              \
    \  if(!t) break;\n                eval(t, d);\n                if(t -> s == 0)\
    \ break;\n                if(x >> (W - d - 1) & 1) t = t -> r;\n             \
    \   else t = t -> l;\n                d++;\n            }\n            if(t) return\
    \ t -> s;\n            else return 0;\n        }\n    \n        ll max_element()\
    \ {\n            assert(root -> s > 0);\n            return search_maix(root,\
    \ 1, 0);\n        }\n    \n        ll min_element() {\n            assert(root\
    \ -> s > 0);\n            return search_maix(root, 0, 0);\n        }\n    \n \
    \       ll kth_element(S k) {\n            assert(k < size());\n            np\
    \ t = root;\n            int d = 0;\n            ll res = 0;\n\t\t\twhile(d <\
    \ W) {\n\t\t\t\teval(t, d);\n                if(t -> l && t -> l -> s >= k + 1)\
    \ {\n\t\t\t\t\tt = t -> l;\n\t\t\t\t}\n                else {\n\t\t\t\t\tif(t\
    \ -> l) k -= t -> l -> s;\n\t\t\t\t\tres += 1LL << (W - d - 1);\n\t\t\t\t\tt =\
    \ t -> r;\n                }\n\t\t\t\t++d;\n\t\t\t}\n\t\t\treturn res;\n     \
    \   }\n\n        S order_of_key(ll key) {//key\u672A\u6E80\u306E\u6570\u5B57\u306E\
    \u500B\u6570\n            np t = root;\n            int d = 0;\n            S\
    \ res = 0;\n            while(d < W) {\n                if(!t) break;\n      \
    \          eval(t, d);\n                if(key >> (W - d - 1) & 1) {\n       \
    \             if(t -> l) res += t -> l -> s;\n                    t = t -> r;\n\
    \                }\n                else {\n                    t = t -> l;\n\
    \                }\n                d++;\n            }\n            return res;\n\
    \        }\n\n        ll upper_bound(ll x) {\n            S p = order_of_key(x+1);\n\
    \            if(p >= size()) return -1;\n            else return kth_element(p);\n\
    \        }\n\n        ll lower_bound(ll x) {\n            return upper_bound(--x);\n\
    \        }\n\n        ll upper_left_bound(ll x) {\n            if(empty()) return\
    \ -1;\n            if(min_element() >= x) return -1;\n            S p = order_of_key(x);\n\
    \            return kth_element(--p);\n        }\n\n        ll lower_left_bound(ll\
    \ x) {\n            if(empty()) return -1;\n            return upper_left_bound(++x);\n\
    \        }\n    \n        void all_xor(X x) {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\
    \u308B\u8981\u7D20\u5168\u3066\u306Bx\u3092xor\u4F5C\u7528\u3055\u305B\u308B\n\
    \            if(root -> s == 0) return;//\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\
    \u3044\n            root -> lazy ^= x;\n            eval(root, 0);\n        }\n\
    \        \n        S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\
    \u7D20\u306E\u7DCF\u6570\n            return root -> s;\n        }\n\n       \
    \ bool empty() {\n            return size() == 0;\n        }\n};    \n/*\n@brief\
    \ binary_trie\n@docs doc/binarytrie.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/binarytrie.hpp
  requiredBy:
  - "\u7802\u5834/binarytrie.example.cpp"
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/binary_trie_xor.test.cpp
  - verify/binary_trie.test.cpp
documentation_of: Datastructure/binarytrie.hpp
layout: document
redirect_from:
- /library/Datastructure/binarytrie.hpp
- /library/Datastructure/binarytrie.hpp.html
title: binary_trie
---
## 概要
binary trie

## 使用例
```
#include "../Utility/template.hpp"
#include "../Datastructure/binarytrie.hpp"

int main() {
    binary_trie<int, int,30> tr;
    //xorの型がint, 個数の型がint, 2 ^ 30未満の要素を格納できる 空の binary_trieを宣言


    tr.insert(10, 1);//10を1つ挿入
    tr.insert(15, 1);
    tr.insert(20, 1);//{10, 15, 20}
    
    cout << tr.order_of_key(10) << endl;//0番目
    cout << tr.order_of_key(15) << endl;//1番目
    cout << tr.order_of_key(12) << endl;//12未満の個数を返すので、1を返す

    cout << tr.kth_element(1) << endl; //15
    // cout << tr.kth_element(3) << endl; 要素数より大きい値はassert

    tr.insert(15, 2); // {10, 15, 15, 15, 20}
    cout << tr.order_of_key(15) << endl;//1
    

    cout << tr.lower_bound(15) << endl;//15  自分以上 
    cout << tr.upper_bound(15) << endl;//20  自分超過
    cout << tr.lower_bound(25) << endl;//-1 存在しない時

    cout << tr.upper_left_bound(15) << endl;//10 自分未満
    cout << tr.lower_left_bound(15) << endl;//15 自分以下

    tr.all_xor(1);//全てに1をxor。 {11, 14, 14, 14, 21}
    cout << tr.min_element() << endl; //11
    cout << tr.count(14) << endl; //3個
    cout << tr.max_element() << endl; //21

    //tr.erase(11, 3);//消しすぎるとassert
    tr.erase(11, 1);
    tr.erase(14, 3);
    tr.erase(21, 1);

    //cout << tr.max_element() << endl;//空の時 max/minを呼ぶとassert


}
```