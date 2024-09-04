---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/offline_connectivity.example.cpp
    title: example/offline_connectivity.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/offline_connectivity.test.cpp
    title: verify/offline_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/offline_connectivity_more.test.cpp
    title: verify/offline_connectivity_more.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/value_dsu.test.cpp
    title: verify/value_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/offline_connectivity.md
    document_title: offline_connectivity
    links: []
  bundledCode: "#line 1 \"Datastructure/offline_connectivity.hpp\"\ntemplate<class\
    \ dsu, class S, class qif, bool multi_edge>\nstruct offline_connectivity {\n \
    \   using pii = pair<int, int>;\n    using edge = array<int, 4>;\n    using que\
    \ = pair<int, qif>;\n    int n, t, sz, qi, li;\n    dsu uf;\n    vec<vec<pii>>\
    \ dat;\n    vec<multiset<pii>> es;\n    vec<edge> lrs;\n    vec<que> qs;\n   \
    \ vec<array<ll, 3>> lz;//{t, \u9802\u70B9, \u4F5C\u7528\u7D20}  \u4F5C\u7528\u7D20\
    \u304Cll\u3067\u306F\u306A\u3044\u5834\u5408\u3001\u9811\u5F35\u308B\u3002\n \
    \   vec<S> res;\n\n    offline_connectivity(int N) : n(N), es(N), qi(0), li(0),\
    \ t(0), sz(1), uf(N) { }\n\n    void build() {\n        rep(u, 0, n) {\n     \
    \       for(auto [v, l] : es[u]) {\n                lrs.push_back(edge{l, t, int(u),\
    \ v});\n            }\n        }\n       \n        while(sz < t) sz <<= 1;\n \
    \       dat.resize(2 * sz);\n\n        for(auto [l, r, u, v] : lrs) {\n      \
    \      l += sz;\n            r += sz;\n            while(l < r) {\n          \
    \      if(l & 1) dat[l++].emplace_back(u, v);\n                if(r & 1) dat[--r].emplace_back(u,\
    \ v);\n                l >>= 1, r >>= 1;\n            }\n        }\n    }\n\n\
    \    TT void dfs(T f, int v) {\n        for(auto [a, b] : dat[v]) uf.merge(a,\
    \ b);\n        if(v >= sz) {\n            while(li < lz.size() && lz[li][0] ==\
    \ v - sz) uf.set(lz[li][1], lz[li][2]), li++;//set\u2192 apply\u306B\u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u304B\u3082(dsu\u306B\u5408\u308F\u305B\u308B)\n\
    \            if(qi < qs.size() && qs[qi].first == v - sz) res.push_back(f(uf,\
    \ qs[qi++].second));\n        }\n        else {\n            dfs(f, v * 2);\n\
    \            dfs(f, v * 2 + 1);\n        }\n        rep(i, 0, dat[v].size()) uf.undo();\n\
    \    }\n    \n\n    TT vec<S> run(T f) {\n        dfs(f, 1);\n        return res;\n\
    \    }\n\n    void link(int u, int v) {\n        if(u > v) swap(u, v);\n     \
    \   if(multi_edge == true) es[u].insert(pii(v, t));\n        else {\n        \
    \    auto it = es[u].lower_bound(pii(v, -1));\n            if(it != es[u].end()\
    \ && (*it).first == v) return;\n            es[u].insert(pii(v, t));\n       \
    \ }\n    }\n\n    void cut(int u, int v) {\n        if(u > v) swap(u, v);\n  \
    \      auto it = es[u].lower_bound(pii(v, -1));\n        if(it == es[u].end())\
    \ return;\n        auto [tar, l] = *it;\n        if(tar != v) return;\n      \
    \  es[u].erase(it);\n        lrs.push_back(edge{l, t, u, v});\n        \n    }\n\
    \n    void query(qif q) {\n        qs.push_back(que(t++, q));\n    }\n\n    void\
    \ apply(int v, ll f) {\n        lz.push_back({t, v, f});\n    }\n\n    void set(int\
    \ v, ll f) {//uf\u306Eapply\u306B\u76F8\u5F53\u3059\u308B\u95A2\u6570\u540D\u304C\
    set\u3060\u3063\u305F\u6642\u7528\n        lz.push_back({t, v, f});\n    }\n\n\
    };\n/*\nS f(dsu &uf, qif q) {\n    return \u7B54\u3048\n}\n\u3092run\u306B\u6E21\
    \u3059\n&\u3092\u4ED8\u3051\u308B\u4E8B\u3092\u5FD8\u308C\u305A\u306B\uFF08\u8A08\
    \u7B97\u91CF\u3053\u308F\u308C\u308B\uFF09\n\n@brief offline_connectivity\n@docs\
    \ doc/offline_connectivity.md\n*/\n"
  code: "template<class dsu, class S, class qif, bool multi_edge>\nstruct offline_connectivity\
    \ {\n    using pii = pair<int, int>;\n    using edge = array<int, 4>;\n    using\
    \ que = pair<int, qif>;\n    int n, t, sz, qi, li;\n    dsu uf;\n    vec<vec<pii>>\
    \ dat;\n    vec<multiset<pii>> es;\n    vec<edge> lrs;\n    vec<que> qs;\n   \
    \ vec<array<ll, 3>> lz;//{t, \u9802\u70B9, \u4F5C\u7528\u7D20}  \u4F5C\u7528\u7D20\
    \u304Cll\u3067\u306F\u306A\u3044\u5834\u5408\u3001\u9811\u5F35\u308B\u3002\n \
    \   vec<S> res;\n\n    offline_connectivity(int N) : n(N), es(N), qi(0), li(0),\
    \ t(0), sz(1), uf(N) { }\n\n    void build() {\n        rep(u, 0, n) {\n     \
    \       for(auto [v, l] : es[u]) {\n                lrs.push_back(edge{l, t, int(u),\
    \ v});\n            }\n        }\n       \n        while(sz < t) sz <<= 1;\n \
    \       dat.resize(2 * sz);\n\n        for(auto [l, r, u, v] : lrs) {\n      \
    \      l += sz;\n            r += sz;\n            while(l < r) {\n          \
    \      if(l & 1) dat[l++].emplace_back(u, v);\n                if(r & 1) dat[--r].emplace_back(u,\
    \ v);\n                l >>= 1, r >>= 1;\n            }\n        }\n    }\n\n\
    \    TT void dfs(T f, int v) {\n        for(auto [a, b] : dat[v]) uf.merge(a,\
    \ b);\n        if(v >= sz) {\n            while(li < lz.size() && lz[li][0] ==\
    \ v - sz) uf.set(lz[li][1], lz[li][2]), li++;//set\u2192 apply\u306B\u3059\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u304B\u3082(dsu\u306B\u5408\u308F\u305B\u308B)\n\
    \            if(qi < qs.size() && qs[qi].first == v - sz) res.push_back(f(uf,\
    \ qs[qi++].second));\n        }\n        else {\n            dfs(f, v * 2);\n\
    \            dfs(f, v * 2 + 1);\n        }\n        rep(i, 0, dat[v].size()) uf.undo();\n\
    \    }\n    \n\n    TT vec<S> run(T f) {\n        dfs(f, 1);\n        return res;\n\
    \    }\n\n    void link(int u, int v) {\n        if(u > v) swap(u, v);\n     \
    \   if(multi_edge == true) es[u].insert(pii(v, t));\n        else {\n        \
    \    auto it = es[u].lower_bound(pii(v, -1));\n            if(it != es[u].end()\
    \ && (*it).first == v) return;\n            es[u].insert(pii(v, t));\n       \
    \ }\n    }\n\n    void cut(int u, int v) {\n        if(u > v) swap(u, v);\n  \
    \      auto it = es[u].lower_bound(pii(v, -1));\n        if(it == es[u].end())\
    \ return;\n        auto [tar, l] = *it;\n        if(tar != v) return;\n      \
    \  es[u].erase(it);\n        lrs.push_back(edge{l, t, u, v});\n        \n    }\n\
    \n    void query(qif q) {\n        qs.push_back(que(t++, q));\n    }\n\n    void\
    \ apply(int v, ll f) {\n        lz.push_back({t, v, f});\n    }\n\n    void set(int\
    \ v, ll f) {//uf\u306Eapply\u306B\u76F8\u5F53\u3059\u308B\u95A2\u6570\u540D\u304C\
    set\u3060\u3063\u305F\u6642\u7528\n        lz.push_back({t, v, f});\n    }\n\n\
    };\n/*\nS f(dsu &uf, qif q) {\n    return \u7B54\u3048\n}\n\u3092run\u306B\u6E21\
    \u3059\n&\u3092\u4ED8\u3051\u308B\u4E8B\u3092\u5FD8\u308C\u305A\u306B\uFF08\u8A08\
    \u7B97\u91CF\u3053\u308F\u308C\u308B\uFF09\n\n@brief offline_connectivity\n@docs\
    \ doc/offline_connectivity.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/offline_connectivity.hpp
  requiredBy:
  - example/offline_connectivity.example.cpp
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/value_dsu.test.cpp
  - verify/offline_connectivity_more.test.cpp
  - verify/offline_connectivity.test.cpp
documentation_of: Datastructure/offline_connectivity.hpp
layout: document
redirect_from:
- /library/Datastructure/offline_connectivity.hpp
- /library/Datastructure/offline_connectivity.hpp.html
title: offline_connectivity
---
## 概要
クエリが先読み可能な時のグラフのconnectivity。logが2つつくが、比較的高速である。
参考 : https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html


## コンストラクタ
**offline_connectivity<dsu, S, qif, (bool)multi_edge> uf(n)** ... [0, n) の頂点のグラフを作成する。 計算量$O(n)$
- **dsu**
要件 : 要素数を引数に持つコンストラクタ、merge(u, v), undo(u, v)
注意 : 本実装が想定しているdsuの実装において、 undoは「直前のmergeを無かったことにする」動きをしなければならない。例えば、merge(u, v)をする直前においてu, vが連結であったとしても、そのmergeは「実行されたmerge」としてundoの対象となる。

- **S**
クエリの答えを収納する型

- **qif**
クエリに答えるのに必要な情報を収納する型。後述の使い方参照。

- **multi_edge**
trueの時多重辺を有効に、falseの時多重辺を無効にする。
**端、multi_edge = trueの時のverifyはランダムテストケースでしかしてない。**

**無効の時**<br>
link(u, v) : u - v辺が既にあるならば、何もしない。無かったら、u-v辺を追加する。<br>
cut(u, v) :u - v辺が存在するならば切る。存在しなければ何もしない。<br>

**有効の時**<br>
link(u, v) : u - v辺を1本追加する。<br>
cut(u, v) : u - v辺が存在するのなら1本切る。<br>
<br>


## 関数

- **link(int u, int v)**...u-v辺を張る。詳しい挙動は上記参照。
    - 計算量 $O(\log{n})$

- **cut(int u, int v)**... u-v辺を切る。詳しい挙動は上記参照。
    - 計算量 $O(\log{n})$

- **void query(qif q)** ... クエリを飛ばす。クエリの情報をqとして入れる。
    - 計算量 $O(\log{n})$

- **void set/apply(int v, ll f)** ... 頂点vにfを作用させる。
    - 計算量 $O(\log{n})$
    
- **void build()**...与えられた情報を元に、処理の準備をする。
    - 計算量 $O((linkの回数 + cutの回数) \times \log{queryを読んだ回数})$
- **vec\<S\> run(S (\*f)(dsu &uf, qif q))**...クエリを処理し、結果を入れた配列を返す。配列のi番目には、i番目のqueryの結果が入る。
    - 計算量 $O((linkの回数 + cutの回数) \times \log{n} \log{queryを呼んだ回数})$
    - 使い方<br>
    この関数において、fはユーザーが定義する関数であり、当然処理もユーザーが決める。よって、この時必要だと思うものをqif型として格納しておく。また、クエリを計算するために、ユーザーにはクエリを処理する時点でのdsuが与えられる。**このdsuは参照で受け取らなければならない。** <br>

```
using dsu = undable_dsu;
using S = int;
using qif = int;
S f(dsu &uf, qif info) {
    return uf.size(info);
}
```
    
## 使用例
クエリとして、2頂点の連結性を問う場合。<br>

```
#include "../Utility/template.hpp"
#include "../Datastructure/undabledsu.hpp"
#include "../Datastructure/offline_connectivity.hpp"

int main() {
    int n = 10;
    offline_connectivity<dsu, bool, pair<int, int>, false> uf(n); 
    /* 
      n頂点の offlien_connevtivityを宣言。　使用するdsuの型名がdsu 答えの型がbool クエリの型がpair<int, int> 多重辺無し
      この状態では、無辺のグラフ。
    */

    uf.link(0, 1);// 0, 1に辺を貼る。

    uf.query(pair<int, int>(0, 1)); // 0, 1についてクエリを飛ばす

    uf.cut(0, 1); // 0, 1辺を切る

    uf.query(pair<int, int>(0, 1)); // 0, 1についてクエリを飛ばす。


    uf.build(); //クエリを飛ばし終わったら呼ぶ。

    auto f = [&](dsu &UF, pair<int, int> query) {
        return UF.same(query.first, query.second);
    };
    //クエリを処理する関数。 dsuは参照で受け取る。

    vec<bool> res = uf.run(f); //fを引数に渡し、結果を受け取る。

    if(res[0] == true) cout << "0と1は連結だった" << endl;
    if(res[1] == false) cout << "0と1は不連結になった" << endl; 
}
```

<br>

## 注意
値の集約について : undo可能dsuに任せている。値の変更がある場合、逆元がないと出来ない。(例 : +, xor)<br>
ただし、値変更がないならば逆元がない(max,min,gcd...)でも可能(だと考えている。この場合、undodsuの実装を少し変更する必要がある。)<br>
自己辺に対応している。

## 解けない問題
クエリを処理する過程において、クエリの結果が必要となるような問題。<br>
例 : (u, v)が今同じ連結成分かどうかで次のクエリが変化する
