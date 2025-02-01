---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/maxflow.hpp
    title: Maxflow
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja
  bundledCode: "#line 1 \"verify/maxflow.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/maxflow.hpp\"\
    \ntemplate <class T> struct mf_graph {\n    struct edge {\n        int st, to;\n\
    \        T cap, flow;\n    };\n\n    struct nedge {\n        int to, rev;\n  \
    \      T cap;\n    };\n\n    int n;\n    vec<unordered_map<int, int>> rev;\n \
    \   vec<pair<int, int>> pos;\n    vec<vec<nedge>> g;\n\n    mf_graph(int _n) :\
    \ n(_n), g(n), rev(n) {}\n\n    int add_edge(int s, int t, T cap) {\n        int\
    \ m = pos.size();\n        pos.push_back({s, g[s].size()});\n        int fi =\
    \ g[s].size();\n        int ti = g[t].size();\n        if (s == t) ti++;\n   \
    \     g[s].push_back(nedge{t, ti, cap});\n        g[t].push_back(nedge{s, fi,\
    \ 0});\n        rev[s][t] = m;\n        return m;\n    }\n\n    T flow(int s,\
    \ int t, T flow_limit = numeric_limits<T>::max()) {\n        vec<int> lv(n), it(n,\
    \ 0);\n\n        auto bfs = [&]() {\n            queue<int> que;\n           \
    \ fill(lv.begin(), lv.end(), -1);\n            lv[s] = 0;\n            que.push(s);\n\
    \            while (!que.empty()) {\n                int v = que.front();\n  \
    \              que.pop();\n\n                for (auto e : g[v]) {\n         \
    \           if (e.cap == 0 || lv[e.to] >= 0) continue;\n                    lv[e.to]\
    \ = lv[v] + 1;\n                    if (e.to == t) return;\n                 \
    \   que.push(e.to);\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto f, int v, T up) {\n            if (v == s) return up;\n     \
    \       T res = 0;\n            int LV = lv[v];\n            for (int &i = it[v];\
    \ i < int(g[v].size()); i++) {\n                nedge &e = g[v][i];\n        \
    \        if (LV <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;\n          \
    \      T d = f(f, e.to, min(up - res, g[e.to][e.rev].cap));\n                if\
    \ (d <= 0) continue;\n                g[v][i].cap += d;\n                g[e.to][e.rev].cap\
    \ -= d;\n                res += d;\n                if (res == up) return res;\n\
    \            }\n            lv[v] = n;\n            return res;\n        };\n\n\
    \        T flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n\
    \            if (lv[t] == -1) break;\n            fill(it.begin(), it.end(), 0);\n\
    \            T f = dfs(dfs, t, flow_limit - flow);\n            if (!f) break;\n\
    \            flow += f;\n        }\n        return flow;\n    }\n\n    // \u4EE5\
    \u4E0B\u3001\u4E0D\u8981\u306A\u3089\u7701\u7565\n\n    int get_id(int s, int\
    \ t) { return rev[s][t]; }\n\n    edge get_edge(int i) {\n        int m = pos.size();\n\
    \        auto e = g[pos[i].first][pos[i].second];\n        auto re = g[e.to][e.rev];\n\
    \        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};\n    }\n\n \
    \   void change_edge(int i, T nc, T nf) {\n        int m = pos.size();\n     \
    \   auto &e = g[pos[i].first][pos[i].second];\n        auto &re = g[e.to][e.rev];\n\
    \        e.cap = nc - nf;\n        re.cap = nf;\n    }\n\n    vec<bool> min_cut(int\
    \ s) {\n        vec<bool> seen(n);\n        queue<int> que;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int p = que.front();\n          \
    \  que.pop();\n            seen[p] = true;\n            for (auto e : g[p]) {\n\
    \                if (e.cap && !seen[e.to]) {\n                    seen[e.to] =\
    \ true;\n                    que.push(e.to);\n                }\n            }\n\
    \        }\n        return seen;\n    }\n};\n\n/*\n@brief Maxflow\n@docs doc/maxflow.md\n\
    */\n#line 4 \"verify/maxflow.test.cpp\"\n\n\nint main() {\n    \n    int V, E;\n\
    \    cin >>  V >> E;\n    mf_graph<ll> flow(V);\n    rep(i,0,E) {\n        int\
    \ u, v;\n        ll c;\n        cin >> u >> v >> c;\n        flow.add_edge(u,\
    \ v, c);\n    }\n\n    ll res = flow.flow(0, V-1);\n    cout << res << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/maxflow.hpp\"\n\
    \n\nint main() {\n    \n    int V, E;\n    cin >>  V >> E;\n    mf_graph<ll> flow(V);\n\
    \    rep(i,0,E) {\n        int u, v;\n        ll c;\n        cin >> u >> v >>\
    \ c;\n        flow.add_edge(u, v, c);\n    }\n\n    ll res = flow.flow(0, V-1);\n\
    \    cout << res << endl;\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/maxflow.hpp
  isVerificationFile: true
  path: verify/maxflow.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/maxflow.test.cpp
layout: document
redirect_from:
- /verify/verify/maxflow.test.cpp
- /verify/verify/maxflow.test.cpp.html
title: verify/maxflow.test.cpp
---
