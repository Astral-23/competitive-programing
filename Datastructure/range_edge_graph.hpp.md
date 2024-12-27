---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/range_edge_graph.example.cpp
    title: example/range_edge_graph.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/range_edge_graph.test.cpp
    title: verify/range_edge_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/range_edge_graph.md
    document_title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF"
    links: []
  bundledCode: "#line 1 \"Datastructure/range_edge_graph.hpp\"\nstruct range_edge_graph\
    \ {\n    #define pb push_back\n    struct edge {\n        int to;\n        ll\
    \ cost;\n        //ll cap; \u30D5\u30ED\u30FC\u306A\u3089\u3053\u308C\u3082\u4F7F\
    \u3046\u3002\n        edge(){}\n        edge(int a, ll b, ll c) : to(a), cost(b)\
    \ {}\n        //edge(int a, ll b, ll c) : to(a), cost(b), cap(c) {}\n        //\u30D5\
    \u30ED\u30FC\u306E\u6642\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n   \
    \ };\n\n    edge e(int to) {\n        return edge(to, 0, LLONG_MAX/4);\n    }\n\
    \  \n    int n;\n    int sz = 1;\n    int node;\n    vec<vec<edge>> g;\n\n   \
    \ range_edge_graph(int N) : n(N) {\n        while(sz < n) sz <<= 1;\n\n      \
    \  g = vec<vec<edge>>(n + 4 * sz);\n        node = n + 4 * sz;\n\n        rep(i,\
    \ 1, sz) {\n            g[i + n].pb( e(i * 2 + n) );\n            g[i + n].pb(\
    \ e(i * 2 + 1 + n) );\n\n            g[i * 2 + n + 2 * sz].pb( e(i + n + 2 * sz)\
    \ );\n            g[i * 2 + 1 + n + 2 * sz].pb( e(i + n + 2 * sz) );\n       \
    \ }\n\n        rep(i, 0, n) {\n            g[i + n + sz].pb( e(i) );\n       \
    \     g[i].pb( e(i + n + 3 * sz) );\n        }\n    }\n\n    void add_edge(int\
    \ sl, int sr, int tl, int tr, ll cost, ll cap) {\n        int nw = node++;\n \
    \       int nw2 = node++;\n        g.pb({ edge( nw2, cost, cap ) });\n       \
    \ g.pb(vec<edge>());\n\n        sl += sz;\n        sr += sz;\n        while(sl\
    \ < sr) {\n            if(sl & 1) g[sl + n + 2 * sz].pb( e(nw) ), sl++;\n    \
    \        if(sr & 1) sr--, g[sr + n + 2 * sz].pb( e(nw) );\n            sl >>=\
    \ 1; sr >>= 1;\n        }\n\n        tl += sz;\n        tr += sz;\n        while(tl\
    \ < tr) {\n            if(tl & 1) g[nw2].pb( e(tl + n) ), tl++;\n            if(tr\
    \ & 1) tr--, g[nw2].pb( e(tr + n) ); \n            tl >>= 1, tr >>= 1;\n     \
    \   }\n    }\n\n    void add_edge(int s, int t, ll cost, ll cap) {\n        g[s].pb(\
    \ edge(t, cost, cap) );\n    }\n\n    vec<vec<edge>> graph() {\n        return\
    \ g;\n    }\n\n    #undef pb\n};\n\n/*\n@brief \u533A\u9593\u306B\u8FBA\u3092\u8CBC\
    \u308B\u30C6\u30AF\n@docs doc/range_edge_graph.md\n*/\n"
  code: "struct range_edge_graph {\n    #define pb push_back\n    struct edge {\n\
    \        int to;\n        ll cost;\n        //ll cap; \u30D5\u30ED\u30FC\u306A\
    \u3089\u3053\u308C\u3082\u4F7F\u3046\u3002\n        edge(){}\n        edge(int\
    \ a, ll b, ll c) : to(a), cost(b) {}\n        //edge(int a, ll b, ll c) : to(a),\
    \ cost(b), cap(c) {}\n        //\u30D5\u30ED\u30FC\u306E\u6642\u306E\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    };\n\n    edge e(int to) {\n        return\
    \ edge(to, 0, LLONG_MAX/4);\n    }\n  \n    int n;\n    int sz = 1;\n    int node;\n\
    \    vec<vec<edge>> g;\n\n    range_edge_graph(int N) : n(N) {\n        while(sz\
    \ < n) sz <<= 1;\n\n        g = vec<vec<edge>>(n + 4 * sz);\n        node = n\
    \ + 4 * sz;\n\n        rep(i, 1, sz) {\n            g[i + n].pb( e(i * 2 + n)\
    \ );\n            g[i + n].pb( e(i * 2 + 1 + n) );\n\n            g[i * 2 + n\
    \ + 2 * sz].pb( e(i + n + 2 * sz) );\n            g[i * 2 + 1 + n + 2 * sz].pb(\
    \ e(i + n + 2 * sz) );\n        }\n\n        rep(i, 0, n) {\n            g[i +\
    \ n + sz].pb( e(i) );\n            g[i].pb( e(i + n + 3 * sz) );\n        }\n\
    \    }\n\n    void add_edge(int sl, int sr, int tl, int tr, ll cost, ll cap) {\n\
    \        int nw = node++;\n        int nw2 = node++;\n        g.pb({ edge( nw2,\
    \ cost, cap ) });\n        g.pb(vec<edge>());\n\n        sl += sz;\n        sr\
    \ += sz;\n        while(sl < sr) {\n            if(sl & 1) g[sl + n + 2 * sz].pb(\
    \ e(nw) ), sl++;\n            if(sr & 1) sr--, g[sr + n + 2 * sz].pb( e(nw) );\n\
    \            sl >>= 1; sr >>= 1;\n        }\n\n        tl += sz;\n        tr +=\
    \ sz;\n        while(tl < tr) {\n            if(tl & 1) g[nw2].pb( e(tl + n) ),\
    \ tl++;\n            if(tr & 1) tr--, g[nw2].pb( e(tr + n) ); \n            tl\
    \ >>= 1, tr >>= 1;\n        }\n    }\n\n    void add_edge(int s, int t, ll cost,\
    \ ll cap) {\n        g[s].pb( edge(t, cost, cap) );\n    }\n\n    vec<vec<edge>>\
    \ graph() {\n        return g;\n    }\n\n    #undef pb\n};\n\n/*\n@brief \u533A\
    \u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF\n@docs doc/range_edge_graph.md\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/range_edge_graph.hpp
  requiredBy:
  - example/range_edge_graph.example.cpp
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/range_edge_graph.test.cpp
documentation_of: Datastructure/range_edge_graph.hpp
layout: document
redirect_from:
- /library/Datastructure/range_edge_graph.hpp
- /library/Datastructure/range_edge_graph.hpp.html
title: "\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF"
---
## 概要
区間に辺を貼るテクを実際に行い、そのグラフを返す。**フローの場合は未verified。**<br>
特徴 : 一般に対応しているので、定数倍が悪い。メモリも悪い。<br>
参考 : https://x.com/noshi91/status/1193177214453338113

## コンストラクタ
**range_edge_graph gh(int N)** ... [0, N) の頂点のグラフを作成する。 計算量 $O(N)$
<br>


## 関数

- **add_edge(int sl, int sr, int tl, int tr, ll cost, ll cap)**...[sl, tl) から [tl, tr) へコスト = cost, 容量 = capの辺を貼る。**半開区間**。最短経路を求める目的の際は、capは任意の値。
    - 計算量 $O(\log{N})$

- **add_edge(int s, int t, ll cost, ll cap)**... sからtへコスト = cost, 容量 = capの辺を貼る。最短経路を求める目的の際は、capは任意の値。
    - 計算量 $O(1)$

- **vec<vec<edge>> graph()**...作成したグラフを返す。
    - **グラフの説明**
    頂点番号 [0, N) が生の頂点を表し、他の頂点が補助頂点である。 
    
    - **使い方**
    例えば、頂点sから頂点tの最短距離を求めたい場合、与えられたグラフにおける頂点sから頂点tへの最短距離を求めれば良い。フローの場合も同様である。ここで、与えられたグラフの頂点数はNを超える事がある。<br>
    具体的には、頂点数のオーダーは $O(N + addedgeが呼ばれた回数)$ であり、辺の数のオーダーは $O(N  + addedgeが呼ばれた回数\log{N})$ である。
    ただし、s, tが [0, N)の範囲を外れた場合の値は未定義である。

## 使用例
```
#include "../Utility/template.hpp"
#include "../Datastructure/range_edge_graph.hpp"


int main() {
    int n = 10;
    range_edge_graph gh(n); //n頂点で無辺のグラフを生成。

    gh.add_edge(0, 3, 6, 9, 10, -1); // [0, 3) の頂点から [6, 9) に向けて 重み = 10の辺を追加。

    gh.add_edge(6, 9, 9, 10, 5, -1); //[6, 9) の頂点から [9, 10) の頂点に向けて　重み = 5の辺を追加。

    gh.add_edge(0, 9, 30, -1); // 0 から 9 に　重み = 30の辺を追加。

    auto g = gh.graph();
    int new_n = g.size();
    //0から9への最短距離を求める。
    
    vec<int> dist(new_n, 100000);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, 0);

    while(!que.empty()) {
        auto [c, v] = que.top();
        que.pop();
        if(dist[v] < c) continue;

        for(auto e : g[v]) {
            if(chmin(dist[e.to], e.cost + c)) {
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    cout << dist[9] << endl; //15
}
```

## グラフの形
https://x.com/noshi91/status/1193177214453338113

## 他
求めたいものが最短距離なのかフローのグラフなのかでグラフの辺の型が少し異なる。<br>
特に、最短距離 && 辺の貼り方が 頂点→区間 のみ || 区間→頂点 のみの場合、より楽で定数倍も良い実装が存在する(oneside_range_edge_graph.hpp)



