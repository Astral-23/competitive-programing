## 概要
区間の幅の制限を無くしたセグ木。max_right, min_leftは存在しない。および、配列による初期化はできない。
これが必要になった場合、恐らく座標圧縮すれば解ける。

参考 : https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
参考 : https://kazuma8128.hatenablog.com/

## コンストラクタ
**dynamicsegtree\<S, op, e, W\> seg(min_pos, max_pos)**... [min_pos, max_pos)に収まる範囲のクエリに対応できるセグ木を構成する。Wは、区間の値を持つ型である。(long long推奨)

## 関数
- **set(int p, S x)**...a[p]にxを代入
- **prod(int l, int r)**...[l, r)の演算結果を返す

