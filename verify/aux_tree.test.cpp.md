---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/hld.hpp
    title: HLD
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439
  bundledCode: "#line 1 \"verify/aux_tree.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439\"\
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
    \ a;\n            b = par[root[b]];\n        }\n    }\n\n    ll dist(int a, int\
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
    */\n#line 4 \"verify/aux_tree.test.cpp\"\n\nconst int inf = 1001001001;\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vec<int> C(n);\n    rep(i, 0, n) cin >> C[i],\
    \ C[i]--;\n    vec<vec<int>> G(n);\n    rep(i, 0, n-1) {\n        int u, v;\n\
    \        cin >> u >> v;\n        u--, v--;\n        G[u].push_back(v);\n     \
    \   G[v].push_back(u);\n    }\n\n    vec<vec<int>> dp(n);\n    vec<int> ans(n,\
    \ inf);\n    HLD hld(G, 0);\n\n    vec<vec<int>> cv(n);\n    rep(i, 0, n) cv[C[i]].push_back(i);\n\
    \n    vec<vec<int>> g(n);\n\n    rep(c, 0, n) {\n        int r = hld.aux_tree(cv[c],\
    \ g);\n        if(r == -1) continue;\n\n        auto dfs = [&](auto f, int v,\
    \ int p) -> int {\n            int res = inf;\n            int d = g[v].size();\n\
    \            dp[v].resize(d);\n            \n            rep(i, 0, d) {\n    \
    \            int to = g[v][i];\n                if(to == p) continue;\n      \
    \          dp[v][i] = f(f, to, v);\n                int nw = dp[v][i] + hld.dist(v,\
    \ to);//\u3053\u3053\u3067\u5230\u9054\u6E08\u307F\n                chmin(res,\
    \ nw);\n            }\n            //res++;\n            if(C[v] == c) res = 0;\n\
    \            return res;\n        };\n\n        auto bfs = [&](auto f, int v,\
    \  int par, int p) -> void {\n            int d =  g[v].size();\n            rep(i,\
    \ 0, d) if(g[v][i] == p) dp[v][i] = par;\n\n            vec<int> L(d+1, inf);\n\
    \            vec<int> R(d+1, inf);\n            rep(i, 0, d) {\n             \
    \   int nw = dp[v][i] + hld.dist(v, g[v][i]);\n                L[i+1] = min(L[i],\
    \ nw);\n            }\n\n            rrep(i, 0, d) {\n                int nw =\
    \ dp[v][i] + hld.dist(v, g[v][i]);\n                R[i] = min(R[i+1], nw);\n\
    \            }\n\n            if(C[v] == c) {\n                ans[v] = L[d];\n\
    \            }\n\n            rep(i, 0, d) {\n                int to = g[v][i];\n\
    \                if(to == p) continue;\n                int nx = min(L[i], R[i+1]);\n\
    \                if(C[v] == c) nx = 0;\n                f(f, to, nx, v);\n   \
    \         }\n        };\n\n        dfs(dfs, r, -1);\n        bfs(bfs, r, inf,\
    \ -1);\n        hld.clean(g);\n    }\n\n    rep(i, 0, n) cout << ans[i] << '\\\
    n';\n        \n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/hld.hpp\"\n\n\
    const int inf = 1001001001;\nint main() {\n    int n;\n    cin >> n;\n    vec<int>\
    \ C(n);\n    rep(i, 0, n) cin >> C[i], C[i]--;\n    vec<vec<int>> G(n);\n    rep(i,\
    \ 0, n-1) {\n        int u, v;\n        cin >> u >> v;\n        u--, v--;\n  \
    \      G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    vec<vec<int>>\
    \ dp(n);\n    vec<int> ans(n, inf);\n    HLD hld(G, 0);\n\n    vec<vec<int>> cv(n);\n\
    \    rep(i, 0, n) cv[C[i]].push_back(i);\n\n    vec<vec<int>> g(n);\n\n    rep(c,\
    \ 0, n) {\n        int r = hld.aux_tree(cv[c], g);\n        if(r == -1) continue;\n\
    \n        auto dfs = [&](auto f, int v, int p) -> int {\n            int res =\
    \ inf;\n            int d = g[v].size();\n            dp[v].resize(d);\n     \
    \       \n            rep(i, 0, d) {\n                int to = g[v][i];\n    \
    \            if(to == p) continue;\n                dp[v][i] = f(f, to, v);\n\
    \                int nw = dp[v][i] + hld.dist(v, to);//\u3053\u3053\u3067\u5230\
    \u9054\u6E08\u307F\n                chmin(res, nw);\n            }\n         \
    \   //res++;\n            if(C[v] == c) res = 0;\n            return res;\n  \
    \      };\n\n        auto bfs = [&](auto f, int v,  int par, int p) -> void {\n\
    \            int d =  g[v].size();\n            rep(i, 0, d) if(g[v][i] == p)\
    \ dp[v][i] = par;\n\n            vec<int> L(d+1, inf);\n            vec<int> R(d+1,\
    \ inf);\n            rep(i, 0, d) {\n                int nw = dp[v][i] + hld.dist(v,\
    \ g[v][i]);\n                L[i+1] = min(L[i], nw);\n            }\n\n      \
    \      rrep(i, 0, d) {\n                int nw = dp[v][i] + hld.dist(v, g[v][i]);\n\
    \                R[i] = min(R[i+1], nw);\n            }\n\n            if(C[v]\
    \ == c) {\n                ans[v] = L[d];\n            }\n\n            rep(i,\
    \ 0, d) {\n                int to = g[v][i];\n                if(to == p) continue;\n\
    \                int nx = min(L[i], R[i+1]);\n                if(C[v] == c) nx\
    \ = 0;\n                f(f, to, nx, v);\n            }\n        };\n\n      \
    \  dfs(dfs, r, -1);\n        bfs(bfs, r, inf, -1);\n        hld.clean(g);\n  \
    \  }\n\n    rep(i, 0, n) cout << ans[i] << '\\n';\n        \n\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/hld.hpp
  isVerificationFile: true
  path: verify/aux_tree.test.cpp
  requiredBy: []
  timestamp: '2025-01-10 00:18:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aux_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aux_tree.test.cpp
- /verify/verify/aux_tree.test.cpp.html
title: verify/aux_tree.test.cpp
---
