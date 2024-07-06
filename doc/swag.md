## 概要
値の集約ができるdeque。
名称について、SWAGと呼ばれる事が多い？
参考 : https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1

## コンストラクタ
**SWAG\<S, op\> swag** ... 空のswagを生成する。セグ木における単位元が必要無いことに注意。計算量 $O(1)$
- **S**
モノイドの型。

- **op**
S (*op) (S, S)
モノイドを2つ受け取り、その演算結果を返す関数を渡す。なお、演算に可換性は要求しない。

## 関数
全て、計算量は償却 $O(1)$
- dequeのpush/pop/size/empty... popは、要素数が0だとassertで落ちる。

- **S get()**... swagに入っているモノイドの集約結果を返す。要素数が0だとassertで落ちる。


