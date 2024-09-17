## 概要
cycle検出

## コンストラクタ 
`cycle_detection<directed> (int n)`  directed = true : 有向グラフ　/ directed = false : 無向グラフ　として、n頂点0辺のグラフを生成

## 関数
- `void add_edge(int u, int v)` ... directed = true : 辺 u -> vを追加 / directed = false : 辺 u <-> v を追加
    - 計算量 $O(1)$
  
- `pair<vec<int>, vec<int>> run()` ... サイクルを探す。 ((サイクルに含まれる頂点), (サイクルに使われた辺の番号(:= 何番目に追加されたか))) を返す。サイクルがない場合、空の配列を返す。頂点及び辺の格納時順は
  [こちら](https://judge.yosupo.jp/problem/cycle_detection_undirected)を参照
    - 計算量 $O(|V| + |E|)$


