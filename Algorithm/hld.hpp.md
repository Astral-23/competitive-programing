---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aux_tree.test.cpp
    title: verify/aux_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/hld.test.cpp
    title: verify/hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/hld_lca.test.cpp
    title: verify/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/jumpontree.test.cpp
    title: verify/jumpontree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/oneside_range_edge_graph.test.cpp
    title: verify/oneside_range_edge_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/range_edge_graph.test.cpp
    title: verify/range_edge_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/hld.md
    document_title: HLD
    links: []
  bundledCode: "#line 1 \"Algorithm/hld.hpp\"\nstruct HLD {\n    using vi = vec<int>;\n\
    \    using pi = pair<int, int>;\n    using pll = pair<long long, long long>;\n\
    \    vi in, out, par, root, rev, dep, pre_vs;\n    vec<ll> dep_w;\n    //    \
    \      \u89AA/\u6210\u5206\u306Etop/in\u306E\u4E2D\u8EAB\u2192\u9802\u70B9\u756A\
    \u53F7\n    int n, r;  // \u9802\u70B9\u6570\u3001\u6839\n    \n    static vec<vec<int>>\
    \ extract_graph(const vec<vec<pll>> &G) {\n        vec<vec<int>> g(G.size());\n\
    \        for (int i = 0; i < int(G.size()); i++) {\n            for (auto [w,\
    \ to] : G[i])\n                if (i < to) {\n                    g[i].push_back(to);\n\
    \                    g[to].push_back(i);\n                }\n        }\n     \
    \   return g;\n    }\n    HLD(const vec<vec<pll>> &g, int a) : HLD(extract_graph(g),\
    \ a) {\n        auto dfs = [&](auto f, int v) -> void {\n            for (auto\
    \ [w, to] : g[v])\n                if (to != par[v]) {\n                    dep_w[to]\
    \ = dep_w[v] + w;\n                    f(f, to);\n                }\n        };\n\
    \        dfs(dfs, r);\n    }\n\n    HLD(vec<vi> g, int a) : n(g.size()), r(a)\
    \ {\n        vi siz(n, 0);\n        in = out = root = rev = vi(n);\n        par\
    \ = vi(n, -1);\n        dep = vi(n, 0);\n        dep_w = vec<ll>(n, 0);\n    \
    \    root[r] = r;\n\n        auto dfs_siz = [&](auto f, int v) -> void {\n   \
    \         siz[v]++;\n            for (int &to : g[v])\n                if (to\
    \ != par[v]) {\n                    dep[to] = dep[v] + 1;\n                  \
    \  par[to] = v;\n                    f(f, to);\n                    siz[v] +=\
    \ siz[to];\n                    if (siz[to] > siz[g[v][0]] || g[v][0] == par[v])\n\
    \                        swap(to, g[v][0]);\n                }\n            return;\n\
    \        };\n\n        dfs_siz(dfs_siz, r);\n\n        int t = 0;\n\n        auto\
    \ dfs_hld = [&](auto f, int v) -> void {\n            rev[t] = v;\n          \
    \  in[v] = t++;\n            for (int to : g[v])\n                if (to != par[v])\
    \ {\n                    root[to] = (to == g[v][0] ? root[v] : to);\n        \
    \            f(f, to);\n                }\n            out[v] = t;\n        };\n\
    \n        dfs_hld(dfs_hld, r);\n        for (int i = 0; i < n; i++) dep_w[i] =\
    \ dep[i];\n    }\n\n    // \u4EE5\u4E0B\u3001\u6B32\u3057\u3044\u3082\u306E\u306E\
    \u307F\u66F8\u304F\n\n    int operator()(int v) const { return in[v]; }\n    int\
    \ operator()(int u, int v) const {\n        assert(par[u] == v || par[v] == u);\n\
    \        if(par[u] == v) return in[u];\n        else return in[v];\n    }\n\n\
    \    int lca(int a, int b) {\n        while (1) {\n            if (in[a] > in[b])\
    \ swap(a, b);\n            if (root[a] == root[b]) return a;\n            b =\
    \ par[root[b]];\n        }\n    }\n\n    ll dist(int a, int b) {\n        int\
    \ lc = lca(a, b);\n        return dep_w[a] + dep_w[b] - 2 * dep_w[lc];\n    }\n\
    \n    vec<pi> path(int s, int t, bool edge) {\n        vec<pi> ls, rs;\n     \
    \   while (root[s] != root[t]) {\n            if (dep[root[s]] > dep[root[t]])\
    \ {\n                ls.emplace_back(in[s] + 1, in[root[s]]);  // \u4E0A\u308A\
    \n                s = par[root[s]];\n            } else {\n                rs.emplace_back(in[root[t]],\
    \ in[t] + 1);  // \u4E0B\u308A\n                t = par[root[t]];\n          \
    \  }\n        }\n\n        if (dep[s] > dep[t])\n            ls.emplace_back(in[s]\
    \ + 1, in[t] + edge);  // \u4E0A\u308A\n        else\n            rs.emplace_back(in[s]\
    \ + edge, in[t] + 1);  // \u4E0B\u308A\n\n        reverse(all(rs));\n        for\
    \ (auto &p : rs) ls.push_back(p);\n        return ls;\n    }\n\n    pi subtree(int\
    \ u, bool edge) { return pi(in[u] + edge, out[u]); }\n\n    int kth_ancestor(int\
    \ v, int k) {\n        if (k > dep[v]) return -1;\n        while (v >= 0) {\n\
    \            if (k <= dep[v] - dep[root[v]]) {\n                return rev[in[v]\
    \ - k];\n            } else {\n                k -= dep[v] - dep[root[v]] + 1;\n\
    \                v = par[root[v]];\n            }\n        }\n    }\n\n    int\
    \ jump(int s, int t, int k) {\n        int m = lca(s, t);\n        int le = dep[s]\
    \ - dep[m];\n        int ri = dep[t] - dep[m];\n        if (0 <= k && k <= le\
    \ + ri) {\n            if (k < le)\n                return kth_ancestor(s, k);\n\
    \            else\n                return kth_ancestor(t, le + ri - k);\n    \
    \    }\n        return -1;\n    }\n\n    int aux_tree(vi vs, vec<vi> &g) {\n \
    \       if (vs.empty()) return -1;\n\n        auto cmp = [&](int i, int j) { return\
    \ in[i] < in[j]; };\n        sort(all(vs), cmp);\n        int m = vs.size();\n\
    \n        rep(i, 0, m - 1) vs.push_back(lca(vs[i], vs[i + 1]));\n        sort(all(vs),\
    \ cmp);\n        vs.erase(unique(all(vs)), vs.end());\n\n        vi st;\n    \
    \    for (auto v : vs) {\n            while (st.size()) {\n                int\
    \ p = st.back();\n                if (in[p] < in[v] && in[v] < out[p]) break;\n\
    \                st.pop_back();\n            }\n            if (st.size()) {\n\
    \                g[st.back()].push_back(v);\n                g[v].push_back(st.back());\n\
    \            }\n            st.push_back(v);\n        }\n\n        swap(vs, pre_vs);\n\
    \        return pre_vs[0];\n    }\n\n    void clean(vec<vi> &g) {\n        for\
    \ (auto v : pre_vs) g[v] = vi();\n        pre_vs = vi();\n        return;\n  \
    \  }\n};\n/*\n@brief HLD\n@docs doc/hld.md\n*/\n"
  code: "struct HLD {\n    using vi = vec<int>;\n    using pi = pair<int, int>;\n\
    \    using pll = pair<long long, long long>;\n    vi in, out, par, root, rev,\
    \ dep, pre_vs;\n    vec<ll> dep_w;\n    //          \u89AA/\u6210\u5206\u306E\
    top/in\u306E\u4E2D\u8EAB\u2192\u9802\u70B9\u756A\u53F7\n    int n, r;  // \u9802\
    \u70B9\u6570\u3001\u6839\n    \n    static vec<vec<int>> extract_graph(const vec<vec<pll>>\
    \ &G) {\n        vec<vec<int>> g(G.size());\n        for (int i = 0; i < int(G.size());\
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
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/hld.hpp
  requiredBy: []
  timestamp: '2025-02-20 17:16:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/oneside_range_edge_graph.test.cpp
  - verify/hld.test.cpp
  - verify/jumpontree.test.cpp
  - verify/range_edge_graph.test.cpp
  - verify/hld_lca.test.cpp
  - verify/aux_tree.test.cpp
documentation_of: Algorithm/hld.hpp
layout: document
redirect_from:
- /library/Algorithm/hld.hpp
- /library/Algorithm/hld.hpp.html
title: HLD
---
## 概要
Heavy Light Decompositionをする。
データ構造などは載せずに、単にパスの集合を返すような実装である。<br>
実装の参考 : https://ebi-fly13.github.io/icpc_library/tree/HeavyLightDecomposition.hpp <br>
実装の参考 : https://github.com/saphmitchy/deliair-lib


## コンストラクタ
` HLD(vec<vi> &g, int a)` ... グラフと根を指定する。 
- 計算量 $O(頂点数)$

## 関数
以下、頂点数をnと置く。特に断りのない限り、計算量は $O(\log n)$ である。

- `int operator()(int v)`... 頂点v の　行きがけ順を返す。
    - 計算量 $O(1)$
- `int lca(int a, int b)`...lca(a, b)  

- `vec<pair<int, int>> path(int s, int t, bool edge)` s→tのパスに対応する区間の集合を返す。また、edge = trueならば辺属性、 falseならば頂点属性である。
- `pair<int, int> subtree(int u, bool edge)`...uの部分木に対応する区間を返す。また、edge = trueならば辺属性、 falseならば頂点属性である。
    - 計算量 $O(1)$
- `kth_ancestor(int v, int k)` ...vからk個だけ辺を登った所にある頂点を返す。そのような頂点が存在しないなら-1を返す。
- `jump(int s, int t, int k)` ... sからtの方向に丁度k個辺を辿った所にある頂点を返す。tを超えてしまう場合は-1を返す。
- `int aux_tree(vec<int> vs, vec<vec<int>> &g)` 元の木から、「vsに含まれる頂点 と、 vsに含まれる頂点同士のLCAとなりうる頂点」を残して圧縮した木をgとして返す。戻り値は、圧縮した木の根。グラフが空の場合-1を返す。
    - 計算量 $O(\|vs\|log\|vs\|)$
    - 木のサイズ $O(|vs|)$

aux_tree 参考 : https://atcoder.jp/contests/abc340/editorial/9249

## 用語
- 頂点属性 <br>

頂点の値を管理する。

- 辺属性 <br>

辺の値を管理する。 <br>

辺の番号について、「頂点 v から根に伸びる辺」が　番号 v の辺である。ここで、辺 root は存在しない。 <br>

部分木内の辺の値を変更するといった場合、部分木から上に伸びる辺を含めたくなく、そういった事情から`edge`フラグが存在する。

また、パスについても、「lcaの頂点から根に伸びる辺」を含めたくない場合が多く、`edge == true`だとそれを含めない。



## 使い方
**セグメント木等と対応させる場合、
sge[i] := hld.in[i] の頂点の値
とする必要がある。**

・**コンストラクタ**
注意 : セグメント木等と併用する && 初期化を配列で行う場合、配列の中身をhldのinの値に応じて並び替える必要が出てくる。
```
HLD hld(G, 0);
vec<ll> B(N);
rep(i,0,N) B[hld(i)] = A[i];
segtree<S, op, e> seg(B);

```
<br>

・**path**
ペアを順に見ていけば良い。
ただし、あるペアが(l, r)だったとして
[1] l <= rの時   [l, r)を表す。下に対応する。
[2] l > rの時  [r, l) を表す。上りに対応する。
のようになる。

演算が可換の時
```
auto ps = hld.path(u, v, false);
ll res = 0;
for(auto [l, r] : ps) {
    if(l >= r) swap(l, r);
    res = op(res, seg.prod(l, r));
}
```

演算が非可換の時
```
S op(S l, S r) {...}

S op2(S l, S r) {
    return op(r, l);
}

...

segtree<S, op, e> seg;
segtree<S, op2, e> seg2;

...


auto ps = hld.path(u, v, false);
ll res = 0;
for(auto [l, r] : ps) {
    if(l <= r) res = op(res, seg(l, r));
    else res = op(res, seg2(r, l));

}
```
<br>

・**値の変更**
注意: 元の頂点番号でセグ木に変更をかけてはいけない。
セグ木の時
```

seg.set(hld(v), new_val);
seg2.set(hld(v), new_val);
```

遅延セグ木の時
```
auto ps = hld.path(u, v, false);
for(auto [l, r] : ps) {
    if(l >= r) swap(l, r);
    seg.apply(l, r, f);
    seg2.apply(l, r, f);
}
```

## auxiliary_treeについて

### auxiliary_treeの使用例

```
#include "../Utility/template.hpp"
#include "../Algorithm/hld.hpp"

int main() {
    int n = 6;
    vec<vec<int>> g(n);
    rep(i, 0, n-1) g[i].push_back(i+1); // 0 - 1 - 2 - 3 - 4 - 5 型の木。

    HLD hld(g, 0); // 0を根としてhldを実行

    cout << hld.lca(0, 3) << endl; // 0


    // auxiliary_treeの使い方
    // (1) : n頂点空のグラフを作成
    vec<vec<int>> ng(n);

    // (2) : 圧縮木に入れたい頂点集合を配列に格納
    vec<int> vs = {1, 3, 5};

    // (3) hldのaux_treeを呼ぶ。
    int r = hld.aux_tree(vs, ng);
        //参照で渡したngにグラフが入っている(無向辺・双方向である。)。
        //ｒは生成されたグラフの根(特に、必ずしも元のグラフにおける値がngに入っているとは限らない。)
    
    // (4) 使用後は、hldの関数を用いてngから辺を削除
    hld.clean(ng);

    // (5) 計算したい頂点集合がまだある場合、(2)に戻る。
}
```

頂点に、頂点番号もデータとして与えたい時
```
rep(i, 0, n) { first_val[hld(i)] = S{dep[i], i};} ... 正しい

rep(i, 0, n) {first_val[hld(i)] = S{dep[hld(i)], hld(i)}; } ... 誤り！
```
### 使用上の注意
[1]gには、サイズがnである空の配列 vec\<vec\<int\>\> g(n)を参照渡しする。
[2]他の補助グラフを求めたくなった場合、新たにgを宣言し直すのではなく、gをclean()関数を使って空にする。
[3]与えられたグラフを使ってdfsや木dpをする場合、返り値として渡されたrootから開始する。特に、元のグラフの根が補助グラフに含まれているとは限らない。

### 気軽に圧縮すると答えが合わない例
**補助グラフは"辺・頂点を無視"することによって成立している。よって、無視した辺や頂点の値が関わってくる場合、工夫が必要となる・もしくは解けない可能性がある。**
[1]頂点間の距離が関わる例
補助グラフは辺を圧縮しているので、元グラフにおける距離を他の手段を用いて得る必要がある。場合によっては、HLDのpathを用いたり、distを用いて解決できるかもしれない。

<br>
<br>

根付き木に対して、以下の用語が定義される。
#### 定義: (頂点vの)子孫 
vから深い方向に辺を辿ることによって辿り着ける頂点集合

#### 定義: (頂点vの)祖先
根→vの最短長のパス上に存在する頂点集合

これより、次の定理が成立する

#### 定理 : uがvの先祖に属する ⇔ vがuの子孫に属する
(図) uが上、vが下のグラフを書く。
- 左 => 右
uは、vから辺を上に辿って辿り着ける頂点である。この時、このパスを逆走することによって、vがuの子孫に属する事が言える。

- 右 => 左
根→vの最短長のパスを求めることを考える。この時、「根 → uの最短長のパス + u→ vの最短長のパス」が条件を満たす。よって、これが根 → vのパスであり、尚且つこのパス上にuが存在することから、uはvの祖先に属する。

#### 定義: (頂点v, uの)LCA 
u, v共に子孫として持つ頂点lであって、最も深い所にある頂点

以下に、同値な定義を与える。
#### 同値な定義:(v, uの)LCA
uの祖先に属し、かつvの祖先に属する頂点lであって、最も深い所にある頂点


この定義より、以下が直ちに言える。
#### 頂点u, vのlcaとしてあり得る頂点は、根→uのパス上にある&&根→vのパス上にある頂点のみである。

祖先の定義より自明。

### 本題

https://atcoder.jp/contests/abc340/editorial/9249
を読む。
補題の証明に上の細かい定理を使う。


