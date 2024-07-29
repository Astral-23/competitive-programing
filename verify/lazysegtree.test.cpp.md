---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/lazysegtree.hpp
    title: lazysegtree
  - icon: ':question:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/lazysegtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\u52D5\u7684mod :\
    \ template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\
    \u6570mod\u3092\u5BA3\u8A00\ntemplate<uint32_t mod>\nstruct modint{\n    using\
    \ mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n    TT modint(T a=0)\
    \ : x((ll(a) % mod + mod) % mod){}\n\n    friend mm operator+(mm a, mm b) {\n\
    \        a.x += b.x;\n        if(a.x >= mod) a.x -= mod;\n        return a;\n\
    \    }\n   friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if(a.x\
    \ >= mod) a.x += mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\
    \u5341\u5206\u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\
    \u826F\u3044\u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return\
    \ (uint64_t)(a.x) * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv();\
    \ }\n    friend mm& operator+=(mm& a, mm b) { return a = a + b; }\n    friend\
    \ mm& operator-=(mm& a, mm b) { return a = a - b; }\n    friend mm& operator*=(mm&\
    \ a, mm b) { return a = a * b; }\n    friend mm& operator/=(mm& a, mm b) { return\
    \ a = a * b.inv(); }\n\n    mm inv() const {return pow(mod-2);}\n    mm pow(const\
    \ ll& y) const {\n        if(!y) return 1;\n        mm res = pow(y >> 1);\n  \
    \      res *= res;\n        if(y & 1) res *= *this;\n        return res;\n   \
    \ }\n\n    friend istream& operator>>(istream &is, mm &a) { \n        ll t;\n\
    \        cin >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend\
    \ ostream& operator<<(ostream &os,  mm a) {\n        return os << a.x;\n    }\n\
    \n    bool operator==(mm a) {return x == a.x;}\n    bool operator!=(mm a) {return\
    \ x != a.x;}\n\n    //bool operator<(const mm& a) const {return x < a.x;}\n};\n\
    \nusing modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1'000'000'007>;\n\
    \n/*\n@brief modint\n*/\n#line 1 \"Datastructure/lazysegtree.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mp)(F, S), F (*cm)(F, F), F (*id)()>\n\
    struct lazysegtree {\n    int n;\n    int sz;\n    int log;\n    vec<S> d;\n \
    \   vec<F> lz;\n    lazysegtree(int n) : lazysegtree(vec<S>(n, e())) {}\n    lazysegtree(const\
    \ vec<S> &v) : n((int)(v.size())) {\n        log = 1;\n        while((1 << log)\
    \ < n) log++;\n        sz = 1 << log;\n        d.resize(2*sz, e());\n        lz.resize(2*sz,\
    \ id());\n        rep(i, 0, n) d[sz+i] = v[i];\n        rrep(i, 1, sz) update(i);\n\
    \    }\n\n    void update(int i) {\n        d[i] = op(d[i<<1], d[i<<1|1]);\n \
    \   }\n\n    void all_apply(int i, F f) {\n        d[i] = mp(f, d[i]);\n     \
    \   if(i < sz) lz[i] = cm(f, lz[i]);\n    }\n\n    void push(int k) {\n      \
    \  all_apply(k * 2, lz[k]);\n        all_apply(k * 2 + 1, lz[k]);\n        lz[k]\
    \ = id();\n    }\n\n    S prod(int l, int r, int k = 1, int L = 0, int R = -1)\
    \ {\n        if(R == -1) R = sz;\n        if(r <= L || R <= l) return e();\n \
    \       if(l <= L && R <= r) return d[k];\n        push(k);\n        int M = (L\
    \ + R) / 2;\n        return op(prod(l, r, k * 2, L, M), prod(l, r, k * 2 + 1,\
    \ M, R));\n    }\n\n    void apply(int l, int r, F f, int k = 1, int L = 0, int\
    \ R = -1) {\n        if(R == -1) R = sz;\n        if(r <= L || R <= l) return;\n\
    \        if(l <= L && R <= r) {\n            all_apply(k, f);\n            return;\n\
    \        }\n        push(k);\n        int M = (L + R) / 2;\n        apply(l, r,\
    \ f, k * 2, L, M); apply(l, r, f, k * 2 + 1, M, R);\n        update(k);\n    }\n\
    \    \n    //\u4EE5\u4E0B\u3001\u5FC5\u8981\u306B\u306A\u3063\u305F\u3089\u66F8\
    \u304F\uFF08\u5168\u3066\u72EC\u7ACB)\n\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= n);\n        assert(g(e()));\n    \
    \    if (l == n) return n;\n        l += sz;\n        for (int i = log; i >= 1;\
    \ i--) push(l >> i);\n        S sm = e();\n        do {\n            while (l\
    \ % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while\
    \ (l < sz) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if (g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - sz;\n            }\n            sm = op(sm, d[l]);\n\
    \            l++;\n        } while ((l & -l) != l);\n        return n;\n    }\n\
    \n   \n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= n);\n        assert(g(e()));\n        if (r == 0) return 0;\n    \
    \    r += sz;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n  \
    \      S sm = e();\n        do {\n            r--;\n            while (r > 1 &&\
    \ (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < sz) {\n                    push(r);\n                    r = (2 * r + 1);\n\
    \                    if (g(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - sz;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n\n    void\
    \ set(int p, S x) {\n        assert(0 <= p && p < n);\n        p += sz;\n    \
    \    rrep(i, 1, log+1) push(p >> i);\n        d[p] = x;\n        rep(i, 1, log+1)\
    \ update(p >> i);\n    }\n\n    S all_prod() { return d[1]; }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    void apply(int\
    \ p, F f) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    \n};\n    \n\
    /*\n@brief lazysegtree\n@docs doc/lazysegtree.md\n*/\n#line 5 \"verify/lazysegtree.test.cpp\"\
    \nusing mint = modint998244353;\nstruct S {\n    mint s; int sz;\n};\n\nS op(S\
    \ l, S r) {\n    return S{l.s + r.s, l.sz + r.sz};\n}\n\nS e() {\n    return S{mint(0),\
    \ 0};\n}\n\nstruct F {\n    mint a, b;\n};\n\nS mapping(F f, S s) {\n    S res;\n\
    \    res.s = f.a * s.s + f.b * s.sz;\n    res.sz = s.sz;\n    return res;\n}\n\
    \nF composition(F l, F r) {\n    return F{r.a * l.a, r.b * l.a + l.b};\n}\n\n\
    F id() {\n    return F{1, 0};\n}\n\nint main() {\n    int N, Q;\n    cin >> N\
    \ >> Q;\n    vector<S> V(N);\n    rep(i, 0, N) {\n        int a;\n        cin\
    \ >> a;\n        V[i] = S{a, 1};\n    }\n    lazysegtree<S, op, e, F, mapping,\
    \ composition, id> seg(V);\n    while(Q--) {\n       // rep(i, 0, N) cout << seg.prod(i,\
    \ i+1).s.x << \" \";\n       // cout << endl;\n        int t;\n        cin >>\
    \ t;\n        if(t == 0) {\n            int l, r, b, c;\n            cin >> l\
    \ >> r >> b >> c;\n            seg.apply(l, r, F{b, c});\n        }\n        else\
    \ {\n            int l, r;\n            cin >> l >> r;\n            cout << seg.prod(l,\
    \ r).s.x << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include\
    \ \"../Datastructure/lazysegtree.hpp\"\nusing mint = modint998244353;\nstruct\
    \ S {\n    mint s; int sz;\n};\n\nS op(S l, S r) {\n    return S{l.s + r.s, l.sz\
    \ + r.sz};\n}\n\nS e() {\n    return S{mint(0), 0};\n}\n\nstruct F {\n    mint\
    \ a, b;\n};\n\nS mapping(F f, S s) {\n    S res;\n    res.s = f.a * s.s + f.b\
    \ * s.sz;\n    res.sz = s.sz;\n    return res;\n}\n\nF composition(F l, F r) {\n\
    \    return F{r.a * l.a, r.b * l.a + l.b};\n}\n\nF id() {\n    return F{1, 0};\n\
    }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<S> V(N);\n  \
    \  rep(i, 0, N) {\n        int a;\n        cin >> a;\n        V[i] = S{a, 1};\n\
    \    }\n    lazysegtree<S, op, e, F, mapping, composition, id> seg(V);\n    while(Q--)\
    \ {\n       // rep(i, 0, N) cout << seg.prod(i, i+1).s.x << \" \";\n       //\
    \ cout << endl;\n        int t;\n        cin >> t;\n        if(t == 0) {\n   \
    \         int l, r, b, c;\n            cin >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, F{b, c});\n        }\n        else {\n            int l, r;\n           \
    \ cin >> l >> r;\n            cout << seg.prod(l, r).s.x << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Datastructure/lazysegtree.hpp
  isVerificationFile: true
  path: verify/lazysegtree.test.cpp
  requiredBy: []
  timestamp: '2024-07-29 19:50:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/verify/lazysegtree.test.cpp
- /verify/verify/lazysegtree.test.cpp.html
title: verify/lazysegtree.test.cpp
---
