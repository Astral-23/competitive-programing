---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/maxflow.test.cpp
    title: verify/maxflow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/maxflow.md
    document_title: Maxflow
    links: []
  bundledCode: "#line 1 \"Algorithm/maxflow.hpp\"\ntemplate<class T> \nstruct mf_graph\
    \ {\n    struct edge {\n        int st, to;\n        T cap, flow;\n    };\n\n\
    \    struct nedge {\n        int to, rev;\n        T cap;\n    };\n\n    int n;\n\
    \    vec<unordered_map<int, int>> rev;\n    vec<pair<int, int>> pos;\n    vec<vec<nedge>>\
    \ g;\n\n    mf_graph(int _n) : n(_n), g(n), rev(n) {}\n\n    int add_edge(int\
    \ s, int t, T cap) {\n        int m = pos.size();\n        pos.push_back({s, g[s].size()});\n\
    \        int fi = g[s].size(); int ti = g[t].size();\n        if(s==t)ti++;\n\
    \        g[s].push_back(nedge{t, ti, cap});\n        g[t].push_back(nedge{s, fi,\
    \ 0});\n        rev[s][t] = m;\n        return m;\n    }\n\n    T flow(int s,\
    \ int t, T flow_limit = numeric_limits<T>::max()) {\n        vec<int> lv(n), it(n,\
    \ 0);\n\n        auto bfs = [&]() {\n            queue<int> que;\n           \
    \ fill(lv.begin(), lv.end(), -1);\n            lv[s] = 0;\n            que.push(s);\n\
    \            while(!que.empty()) {\n                int v = que.front();\n   \
    \             que.pop();\n\n                for(auto e : g[v]) {\n           \
    \         if(e.cap == 0 || lv[e.to] >= 0) continue;\n                    lv[e.to]\
    \ = lv[v] + 1;\n                    if(e.to == t) return;\n                  \
    \  que.push(e.to);\n                }\n            }\n        };\n\n        auto\
    \ dfs = [&](auto f, int v, T up) {\n            if(v==s) return up;\n        \
    \    T res = 0;\n            int LV = lv[v];\n            for(int& i = it[v];\
    \ i < int(g[v].size()); i++) {\n                nedge& e = g[v][i];\n        \
    \        if(LV <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;\n           \
    \     T d = f(f, e.to, min(up - res, g[e.to][e.rev].cap));\n                if(d\
    \ <= 0) continue;\n                g[v][i].cap += d;\n                g[e.to][e.rev].cap\
    \ -= d;\n                res += d;\n                if(res == up) return res;\n\
    \            }\n            lv[v] = n;\n            return res;\n        };\n\n\
    \        T flow = 0;\n        while(flow < flow_limit) {\n            bfs();\n\
    \            if(lv[t] == -1) break;\n            fill(it.begin(), it.end(), 0);\n\
    \            T f = dfs(dfs, t, flow_limit - flow);\n            if(!f) break;\n\
    \            flow += f;\n        }\n        return flow;\n    }\n\n    //\u4EE5\
    \u4E0B\u3001\u4E0D\u8981\u306A\u3089\u7701\u7565\n\n    int get_id(int s, int\
    \ t) {\n        return rev[s][t];\n    }\n\n    edge get_edge(int i) {\n     \
    \   int m = pos.size();\n        auto e = g[pos[i].first][pos[i].second];\n  \
    \      auto re = g[e.to][e.rev];\n        return edge{pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n\n    void change_edge(int i, T nc, T nf) {\n   \
    \     int m = pos.size();\n        auto& e = g[pos[i].first][pos[i].second];\n\
    \        auto& re = g[e.to][e.rev];\n        e.cap = nc - nf;\n        re.cap\
    \ = nf;\n    }\n\n    vec<bool> min_cut(int s) {\n        vec<bool> seen(n);\n\
    \        queue<int> que;\n        que.push(s);\n        while(!que.empty()) {\n\
    \            int p = que.front();\n            que.pop();\n            seen[p]=true;\n\
    \            for(auto e : g[p]) {\n                if(e.cap && !seen[e.to]) {\n\
    \                    seen[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return seen;\n    }\n\n\
    };\n\n\n\n/*\n@brief Maxflow\n@docs doc/maxflow.md\n*/\n"
  code: "template<class T> \nstruct mf_graph {\n    struct edge {\n        int st,\
    \ to;\n        T cap, flow;\n    };\n\n    struct nedge {\n        int to, rev;\n\
    \        T cap;\n    };\n\n    int n;\n    vec<unordered_map<int, int>> rev;\n\
    \    vec<pair<int, int>> pos;\n    vec<vec<nedge>> g;\n\n    mf_graph(int _n)\
    \ : n(_n), g(n), rev(n) {}\n\n    int add_edge(int s, int t, T cap) {\n      \
    \  int m = pos.size();\n        pos.push_back({s, g[s].size()});\n        int\
    \ fi = g[s].size(); int ti = g[t].size();\n        if(s==t)ti++;\n        g[s].push_back(nedge{t,\
    \ ti, cap});\n        g[t].push_back(nedge{s, fi, 0});\n        rev[s][t] = m;\n\
    \        return m;\n    }\n\n    T flow(int s, int t, T flow_limit = numeric_limits<T>::max())\
    \ {\n        vec<int> lv(n), it(n, 0);\n\n        auto bfs = [&]() {\n       \
    \     queue<int> que;\n            fill(lv.begin(), lv.end(), -1);\n         \
    \   lv[s] = 0;\n            que.push(s);\n            while(!que.empty()) {\n\
    \                int v = que.front();\n                que.pop();\n\n        \
    \        for(auto e : g[v]) {\n                    if(e.cap == 0 || lv[e.to] >=\
    \ 0) continue;\n                    lv[e.to] = lv[v] + 1;\n                  \
    \  if(e.to == t) return;\n                    que.push(e.to);\n              \
    \  }\n            }\n        };\n\n        auto dfs = [&](auto f, int v, T up)\
    \ {\n            if(v==s) return up;\n            T res = 0;\n            int\
    \ LV = lv[v];\n            for(int& i = it[v]; i < int(g[v].size()); i++) {\n\
    \                nedge& e = g[v][i];\n                if(LV <= lv[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n                T d = f(f, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \                if(d <= 0) continue;\n                g[v][i].cap += d;\n   \
    \             g[e.to][e.rev].cap -= d;\n                res += d;\n          \
    \      if(res == up) return res;\n            }\n            lv[v] = n;\n    \
    \        return res;\n        };\n\n        T flow = 0;\n        while(flow <\
    \ flow_limit) {\n            bfs();\n            if(lv[t] == -1) break;\n    \
    \        fill(it.begin(), it.end(), 0);\n            T f = dfs(dfs, t, flow_limit\
    \ - flow);\n            if(!f) break;\n            flow += f;\n        }\n   \
    \     return flow;\n    }\n\n    //\u4EE5\u4E0B\u3001\u4E0D\u8981\u306A\u3089\u7701\
    \u7565\n\n    int get_id(int s, int t) {\n        return rev[s][t];\n    }\n\n\
    \    edge get_edge(int i) {\n        int m = pos.size();\n        auto e = g[pos[i].first][pos[i].second];\n\
    \        auto re = g[e.to][e.rev];\n        return edge{pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n\n    void change_edge(int i, T nc, T nf) {\n   \
    \     int m = pos.size();\n        auto& e = g[pos[i].first][pos[i].second];\n\
    \        auto& re = g[e.to][e.rev];\n        e.cap = nc - nf;\n        re.cap\
    \ = nf;\n    }\n\n    vec<bool> min_cut(int s) {\n        vec<bool> seen(n);\n\
    \        queue<int> que;\n        que.push(s);\n        while(!que.empty()) {\n\
    \            int p = que.front();\n            que.pop();\n            seen[p]=true;\n\
    \            for(auto e : g[p]) {\n                if(e.cap && !seen[e.to]) {\n\
    \                    seen[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return seen;\n    }\n\n\
    };\n\n\n\n/*\n@brief Maxflow\n@docs doc/maxflow.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/maxflow.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/maxflow.test.cpp
documentation_of: Algorithm/maxflow.hpp
layout: document
redirect_from:
- /library/Algorithm/maxflow.hpp
- /library/Algorithm/maxflow.hpp.html
title: Maxflow
---
## 概要
ACL の maxflowと同じ
参考 : https://github.com/atcoder/ac-library

## 省略できるもの
get_id, get_edge, change_edge, min_cutは他の機能と独立であり、省略できます。具体的には、flow(int s, int t, T flow_limit)以下の関数が該当します。
また、これらの機能のverifyはしていません
## コンストラクタ
mf_grash<T>(n)  頂点数nのグラフを作成する
<br>
T ... 辺容量・フローの値を格納する型

## 関数
ある辺の辺番号を、その辺が追加された順番で定義する。<br>
- **add_edge(int s, int t, T cap)**...sからtへ最大容量cap, 流量0の辺を追加し、何番目に追加された辺か返す

- **flow(int s, int t, T flow_limit = numeric::max())**... sからtへ流量flow_limitに達するまで流せる限り流し、流せた量を返す。<br>
これを複数回呼んだ場合、２回目以降は
$(新たなtのin) - (前のtのin) \le flow_limit$
を満たす内 (新たなin) - (前のtのin)が最大になるようにし、その(新たなin) - (前のtのin)を返す。<br>
つまり、この場合のflow_limitは前との差分に関する制約を表す。

- **get_id(int s, int t)**...s → tの辺であって、最後に追加された物の辺番号を返す

- **get_edge(int i)** ... 辺番号iの辺の今の状態を返す

- **change_edge(int i, T new_cap, T new_flow)** ... i番目に追加された辺容量、流量を new_cap, new_flowに変更する

- **min_cut(int s)**...長さnのvectorを返す。i番目の要素には、sからiへ残余グラフで到達可能なとき、またその時のみtrueを返す。flow(s, t)をちょうど1回呼んだ後に呼ぶと、返り値はs, t間のmincutに対応する。

