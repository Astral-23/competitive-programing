


# monotone だと使えるアルゴリズム
## monotone minima
> 命題(monotone minima):  $H \times W$ 行列が与えられた時、各行のargminを $O(アクセス時間 \times W \log H)$ で求められる
- アクセスはスライドアクセス(Moのように $f(i, j)$ を $f(i ± 1、j ± 1)$ から求める) のでも計算量は変化しない


> 系: 
> $$ dp[i] := \min f(i, j) \quad (0 \le j \le W)$$
> の時、 $f$ がmonotoneならばこのdpは上のアルゴリズムで計算できる



# monotone の判定
> 命題: monge $\Rightarrow$ monotone

# mongeの判定
> 命題: 行列 $A$ について、
> $$ monge ⇔ \forall (i, j), \quad  A_{i, j+1} - A_{i, j} \ge A_{i+1, j+1} - A_{i+1, j}$$
- 例: 列に対し区間min, 区間転倒数はmonge

> 命題: monge行列の和はmonge

> 命題: $1$ 行にのみ値 $c$ が、他 $0$ の行列は monge。 $1$ 列にのみ値 $c$ が、他 $0$ の行列は monge。 

> 系: 行/列に加算する操作をしてもmonge 

> 命題: monge行列 $\times k \quad (\ge 0)$ は monge