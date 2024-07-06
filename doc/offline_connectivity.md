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
