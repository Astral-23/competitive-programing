---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/swag.hpp
    title: SWAG
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"\\u7802\\u5834/swag.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/swag.hpp\"\n\
    \ntemplate<class S, S (*op)(S, S)>  struct SWAG {\n    struct foldable_stack {\n\
    \        stack<S> data;\n        stack<S> res;\n        foldable_stack(){}\n\n\
    \        void push(S a, int type) {//type == 1 : \u914D\u5217\u306E\u53F3\u306B\
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
    */\n#line 1 \"Utility/modint.hpp\"\n\n// \u52D5\u7684mod : template<int mod> \u3092\
    \u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\
    \ntemplate <uint32_t mod> struct modint {\n    using mm = modint;\n    uint32_t\
    \ x;\n    modint() : x(0) {}\n    TT modint(T a = 0) : x((ll(a) % mod + mod))\
    \ {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm a, mm\
    \ b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n        return\
    \ a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n    \
    \    if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\
    \u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\
    \u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm\
    \ b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm b) {\
    \ return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return a = a\
    \ + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n    friend\
    \ mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const { return pow(mod\
    \ - 2); }\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n\
    \        while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n\
    \            y /= 2;\n        }\n        return res;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mm &a) {\n        ll t;\n        cin >> t;\n      \
    \  a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line\
    \ 5 \"\\u7802\\u5834/swag.test.cpp\"\n\nusing mint = modint998244353;\n\nstruct\
    \ S {\n    mint a, b;\n    S() {}\n    S(mint c, mint d) : a(c), b(d) {}\n};\n\
    \nS op(S l, S r) {\n    l.a *= r.a;\n    l.b *= r.a;\n    l.b += r.b;\n    return\
    \ l;\n}\n\n\nint main() {\n    SWAG<S, op> swag;\n    int q;\n    cin >> q;\n\
    \    while(q--) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n \
    \           mint a, b;\n            cin >> a >> b;\n            swag.push_back(S(a,\
    \ b));\n        }\n        else if(t == 1) {\n            swag.pop_front();\n\
    \        }\n        else {\n            mint x;\n            cin >> x;\n     \
    \       if(!swag.empty()) {\n              auto [a, b] = swag.get();\n       \
    \       cout << a * x + b << '\\n';\n            }\n            else {\n     \
    \           cout << x << '\\n';\n            }\n        } \n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/swag.hpp\"\
    \n#include \"../Utility/modint.hpp\"\n\nusing mint = modint998244353;\n\nstruct\
    \ S {\n    mint a, b;\n    S() {}\n    S(mint c, mint d) : a(c), b(d) {}\n};\n\
    \nS op(S l, S r) {\n    l.a *= r.a;\n    l.b *= r.a;\n    l.b += r.b;\n    return\
    \ l;\n}\n\n\nint main() {\n    SWAG<S, op> swag;\n    int q;\n    cin >> q;\n\
    \    while(q--) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n \
    \           mint a, b;\n            cin >> a >> b;\n            swag.push_back(S(a,\
    \ b));\n        }\n        else if(t == 1) {\n            swag.pop_front();\n\
    \        }\n        else {\n            mint x;\n            cin >> x;\n     \
    \       if(!swag.empty()) {\n              auto [a, b] = swag.get();\n       \
    \       cout << a * x + b << '\\n';\n            }\n            else {\n     \
    \           cout << x << '\\n';\n            }\n        } \n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/swag.hpp
  - Utility/modint.hpp
  isVerificationFile: true
  path: "\u7802\u5834/swag.test.cpp"
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: "\u7802\u5834/swag.test.cpp"
layout: document
redirect_from:
- "/verify/\u7802\u5834/swag.test.cpp"
- "/verify/\u7802\u5834/swag.test.cpp.html"
title: "\u7802\u5834/swag.test.cpp"
---
