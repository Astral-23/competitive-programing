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


