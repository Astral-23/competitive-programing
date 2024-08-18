---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Algorithm/limited_knapsack.hpp
    title: Algorithm/limited_knapsack.hpp
  - icon: ':x:'
    path: Datastructure/offset_manager.hpp
    title: offset_manager
  - icon: ':question:'
    path: Datastructure/swag.hpp
    title: SWAG
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp
  bundledCode: "#line 1 \"verify/limited_knapsack.test.cpp\"\n//#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp\"\n\
    #line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n\
    #define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x)\
    \ begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec = vector<T>;\n\
    template <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1 &x, T2 y)\
    \ {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/swag.hpp\"\n\ntemplate<class\
    \ S, S (*op)(S, S)>  struct SWAG {\n    struct foldable_stack {\n        stack<S>\
    \ data;\n        stack<S> res;\n        foldable_stack(){}\n\n        void push(S\
    \ a, int type) {//type == 1 : \u914D\u5217\u306E\u53F3\u306B\u8FFD\u52A0\u3001\
    \u3064\u307E\u308AR  type == 0 : \u914D\u5217\u306E\u5DE6\u306B\u8FFD\u52A0\u3001\
    \u3064\u307E\u308AL \n            data.push(a);\n            if(!res.empty())\
    \ {\n               if(type == 0) res.push(op(a, res.top()));//res\u304C\u7A7A\
    \u306A\u3089\u305D\u308C\u3092\u5165\u308C\u308B\n               else res.push(op(res.top(),\
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
    */\n#line 1 \"Datastructure/offset_manager.hpp\"\nTT struct offset_manager {\n\
    \    T offset;\n\n    offset_manager() {\n        offset = T();\n    }\n\n   \
    \ void add_all(T x) {\n        offset += x;\n    }\n\n    T push(T x) {// \u751F\
    \u306E\u5024 \u2192 \u88DC\u6B63\u5024\n        return x - offset;\n    }\n\n\
    \    T pop(T x) {// \u88DC\u6B63\u5024 \u2192 \u751F\u306E\u5024\n        return\
    \ x + offset;\n    }\n};\n\n/*\n@brief offset_manager\n@docs doc/offset_manager.md\n\
    */\n#line 1 \"Algorithm/limited_knapsack.hpp\"\n// O(nw)\n// require : offset_manager\
    \ / swag\n// constrains : V[i] >= 0, W[i] > 0 \n// if 0 >= W[i] && V[i] >= 0 \
    \ \u5168\u3066\u4F7F\u3046\u3002\n// if 0 >= V[i] && W[i] >= 0  \u4F7F\u308F\u306A\
    \u3044\n// if 0 >= V[i] && 0 >= W[i]  \u8CA0\u306E\u65B9\u5411\u3092\u6301\u3064\
    \u3002 mod\u3092 abs\u3067\u3084\u308B\u3002\u4ED6\u306B\u3042\u308B\uFF1F\n\n\
    \nll op_knapsack(ll l, ll r) {return max(l, r);}\nconst ll INF_k = 1001001001001001001;\n\
    \nll limited_knapsack(vec<ll> V, vec<ll> W, vec<ll> M, ll w) {\n    int n = V.size();\n\
    \    vec<ll> dp(w + 1, -INF_k);\n    dp[0] = 0;\n    rep(i, 0, n) {\n        assert(W[i]\
    \ > 0);\n        //assert(V[i] > 0);\n    }\n\n    rep(i, 0, n) {\n        vec<ll>\
    \ pre(w + 1, -INF_k);\n        swap(dp, pre);\n        rep(mod, 0, W[i]) {\n \
    \           offset_manager<ll> ofs;\n            SWAG<ll, op_knapsack> swag; \n\
    \n            rep(bi, 0, w + 1) {//\u4F7F\u3046\u500B\u6570\u306Emax\n       \
    \         ll si = bi * W[i] + mod;\n                if(si > w) break;\n\n    \
    \            ofs.add_all(V[i]);\n                ll v = pre[si];\n           \
    \     v = ofs.push(v); \n                swag.push_back(v);\n                if(bi\
    \ > M[i]) swag.pop_front();\n                if(swag.empty() == false) chmax(dp[si],\
    \ ofs.pop(swag.get()));\n            }\n        }\n    }\n\n\n    ll res = -1;\n\
    \    rep(i, 0, w + 1) chmax(res, dp[i]);\n\n    return res;\n}\n\n#line 6 \"verify/limited_knapsack.test.cpp\"\
    \nint main() { //O(NW)\n    ll n, w;\n    cin >> n >> w;\n    vec<ll> V(n), W(n),\
    \ M(n);\n    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];\n    cout << limited_knapsack(V,\
    \ W, M, w) << endl;\n\n    \n}\n"
  code: "//#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp\"\
    \n#include \"../Utility/template.hpp\" \n#include \"../Datastructure/swag.hpp\"\
    \n#include \"../Datastructure/offset_manager.hpp\"\n#include \"../Algorithm/limited_knapsack.hpp\"\
    \nint main() { //O(NW)\n    ll n, w;\n    cin >> n >> w;\n    vec<ll> V(n), W(n),\
    \ M(n);\n    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];\n    cout << limited_knapsack(V,\
    \ W, M, w) << endl;\n\n    \n}\n"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/swag.hpp
  - Datastructure/offset_manager.hpp
  - Algorithm/limited_knapsack.hpp
  isVerificationFile: true
  path: verify/limited_knapsack.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 17:06:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/limited_knapsack.test.cpp
layout: document
redirect_from:
- /verify/verify/limited_knapsack.test.cpp
- /verify/verify/limited_knapsack.test.cpp.html
title: verify/limited_knapsack.test.cpp
---
