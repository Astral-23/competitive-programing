---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/rhash.example.cpp
    title: example/rhash.example.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Rhash.test.cpp
    title: verify/Rhash.test.cpp
  - icon: ':x:'
    path: verify/Rhash_more.test.cpp
    title: verify/Rhash_more.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: doc/Rhash.md
    document_title: Rolling_hash
    links: []
  bundledCode: "#line 1 \"String/Rhash.hpp\"\nstruct rhash {\n    static const uint64_t\
    \ mod = (1LL << 61) - 1;\n    using mm = rhash;\n    uint64_t x;\n\n    rhash()\
    \ : x(0) {}\n    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {\n      \
    \  if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n \
    \       a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n        return a;\n\
    \    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if\
    \ (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    friend mm operator*(mm\
    \ a, mm b) {\n        __uint128_t t = (__uint128_t)(a.x) * b.x;\n        t = (t\
    \ >> 61) + (t & mod);\n        return (t >= mod) ? t - mod : t;\n    }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v\
    \ = *this;\n        while (y) {\n            if (y & 1) res *= v;\n          \
    \  v *= v;\n            y /= 2;\n        }\n        return res;\n    }\n\n   \
    \ friend istream &operator>>(istream &is, mm &a) {\n        ll t;\n\n        cin\
    \ >> t;\n        a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\n\nstruct Rhash {\n    static const rhash\
    \ brh;\n    static vec<rhash> pw;\n    static const int MAX_SIZE;\n    int n;\n\
    \    vec<rhash> H;\n\n    static void initialize_pow() {\n        pw.resize(MAX_SIZE\
    \ + 1);\n        pw[0] = 1;\n        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i -\
    \ 1] * brh; }\n    }\n\n    Rhash() {\n        if (pw.empty()) initialize_pow();\n\
    \    }\n\n    Rhash(string S) : n(S.size()) {\n        if (pw.empty()) initialize_pow();\n\
    \        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n            H[i] +=\
    \ S[i];\n            if (i) {\n                H[i] += H[i - 1] * brh;\n     \
    \       }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n        assert(0\
    \ <= l && r <= n);\n        if (l >= r) return 0;\n        rhash res = H[r - 1];\n\
    \        if (l) res -= H[l - 1] * pw[r - l];\n        return res;\n    }\n\n \
    \   rhash get(int p) { return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l,\
    \ ll r) { return make_pair(n - r, n - l); }\n};\n\nconst rhash Rhash::brh = 200224;\n\
    const int Rhash::MAX_SIZE = 500000;\nvec<rhash> Rhash::pw;\n\nrhash connect(rhash\
    \ mae, rhash usiro, ll len_of_usiro) {\n    if (len_of_usiro <= Rhash::MAX_SIZE)\
    \ {\n        return mae * Rhash::pw[len_of_usiro] + usiro;\n    } else {\n   \
    \     return mae * Rhash::brh.pow(len_of_usiro) + usiro;\n    }\n}\n\nrhash rhash_pow(rhash\
    \ x, ll y, ll len) {\n    rhash res = 0;\n    rhash len_pw;\n    if (len <= Rhash::MAX_SIZE)\n\
    \        len_pw = Rhash::pw[len];\n    else\n        len_pw = Rhash::brh.pow(len);\n\
    \n    while (y) {\n        if (y & 1) {\n            res = res * len_pw + x;\n\
    \        }\n        x = x * len_pw + x;\n        y /= 2;\n        len_pw *= len_pw;\n\
    \    }\n    return res;\n}\n\n/*\n@brief Rolling_hash\n@docs doc/Rhash.md\n*/\n"
  code: "struct rhash {\n    static const uint64_t mod = (1LL << 61) - 1;\n    using\
    \ mm = rhash;\n    uint64_t x;\n\n    rhash() : x(0) {}\n    TT rhash(T a = 0)\
    \ : x((__int128_t(a) % mod + mod)) {\n        if (x >= mod) x -= mod;\n    }\n\
    \n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n        if (a.x\
    \ >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm operator-(mm a,\
    \ mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x += mod;\n        return\
    \ a;\n    }\n\n    friend mm operator*(mm a, mm b) {\n        __uint128_t t =\
    \ (__uint128_t)(a.x) * b.x;\n        t = (t >> 61) + (t & mod);\n        return\
    \ (t >= mod) ? t - mod : t;\n    }\n    friend mm &operator+=(mm &a, mm b) { return\
    \ a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n\
    \    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n\n    mm pow(ll\
    \ y) const {\n        mm res = 1;\n        mm v = *this;\n        while (y) {\n\
    \            if (y & 1) res *= v;\n            v *= v;\n            y /= 2;\n\
    \        }\n        return res;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, mm &a) {\n        ll t;\n\n        cin >> t;\n        a = mm(t);\n    \
    \    return is;\n    }\n\n    friend ostream &operator<<(ostream &os, mm a) {\
    \ return os << a.x; }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool\
    \ operator!=(mm a) { return x != a.x; }\n    bool operator<(const mm &a) const\
    \ { return x < a.x; }\n};\n\nstruct Rhash {\n    static const rhash brh;\n   \
    \ static vec<rhash> pw;\n    static const int MAX_SIZE;\n    int n;\n    vec<rhash>\
    \ H;\n\n    static void initialize_pow() {\n        pw.resize(MAX_SIZE + 1);\n\
    \        pw[0] = 1;\n        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh;\
    \ }\n    }\n\n    Rhash() {\n        if (pw.empty()) initialize_pow();\n    }\n\
    \n    Rhash(string S) : n(S.size()) {\n        if (pw.empty()) initialize_pow();\n\
    \        H = vec<rhash>(n, 0);\n\n        rep(i, 0, n) {\n            H[i] +=\
    \ S[i];\n            if (i) {\n                H[i] += H[i - 1] * brh;\n     \
    \       }\n        }\n    }\n\n    rhash prod(ll l, ll r) {\n        assert(0\
    \ <= l && r <= n);\n        if (l >= r) return 0;\n        rhash res = H[r - 1];\n\
    \        if (l) res -= H[l - 1] * pw[r - l];\n        return res;\n    }\n\n \
    \   rhash get(int p) { return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l,\
    \ ll r) { return make_pair(n - r, n - l); }\n};\n\nconst rhash Rhash::brh = 200224;\n\
    const int Rhash::MAX_SIZE = 500000;\nvec<rhash> Rhash::pw;\n\nrhash connect(rhash\
    \ mae, rhash usiro, ll len_of_usiro) {\n    if (len_of_usiro <= Rhash::MAX_SIZE)\
    \ {\n        return mae * Rhash::pw[len_of_usiro] + usiro;\n    } else {\n   \
    \     return mae * Rhash::brh.pow(len_of_usiro) + usiro;\n    }\n}\n\nrhash rhash_pow(rhash\
    \ x, ll y, ll len) {\n    rhash res = 0;\n    rhash len_pw;\n    if (len <= Rhash::MAX_SIZE)\n\
    \        len_pw = Rhash::pw[len];\n    else\n        len_pw = Rhash::brh.pow(len);\n\
    \n    while (y) {\n        if (y & 1) {\n            res = res * len_pw + x;\n\
    \        }\n        x = x * len_pw + x;\n        y /= 2;\n        len_pw *= len_pw;\n\
    \    }\n    return res;\n}\n\n/*\n@brief Rolling_hash\n@docs doc/Rhash.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/Rhash.hpp
  requiredBy:
  - example/rhash.example.cpp
  timestamp: '2024-08-06 18:24:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/Rhash.test.cpp
  - verify/Rhash_more.test.cpp
documentation_of: String/Rhash.hpp
layout: document
redirect_from:
- /library/String/Rhash.hpp
- /library/String/Rhash.hpp.html
title: Rolling_hash
---
## 概要
Rolling hash。半開区間に注意。

## 使用時に変更する物
`const rhash Rhash::brh = 200224;` ...値の種類数以上  

`const int Rhash::MAX_SIZE = 500000;` ... Rhash型で管理できる最大文字列長
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
        - y $\times$ len $\le$ MAX_SIZE の時: $O(\log y)$
        - y $\times$ len > MAX_SIZE の時: $O(\log y \log (y \times len))$

  
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
