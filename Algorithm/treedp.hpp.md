---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/treedp.test.cpp
    title: verify/treedp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/treedp.md
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links: []
  bundledCode: "#line 1 \"Algorithm/treedp.hpp\"\ntemplate <class S,\n          S\
    \ (*op)(S, S),\n          S (*e)(),\n          S (*addroot)(S, int),\n       \
    \   class F,\n          S (*mp)(F, S)>\nstruct TDP {\n    using pif = pair<int,\
    \ F>;\n    using vs = vec<S>;\n    using vvs = vec<vs>;\n\n    int n;\n    vec<vec<pif>>\
    \ g;\n    vvs dp;\n    // dp[v][i] :=  (v \u2192 g[v][i])\u306E\u8FBA\u306B\u3064\
    \u3044\u3066\u3001\n    // g[v][i]\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\
    \u306E\u7D50\u679C\n    vs ans;\n\n    TDP(int n) : n(n) {\n        g.resize(n);\n\
    \        dp = vvs(n);\n        ans = vs(n, e());\n    }\n\n  private:\n    S dfs(int\
    \ v, int p) {\n        S res = e();\n        int d = g[v].size();\n        dp[v].resize(d);\n\
    \        rep(i, 0, d) {\n            int to = g[v][i].first;\n            if (to\
    \ == p) continue;\n            dp[v][i] = dfs(to, v);\n            res = op(res,\
    \ mp(g[v][i].second, dp[v][i]));\n            // \u90E8\u5206\u6728\u306E\u7D50\
    \u679C\u3092\u96C6\u7D04\u3002\n            // \u672C\u5B9F\u88C5\u3067\u306F\u8FBA\
    \u3092\u52A0\u5473 ->\n            // \u90E8\u5206\u6728\u96C6\u7D04\u306E\u9806\
    \u3092\u5FB9\u5E95\u3057\u3066\u3044\u308B(\u8FBB\u8904\u304C\u5408\u3046\u306A\
    \u3089\u3044\u3064\u3067\u3082\u826F\u3044)\n        }\n        // \u8FBA\u30FB\
    \u9802\u70B9\u3092add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\
    \u306E\u3092\u8FD4\u3059\u3002\n        return addroot(res, v);\n    }\n\n   \
    \ void bfs(int v, S par, int p) {\n        int d = g[v].size();\n        rep(i,\
    \ 0, d) if (g[v][i].first == p) dp[v][i] = par;\n        // \u89AA\u306E\u7D50\
    \u679C\u3092\u6E21\u3057\u3066\u304A\u304F\u3002\n\n        vs L(d + 1, e());\n\
    \        vs R(d + 1, e());\n\n        rep(i, 0, d) L[i + 1] = op(L[i], mp(g[v][i].second,\
    \ dp[v][i]));\n        rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i\
    \ + 1]);\n        // \u672C\u5B9F\u88C5\u3067\u306F\u8FBA\u3092\u52A0\u5473 ->\n\
    \        // \u90E8\u5206\u6728\u96C6\u7D04\u306E\u9806\u3092\u5FB9\u5E95\u3057\
    \u3066\u3044\u308B(\u8FBB\u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\u3067\
    \u3082\u826F\u3044)\n\n        ans[v] = addroot(L[d], v);\n        // \u8FBA\u30FB\
    \u9802\u70B9\u3092add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\
    \u306E\u3092\u8FD4\u3059\u3002ans\u306B\u683C\u7D0D\u3059\u308B\u6642\u3060\u3051\
    \u4F55\u304B\u5F04\u308A\u305F\u3044\u306A\u3089\u3053\u3053\u3092\u5F04\u308B\
    \u3002\n\n        rep(i, 0, d) {\n            int to = g[v][i].first;\n      \
    \      if (to == p) continue;\n            S nx = op(L[i], R[i + 1]);\n      \
    \      // \u672C\u5B9F\u88C5\u3067\u306F\u8FBA\u3092\u52A0\u5473 ->\n        \
    \    // \u90E8\u5206\u6728\u96C6\u7D04\u306E\u9806\u3092\u5FB9\u5E95\u3057\u3066\
    \u3044\u308B(\u8FBB\u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\u3067\u3082\
    \u826F\u3044)\n\n            bfs(to, addroot(nx, v), v);\n            // to ->\
    \ v\u306E\u5411\u304D\u306B\u8FBA\u30FB\u9802\u70B9\u3092add\u3057\u305F\u5F71\
    \u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\u3002\n   \
    \     }\n    }\n\n  public:\n    // s -> t \u306B\u91CD\u307Ff\u306E\u8FBA\u3001\
    \ t -> s\u306B\u91CD\u307Fh\u306E\u8FBA\n    void add_edge(int s, int t, F f,\
    \ F h) {\n        g[s].emplace_back(t, f);\n        g[t].emplace_back(s, h);\n\
    \    }\n\n    vec<S> exe() {\n        dfs(0, -1);\n        bfs(0, e(), -1);\n\
    \        return ans;\n    }\n};\n\n/*\n@brief \u5168\u65B9\u4F4D\u6728DP\n@docs\
    \ doc/treedp.md\n*/\n"
  code: "template <class S,\n          S (*op)(S, S),\n          S (*e)(),\n     \
    \     S (*addroot)(S, int),\n          class F,\n          S (*mp)(F, S)>\nstruct\
    \ TDP {\n    using pif = pair<int, F>;\n    using vs = vec<S>;\n    using vvs\
    \ = vec<vs>;\n\n    int n;\n    vec<vec<pif>> g;\n    vvs dp;\n    // dp[v][i]\
    \ :=  (v \u2192 g[v][i])\u306E\u8FBA\u306B\u3064\u3044\u3066\u3001\n    // g[v][i]\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u7D50\u679C\n    vs ans;\n\n\
    \    TDP(int n) : n(n) {\n        g.resize(n);\n        dp = vvs(n);\n       \
    \ ans = vs(n, e());\n    }\n\n  private:\n    S dfs(int v, int p) {\n        S\
    \ res = e();\n        int d = g[v].size();\n        dp[v].resize(d);\n       \
    \ rep(i, 0, d) {\n            int to = g[v][i].first;\n            if (to == p)\
    \ continue;\n            dp[v][i] = dfs(to, v);\n            res = op(res, mp(g[v][i].second,\
    \ dp[v][i]));\n            // \u90E8\u5206\u6728\u306E\u7D50\u679C\u3092\u96C6\
    \u7D04\u3002\n            // \u672C\u5B9F\u88C5\u3067\u306F\u8FBA\u3092\u52A0\u5473\
    \ ->\n            // \u90E8\u5206\u6728\u96C6\u7D04\u306E\u9806\u3092\u5FB9\u5E95\
    \u3057\u3066\u3044\u308B(\u8FBB\u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\
    \u3067\u3082\u826F\u3044)\n        }\n        // \u8FBA\u30FB\u9802\u70B9\u3092\
    add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\u3002\n        return addroot(res, v);\n    }\n\n    void bfs(int v, S\
    \ par, int p) {\n        int d = g[v].size();\n        rep(i, 0, d) if (g[v][i].first\
    \ == p) dp[v][i] = par;\n        // \u89AA\u306E\u7D50\u679C\u3092\u6E21\u3057\
    \u3066\u304A\u304F\u3002\n\n        vs L(d + 1, e());\n        vs R(d + 1, e());\n\
    \n        rep(i, 0, d) L[i + 1] = op(L[i], mp(g[v][i].second, dp[v][i]));\n  \
    \      rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i + 1]);\n    \
    \    // \u672C\u5B9F\u88C5\u3067\u306F\u8FBA\u3092\u52A0\u5473 ->\n        //\
    \ \u90E8\u5206\u6728\u96C6\u7D04\u306E\u9806\u3092\u5FB9\u5E95\u3057\u3066\u3044\
    \u308B(\u8FBB\u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\u3067\u3082\u826F\
    \u3044)\n\n        ans[v] = addroot(L[d], v);\n        // \u8FBA\u30FB\u9802\u70B9\
    \u3092add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\u3057\u305F\u3082\u306E\u3092\
    \u8FD4\u3059\u3002ans\u306B\u683C\u7D0D\u3059\u308B\u6642\u3060\u3051\u4F55\u304B\
    \u5F04\u308A\u305F\u3044\u306A\u3089\u3053\u3053\u3092\u5F04\u308B\u3002\n\n \
    \       rep(i, 0, d) {\n            int to = g[v][i].first;\n            if (to\
    \ == p) continue;\n            S nx = op(L[i], R[i + 1]);\n            // \u672C\
    \u5B9F\u88C5\u3067\u306F\u8FBA\u3092\u52A0\u5473 ->\n            // \u90E8\u5206\
    \u6728\u96C6\u7D04\u306E\u9806\u3092\u5FB9\u5E95\u3057\u3066\u3044\u308B(\u8FBB\
    \u8904\u304C\u5408\u3046\u306A\u3089\u3044\u3064\u3067\u3082\u826F\u3044)\n\n\
    \            bfs(to, addroot(nx, v), v);\n            // to -> v\u306E\u5411\u304D\
    \u306B\u8FBA\u30FB\u9802\u70B9\u3092add\u3057\u305F\u5F71\u97FF\u3092\u53CD\u6620\
    \u3057\u305F\u3082\u306E\u3092\u8FD4\u3059\u3002\n        }\n    }\n\n  public:\n\
    \    // s -> t \u306B\u91CD\u307Ff\u306E\u8FBA\u3001 t -> s\u306B\u91CD\u307F\
    h\u306E\u8FBA\n    void add_edge(int s, int t, F f, F h) {\n        g[s].emplace_back(t,\
    \ f);\n        g[t].emplace_back(s, h);\n    }\n\n    vec<S> exe() {\n       \
    \ dfs(0, -1);\n        bfs(0, e(), -1);\n        return ans;\n    }\n};\n\n/*\n\
    @brief \u5168\u65B9\u4F4D\u6728DP\n@docs doc/treedp.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/treedp.hpp
  requiredBy: []
  timestamp: '2024-10-22 05:36:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/treedp.test.cpp
documentation_of: Algorithm/treedp.hpp
layout: document
redirect_from:
- /library/Algorithm/treedp.hpp
- /library/Algorithm/treedp.hpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
## 概要
抽象化した全方位木DP。逆元を仮定していない。

## 注意喚起
これを貼るだけで解けないのなら、ライブラリを改造して対応しようとせずに、一から書いた方が遥かに速い場合が多い。

## 全方位と相性が悪いであろう木DPのタイプ
- mergeに時間がかかるdp
例えば、2乗の木DP。全方位にせずに、全ての頂点について毎回木DPした方が良さそう。

## このテンプレと相性が悪いタイプ
- mergeに補助的なデータ構造が必要な木dp
- 逆元を用いた場合に高速なタイプ
例: 子の頂点のうち、k番目に大きい値を根のスコアとする

## 手を加えなくても解ける問題のタイプ
- 部分木の結果のmergeが高速であるdp
affine変換等


## コンストラクタ
**TDP<S, op, e, addroot, F, mp> tdp(n)** 

- **S**
部分木の結果を格納する型

- **F**
部分木の根に辺を追加することによる、部分木の結果への影響を計算するのに必要な情報を格納する型

- **S op(l S, r S)**
部分木の結果をmergeする関数。この際、l, r共に辺の情報は反映済みである。

- **S e()**
結果の単位元。単位元が思い浮かばない場合、返り値を特殊なものにしてopで弾く。
- **S addroot(S s, int now)**
vの子の結果を(辺の情報を含めて)mergeしたものSと、自分の頂点番号vが与えられるのでそれにvの情報を付加し、vの結果を返す

- **S mp(F f, S s)**
ある部分木の結果sに、辺の情報fを付加する。

- **計算量**
    $O(n)$



## 関数

- `void add_edge(int s, int t, F f, F h)`...s, t間に辺を張る。 s->tの重みがf, t->sの重みがh。
    - **制約**
    $0 \le s, t < n$
    - **計算量**
    $O(1)$

- **vec\<S\> exe()**...全方位木DPをする。
    - **計算量**
    addroot, mp, opをそれぞれ$O(頂点数)$回行う。



