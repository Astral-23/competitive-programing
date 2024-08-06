---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/hld.hpp
    title: HLD
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
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"verify/jumpontree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/hld.hpp\"\nstruct HLD {\n    using\
    \ vi = vec<int>;\n    using pi = pair<int, int>;\n    vi in, out, par, root, rev,\
    \ dep, pre_vs;\n    //          \u89AA/\u6210\u5206\u306Etop/in\u306E\u4E2D\u8EAB\
    \u2192\u9802\u70B9\u756A\u53F7\n    int n, r;//\u9802\u70B9\u6570\u3001\u6839\n\
    \    \n  \n    HLD(vec<vi> &g, int a): n(g.size()), r(a) {\n        vi siz(n,\
    \ 0);\n        in = out = root = rev = vi(n);\n        par = vi(n, -1);\n    \
    \    dep = vi(n, 0);\n        root[r] = r;\n\n        auto dfs_siz = [&](auto\
    \ f, int v) -> void {\n            siz[v]++;\n            for(int& to : g[v])\
    \ if(to != par[v]) {\n                dep[to] = dep[v] + 1;\n                par[to]\
    \ = v;\n                f(f, to);\n                siz[v] += siz[to];\n      \
    \          if(siz[to] > siz[g[v][0]] || g[v][0] == par[v]) swap(to, g[v][0]);\n\
    \            }\n            return;\n        };\n\n        dfs_siz(dfs_siz, r);\n\
    \        \n        int t = 0;\n\n        auto dfs_hld = [&](auto f, int v) ->\
    \ void {\n            rev[t] = v;\n            in[v]=t++;\n            for(int\
    \ to : g[v]) if(to != par[v]) {\n                root[to] = (to == g[v][0] ? root[v]\
    \ : to);\n                f(f, to);\n            }\n            out[v] = t;\n\
    \        };\n\n        dfs_hld(dfs_hld, r);\n    }\n\n\n    //\u4EE5\u4E0B\u3001\
    \u6B32\u3057\u3044\u3082\u306E\u306E\u307F\u66F8\u304F\n\n\n    int lca(int a,\
    \ int b) {\n        while(1) {\n            if(in[a] > in[b]) swap(a, b);\n  \
    \          if(root[a] == root[b]) return a;\n            b = par[root[b]];\n \
    \       }\n    }\n\n    int dist(int a, int b) {\n        int lc = lca(a, b);\n\
    \        return dep[a] + dep[b] - 2 * dep[lc];\n    }\n\n    vec<pi> path(int\
    \ s, int t, bool edge) {\n        vec<pi> ls, rs;\n        while(root[s] != root[t])\
    \ {\n            if(dep[root[s]] > dep[root[t]]) {\n                ls.emplace_back(in[s]\
    \ + 1, in[root[s]]);//\u4E0A\u308A\n                s = par[root[s]];\n      \
    \      }\n            else {\n                rs.emplace_back(in[root[t]], in[t]\
    \ + 1);//\u4E0B\u308A\n                t = par[root[t]];\n            }\n    \
    \    }\n\n        if(dep[s] > dep[t]) ls.emplace_back(in[s] + 1, in[t] + edge);//\u4E0A\
    \u308A\n        else rs.emplace_back(in[s] + edge, in[t] + 1);//\u4E0B\u308A\n\
    \        \n        reverse(all(rs));\n        for(auto &p : rs) ls.push_back(p);\n\
    \        return ls;\n    }\n\n    pi subtree(int u, bool edge) {\n        return\
    \ pi(in[u]+edge, out[u]);\n    }\n\n    int kth_ancestor(int v, int k) {\n   \
    \     if(k > dep[v]) return -1;\n        while(v >= 0) {\n            if(k <=\
    \ dep[v] - dep[root[v]]) {\n                return rev[in[v] - k];\n         \
    \   }\n            else {\n                k -= dep[v] - dep[root[v]] + 1;\n \
    \               v = par[root[v]];\n            }\n        }\n    }\n\n    int\
    \ jump(int s, int t, int k) {\n        int m = lca(s, t);\n        int le = dep[s]\
    \ - dep[m];\n        int ri = dep[t] - dep[m];\n        if(0 <= k && k <= le +\
    \ ri) {\n            if(k < le) return kth_ancestor(s, k);\n            else return\
    \ kth_ancestor(t, le + ri - k);\n        }\n        return -1;\n    }\n\n    int\
    \ aux_tree(vi vs, vec<vi> &g) {\n        if(vs.empty()) return -1;\n        \n\
    \        auto cmp = [&](int i, int j) { return in[i] < in[j]; };\n        sort(all(vs),\
    \ cmp);\n        int m = vs.size();\n\n        rep(i, 0, m-1) vs.push_back(lca(vs[i],\
    \ vs[i + 1]));\n        sort(all(vs), cmp);\n        vs.erase(unique(all(vs)),\
    \ vs.end());\n\n        vi st;\n        for(auto v : vs) {\n            while(st.size())\
    \ {\n                int p = st.back();\n                if(in[p] < in[v] && in[v]\
    \ < out[p]) break;\n                st.pop_back();\n            }\n          \
    \  if(st.size()) {\n                g[st.back()].push_back(v);\n             \
    \   g[v].push_back(st.back());\n            }\n            st.push_back(v);\n\
    \        }\n\n        swap(vs, pre_vs);\n        return pre_vs[0];\n    }\n\n\
    \    void clean(vec<vi> &g) {\n        for(auto v : pre_vs) g[v] = vi();\n   \
    \     pre_vs = vi();\n        return;\n    }\n};  \n\n\n\n/*\n@brief HLD\n@docs\
    \ doc/hld.md\n*/\n#line 4 \"verify/jumpontree.test.cpp\"\n\nint main() {\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    vec<vec<int>> G(N);\n    rep(i, 0, N-1) {\n\
    \        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n     \
    \   G[v].push_back(u);\n    }\n\n    HLD hld(G, 0);\n\n    while(Q--) {\n    \
    \    int s, t, i;\n        cin >> s >> t >> i;\n        cout << hld.jump(s, t,\
    \ i) << '\\n';\n\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Algorithm/hld.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    vec<vec<int>> G(N);\n    rep(i, 0,\
    \ N-1) {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    HLD hld(G, 0);\n\n    while(Q--) {\n\
    \        int s, t, i;\n        cin >> s >> t >> i;\n        cout << hld.jump(s,\
    \ t, i) << '\\n';\n\n    }\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/hld.hpp
  isVerificationFile: true
  path: verify/jumpontree.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/jumpontree.test.cpp
layout: document
redirect_from:
- /verify/verify/jumpontree.test.cpp
- /verify/verify/jumpontree.test.cpp.html
title: verify/jumpontree.test.cpp
---