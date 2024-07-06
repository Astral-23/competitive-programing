## 概要
Rolling hash。半開区間に注意。
最大文字列長・brh(ある項が取りうる値の種類数より大) には毎回注意(pw配列のサイズ。)


## コンストラクタ
TT Rhash rh(T S) ... Sのハッシュを計算する。Sはstringや配列。
- **計算量**
    $O(|S|)$

## 関数
以下、|S| = nと置く。時間計算量は全てO(1)
- **rhash get(int l, int r)**... [l, r)のハッシュを返す。区間が潰れていた場合、0を返す。
    - **制約**
    $0 \le l , r \le n$

- **rhash get(int p)**... p文字目のハッシュを返す。
    - **制約**
    $0 \le p  < n$
    
- **pair<int, int> conv(int l, int r)**...reverseしたハッシュを逆方向として、正方向の[l, r)と対応する逆方向の区間を返す。回文判定に使う。

- **rhash unit(rhash mae, rhash usiro, int len_of_usiro)** ... ハッシュを結合する。
  
## 使用例

```
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

int main() {
    string s = "abc";
    Rhash S(s); //sのローリングハッシュを持つ構造体を宣言した。

    string t = "abcde";
    Rhash T(t);
    
    cout << S.get(0, 2) << endl; //s の [0, 2)、つまり"ab"に対応するハッシュを出力

    if(S.get(0, 3) == T.get(0, 3)) {
        cout << "一致" << endl;
    }

    if(S.get(0, 3) != T.get(2, 5)) {
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

    if(K.get(1, 4) == RK.get(rl, rr)) {
        cout << "bcbは回文" << endl;
    }
}


```
