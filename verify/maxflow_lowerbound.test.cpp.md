---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Algorithm/maxflow.hpp
    title: Maxflow
  - icon: ':x:'
    path: Algorithm/maxflow_lowerbound.hpp
    title: Algorithm/maxflow_lowerbound.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
  bundledCode: "#line 1 \"verify/maxflow_lowerbound.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\n*/\n#line 1 \"Algorithm/maxflow.hpp\"\ntemplate <class T> struct mf_graph\
    \ {\n    struct edge {\n        int st, to;\n        T cap, flow;\n    };\n\n\
    \    struct nedge {\n        int to, rev;\n        T cap;\n    };\n\n    int n;\n\
    \    vec<unordered_map<int, int>> rev;\n    vec<pair<int, int>> pos;\n    vec<vec<nedge>>\
    \ g;\n\n    mf_graph(int _n) : n(_n), g(n), rev(n) {}\n\n    int add_edge(int\
    \ s, int t, T cap) {\n        int m = pos.size();\n        pos.push_back({s, g[s].size()});\n\
    \        int fi = g[s].size();\n        int ti = g[t].size();\n        if (s ==\
    \ t) ti++;\n        g[s].push_back(nedge{t, ti, cap});\n        g[t].push_back(nedge{s,\
    \ fi, 0});\n        rev[s][t] = m;\n        return m;\n    }\n\n    T flow(int\
    \ s, int t, T flow_limit = numeric_limits<T>::max()) {\n        vec<int> lv(n),\
    \ it(n, 0);\n\n        auto bfs = [&]() {\n            queue<int> que;\n     \
    \       fill(lv.begin(), lv.end(), -1);\n            lv[s] = 0;\n            que.push(s);\n\
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
    */\n#line 1 \"Algorithm/maxflow_lowerbound.hpp\"\nstruct mf_graph_with_lowerbound\
    \ {\n    int n;\n    mf_graph<ll> mf;  // atcoder::mf_graph\u3067\u3082\u826F\u3044\
    \u3002\n    int S, T;\n    ll sum;\n    vector<ll> lows, d;\n    ll total_flow;\n\
    \n    mf_graph_with_lowerbound(int n)\n        : n(n), mf(n + 2), S(n), T(n +\
    \ 1), sum(0), d(n, 0), total_flow(0) {}\n\n    int add_edge(int from, int to,\
    \ ll low, ll high) {\n        lows.push_back(low);\n        d[from] -= low;\n\
    \        d[to] += low;\n        return mf.add_edge(from, to, high - low);\n  \
    \  }\n\n    void build() {\n        rep(i, 0, n) {\n            if (d[i] > 0)\
    \ {\n                mf.add_edge(S, i, d[i]);\n                sum += d[i];\n\
    \            } else\n                mf.add_edge(i, T, -d[i]);\n        }\n  \
    \  }\n\n    bool is_feasable(int s, int t) {\n        build();\n        mf.add_edge(t,\
    \ s, LLONG_MAX / 4);  // INF = LLONG_MAX / 4\n        total_flow += mf.flow(S,\
    \ T);\n        return total_flow == sum;\n    }\n\n    ll flow(int s, int t) {\n\
    \        if (is_feasable(s, t) == false) return -1;\n        mf.add_edge(S, s,\
    \ LLONG_MAX / 4);\n        mf.add_edge(t, T, LLONG_MAX / 4);\n        return (total_flow\
    \ += mf.flow(S, T)) - sum;\n    }\n\n    vector<ll> output() {  // not verified\n\
    \        vector<ll> res;\n        rep(i, 0, lows.size()) { res.push_back(lows[i]\
    \ + mf.get_edge(i).flow); }\n        return res;\n    }\n};\n#line 5 \"verify/maxflow_lowerbound.test.cpp\"\
    \n\n\nusing pll = pair<ll, ll>;\n\nint main() {\n    int n, m;\n    while (1)\
    \ {\n        cin >> n >> m;\n\n        if (n == 0) break;\n\n        vector<pll>\
    \ es;\n        rep(i, 0, m) {\n            int u, v;\n            cin >> u >>\
    \ v;\n            u--, v--;\n            es.emplace_back(u, v);\n        }\n\n\
    \        int ans_m = -1;\n        int ans_M = -1;\n\n        auto che = [&](int\
    \ mi, int Mi) {\n            int s = n + m;\n            int t = s + 1;\n\n  \
    \          mf_graph_with_lowerbound mf(t + 1);\n\n            rep(i, 0, m) {\n\
    \                mf.add_edge(s, i, 1, 1);\n                mf.add_edge(i, m +\
    \ es[i].first, 0, 1);\n                mf.add_edge(i, m + es[i].second, 0, 1);\n\
    \            }\n\n            rep(i, 0, n) { mf.add_edge(m + i, t, mi, Mi); }\n\
    \n            if (mf.is_feasable(s, t)) {\n                return true;\n    \
    \        } else\n                return false;\n        };\n\n        ll w = 1e7;\n\
    \        rrep(mi, 0, n + 1) {\n            ll li = 0;\n            ll ri = li\
    \ + min<ll>(w, m);\n            while (li < ri) {  /// xxxxoooo\n            \
    \    ll mid = (li + ri) / 2;\n                if (che(mi, mi + mid)) {\n     \
    \               ri = mid;\n                } else {\n                    li =\
    \ mid + 1;\n                }\n            }\n            if (che(mi, mi + li)\
    \ && chmin(w, li - mi)) {\n                ans_m = mi;\n                ans_M\
    \ = mi + li;\n            }\n        }\n\n        cout << ans_m << \" \" << ans_M\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/maxflow.hpp\"\n\
    #include \"../Algorithm/maxflow_lowerbound.hpp\"\n\n\nusing pll = pair<ll, ll>;\n\
    \nint main() {\n    int n, m;\n    while (1) {\n        cin >> n >> m;\n\n   \
    \     if (n == 0) break;\n\n        vector<pll> es;\n        rep(i, 0, m) {\n\
    \            int u, v;\n            cin >> u >> v;\n            u--, v--;\n  \
    \          es.emplace_back(u, v);\n        }\n\n        int ans_m = -1;\n    \
    \    int ans_M = -1;\n\n        auto che = [&](int mi, int Mi) {\n           \
    \ int s = n + m;\n            int t = s + 1;\n\n            mf_graph_with_lowerbound\
    \ mf(t + 1);\n\n            rep(i, 0, m) {\n                mf.add_edge(s, i,\
    \ 1, 1);\n                mf.add_edge(i, m + es[i].first, 0, 1);\n           \
    \     mf.add_edge(i, m + es[i].second, 0, 1);\n            }\n\n            rep(i,\
    \ 0, n) { mf.add_edge(m + i, t, mi, Mi); }\n\n            if (mf.is_feasable(s,\
    \ t)) {\n                return true;\n            } else\n                return\
    \ false;\n        };\n\n        ll w = 1e7;\n        rrep(mi, 0, n + 1) {\n  \
    \          ll li = 0;\n            ll ri = li + min<ll>(w, m);\n            while\
    \ (li < ri) {  /// xxxxoooo\n                ll mid = (li + ri) / 2;\n       \
    \         if (che(mi, mi + mid)) {\n                    ri = mid;\n          \
    \      } else {\n                    li = mid + 1;\n                }\n      \
    \      }\n            if (che(mi, mi + li) && chmin(w, li - mi)) {\n         \
    \       ans_m = mi;\n                ans_M = mi + li;\n            }\n       \
    \ }\n\n        cout << ans_m << \" \" << ans_M << endl;\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/maxflow.hpp
  - Algorithm/maxflow_lowerbound.hpp
  isVerificationFile: true
  path: verify/maxflow_lowerbound.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/maxflow_lowerbound.test.cpp
layout: document
redirect_from:
- /verify/verify/maxflow_lowerbound.test.cpp
- /verify/verify/maxflow_lowerbound.test.cpp.html
title: verify/maxflow_lowerbound.test.cpp
---
