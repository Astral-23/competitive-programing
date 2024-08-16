---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/binarytrie.hpp
    title: binary_trie
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/binary_trie.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/binarytrie.hpp\"\
    \ntemplate<typename X, typename S, int W>\nstruct binary_trie {\n    struct Node\
    \ {\n          Node* l = nullptr;\n          Node* r = nullptr;\n          S s\
    \ = 0; \n          X lazy = 0;\n          Node (){}\n    };\n\n\tbinary_trie(){}\n\
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
    \ binary_trie\n@docs doc/binarytrie.md\n*/\n#line 4 \"verify/binary_trie.test.cpp\"\
    \n\nint main() {\n    binary_trie<int, int, 25> tr;\n    int n, q;\n    cin >>\
    \ n >> q;\n    string t;\n    cin >> t;\n    rep(i, 0, n) if(t[i] == '1') tr.insert(i,\
    \ 1);\n\n    while(q--) {\n        int ty, k;\n        cin >> ty >> k;\n     \
    \   if(ty == 0) {\n            if(!tr.count(k)) tr.insert(k, 1);\n        }\n\
    \        else if(ty == 1) {\n            int cnt = tr.count(k);\n            if(cnt\
    \ > 0) tr.erase(k, 1);\n        }\n        else if(ty == 2) {\n            if(tr.count(k))\
    \ cout << 1 << '\\n';\n            else cout << 0 << '\\n';\n        }\n     \
    \   else if(ty == 3) {\n            cout << tr.lower_bound(k) << '\\n';\n    \
    \    }\n        else {\n            cout << tr.lower_left_bound(k) << \"\\n\"\
    ;\n\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/binarytrie.hpp\"\
    \n\nint main() {\n    binary_trie<int, int, 25> tr;\n    int n, q;\n    cin >>\
    \ n >> q;\n    string t;\n    cin >> t;\n    rep(i, 0, n) if(t[i] == '1') tr.insert(i,\
    \ 1);\n\n    while(q--) {\n        int ty, k;\n        cin >> ty >> k;\n     \
    \   if(ty == 0) {\n            if(!tr.count(k)) tr.insert(k, 1);\n        }\n\
    \        else if(ty == 1) {\n            int cnt = tr.count(k);\n            if(cnt\
    \ > 0) tr.erase(k, 1);\n        }\n        else if(ty == 2) {\n            if(tr.count(k))\
    \ cout << 1 << '\\n';\n            else cout << 0 << '\\n';\n        }\n     \
    \   else if(ty == 3) {\n            cout << tr.lower_bound(k) << '\\n';\n    \
    \    }\n        else {\n            cout << tr.lower_left_bound(k) << \"\\n\"\
    ;\n\n        }\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/binarytrie.hpp
  isVerificationFile: true
  path: verify/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/binary_trie.test.cpp
- /verify/verify/binary_trie.test.cpp.html
title: verify/binary_trie.test.cpp
---
