---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination.test.cpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/cmb.md
    document_title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
    links: []
  bundledCode: "#line 1 \"Math/combination.hpp\"\ntemplate <typename T, long long\
    \ mod> struct combination {\n    vector<long long> fac, ifac, inv;\n    long long\
    \ N;\n    combination() {\n        fac.resize(2, 1);\n        ifac.resize(2, 1);\n\
    \        inv.resize(2, 1);\n        N = 1;\n    }\n\n    void reserve(long long\
    \ n) { expand(n); }\n\n    T operator()(int n, int k) { return C(n, k); }\n\n\
    \    T C(int n, int k) {\n        if (k < 0) return 0;\n        if (k == 0) return\
    \ 1;\n        if (n < k) return 0;\n        if (N < n) expand(n);\n        return\
    \ fac[n] * ifac[n - k] % mod * ifac[k] % mod;\n    }\n\n    T P(int n, int k)\
    \ {\n        if (k < 0) return 0;\n        if (k == 0) return 1;\n        if (n\
    \ < k) return 0;\n        if (N < n) expand(n);\n        return fac[n] * ifac[n\
    \ - k] % mod;\n    }\n\n    T B(int n) {\n        if (N < n) expand(n);\n    \
    \    return (n < 0 ? 0 : fac[n]);\n    }\n    T invB(int n) {\n        if (N <\
    \ n) expand(n);\n        return (n < 0 ? 0 : ifac[n]);\n    }\n\n    T H(int n,\
    \ int k) {\n        return C(n + k - 1, k);\n    }\n\n    T Cn(int n) { return\
    \ C(2 * n, n) * inv[n + 1] % mod; }\n\n  private:\n    constexpr static bool is_prime_constexpr(long\
    \ long x) {\n        if (x <= 1) return false;\n        for (long long i = 2;\
    \ i * i <= x; i++) {\n            if (x % i == 0) return false;\n        }\n \
    \       return true;\n    }\n\n    static_assert(is_prime_constexpr(mod), \"mod\
    \ must be prime\");\n\n    long long extgcd(long long a, long long b, long long\
    \ &x, long long &y) {\n        if (b == 0) {\n            x = 1;\n           \
    \ y = 0;\n            return a;\n        }\n        auto d = extgcd(b, a % b,\
    \ y, x);\n        y -= a / b * x;\n        return d;\n    }\n\n    long long modinv(long\
    \ long a) {\n        long long x, y;\n        extgcd(a, mod, x, y);\n        x\
    \ %= mod;\n        if (x < 0) x += mod;\n        return x;\n    }\n\n    void\
    \ expand(long long new_max_n) {\n        if (new_max_n <= N) return;\n       \
    \ long long nx = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\u3066\u3044\
    \u304F\u3002\n        while (nx < new_max_n) nx <<= 1;\n        new_max_n = nx;\n\
    \n        long long pre = N;\n        N = new_max_n;\n        fac.resize(N + 1);\n\
    \        ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for (long long\
    \ i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i % mod;\n  \
    \      }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N] * fac[N\
    \ - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n      \
    \      ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i] *\
    \ fac[i - 1] % mod;\n        }\n        return;\n    }\n};\n\nusing combination998244353\
    \ = combination<atcoder::modint998244353, 998244353>;\n/*\n@brief \u30B3\u30F3\
    \u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n*/\n"
  code: "template <typename T, long long mod> struct combination {\n    vector<long\
    \ long> fac, ifac, inv;\n    long long N;\n    combination() {\n        fac.resize(2,\
    \ 1);\n        ifac.resize(2, 1);\n        inv.resize(2, 1);\n        N = 1;\n\
    \    }\n\n    void reserve(long long n) { expand(n); }\n\n    T operator()(int\
    \ n, int k) { return C(n, k); }\n\n    T C(int n, int k) {\n        if (k < 0)\
    \ return 0;\n        if (k == 0) return 1;\n        if (n < k) return 0;\n   \
    \     if (N < n) expand(n);\n        return fac[n] * ifac[n - k] % mod * ifac[k]\
    \ % mod;\n    }\n\n    T P(int n, int k) {\n        if (k < 0) return 0;\n   \
    \     if (k == 0) return 1;\n        if (n < k) return 0;\n        if (N < n)\
    \ expand(n);\n        return fac[n] * ifac[n - k] % mod;\n    }\n\n    T B(int\
    \ n) {\n        if (N < n) expand(n);\n        return (n < 0 ? 0 : fac[n]);\n\
    \    }\n    T invB(int n) {\n        if (N < n) expand(n);\n        return (n\
    \ < 0 ? 0 : ifac[n]);\n    }\n\n    T H(int n, int k) {\n        return C(n +\
    \ k - 1, k);\n    }\n\n    T Cn(int n) { return C(2 * n, n) * inv[n + 1] % mod;\
    \ }\n\n  private:\n    constexpr static bool is_prime_constexpr(long long x) {\n\
    \        if (x <= 1) return false;\n        for (long long i = 2; i * i <= x;\
    \ i++) {\n            if (x % i == 0) return false;\n        }\n        return\
    \ true;\n    }\n\n    static_assert(is_prime_constexpr(mod), \"mod must be prime\"\
    );\n\n    long long extgcd(long long a, long long b, long long &x, long long &y)\
    \ {\n        if (b == 0) {\n            x = 1;\n            y = 0;\n         \
    \   return a;\n        }\n        auto d = extgcd(b, a % b, y, x);\n        y\
    \ -= a / b * x;\n        return d;\n    }\n\n    long long modinv(long long a)\
    \ {\n        long long x, y;\n        extgcd(a, mod, x, y);\n        x %= mod;\n\
    \        if (x < 0) x += mod;\n        return x;\n    }\n\n    void expand(long\
    \ long new_max_n) {\n        if (new_max_n <= N) return;\n        long long nx\
    \ = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\u3066\u3044\u304F\u3002\
    \n        while (nx < new_max_n) nx <<= 1;\n        new_max_n = nx;\n\n      \
    \  long long pre = N;\n        N = new_max_n;\n        fac.resize(N + 1);\n  \
    \      ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for (long long\
    \ i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i % mod;\n  \
    \      }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N] * fac[N\
    \ - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n      \
    \      ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i] *\
    \ fac[i - 1] % mod;\n        }\n        return;\n    }\n};\n\nusing combination998244353\
    \ = combination<atcoder::modint998244353, 998244353>;\n/*\n@brief \u30B3\u30F3\
    \u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.hpp
  requiredBy: []
  timestamp: '2025-01-13 01:51:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Math_combination.test.cpp
documentation_of: Math/combination.hpp
layout: document
redirect_from:
- /library/Math/combination.hpp
- /library/Math/combination.hpp.html
title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
---
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

- ``` T operator()(int n, int k) ``` ... $\binom{n}{r}$

- ``` T C(int n, int k) ```... $\binom{n}{r}$

- `T B(int n)`... $n!$

- `T invB(int n)`... $\frac{1}{n!}$

- `T H(int n, int k)`... $\binom{n+k-1}{k}$ 
    - 補遺
        - 重複あり組み合わせ


- `T Cn(int u)`... $\frac{\binom{2n}{n}}{(n+1)}$ 
    - 補遺
        - カタラン数


## 負の二項係数の扱い
$a> 0, \quad b \in \mathbb{Z}$ とする.

$$ \binom{-a}{b} = \begin{cases} 0 &\text {if }  b \neq 0 \\ 1 &\text{otherwise} \end{cases}$$

とした。  

### 成立するもの  
- 自然数の範囲で成立したものは、自然数の範囲で全て成立。  

$$ \binom{z}{r} = \binom{z-1}{r} +  \binom{z-1}{r-1},  \quad \forall z , r\in  \mathbb{Z} $$  

- 小さい $n$ に帰着させる時負の扱いを気にしなくて良くなって便利  

$$ H(0, 0) = 1 $$  

- こうであって欲しい

### 成立しないもの  

$$ \binom{n}{r} = \binom{n}{n-r} , \quad n, r \in \mathbb{Z_{<0}} $$