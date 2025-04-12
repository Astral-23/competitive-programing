---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/rangeset.hpp
    title: Datastructure/rangeset.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2880
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2880
  bundledCode: "#line 1 \"verify/Datastructure_rangeset.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Datastructure/rangeset.hpp\"\ntemplate <typename T, bool merge_adju>\
    \ struct rangeset : public std::map<T, T> {\n    rangeset() {}\n    auto get(T\
    \ p) const {\n        auto it = (*this).upper_bound(p);\n        if (it == (*this).begin()\
    \ || (--it)->second <= p) return (*this).end();\n        return it;\n    }\n\n\
    \    //[l, r)\n    pair<T, T> insert(T l, T r) {\n        if (l == r) return make_pair(l,\
    \ r);\n        assert(l <= r);\n        auto itl = (*this).upper_bound(l),\n \
    \            itr = (*this).lower_bound(r + merge_adju);\n        if (itl != (*this).begin()\
    \ && (--itl)->second + merge_adju <= l) {\n            ++itl;\n        }\n\n \
    \       if (itl != itr) {\n            if (itl->first < l) l = itl->first;\n \
    \           if (prev(itr)->second > r) r = prev(itr)->second;\n            map<T,\
    \ T>::erase(itl, itr);\n        }\n        (*this)[l] = r;\n        return make_pair(l,\
    \ r);\n    }\n\n    pair<T, T> insert(T p) { return insert(p, p + 1); }\n\n  \
    \  //[l, r)\n    void erase(T l, T r) {\n        if (l == r) return;\n       \
    \ assert(l <= r);\n        auto itl = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n\
    \        if (itl != (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n\
    \        }\n        if (itl == itr) return;\n        T tl = l, tr = r;\n     \
    \   if (itl->first < l) tl = itl->first;\n        if (prev(itr)->second > r) tr\
    \ = prev(itr)->second;\n        map<T, T>::erase(itl, itr);\n        if (tl <\
    \ l) (*this)[tl] = l;\n        if (tr > r) (*this)[r] = tr;\n    }\n\n    void\
    \ erase(T p) { erase(p, p + 1); }\n\n    // p\u3092\u542B\u3080\u533A\u9593\u304C\
    \u3042\u308B\u304B\n    bool contains(T p) const { return get(p) != (*this).end();\
    \ }\n\n    //[l, r)\u306E\u3046\u30611\u8981\u7D20\u3067\u3082\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\n    bool contains(T l, T r) const {\n        auto itl\
    \ = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n        if (itl !=\
    \ (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n        }\n\
    \        if (itl == itr)\n            return false;\n        else\n          \
    \  return true;\n    }\n\n    // a\u3068b\u3092\u5171\u306B\u542B\u3080\u533A\u9593\
    \u304C\u3042\u308B\u304B\n    bool same(T a, T b) const {\n        if (a > b)\
    \ swap(a, b);\n\n        auto it = get(a);\n        if (it == (*this).end()) return\
    \ false;\n        return b < it->second;\n    }\n\n    T mex(T x = 0) const {\n\
    \        auto it = get(x);\n        if (it == (*this).end())\n            return\
    \ x;\n        else\n            return it->second;\n    }\n\n    template <typename\
    \ TYPE, bool ME>\n    friend ostream &operator<<(ostream &os, rangeset<TYPE, ME>\
    \ const &rhs) {\n        for (auto [l, r] : rhs) os << \"[\" << l << \", \" <<\
    \ r << \")\";\n        return os;\n    }\n};\n#line 4 \"verify/Datastructure_rangeset.test.cpp\"\
    \n\nint main() {\n    ll n, m, q;\n    cin >> n >> m >> q;\n    using P = array<ll,\
    \ 4>;\n\n    rangeset<ll, false> rs;\n    vec<P> es;\n    rep(i, 0, m) {\n   \
    \     ll d, a, b;\n        cin >> d >> a >> b;\n        a--;\n        es.push_back(P{d,\
    \ 1, a, b});\n    }\n\n    rep(i, 0, q) {\n        ll e, s, t;\n        cin >>\
    \ e >> s >> t;\n        s--;\n        es.push_back(P{e, -i, s, t});\n    }\n\n\
    \    sort(all(es));\n    vec<ll> ans(q);\n    for (auto [d, type, a, b] : es)\
    \ {\n        if (type != 1) {\n            ll id = -type;\n            if(a >=\
    \ b - 1) ans[id] = true;\n            else ans[id] = rs.same(a, b - 1);\n    \
    \    } else {\n            rs.insert(a, b);\n        }\n    }\n\n    rep(i, 0,\
    \ q) {\n        if (ans[i]) {\n            cout << \"Yes\" << endl;\n        }\
    \ else {\n            cout << \"No\" << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Datastructure/rangeset.hpp\"\n\n\
    int main() {\n    ll n, m, q;\n    cin >> n >> m >> q;\n    using P = array<ll,\
    \ 4>;\n\n    rangeset<ll, false> rs;\n    vec<P> es;\n    rep(i, 0, m) {\n   \
    \     ll d, a, b;\n        cin >> d >> a >> b;\n        a--;\n        es.push_back(P{d,\
    \ 1, a, b});\n    }\n\n    rep(i, 0, q) {\n        ll e, s, t;\n        cin >>\
    \ e >> s >> t;\n        s--;\n        es.push_back(P{e, -i, s, t});\n    }\n\n\
    \    sort(all(es));\n    vec<ll> ans(q);\n    for (auto [d, type, a, b] : es)\
    \ {\n        if (type != 1) {\n            ll id = -type;\n            if(a >=\
    \ b - 1) ans[id] = true;\n            else ans[id] = rs.same(a, b - 1);\n    \
    \    } else {\n            rs.insert(a, b);\n        }\n    }\n\n    rep(i, 0,\
    \ q) {\n        if (ans[i]) {\n            cout << \"Yes\" << endl;\n        }\
    \ else {\n            cout << \"No\" << endl;\n        }\n    }\n}\n"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/rangeset.hpp
  isVerificationFile: true
  path: verify/Datastructure_rangeset.test.cpp
  requiredBy: []
  timestamp: '2025-04-03 05:20:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Datastructure_rangeset.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_rangeset.test.cpp
- /verify/verify/Datastructure_rangeset.test.cpp.html
title: verify/Datastructure_rangeset.test.cpp
---
