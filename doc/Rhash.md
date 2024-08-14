## 概要
Rolling hash。半開区間に注意。

## 使用時に変更する物
`const rhash brh = 200224;` ...値の種類数以上  

`const int MAX_SIZE = 500000;` ... Rhash型で管理できる最大文字列長
- rhash型で管理する場合には関係がない
    - 例えば、後述のpowを用いる事で、長さが10^9の文字列のハッシュを計算することはできる
    - Rhashで管理するメリットは区間取得ができる事のみである
- 他、後述のpowの計算量に関わってくる


注意: 値0に相当する文字を作ると、その項の寄与は0
**特に、0を含むvectorについて無理やりローリングハッシュを取るのはバグの温床**

## コンストラクタ
`TT Rhash (T S)` ... Sのハッシュを計算する。Sはstringや配列。
- 計算量
    $O(|S|)$

## 関数
以下、|S| = nと置く。時間計算量は基本O(1)

- `rhash prod(ll l, ll r)`... [l, r)のハッシュを返す。区間が潰れていた場合、0を返す。
    - 制約
    $0 \le l , r \le n$

- `rhash get(ll p)`... p文字目のハッシュを返す。
    - 制約
    $0 \le p  < n$
    
- `pair<ll, ll> conv(ll l, ll r)`...reverseしたハッシュを逆方向として、正方向の[l, r)と対応する逆方向の区間を返す。回文判定に使う。

- `rhash connect(rhash mae, rhash usiro, ll len_of_usiro)` ... ハッシュを結合する。
    - 計算量
        - len_of_usiro $\le$ MAX_SIZE の時: $O(1)$
        - len_of_usiro > MAX_SIZE の時: $O(\log LenOfUsiro)$
- `rhash rhash_pow(const rhash &x, const ll &y, ll len)`... ハッシュ = x, 長さ = len に対応する文字列を y　個連結した文字列のハッシュを返す
    - 計算量
        -  $O(\log y)$
- `rhash cal_rhash(string S)`...string Sのハッシュを計算して返す。
    - 計算量
        - $O(|S|)$
  
## 使用例

```
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

int main() {
    string s = "abc";
    Rhash S(s); //sのローリングハッシュを持つ構造体を宣言した。

    string t = "abcde";
    Rhash T(t);
    
    cout << S.prod(0, 2) << endl; //s の [0, 2)、つまり"ab"に対応するハッシュを出力

    if(S.prod(0, 3) == T.prod(0, 3)) {
        cout << "一致" << endl;
    }

    if(S.prod(0, 3) != T.prod(2, 5)) {
        cout << "不一致" << endl;
    }

    if(S.get(0) == T.get(0)) {
        cout << "一致" << endl;
    }

    if(S.get(0) != T.get(1)) {
        cout << "不一致" << endl;
    }

    string k = "abcbd";
    string reverse_k = "dbcba";

    Rhash K(k);
    Rhash RK(reverse_k);

    auto[rl, rr] = K.conv(1, 4);//Kの[1, 4)は、そのreverse文字列のどこに対応するか

    if(K.prod(1, 4) == RK.prod(rl, rr)) {
        cout << "bcbは回文" << endl;
    }
}


```
