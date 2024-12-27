---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Algorithm/hld.hpp
    title: HLD
  - icon: ':question:'
    path: Datastructure/segtree.hpp
    title: segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/hld.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/hld.hpp\"\
    \nstruct HLD {\n    using vi = vec<int>;\n    using pi = pair<int, int>;\n   \
    \ using pll = pair<long long, long long>;\n    vi in, out, par, root, rev, dep,\
    \ pre_vs;\n    vec<ll> dep_w;\n    //          \u89AA/\u6210\u5206\u306Etop/in\u306E\
    \u4E2D\u8EAB\u2192\u9802\u70B9\u756A\u53F7\n    int n, r;  // \u9802\u70B9\u6570\
    \u3001\u6839\n\n    static vec<vec<int>> extract_graph(const vec<vec<pll>> &G)\
    \ {\n        vec<vec<int>> g(G.size());\n        for (int i = 0; i < int(G.size());\
    \ i++) {\n            for (auto [w, to] : G[i])\n                if (i < to) {\n\
    \                    g[i].push_back(to);\n                    g[to].push_back(i);\n\
    \                }\n        }\n        return g;\n    }\n    HLD(const vec<vec<pll>>\
    \ &g, int a) : HLD(extract_graph(g), a) {\n        auto dfs = [&](auto f, int\
    \ v) -> void {\n            for (auto [w, to] : g[v])\n                if (to\
    \ != par[v]) {\n                    dep_w[to] = dep_w[v] + w;\n              \
    \      f(f, to);\n                }\n        };\n        dfs(dfs, r);\n    }\n\
    \n    HLD(vec<vi> g, int a) : n(g.size()), r(a) {\n        vi siz(n, 0);\n   \
    \     in = out = root = rev = vi(n);\n        par = vi(n, -1);\n        dep =\
    \ vi(n, 0);\n        dep_w = vec<ll>(n, 0);\n        root[r] = r;\n\n        auto\
    \ dfs_siz = [&](auto f, int v) -> void {\n            siz[v]++;\n            for\
    \ (int &to : g[v])\n                if (to != par[v]) {\n                    dep[to]\
    \ = dep[v] + 1;\n                    par[to] = v;\n                    f(f, to);\n\
    \                    siz[v] += siz[to];\n                    if (siz[to] > siz[g[v][0]]\
    \ || g[v][0] == par[v])\n                        swap(to, g[v][0]);\n        \
    \        }\n            return;\n        };\n\n        dfs_siz(dfs_siz, r);\n\n\
    \        int t = 0;\n\n        auto dfs_hld = [&](auto f, int v) -> void {\n \
    \           rev[t] = v;\n            in[v] = t++;\n            for (int to : g[v])\n\
    \                if (to != par[v]) {\n                    root[to] = (to == g[v][0]\
    \ ? root[v] : to);\n                    f(f, to);\n                }\n       \
    \     out[v] = t;\n        };\n\n        dfs_hld(dfs_hld, r);\n        for (int\
    \ i = 0; i < n; i++) dep_w[i] = dep[i];\n    }\n\n    // \u4EE5\u4E0B\u3001\u6B32\
    \u3057\u3044\u3082\u306E\u306E\u307F\u66F8\u304F\n\n    int operator()(int v)\
    \ const { return in[v]; }\n    int operator()(int u, int v) const {\n        assert(par[u]\
    \ == v || par[v] == u);\n        if(par[u] == v) return in[u];\n        else return\
    \ in[v];\n    }\n\n    int lca(int a, int b) {\n        while (1) {\n        \
    \    if (in[a] > in[b]) swap(a, b);\n            if (root[a] == root[b]) return\
    \ a;\n            b = par[root[b]];\n        }\n    }\n\n    int dist(int a, int\
    \ b) {\n        int lc = lca(a, b);\n        return dep_w[a] + dep_w[b] - 2 *\
    \ dep_w[lc];\n    }\n\n    vec<pi> path(int s, int t, bool edge) {\n        vec<pi>\
    \ ls, rs;\n        while (root[s] != root[t]) {\n            if (dep[root[s]]\
    \ > dep[root[t]]) {\n                ls.emplace_back(in[s] + 1, in[root[s]]);\
    \  // \u4E0A\u308A\n                s = par[root[s]];\n            } else {\n\
    \                rs.emplace_back(in[root[t]], in[t] + 1);  // \u4E0B\u308A\n \
    \               t = par[root[t]];\n            }\n        }\n\n        if (dep[s]\
    \ > dep[t])\n            ls.emplace_back(in[s] + 1, in[t] + edge);  // \u4E0A\u308A\
    \n        else\n            rs.emplace_back(in[s] + edge, in[t] + 1);  // \u4E0B\
    \u308A\n\n        reverse(all(rs));\n        for (auto &p : rs) ls.push_back(p);\n\
    \        return ls;\n    }\n\n    pi subtree(int u, bool edge) { return pi(in[u]\
    \ + edge, out[u]); }\n\n    int kth_ancestor(int v, int k) {\n        if (k >\
    \ dep[v]) return -1;\n        while (v >= 0) {\n            if (k <= dep[v] -\
    \ dep[root[v]]) {\n                return rev[in[v] - k];\n            } else\
    \ {\n                k -= dep[v] - dep[root[v]] + 1;\n                v = par[root[v]];\n\
    \            }\n        }\n    }\n\n    int jump(int s, int t, int k) {\n    \
    \    int m = lca(s, t);\n        int le = dep[s] - dep[m];\n        int ri = dep[t]\
    \ - dep[m];\n        if (0 <= k && k <= le + ri) {\n            if (k < le)\n\
    \                return kth_ancestor(s, k);\n            else\n              \
    \  return kth_ancestor(t, le + ri - k);\n        }\n        return -1;\n    }\n\
    \n    int aux_tree(vi vs, vec<vi> &g) {\n        if (vs.empty()) return -1;\n\n\
    \        auto cmp = [&](int i, int j) { return in[i] < in[j]; };\n        sort(all(vs),\
    \ cmp);\n        int m = vs.size();\n\n        rep(i, 0, m - 1) vs.push_back(lca(vs[i],\
    \ vs[i + 1]));\n        sort(all(vs), cmp);\n        vs.erase(unique(all(vs)),\
    \ vs.end());\n\n        vi st;\n        for (auto v : vs) {\n            while\
    \ (st.size()) {\n                int p = st.back();\n                if (in[p]\
    \ < in[v] && in[v] < out[p]) break;\n                st.pop_back();\n        \
    \    }\n            if (st.size()) {\n                g[st.back()].push_back(v);\n\
    \                g[v].push_back(st.back());\n            }\n            st.push_back(v);\n\
    \        }\n\n        swap(vs, pre_vs);\n        return pre_vs[0];\n    }\n\n\
    \    void clean(vec<vi> &g) {\n        for (auto v : pre_vs) g[v] = vi();\n  \
    \      pre_vs = vi();\n        return;\n    }\n};\n/*\n@brief HLD\n@docs doc/hld.md\n\
    */\n#line 1 \"Datastructure/segtree.hpp\"\ntemplate <class S, S (*op)(S, S), S\
    \ (*e)()> struct segtree {\n    int n;\n    int sz;\n    vector<S> d;\n\n    segtree(int\
    \ n) : segtree(vector<S>(n, e())) {}\n\n    segtree(const vector<S> &v) : n((int)v.size()),\
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
    */\n#line 5 \"verify/hld.test.cpp\"\n\n\nusing S = ll;\nS op(S l, S r) {\n   \
    \ return l + r;\n}\n\nS e() {\n    return 0LL;\n}\n\n\n\nint main() {\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vec<ll> A(N);\n    rep(i,0,N) cin >> A[i];\n\
    \    vec<vec<int>> G(N);\n    rep(i, 0, N-1) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\
    \    \n    \n    HLD hld(G, 0);\n    vec<ll> B(N);\n    rep(i,0,N) B[hld.in[i]]\
    \ = A[i];\n    segtree<S, op, e> seg(B);\n\n    while(Q--) {\n        int t;\n\
    \        cin >> t;\n        if(t==0) {\n            int p, x;\n            cin\
    \ >> p >> x;\n            p = hld.in[p];\n            seg.set(p, seg.get(p) +\
    \ x);\n        }\n        else {\n            int u, v;\n            cin >> u\
    \ >> v;\n            auto ps = hld.path(u, v, false);\n            ll res = 0;\n\
    \            for(auto [l, r] : ps) {\n                if(l >= r) swap(l, r);\n\
    \                res += seg.prod(l, r);\n            }\n            cout << res\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Algorithm/hld.hpp\"\n#include\
    \ \"../Datastructure/segtree.hpp\"\n\n\nusing S = ll;\nS op(S l, S r) {\n    return\
    \ l + r;\n}\n\nS e() {\n    return 0LL;\n}\n\n\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vec<ll> A(N);\n    rep(i,0,N) cin >> A[i];\n    vec<vec<int>>\
    \ G(N);\n    rep(i, 0, N-1) {\n        int u, v;\n        cin >> u >> v;\n   \
    \     G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    \n    \n    HLD\
    \ hld(G, 0);\n    vec<ll> B(N);\n    rep(i,0,N) B[hld.in[i]] = A[i];\n    segtree<S,\
    \ op, e> seg(B);\n\n    while(Q--) {\n        int t;\n        cin >> t;\n    \
    \    if(t==0) {\n            int p, x;\n            cin >> p >> x;\n         \
    \   p = hld.in[p];\n            seg.set(p, seg.get(p) + x);\n        }\n     \
    \   else {\n            int u, v;\n            cin >> u >> v;\n            auto\
    \ ps = hld.path(u, v, false);\n            ll res = 0;\n            for(auto [l,\
    \ r] : ps) {\n                if(l >= r) swap(l, r);\n                res += seg.prod(l,\
    \ r);\n            }\n            cout << res << '\\n';\n        }\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/hld.hpp
  - Datastructure/segtree.hpp
  isVerificationFile: true
  path: verify/hld.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/hld.test.cpp
layout: document
redirect_from:
- /verify/verify/hld.test.cpp
- /verify/verify/hld.test.cpp.html
title: verify/hld.test.cpp
---
