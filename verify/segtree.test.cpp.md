---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/segtree.hpp\"\
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
    /*\n@brief segtree\n@docs doc/segtree.md\n*/\n#line 4 \"verify/segtree.test.cpp\"\
    \n\nusing S = int;\nS op(S l, S r) {\n\treturn l + r;\n}\n\nS e() {\n\treturn\
    \ 0;\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> T(N, 0);\n\
    \tstring t;\n\tcin >> t;\n    rep(i, 0, N) if(t[i] == '1') {\n\t\tT[i] = 1;\n\t\
    }\n\tsegtree<S, op, e> seg(T);\n\n\twhile(Q--) {\n\t\tint t, k;\n\t\tcin >> t\
    \ >> k;\n\t\tif(t==0) {\n\t\t\tseg.set(k, 1);\n\t\t}\n\t\telse if(t==1) {\n\t\t\
    \tseg.set(k, 0);\n\t\t}\n\t\telse if(t==2) {\n\t\t\tif(seg.get(k)) cout << 1 <<\
    \ '\\n';\n\t\t\telse cout << 0 << '\\n';\n\t\t}\n\t\telse if(t==3) {\n\t\t\tauto\
    \ nex = [&](int v) {\n\t\t\t\treturn v == 0;\n\t\t\t};\n\t\t\tint res = seg.max_right(k,\
    \ nex);\n\t\t\tif(res==N) cout << -1 << '\\n';\n            else  cout << res\
    \ << '\\n';\n\t\t}\n\t\telse if(t==4) {\n\t\t\tauto pre = [&](int v) {\n\t\t\t\
    \treturn v == 0;\n\t\t\t};\n\t\t\tint res = seg.min_left(k+1, pre);\n\t\t\tcout\
    \ << res-1 << '\\n';\n\t\t}\n\t}\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/segtree.hpp\"\
    \n\nusing S = int;\nS op(S l, S r) {\n\treturn l + r;\n}\n\nS e() {\n\treturn\
    \ 0;\n}\n\n\nint main() {\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<int> T(N, 0);\n\
    \tstring t;\n\tcin >> t;\n    rep(i, 0, N) if(t[i] == '1') {\n\t\tT[i] = 1;\n\t\
    }\n\tsegtree<S, op, e> seg(T);\n\n\twhile(Q--) {\n\t\tint t, k;\n\t\tcin >> t\
    \ >> k;\n\t\tif(t==0) {\n\t\t\tseg.set(k, 1);\n\t\t}\n\t\telse if(t==1) {\n\t\t\
    \tseg.set(k, 0);\n\t\t}\n\t\telse if(t==2) {\n\t\t\tif(seg.get(k)) cout << 1 <<\
    \ '\\n';\n\t\t\telse cout << 0 << '\\n';\n\t\t}\n\t\telse if(t==3) {\n\t\t\tauto\
    \ nex = [&](int v) {\n\t\t\t\treturn v == 0;\n\t\t\t};\n\t\t\tint res = seg.max_right(k,\
    \ nex);\n\t\t\tif(res==N) cout << -1 << '\\n';\n            else  cout << res\
    \ << '\\n';\n\t\t}\n\t\telse if(t==4) {\n\t\t\tauto pre = [&](int v) {\n\t\t\t\
    \treturn v == 0;\n\t\t\t};\n\t\t\tint res = seg.min_left(k+1, pre);\n\t\t\tcout\
    \ << res-1 << '\\n';\n\t\t}\n\t}\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/segtree.hpp
  isVerificationFile: true
  path: verify/segtree.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/segtree.test.cpp
- /verify/verify/segtree.test.cpp.html
title: verify/segtree.test.cpp
---
