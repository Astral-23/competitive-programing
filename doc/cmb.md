## 概要
$O(n)$ 構築・自動拡張 combinationと付随する関数。  

参考 : https://drken1215.hatenablog.com/entry/2018/06/08/210000



## コンストラクタ
`template<typename T, long long mod> cmb` ... modと戻り値の型を指定
- 制約
    - `mod` は素数(assertで落ちる)
    - `(mod-1) * (mod-1)` が `long long` に収まる(assertで落ちない)
- 計算量
    - $O(1)$

- 補遺
    - `using combination998244353 = cmb<atcoder::modint998244353, 998244353>` がエイリアスとして登録されている

## 関数
- 以下の全ての関数について、計算されているテーブル長が足りなかった場合自動で拡張される
    - 計算量  
        - 最終的なテーブルのサイズを $n$ として $\Theta(n)$
- `T C(int n, int k)`... $\binom{n}{r}$

- `T B(int n)`... $n!$

- `T invB(int n)`... $\frac{1}{n!}$

- `T H(int n, int k)`... $\binom{n+k-1}{k}$ 
    - 補遺
        - 重複あり組み合わせ


- `T Cn(int u)`... $\frac{\binom{2n}{n}}{(n+1)}$ 
    - 補遺
        - カタラン数


## 負の二項係数の扱い
$$ \binom{-a \in \mathbb{N}}{0} = 1, \quad \binom{-a \in \mathbb{N}}{b \neq 0} = 0$$
とした。  

### 成立するもの
$$ \binom{n}{r} = \binom{n-1}{r} + \binom{n-1}{r-1},  \quad \forall n \in  \mathbb{Z}$$
$$ \binom{n}{r} = \binom{n}{n-r} , \quad n, r \in \mathbb{N},  r \le n$$
$$ H(0, 0) = 1 $$


### 成立しないもの
$$ \binom{n}{r} = \binom{n}{n-r} , \quad n, r \in \mathbb{Z_{<0}} $$