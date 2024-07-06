---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/binarytrie.hpp
    title: binary_trie
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i\
    \ < (ll)(t); i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n\
    #define TT template<typename T>\nTT using vec = vector<T>;\ntemplate<class T1,\
    \ class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }\n\
    template<class T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y,\
    \ true) : false; }\n\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line\
    \ 1 \"Datastructure/binarytrie.hpp\"\ntemplate<typename X, typename S, int W>\n\
    struct binary_trie {\n    struct Node {\n          Node* l = nullptr;\n      \
    \    Node* r = nullptr;\n          S s = 0; \n          X lazy = 0;\n        \
    \  Node (){}\n    };\n\n\tbinary_trie(){}\n\n    using np = Node*;\n\t\n    np\
    \ root = new Node;//Binary_Trie_Tree\u306E\u6839\u3092\u8868\u3059\u30CE\u30FC\
    \u30C9\u3002\n\n    private:\n        void eval(np t, int d) {\n            X\
    \ x = t -> lazy;\n            if(d != W && x != 0) {\n                if(t ->\
    \ l)t -> l -> lazy ^= x;\n                if(t -> r)t -> r -> lazy ^= x;\n   \
    \       \n                if(x >> (W - d - 1) & 1) {\n\t\t\t\t    swap(t -> l,\
    \ t -> r);\n\t\t\t    }\n\t\t\t}\n            t -> lazy = 0;\n            return\
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
    \ doc/binarytrie.md\n*/\n#line 3 \"\\u7802\\u5834/binarytrie.example.cpp\"\n\n\
    int main() {\n    binary_trie<int, int,30> tr;\n    //xor\u306E\u578B\u304Cint,\
    \ \u500B\u6570\u306E\u578B\u304Cint, 2 ^ 30\u672A\u6E80\u306E\u8981\u7D20\u3092\
    \u683C\u7D0D\u3067\u304D\u308B \u7A7A\u306E binary_trie\u3092\u5BA3\u8A00\n\n\n\
    \    tr.insert(10, 1);//10\u30921\u3064\u633F\u5165\n    tr.insert(15, 1);\n \
    \   tr.insert(20, 1);//{10, 15, 20}\n    \n    cout << tr.order_of_key(10) <<\
    \ endl;//0\u756A\u76EE\n    cout << tr.order_of_key(15) << endl;//1\u756A\u76EE\
    \n    cout << tr.order_of_key(12) << endl;//12\u672A\u6E80\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\u306E\u3067\u30011\u3092\u8FD4\u3059\n\n    cout << tr.kth_element(1)\
    \ << endl; //15\n    // cout << tr.kth_element(3) << endl; \u8981\u7D20\u6570\u3088\
    \u308A\u5927\u304D\u3044\u5024\u306Fassert\n\n    tr.insert(15, 2); // {10, 15,\
    \ 15, 15, 20}\n    cout << tr.order_of_key(15) << endl;//1\n    \n\n    cout <<\
    \ tr.lower_bound(15) << endl;//15  \u81EA\u5206\u4EE5\u4E0A \n    cout << tr.upper_bound(15)\
    \ << endl;//20  \u81EA\u5206\u8D85\u904E\n    cout << tr.lower_bound(25) << endl;//-1\
    \ \u5B58\u5728\u3057\u306A\u3044\u6642\n\n    cout << tr.upper_left_bound(15)\
    \ << endl;//10 \u81EA\u5206\u672A\u6E80\n    cout << tr.lower_left_bound(15) <<\
    \ endl;//15 \u81EA\u5206\u4EE5\u4E0B\n\n    tr.all_xor(1);//\u5168\u3066\u306B\
    1\u3092xor\u3002 {11, 14, 14, 14, 21}\n    cout << tr.min_element() << endl; //11\n\
    \    cout << tr.count(14) << endl; //3\u500B\n    cout << tr.max_element() <<\
    \ endl; //21\n\n    //tr.erase(11, 3);//\u6D88\u3057\u3059\u304E\u308B\u3068assert\n\
    \    tr.erase(11, 1);\n    tr.erase(14, 3);\n    tr.erase(21, 1);\n\n    //cout\
    \ << tr.max_element() << endl;//\u7A7A\u306E\u6642 max/min\u3092\u547C\u3076\u3068\
    assert\n\n\n}\n"
  code: "#include \"../Utility/template.hpp\"\n#include \"../Datastructure/binarytrie.hpp\"\
    \n\nint main() {\n    binary_trie<int, int,30> tr;\n    //xor\u306E\u578B\u304C\
    int, \u500B\u6570\u306E\u578B\u304Cint, 2 ^ 30\u672A\u6E80\u306E\u8981\u7D20\u3092\
    \u683C\u7D0D\u3067\u304D\u308B \u7A7A\u306E binary_trie\u3092\u5BA3\u8A00\n\n\n\
    \    tr.insert(10, 1);//10\u30921\u3064\u633F\u5165\n    tr.insert(15, 1);\n \
    \   tr.insert(20, 1);//{10, 15, 20}\n    \n    cout << tr.order_of_key(10) <<\
    \ endl;//0\u756A\u76EE\n    cout << tr.order_of_key(15) << endl;//1\u756A\u76EE\
    \n    cout << tr.order_of_key(12) << endl;//12\u672A\u6E80\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\u306E\u3067\u30011\u3092\u8FD4\u3059\n\n    cout << tr.kth_element(1)\
    \ << endl; //15\n    // cout << tr.kth_element(3) << endl; \u8981\u7D20\u6570\u3088\
    \u308A\u5927\u304D\u3044\u5024\u306Fassert\n\n    tr.insert(15, 2); // {10, 15,\
    \ 15, 15, 20}\n    cout << tr.order_of_key(15) << endl;//1\n    \n\n    cout <<\
    \ tr.lower_bound(15) << endl;//15  \u81EA\u5206\u4EE5\u4E0A \n    cout << tr.upper_bound(15)\
    \ << endl;//20  \u81EA\u5206\u8D85\u904E\n    cout << tr.lower_bound(25) << endl;//-1\
    \ \u5B58\u5728\u3057\u306A\u3044\u6642\n\n    cout << tr.upper_left_bound(15)\
    \ << endl;//10 \u81EA\u5206\u672A\u6E80\n    cout << tr.lower_left_bound(15) <<\
    \ endl;//15 \u81EA\u5206\u4EE5\u4E0B\n\n    tr.all_xor(1);//\u5168\u3066\u306B\
    1\u3092xor\u3002 {11, 14, 14, 14, 21}\n    cout << tr.min_element() << endl; //11\n\
    \    cout << tr.count(14) << endl; //3\u500B\n    cout << tr.max_element() <<\
    \ endl; //21\n\n    //tr.erase(11, 3);//\u6D88\u3057\u3059\u304E\u308B\u3068assert\n\
    \    tr.erase(11, 1);\n    tr.erase(14, 3);\n    tr.erase(21, 1);\n\n    //cout\
    \ << tr.max_element() << endl;//\u7A7A\u306E\u6642 max/min\u3092\u547C\u3076\u3068\
    assert\n\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/binarytrie.hpp
  isVerificationFile: false
  path: "\u7802\u5834/binarytrie.example.cpp"
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: "\u7802\u5834/binarytrie.example.cpp"
layout: document
redirect_from:
- "/library/\u7802\u5834/binarytrie.example.cpp"
- "/library/\u7802\u5834/binarytrie.example.cpp.html"
title: "\u7802\u5834/binarytrie.example.cpp"
---
