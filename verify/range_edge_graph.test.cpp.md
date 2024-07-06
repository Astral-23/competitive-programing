---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/hld.hpp
    title: HLD
  - icon: ':heavy_check_mark:'
    path: Datastructure/range_edge_graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/4022
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/4022
  bundledCode: "#line 1 \"verify/range_edge_graph.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4022\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"\
    Datastructure/range_edge_graph.hpp\"\nstruct range_edge_graph {\n    #define pb\
    \ push_back\n    struct edge {\n        int to;\n        ll cost;\n        //ll\
    \ cap; \u30D5\u30ED\u30FC\u306A\u3089\u3053\u308C\u3082\u4F7F\u3046\u3002\n  \
    \      edge(){}\n        edge(int a, ll b, ll c) : to(a), cost(b) {}\n       \
    \ //edge(int a, ll b, ll c) : to(a), cost(b), cap(c) {}\n        //\u30D5\u30ED\
    \u30FC\u306E\u6642\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    };\n\n\
    \    edge e(int to) {\n        return edge(to, 0, LLONG_MAX/4);\n    }\n  \n \
    \   int n;\n    int sz = 1;\n    int node;\n    vec<vec<edge>> g;\n\n    range_edge_graph(int\
    \ N) : n(N) {\n        while(sz < n) sz <<= 1;\n\n        g = vec<vec<edge>>(n\
    \ + 4 * sz);\n        node = n + 4 * sz;\n\n        rep(i, 1, sz) {\n        \
    \    g[i + n].pb( e(i * 2 + n) );\n            g[i + n].pb( e(i * 2 + 1 + n) );\n\
    \n            g[i * 2 + n + 2 * sz].pb( e(i + n + 2 * sz) );\n            g[i\
    \ * 2 + 1 + n + 2 * sz].pb( e(i + n + 2 * sz) );\n        }\n\n        rep(i,\
    \ 0, n) {\n            g[i + n + sz].pb( e(i) );\n            g[i].pb( e(i + n\
    \ + 3 * sz) );\n        }\n    }\n\n    void add_edge(int sl, int sr, int tl,\
    \ int tr, ll cost, ll cap) {\n        int nw = node++;\n        int nw2 = node++;\n\
    \        g.pb({ edge( nw2, cost, cap ) });\n        g.pb(vec<edge>());\n\n   \
    \     sl += sz;\n        sr += sz;\n        while(sl < sr) {\n            if(sl\
    \ & 1) g[sl + n + 2 * sz].pb( e(nw) ), sl++;\n            if(sr & 1) sr--, g[sr\
    \ + n + 2 * sz].pb( e(nw) );\n            sl >>= 1; sr >>= 1;\n        }\n\n \
    \       tl += sz;\n        tr += sz;\n        while(tl < tr) {\n            if(tl\
    \ & 1) g[nw2].pb( e(tl + n) ), tl++;\n            if(tr & 1) tr--, g[nw2].pb(\
    \ e(tr + n) ); \n            tl >>= 1, tr >>= 1;\n        }\n    }\n\n    void\
    \ add_edge(int s, int t, ll cost, ll cap) {\n        g[s].pb( edge(t, cost, cap)\
    \ );\n    }\n\n    vec<vec<edge>> graph() {\n        return g;\n    }\n\n    #undef\
    \ pb\n};\n\n/*\n@brief \u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF\n\
    @docs doc/range_edge_graph.md\n*/\n#line 1 \"Algorithm/hld.hpp\"\nstruct HLD {\n\
    \    using vi = vec<int>;\n    using pi = pair<int, int>;\n    vi in, out, par,\
    \ root, rev, dep, pre_vs;\n    //          \u89AA/\u6210\u5206\u306Etop/in\u306E\
    \u4E2D\u8EAB\u2192\u9802\u70B9\u756A\u53F7\n    int n, r;//\u9802\u70B9\u6570\u3001\
    \u6839\n    \n  \n    HLD(vec<vi> &g, int a): n(g.size()), r(a) {\n        vi\
    \ siz(n, 0);\n        in = out = root = rev = vi(n);\n        par = vi(n, -1);\n\
    \        dep = vi(n, 0);\n        root[r] = r;\n\n        auto dfs_siz = [&](auto\
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
    \ doc/hld.md\n*/\n#line 5 \"verify/range_edge_graph.test.cpp\"\n\nusing pll =\
    \ pair<int, ll>;\nint main() {\n\tll N, s, t;\n\tcin >> N >> s >> t;\n\ts--, t--;\n\
    \tvec<vec<pll>> g(N);\n\tvec<vec<int>> ng(N);\n\trep(i, 0, N-1) {\n\t\tll a, b,\
    \ c;\n\t\tcin >> a >> b >> c;\n\t\ta--, b--;\n\t\tg[a].push_back(pll(b, c));\n\
    \t\tg[b].push_back(pll(a, c));\n\t\tng[a].push_back(b);\n\t\tng[b].push_back(a);\n\
    \t}\n\n\tvec<int> T(N), D(N);\n\trep(i, 1, N) {\n\t\tcin >> T[i] >> D[i];\n\t\
    }\n\n\tHLD hld(ng, 0);\n\tng.clear();\n\n\tvec<int> ord(N, -1);\n\tvec<vec<pll>>\
    \ ds(N);\n\n\n\t{   \n\t\tint id = 0;\n\t\tqueue<int> que;\n\t\tque.push(0);\n\
    \t\tord[0] = id++;\n\n\t\twhile(!que.empty()) {\n\t\t\tauto now = que.front();\n\
    \t\t\tque.pop();\n\t\t\tds[hld.dep[now]].push_back(pll(ord[now], now));\n\n\t\t\
    \tfor(auto [to, c] : g[now]) if(ord[to] == -1) {\n\t\t\t\tord[to] = id++;\n\t\t\
    \t\tque.push(to);\n\t\t\t}\n\t\t}\n\n\t\trep(i, 0, N) sort(all(ds[i]));\n\t}\n\
    \n    \n\tvec<int> rev(N);\n\trep(i, 0, N) {\n\t\trep(j, 0, ds[i].size()) {\n\t\
    \t\trev[ds[i][j].second] = j;\n\t\t}\n\t}\n\n\trange_edge_graph gh(N);\n\n\n\t\
    rep(i, 1, N) {//\u8FBA\u3092\u8CBC\u308B\u30D5\u30A7\u30FC\u30BA\n\t    ll d =\
    \ D[i];\n\t\tauto& vs = ds[hld.dep[i]];\n\t\t//\u81EA\u5206\u304Cvs\u306E\u4E2D\
    \u3067 m \u756A\u76EE\u3068\u3059\u308B\u3002\n\t\tint m = rev[i];\n\t\tint l,\
    \ r;\n\t\t{\n\t\t\tint li = 0;\n\t\t\tint ri = m;\n\t\t\twhile(li < ri) {//xxxxooo\n\
    \t\t\t\tint mid = (li + ri) >> 1;\n\t\t\t\tint dis = hld.dist(vs[mid].second,\
    \ i);\n\t\t\t\tif(dis <= d) ri = mid;\n\t\t\t\telse li = mid + 1;\n\t\t\t}\n\t\
    \t\tl = li;\n\t\t}\n\n\n\t\t{\n\t\t\tint li = m;\n\t\t\tint ri = vs.size()-1;\n\
    \t\t\twhile(li < ri) {\n\t\t\t\tint mid = (li + ri + 1) >> 1;\n\t\t\t\tint dis\
    \ = hld.dist(vs[mid].second, i);\n\t\t\t\tif(dis <= d) li = mid;\n\t\t\t\telse\
    \ ri = mid - 1;\n\t\t\t}\n\t\t\tr = li;\n\t\t}\n\n\t\t//[l, r]\n\t\tl = vs[l].first;\n\
    \t\tr = vs[r].first;//ord\u306B\u5909\u63DB\n\t\tint now = ord[i];\n\n\t\tgh.add_edge(now,\
    \ now+1, l, r+1, T[i], LLONG_MAX);\n\t}\n\n\trep(i, 0, N) {\n\t\tint now = ord[i];\n\
    \t\tfor(auto [to, c] : g[i]) {\n\t\t\tto = ord[to];\n\t\t\tgh.add_edge(now, to,\
    \ c, LLONG_MAX);\n\n\t\t}\n\t}\n\n\tauto G = gh.graph();\n\tint M = G.size();\n\
    \n\ts = ord[s], t = ord[t];\n\tvec<ll> ans(M, LLONG_MAX);\n\tans[s] = 0;\n\n\n\
    \n\tpriority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>>\
    \ que;\n\tque.push({0, s});\n\twhile(!que.empty()) {\n\t\tauto [c, v] = que.top();\n\
    \t\tque.pop();\n\t\tif(ans[v] < c) continue;\n\t\tfor(auto e : G[v]) {\n\t\t\t\
    ll cost = e.cost + ans[v];\n\t\t\tif(chmin(ans[e.to], cost)) {\n\t\t\t\tque.push({ans[e.to],\
    \ e.to});\n\t\t\t}\n\n\t\t}\n\t}\n\n\tcout << ans[t] << endl;\n\n\n\n\n\t\n\n\n\
    \n\n\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4022\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Datastructure/range_edge_graph.hpp\"\
    \n#include \"../Algorithm/hld.hpp\"\n\nusing pll = pair<int, ll>;\nint main()\
    \ {\n\tll N, s, t;\n\tcin >> N >> s >> t;\n\ts--, t--;\n\tvec<vec<pll>> g(N);\n\
    \tvec<vec<int>> ng(N);\n\trep(i, 0, N-1) {\n\t\tll a, b, c;\n\t\tcin >> a >> b\
    \ >> c;\n\t\ta--, b--;\n\t\tg[a].push_back(pll(b, c));\n\t\tg[b].push_back(pll(a,\
    \ c));\n\t\tng[a].push_back(b);\n\t\tng[b].push_back(a);\n\t}\n\n\tvec<int> T(N),\
    \ D(N);\n\trep(i, 1, N) {\n\t\tcin >> T[i] >> D[i];\n\t}\n\n\tHLD hld(ng, 0);\n\
    \tng.clear();\n\n\tvec<int> ord(N, -1);\n\tvec<vec<pll>> ds(N);\n\n\n\t{   \n\t\
    \tint id = 0;\n\t\tqueue<int> que;\n\t\tque.push(0);\n\t\tord[0] = id++;\n\n\t\
    \twhile(!que.empty()) {\n\t\t\tauto now = que.front();\n\t\t\tque.pop();\n\t\t\
    \tds[hld.dep[now]].push_back(pll(ord[now], now));\n\n\t\t\tfor(auto [to, c] :\
    \ g[now]) if(ord[to] == -1) {\n\t\t\t\tord[to] = id++;\n\t\t\t\tque.push(to);\n\
    \t\t\t}\n\t\t}\n\n\t\trep(i, 0, N) sort(all(ds[i]));\n\t}\n\n    \n\tvec<int>\
    \ rev(N);\n\trep(i, 0, N) {\n\t\trep(j, 0, ds[i].size()) {\n\t\t\trev[ds[i][j].second]\
    \ = j;\n\t\t}\n\t}\n\n\trange_edge_graph gh(N);\n\n\n\trep(i, 1, N) {//\u8FBA\u3092\
    \u8CBC\u308B\u30D5\u30A7\u30FC\u30BA\n\t    ll d = D[i];\n\t\tauto& vs = ds[hld.dep[i]];\n\
    \t\t//\u81EA\u5206\u304Cvs\u306E\u4E2D\u3067 m \u756A\u76EE\u3068\u3059\u308B\u3002\
    \n\t\tint m = rev[i];\n\t\tint l, r;\n\t\t{\n\t\t\tint li = 0;\n\t\t\tint ri =\
    \ m;\n\t\t\twhile(li < ri) {//xxxxooo\n\t\t\t\tint mid = (li + ri) >> 1;\n\t\t\
    \t\tint dis = hld.dist(vs[mid].second, i);\n\t\t\t\tif(dis <= d) ri = mid;\n\t\
    \t\t\telse li = mid + 1;\n\t\t\t}\n\t\t\tl = li;\n\t\t}\n\n\n\t\t{\n\t\t\tint\
    \ li = m;\n\t\t\tint ri = vs.size()-1;\n\t\t\twhile(li < ri) {\n\t\t\t\tint mid\
    \ = (li + ri + 1) >> 1;\n\t\t\t\tint dis = hld.dist(vs[mid].second, i);\n\t\t\t\
    \tif(dis <= d) li = mid;\n\t\t\t\telse ri = mid - 1;\n\t\t\t}\n\t\t\tr = li;\n\
    \t\t}\n\n\t\t//[l, r]\n\t\tl = vs[l].first;\n\t\tr = vs[r].first;//ord\u306B\u5909\
    \u63DB\n\t\tint now = ord[i];\n\n\t\tgh.add_edge(now, now+1, l, r+1, T[i], LLONG_MAX);\n\
    \t}\n\n\trep(i, 0, N) {\n\t\tint now = ord[i];\n\t\tfor(auto [to, c] : g[i]) {\n\
    \t\t\tto = ord[to];\n\t\t\tgh.add_edge(now, to, c, LLONG_MAX);\n\n\t\t}\n\t}\n\
    \n\tauto G = gh.graph();\n\tint M = G.size();\n\n\ts = ord[s], t = ord[t];\n\t\
    vec<ll> ans(M, LLONG_MAX);\n\tans[s] = 0;\n\n\n\n\tpriority_queue<array<ll, 2>,\
    \ vector<array<ll, 2>>, greater<array<ll, 2>>> que;\n\tque.push({0, s});\n\twhile(!que.empty())\
    \ {\n\t\tauto [c, v] = que.top();\n\t\tque.pop();\n\t\tif(ans[v] < c) continue;\n\
    \t\tfor(auto e : G[v]) {\n\t\t\tll cost = e.cost + ans[v];\n\t\t\tif(chmin(ans[e.to],\
    \ cost)) {\n\t\t\t\tque.push({ans[e.to], e.to});\n\t\t\t}\n\n\t\t}\n\t}\n\n\t\
    cout << ans[t] << endl;\n\n\n\n\n\t\n\n\n\n\n\n}\n"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/range_edge_graph.hpp
  - Algorithm/hld.hpp
  isVerificationFile: true
  path: verify/range_edge_graph.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/range_edge_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/range_edge_graph.test.cpp
- /verify/verify/range_edge_graph.test.cpp.html
title: verify/range_edge_graph.test.cpp
---
