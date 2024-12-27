---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Algorithm/Mo.hpp
    title: "Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  - icon: ':x:'
    path: Datastructure/segtree.hpp
    title: segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"verify/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/Mo.hpp\"\
    \n\nstruct Mo {\n    int n, q;\n    vec<pair<int, int>> qs;\n    vec<int> qi;\n\
    \    Mo(int n, vec<pair<int, int>> qs) : n(n), q(qs.size()), qs(qs) {   \n   \
    \     qi = vec<int>(q);\n        iota(all(qi), 0);\n        int width = max<int>(1,\
    \ 1.0 * n / max(1.0, sqrt(q * 2.0 / 3.0)));\n        sort(all(qi), [&](int i,\
    \ int j) {\n            if(qs[i].first/width != qs[j].first/width) {\n       \
    \         return qs[i].first < qs[j].first;\n            }\n            else {\n\
    \                int g = qs[i].first / width;\n                if(g % 2 == 0)\
    \ {\n                    return qs[i].second < qs[j].second;\n               \
    \ }\n                else {\n                    return qs[i].second > qs[j].second;\n\
    \                }\n            }\n        });\n    }\n    \n    template<class\
    \ AL, class AR, class DL, class DR, class REM> void run(AL addL, AR addR, DL delL,\
    \ DR delR, REM rem) {\n        int l = 0, r = 0;\n        for(int i : qi) {\n\
    \            while(l > qs[i].first) addL(--l);\n            while(l < qs[i].first)\
    \ delL(l++);\n            while(r < qs[i].second)addR(r++);\n            while(r\
    \ > qs[i].second)delR(--r);\n            rem(i, l, r);            \n        }\n\
    \    }\n};\n\n/*\n@brief Mo\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n*/\n#line 1 \"\
    Datastructure/segtree.hpp\"\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\n    int n;\n    int sz;\n    vector<S> d;\n\n    segtree(int n) :\
    \ segtree(vector<S>(n, e())) {}\n\n    segtree(const vector<S> &v) : n((int)v.size()),\
    \ sz(1) {\n        while(sz < n) sz <<= 1;\n        d.resize(2*sz, e());\n   \
    \     rep(i, 0, n) {\n            d[sz+i] = v[i];\n        }\n        rrep(i,\
    \ 1, sz) d[i] = op(d[i<<1], d[i<<1|1]);\n    }\n\n    void set(int p, S x) {\n\
    \        assert(0 <= p && p < n);\n        p += sz;\n        d[p] = x;\n     \
    \   while(p > 1) {\n            p >>= 1;\n            d[p] = op(d[p<<1], d[p<<1|1]);\n\
    \        }\n    }\n\n    S get(int p) const {\n        assert(0 <= p && p < n);\n\
    \        return d[p + sz];\n    }\n\n    S prod(int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n    \
    \    l += sz;\n        r += sz;\n\n        while (l < r) {\n            if (l\
    \ & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template <class\
    \ F> int max_right(int l, F f) const {\n        assert(0 <= l && l <= n);\n  \
    \      assert(f(e()));\n        if (l == n) return n;\n        l += sz;\n    \
    \    S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n    \
    \        if (!f(op(sm, d[l]))) {\n                while (l < sz) {\n         \
    \           l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n       \
    \                 sm = op(sm, d[l]);\n                        l++;\n         \
    \           }\n                }\n                return l - sz;\n           \
    \ }\n            sm = op(sm, d[l]);\n            l++;\n        } while ((l & -l)\
    \ != l);\n        return n;\n    }\n\n    template <class F> int min_left(int\
    \ r, F f) const {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if (r == 0) return 0;\n        r += sz;\n        S sm = e();\n      \
    \  do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n   \
    \         if (!f(op(d[r], sm))) {\n                while (r < sz) {\n        \
    \            r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n  \
    \                      sm = op(d[r], sm);\n                        r--;\n    \
    \                }\n                }\n                return r + 1 - sz;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n    \n};\n/*\n@brief segtree\n@docs doc/segtree.md\n\
    */\n#line 6 \"verify/mo.test.cpp\"\nusing S = ll;\nS op(S l, S r) {return l +\
    \ r;}\nS e() {return 0;}\n\nll ans = 0;\nvec<ll> res;\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    res = vec<ll>(q);\n    vec<ll> A(n);\n    rep(i,\
    \ 0, n) cin >> A[i];\n\n    vec<ll> cmp = A;\n    sort(all(cmp));\n    cmp.erase(unique(all(cmp)),\
    \ cmp.end());\n\n    auto get = [&](int x) {\n        return lower_bound(all(cmp),\
    \ x) - cmp.begin();\n    };\n\n    segtree<S, op, e> seg(n);\n\n    auto addL\
    \ = [&](int id) {\n        int i = get(A[id]);\n        ans += seg.prod(0, i);\n\
    \        seg.set(i, seg.get(i) + 1);\n    };\n\n    auto addR = [&](int id) {\n\
    \        int i = get(A[id]);\n        ans += seg.prod(i + 1, n);\n        seg.set(i,\
    \ seg.get(i) + 1);\n    };\n\n    auto delL = [&](int id) {\n        int i = get(A[id]);\n\
    \        seg.set(i, seg.get(i) - 1);\n        ans -= seg.prod(0, i);\n    };\n\
    \n    auto delR = [&](int id) {\n        int i = get(A[id]);\n        seg.set(i,\
    \ seg.get(i) - 1);\n        ans -= seg.prod(i + 1, n);\n    };\n\n    auto rem\
    \ = [&](int id, int l, int r) {//id\u756A\u76EE\u306B\u683C\u7D0D\u3055\u308C\u305F\
    \u533A\u9593\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3059\u308B\u7B54\u3048\u3092\
    \u3069\u3046\u3059\u308B\u304B\u3002\n        res[id] = ans;\n    };\n\n    vec<pair<int,\
    \ int>> qs;\n    rep(i, 0, q) {\n        int l, r;\n        cin >> l >> r;\n \
    \       qs.emplace_back(l, r);\n    }\n\n    Mo mo(n, qs);\n    mo.run(addL, addR,\
    \ delL, delR, rem);\n\n    rep(i, 0, q) {\n        cout << res[i] << '\\n';\n\
    \    }\n\n}\n\n\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/Mo.hpp\"\n#include\
    \ \"../Datastructure/segtree.hpp\"\nusing S = ll;\nS op(S l, S r) {return l +\
    \ r;}\nS e() {return 0;}\n\nll ans = 0;\nvec<ll> res;\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    res = vec<ll>(q);\n    vec<ll> A(n);\n    rep(i,\
    \ 0, n) cin >> A[i];\n\n    vec<ll> cmp = A;\n    sort(all(cmp));\n    cmp.erase(unique(all(cmp)),\
    \ cmp.end());\n\n    auto get = [&](int x) {\n        return lower_bound(all(cmp),\
    \ x) - cmp.begin();\n    };\n\n    segtree<S, op, e> seg(n);\n\n    auto addL\
    \ = [&](int id) {\n        int i = get(A[id]);\n        ans += seg.prod(0, i);\n\
    \        seg.set(i, seg.get(i) + 1);\n    };\n\n    auto addR = [&](int id) {\n\
    \        int i = get(A[id]);\n        ans += seg.prod(i + 1, n);\n        seg.set(i,\
    \ seg.get(i) + 1);\n    };\n\n    auto delL = [&](int id) {\n        int i = get(A[id]);\n\
    \        seg.set(i, seg.get(i) - 1);\n        ans -= seg.prod(0, i);\n    };\n\
    \n    auto delR = [&](int id) {\n        int i = get(A[id]);\n        seg.set(i,\
    \ seg.get(i) - 1);\n        ans -= seg.prod(i + 1, n);\n    };\n\n    auto rem\
    \ = [&](int id, int l, int r) {//id\u756A\u76EE\u306B\u683C\u7D0D\u3055\u308C\u305F\
    \u533A\u9593\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u3059\u308B\u7B54\u3048\u3092\
    \u3069\u3046\u3059\u308B\u304B\u3002\n        res[id] = ans;\n    };\n\n    vec<pair<int,\
    \ int>> qs;\n    rep(i, 0, q) {\n        int l, r;\n        cin >> l >> r;\n \
    \       qs.emplace_back(l, r);\n    }\n\n    Mo mo(n, qs);\n    mo.run(addL, addR,\
    \ delL, delR, rem);\n\n    rep(i, 0, q) {\n        cout << res[i] << '\\n';\n\
    \    }\n\n}\n\n\n\n\n"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/Mo.hpp
  - Datastructure/segtree.hpp
  isVerificationFile: true
  path: verify/mo.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/mo.test.cpp
layout: document
redirect_from:
- /verify/verify/mo.test.cpp
- /verify/verify/mo.test.cpp.html
title: verify/mo.test.cpp
---
