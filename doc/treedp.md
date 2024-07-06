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

## 解決策
全てを書き直す(そんな)

```
...

    S dfs(int v, int p) {
        S res = e();
        int d = g[v].size();
        dp[v].resize(d);
        rep(i, 0, d) {
            int to = g[v][i].first;
            if(to == p) continue;
            dp[v][i] = dfs(to, v);
            //res = op(res, mp(g[v][i].second, dp[v][i]));
            //dfsの段階。部分木の結果をmergeする。
        }
        //return addroot(res, v);
        //vの情報を付加して返す。
    }

    void bfs(int v, S par, int p) {
        int d = g[v].size();
        rep(i, 0, d) if(g[v][i].first == p) dp[v][i] = par;

       // vs L (d + 1, e());逆元を仮定するのでいらない。
       // vs R (d + 1, e());

        //rep(i, 0, d) L[i+1] = op(L[i], mp(g[v][i].second, dp[v][i]));
        //rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i+1]);
        
        //このように、子全部の結果をmergeする。必要ならここでデータ構造を作る。
        S res = e();
        rep(i, 0, d) res = op(res, mp(g[v][i].second, res));
       
        //ここは変化なし。
        ans[v] = addroot(L[d], v);
      
        rep(i, 0, d) {
            int to = g[v][i].first;
            //行き先の結果を省く。
            S to_res = dp[v][i];
            
            if(to == p) continue;

            res -= to_res;
            bfs(to, addroot(res, v), v);
            res += to_res;
        }

    }

...

```

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

- **add_edge(int s, int t, F f)**...辺の情報をfとして、s→tの有向辺を追加
    - **制約**
    $0 \le s, t < n$
    - **計算量**
    $O(1)$

- **vec\<S\> exe()**...全方位木DPをする。
    - **計算量**
    addroot, mp, opをそれぞれ$O(頂点数)$回行う。



