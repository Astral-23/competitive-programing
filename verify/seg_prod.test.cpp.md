---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/segtree.hpp
    title: segtree
  - icon: ':question:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/seg_prod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\
    \n\n// \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\
    \u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    mm operator-() const { return mod - x;\
    \ }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\
    \u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\u3059\u3002\n\n    friend\
    \ mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n    friend mm &operator/=(mm\
    \ &a, mm b) { return a = a * b.inv(); }\n\n    mm inv() const {\n        assert(x\
    \ != 0);\n        return pow(mod - 2);\n    }\n    mm pow(ll y) const {\n    \
    \    mm res = 1;\n        mm v = *this;\n        while (y) {\n            if (y\
    \ & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n      \
    \  return res;\n    }\n\n    friend istream &operator>>(istream &is, mm &a) {\n\
    \        ll t;\n        cin >> t;\n        a = mm(t);\n        return is;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os << a.x;\
    \ }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line 4 \"verify/seg_prod.test.cpp\"\
    \n//#include \"../Datastructure/dynamicseg.hpp\"\n#line 1 \"Datastructure/segtree.hpp\"\
    \ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n    int n;\n \
    \   int sz;\n    vector<S> d;\n\n    segtree(int n) : segtree(vector<S>(n, e()))\
    \ {}\n\n    segtree(const vector<S> &v) : n((int)v.size()), sz(1) {\n        while(sz\
    \ < n) sz <<= 1;\n        d.resize(2*sz, e());\n        rep(i, 0, n) {\n     \
    \       d[sz+i] = v[i];\n        }\n        rrep(i, 1, sz) d[i] = op(d[i<<1],\
    \ d[i<<1|1]);\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p\
    \ < n);\n        p += sz;\n        d[p] = x;\n        while(p > 1) {\n       \
    \     p >>= 1;\n            d[p] = op(d[p<<1], d[p<<1|1]);\n        }\n    }\n\
    \n    S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p\
    \ + sz];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        S sml = e(), smr = e();\n        l += sz;\n    \
    \    r += sz;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n\
    \        if (l == n) return n;\n        l += sz;\n        S sm = e();\n      \
    \  do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l])))\
    \ {\n                while (l < sz) {\n                    l = (2 * l);\n    \
    \                if (f(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            sm = op(sm, d[l]);\n \
    \           l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n    template <class F> int min_left(int r, F f) const {\n        assert(0 <=\
    \ r && r <= n);\n        assert(f(e()));\n        if (r == 0) return 0;\n    \
    \    r += sz;\n        S sm = e();\n        do {\n            r--;\n         \
    \   while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n \
    \               while (r < sz) {\n                    r = (2 * r + 1);\n     \
    \               if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n    \n};\n\
    /*\n@brief segtree\n@docs doc/segtree.md\n*/\n#line 6 \"verify/seg_prod.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nstruct S{\n    mint a, b;\n    S(){}\n\
    \    S(mint d, mint t) : a(d), b(t){}\n};\n\nS op(S l, S r) {\n\tS res;\n    res.a\
    \ = l.a * r.a;\n    res.b = r.a * l.b + r.b;\n    return res;\n}\n\nS e() {\n\t\
    return S(1, 0);\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n    vec<ll>\
    \ A(N), B(N);\n    rep(i, 0, N) cin >> A[i] >> B[i];\n    vec<S> C(N);\n    rep(i,\
    \ 0, N) C[i] = S(A[i], B[i]);\n\n    segtree<S, op, e> seg(C);\n\n\n    while(Q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t==0) {\n            int p,\
    \ c, d;\n            cin >> p >> c >> d;\n            seg.set(p, S(c, d));\n \
    \       }\n        else {\n            int l, r, x;\n            cin >> l >> r\
    \ >> x;\n            auto [a, b] = seg.prod(l ,r);\n            cout << (x * a\
    \ + b).x << '\\n';\n        }\n    }\n   \n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n//#include\
    \ \"../Datastructure/dynamicseg.hpp\"\n#include \"../Datastructure/segtree.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nstruct S{\n    mint a, b;\n    S(){}\n\
    \    S(mint d, mint t) : a(d), b(t){}\n};\n\nS op(S l, S r) {\n\tS res;\n    res.a\
    \ = l.a * r.a;\n    res.b = r.a * l.b + r.b;\n    return res;\n}\n\nS e() {\n\t\
    return S(1, 0);\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n    vec<ll>\
    \ A(N), B(N);\n    rep(i, 0, N) cin >> A[i] >> B[i];\n    vec<S> C(N);\n    rep(i,\
    \ 0, N) C[i] = S(A[i], B[i]);\n\n    segtree<S, op, e> seg(C);\n\n\n    while(Q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t==0) {\n            int p,\
    \ c, d;\n            cin >> p >> c >> d;\n            seg.set(p, S(c, d));\n \
    \       }\n        else {\n            int l, r, x;\n            cin >> l >> r\
    \ >> x;\n            auto [a, b] = seg.prod(l ,r);\n            cout << (x * a\
    \ + b).x << '\\n';\n        }\n    }\n   \n\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Datastructure/segtree.hpp
  isVerificationFile: true
  path: verify/seg_prod.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/seg_prod.test.cpp
layout: document
redirect_from:
- /verify/verify/seg_prod.test.cpp
- /verify/verify/seg_prod.test.cpp.html
title: verify/seg_prod.test.cpp
---
