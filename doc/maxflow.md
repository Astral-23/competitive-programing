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

