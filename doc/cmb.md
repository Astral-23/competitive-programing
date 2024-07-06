## 概要
O(N)構築 combinationと付随する関数。
参考 : https://drken1215.hatenablog.com/entry/2018/06/08/210000

## 省略できるもの
コンストラクタとC(int n, int k)以外の関数はそれぞれ独立なので省略できます。及び、C(int n, int k)以外の関数のverifyはしていません。

## コンストラクタ
**CMB cmb(int r, int mod)** ... modを指定した上で、[0, r]の階乗や整数の逆元を求める  
- **計算量**
    $O(n)$

## 関数

- **ll C(int n, int k)**... $\binom{n}{r}$
    - **制約**
    $n, k \le r$

- **ll B(int n)**... $n!$
    - **制約**
    $0 \le n \le r$

- **ll invB(int n)**... $n!$ の逆元
    - **制約**
    $0 \le n \le r$

- **ll H(int n, int k)**... $\binom{n+k-1}{k}$ 重複あり組み合わせ
    - **制約**
    $n+k-1 \le r$

- **ll Cn(int u)**... $\binom{2n}{n} /(n+1)$ カタラン数
    - **制約**
    $2n \le r$
  
