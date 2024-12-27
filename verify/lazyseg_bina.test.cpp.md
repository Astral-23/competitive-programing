---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/lazysegtree.hpp
    title: lazysegtree
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=4021
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=4021
  bundledCode: "#line 1 \"verify/lazyseg_bina.test.cpp\"\n\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=4021\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/lazysegtree.hpp\"\
    \ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n        \
    \  class F,\n          S (*mp)(F, S),\n          F (*cm)(F, F),\n          F (*id)()>\n\
    struct lazysegtree {\n    int n;\n    int sz;\n    int log;\n    vec<S> d;\n \
    \   vec<F> lz;\n    lazysegtree(int n) : lazysegtree(vec<S>(n, e())) {}\n    lazysegtree(const\
    \ vec<S> &v) : n((int)(v.size())) {\n        log = 1;\n        while ((1 << log)\
    \ < n) log++;\n        sz = 1 << log;\n        d.resize(2 * sz, e());\n      \
    \  lz.resize(2 * sz, id());\n        rep(i, 0, n) d[sz + i] = v[i];\n        rrep(i,\
    \ 1, sz) update(i);\n    }\n\n    void update(int i) { d[i] = op(d[i << 1], d[i\
    \ << 1 | 1]); }\n\n    void all_apply(int i, F f) {\n        d[i] = mp(f, d[i]);\n\
    \        if (i < sz) lz[i] = cm(f, lz[i]);\n    }\n\n    void push(int k) {\n\
    \        all_apply(k * 2, lz[k]);\n        all_apply(k * 2 + 1, lz[k]);\n    \
    \    lz[k] = id();\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l\
    \ && l <= r && r <= n);\n        if (l == r) return e();\n\n        l += sz;\n\
    \        r += sz;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        S sml = e(), smr = e();\n        while\
    \ (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r\
    \ & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
    \      }\n\n        return op(sml, smr);\n    }\n\n    void apply(int l, int r,\
    \ F f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \n        l += sz;\n        r += sz;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ l2 = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ f);\n                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    // \u4EE5\u4E0B\u3001\u5FC5\u8981\u306B\
    \u306A\u3063\u305F\u3089\u66F8\u304F\uFF08\u5168\u3066\u72EC\u7ACB)\n\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= n);\n \
    \       assert(g(e()));\n        if (l == n) return n;\n        l += sz;\n   \
    \     for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < sz) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - sz;\n    \
    \        }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return n;\n    }\n\n    template <class G> int min_left(int\
    \ r, G g) {\n        assert(0 <= r && r <= n);\n        assert(g(e()));\n    \
    \    if (r == 0) return 0;\n        r += sz;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < sz) {\n                    push(r);\n        \
    \            r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n  \
    \                      sm = op(d[r], sm);\n                        r--;\n    \
    \                }\n                }\n                return r + 1 - sz;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p\
    \ && p < n);\n        p += sz;\n        rrep(i, 1, log + 1) push(p >> i);\n  \
    \      d[p] = x;\n        rep(i, 1, log + 1) update(p >> i);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    S get(int p) {\n        assert(0 <= p && p < n);\n \
    \       p += sz;\n        for (int i = log; i >= 1; i--) push(p >> i);\n     \
    \   return d[p];\n    }\n\n    void apply(int p, F f) {\n        assert(0 <= p\
    \ && p < n);\n        p += sz;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n};\n\n/*\n@brief lazysegtree\n@docs doc/lazysegtree.md\n\
    */\n#line 5 \"verify/lazyseg_bina.test.cpp\"\n\n\nstruct S{\n\tll idx;\n\tll x;\n\
    };\nS op(S a,S b){\n    if(a.x==b.x){\n        if(a.idx>b.idx) return a;\n   \
    \     return b;\n    }\n\tif(a.x>b.x) return a;\n\treturn b;\n}\nS e(){\n\treturn\
    \ {-1,(ll)(-1e18)};\n}\nusing F = ll;\nS mapping(F f,S a){\n    a.x+=f;\n    return\
    \ a;\n}\nF comb(F f,F g){\n    return f+g;\n}\nF id(){\n    return 0;\n}\n\nusing\
    \ segtree = lazysegtree<S,op,e,F,mapping,comb,id>;\n\nint main(){\n\tint h,w;\n\
    \tcin>>h>>w;\n\tvector<string> s(h);\n\trep(i,0, h) cin>>s.at(i);\n\tvector<vector<ll>>\
    \ dp(h+1,vector<ll>(w+1,0));\n\t{\n\t\tvector<vector<ll>> dp1(h+1,vector<ll>(w+1,0));\n\
    \t\tvector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));\n\t\tfor(int i=h-1;i>=0;i--){\n\
    \t\t\tfor(int j=w-1;j>=0;j--){\n\t\t\t\tif(s.at(i).at(j)=='0') continue;\n\t\t\
    \t\tdp1.at(i).at(j)=dp1.at(i+1).at(j)+1;\n\t\t\t\tdp2.at(i).at(j)=dp2.at(i).at(j+1)+1;\n\
    \t\t\t\tdp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));\n\t\t\t}\n\t\t}\n\
    \t}\n\tvector<string> rs(h);\n\trep(i,0, h) rep(j,0, w){\n\t\trs.at(i)+=s.at(h-1-i).at(w-1-j);\n\
    \t}\n\tvector<vector<ll>> rdp(h+1,vector<ll>(w+1,0));\n\t{\n\t\tvector<vector<ll>>\
    \ rrdp(h+1,vector<ll>(w+1,0));\n\t\tvector<vector<ll>> dp1(h+1,vector<ll>(w+1,0));\n\
    \t\tvector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));\n\t\tfor(int i=h-1;i>=0;i--){\n\
    \t\t\tfor(int j=w-1;j>=0;j--){\n\t\t\t\tif(rs.at(i).at(j)=='0') continue;\n\t\t\
    \t\tdp1.at(i).at(j)=dp1.at(i+1).at(j)+1;\n\t\t\t\tdp2.at(i).at(j)=dp2.at(i).at(j+1)+1;\n\
    \t\t\t\trrdp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));\n\t\t\t}\n\t\t\
    }\n\t\trep(i,0, h) rep(j,0, w){\n\t\t\trdp.at(i).at(j)=rrdp.at(h-1-i).at(w-1-j);\n\
    \t\t}\n\t}\n    ll ans=0;\n\tfor(int k=-h+1;k<w;k++){\n\t\tvector<S> tmp;\n  \
    \      int d=0;\n\t\tfor(int i=0;i<h;i++){\n\t\t\tint j=i+k;\n\t\t\tif(j<0||j>=w)\
    \ continue;\n\t\t\ttmp.push_back({d,rdp.at(i).at(j)-d});\n            d++;\n\t\
    \t}\n        segtree seg(tmp);\n        d=0;\n\t\tfor(int i=0;i<h;i++){\n\t\t\t\
    int j=i+k;\n\t\t\tif(j<0||j>=w) continue;\n            //if(dp.at(i).at(j)==0)\
    \ continue;\n\t\t\tauto ch = [&](S now) {\n\t\t\t\treturn now.x < 0;\n\t\t\t};\n\
    \            ll v =seg.min_left(dp.at(i).at(j)+d,ch);\n\t\t\t//cout << dp.at(i).at(j)\
    \ << endl;\n            if(v > 0){\n\t\t\t\tv--;\n                ans=max(ans,v-d+1);\n\
    \            }\n            d++;\n            seg.apply(0,tmp.size(),1);\n\t\t\
    }\n\t}\n    cout<<ans<<endl;\n}\n\n\n"
  code: "\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=4021\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/lazysegtree.hpp\"\
    \n\n\nstruct S{\n\tll idx;\n\tll x;\n};\nS op(S a,S b){\n    if(a.x==b.x){\n \
    \       if(a.idx>b.idx) return a;\n        return b;\n    }\n\tif(a.x>b.x) return\
    \ a;\n\treturn b;\n}\nS e(){\n\treturn {-1,(ll)(-1e18)};\n}\nusing F = ll;\nS\
    \ mapping(F f,S a){\n    a.x+=f;\n    return a;\n}\nF comb(F f,F g){\n    return\
    \ f+g;\n}\nF id(){\n    return 0;\n}\n\nusing segtree = lazysegtree<S,op,e,F,mapping,comb,id>;\n\
    \nint main(){\n\tint h,w;\n\tcin>>h>>w;\n\tvector<string> s(h);\n\trep(i,0, h)\
    \ cin>>s.at(i);\n\tvector<vector<ll>> dp(h+1,vector<ll>(w+1,0));\n\t{\n\t\tvector<vector<ll>>\
    \ dp1(h+1,vector<ll>(w+1,0));\n\t\tvector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));\n\
    \t\tfor(int i=h-1;i>=0;i--){\n\t\t\tfor(int j=w-1;j>=0;j--){\n\t\t\t\tif(s.at(i).at(j)=='0')\
    \ continue;\n\t\t\t\tdp1.at(i).at(j)=dp1.at(i+1).at(j)+1;\n\t\t\t\tdp2.at(i).at(j)=dp2.at(i).at(j+1)+1;\n\
    \t\t\t\tdp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));\n\t\t\t}\n\t\t}\n\
    \t}\n\tvector<string> rs(h);\n\trep(i,0, h) rep(j,0, w){\n\t\trs.at(i)+=s.at(h-1-i).at(w-1-j);\n\
    \t}\n\tvector<vector<ll>> rdp(h+1,vector<ll>(w+1,0));\n\t{\n\t\tvector<vector<ll>>\
    \ rrdp(h+1,vector<ll>(w+1,0));\n\t\tvector<vector<ll>> dp1(h+1,vector<ll>(w+1,0));\n\
    \t\tvector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));\n\t\tfor(int i=h-1;i>=0;i--){\n\
    \t\t\tfor(int j=w-1;j>=0;j--){\n\t\t\t\tif(rs.at(i).at(j)=='0') continue;\n\t\t\
    \t\tdp1.at(i).at(j)=dp1.at(i+1).at(j)+1;\n\t\t\t\tdp2.at(i).at(j)=dp2.at(i).at(j+1)+1;\n\
    \t\t\t\trrdp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));\n\t\t\t}\n\t\t\
    }\n\t\trep(i,0, h) rep(j,0, w){\n\t\t\trdp.at(i).at(j)=rrdp.at(h-1-i).at(w-1-j);\n\
    \t\t}\n\t}\n    ll ans=0;\n\tfor(int k=-h+1;k<w;k++){\n\t\tvector<S> tmp;\n  \
    \      int d=0;\n\t\tfor(int i=0;i<h;i++){\n\t\t\tint j=i+k;\n\t\t\tif(j<0||j>=w)\
    \ continue;\n\t\t\ttmp.push_back({d,rdp.at(i).at(j)-d});\n            d++;\n\t\
    \t}\n        segtree seg(tmp);\n        d=0;\n\t\tfor(int i=0;i<h;i++){\n\t\t\t\
    int j=i+k;\n\t\t\tif(j<0||j>=w) continue;\n            //if(dp.at(i).at(j)==0)\
    \ continue;\n\t\t\tauto ch = [&](S now) {\n\t\t\t\treturn now.x < 0;\n\t\t\t};\n\
    \            ll v =seg.min_left(dp.at(i).at(j)+d,ch);\n\t\t\t//cout << dp.at(i).at(j)\
    \ << endl;\n            if(v > 0){\n\t\t\t\tv--;\n                ans=max(ans,v-d+1);\n\
    \            }\n            d++;\n            seg.apply(0,tmp.size(),1);\n\t\t\
    }\n\t}\n    cout<<ans<<endl;\n}\n\n\n"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/lazysegtree.hpp
  isVerificationFile: true
  path: verify/lazyseg_bina.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/lazyseg_bina.test.cpp
layout: document
redirect_from:
- /verify/verify/lazyseg_bina.test.cpp
- /verify/verify/lazyseg_bina.test.cpp.html
title: verify/lazyseg_bina.test.cpp
---
