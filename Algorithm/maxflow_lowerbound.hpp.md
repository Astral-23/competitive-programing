---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/maxflow_lowerbound.test.cpp
    title: verify/maxflow_lowerbound.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Algorithm/maxflow_lowerbound.hpp\"\nstruct mf_graph_with_lowerbound\
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
    \ + mf.get_edge(i).flow); }\n        return res;\n    }\n};\n"
  code: "struct mf_graph_with_lowerbound {\n    int n;\n    mf_graph<ll> mf;  // atcoder::mf_graph\u3067\
    \u3082\u826F\u3044\u3002\n    int S, T;\n    ll sum;\n    vector<ll> lows, d;\n\
    \    ll total_flow;\n\n    mf_graph_with_lowerbound(int n)\n        : n(n), mf(n\
    \ + 2), S(n), T(n + 1), sum(0), d(n, 0), total_flow(0) {}\n\n    int add_edge(int\
    \ from, int to, ll low, ll high) {\n        lows.push_back(low);\n        d[from]\
    \ -= low;\n        d[to] += low;\n        return mf.add_edge(from, to, high -\
    \ low);\n    }\n\n    void build() {\n        rep(i, 0, n) {\n            if (d[i]\
    \ > 0) {\n                mf.add_edge(S, i, d[i]);\n                sum += d[i];\n\
    \            } else\n                mf.add_edge(i, T, -d[i]);\n        }\n  \
    \  }\n\n    bool is_feasable(int s, int t) {\n        build();\n        mf.add_edge(t,\
    \ s, LLONG_MAX / 4);  // INF = LLONG_MAX / 4\n        total_flow += mf.flow(S,\
    \ T);\n        return total_flow == sum;\n    }\n\n    ll flow(int s, int t) {\n\
    \        if (is_feasable(s, t) == false) return -1;\n        mf.add_edge(S, s,\
    \ LLONG_MAX / 4);\n        mf.add_edge(t, T, LLONG_MAX / 4);\n        return (total_flow\
    \ += mf.flow(S, T)) - sum;\n    }\n\n    vector<ll> output() {  // not verified\n\
    \        vector<ll> res;\n        rep(i, 0, lows.size()) { res.push_back(lows[i]\
    \ + mf.get_edge(i).flow); }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/maxflow_lowerbound.hpp
  requiredBy: []
  timestamp: '2024-07-19 19:51:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/maxflow_lowerbound.test.cpp
documentation_of: Algorithm/maxflow_lowerbound.hpp
layout: document
redirect_from:
- /library/Algorithm/maxflow_lowerbound.hpp
- /library/Algorithm/maxflow_lowerbound.hpp.html
title: Algorithm/maxflow_lowerbound.hpp
---
