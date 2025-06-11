---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: example/rhash.example.cpp
    title: example/rhash.example.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Rhash.test.cpp
    title: verify/Rhash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Rhash_more.test.cpp
    title: verify/Rhash_more.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/Rhash.md
    document_title: rolling_hash
    links: []
  bundledCode: "#line 1 \"String/Rhash.hpp\"\nnamespace rolling_hash {\nstruct rhash\
    \ {\n    static const uint64_t mod = (1LL << 61) - 1;\n    using mm = rhash;\n\
    \    uint64_t x;\n\n    rhash() : x(0) {}\n    TT rhash(T a = 0) : x((__int128_t(a)\
    \ % mod + mod)) {\n        if (x >= mod) x -= mod;\n    }\n\n    uint64_t val()\
    \ const { return x; }\n\n    friend mm operator+(mm a, mm b) {\n        a.x +=\
    \ b.x;\n        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend\
    \ mm operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x\
    \ += mod;\n        return a;\n    }\n\n    friend mm operator*(mm a, mm b) {\n\
    \        __uint128_t t = (__uint128_t)(a.x) * b.x;\n        t = (t >> 61) + (t\
    \ & mod);\n        return (t >= mod) ? t - mod : t;\n    }\n    friend mm &operator+=(mm\
    \ &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm &a, mm b) { return\
    \ a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return a = a * b; }\n\
    \n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n     \
    \   while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n     \
    \       y /= 2;\n        }\n        return res;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, mm &a) {\n        ll t;\n        cin >> t;\n        a = mm(t);\n      \
    \  return is;\n    }\n    friend ostream &operator<<(ostream &os, mm a) { return\
    \ os << a.x; }\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n    bool operator<(const mm &a) const { return x <\
    \ a.x; }\n};\n// using rhash = atcoder::static_modint<998244853>;\nconst rhash\
    \ brh = 200224;\nconst int MAX_SIZE = 10'000'000;\narray<rhash, MAX_SIZE + 1>\
    \ pw;\nstruct Initializer {\n    Initializer() {\n        pw[0] = 1;\n       \
    \ rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }\n    }\n};\n\nInitializer\
    \ initializer;\nstruct Rhash {\n    int n;\n    vec<rhash> H;\n    Rhash(string\
    \ S = \"\") : n(S.size()) {\n        H = vec<rhash>(n, 0);\n\n        rep(i, 0,\
    \ n) {\n            H[i] += S[i];\n            if (i) {\n                H[i]\
    \ += H[i - 1] * brh;\n            }\n        }\n    }\n    void push_back(char\
    \ a) {\n        n++;\n        H.resize(n, 0);\n        H[n - 1] = a;\n       \
    \ if (n - 1) {\n            H[n - 1] += H[n - 2] * brh;\n        }\n    }\n  \
    \  rhash prod(ll l, ll r) const {\n        assert(0 <= l && r <= n);\n       \
    \ rhash res = 0;\n        if (r) res = H[r - 1];\n        if (l) res -= H[l -\
    \ 1] * pw[r - l];\n        return res;\n    }\n\n    rhash get(int p) const {\
    \ return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l, ll r) const { return\
    \ make_pair(n - r, n - l); }\n\n    ll size() const { return n; }\n};\n\nstruct\
    \ substring {\n    const Rhash *S;\n    ll l, r;\n    substring() { S = nullptr;\
    \ }\n    substring(Rhash const &S, ll l, ll r) : S(&S), l(l), r(r) {\n       \
    \ assert(0 <= l && l <= r && r <= S.size());\n    }\n    ll size() const { return\
    \ r - l; }\n    rhash prod(ll s, ll t) const {\n        assert(l + t <= r);\n\
    \        return S->prod(l + s, l + t);\n    }\n    rhash get(int p) const { return\
    \ prod(p, p + 1); }\n    ll lcp(substring const &a) const {\n        ll len =\
    \ min(size(), a.size());\n        ll ok = 0, ng = len + 1;\n        while (ng\
    \ - ok > 1) {\n            ll mid = (ng + ok) >> 1;\n            (prod(0, mid)\
    \ == a.prod(0, mid) ? ok : ng) = mid;\n        }\n        return ok;\n    }\n\
    \    /* \u8981\u4EF6: 1\u6587\u5B57\u30CF\u30C3\u30B7\u30E5\u306E\u5927\u5C0F\
    \ \u21D4\u3000\u5143\u306E\u6587\u5B57\u5217\u3067\u306E1\u6587\u5B57\u6BD4\u8F03\
    */\n    bool operator<(substring const &a) const {\n        ll len = lcp(a);\n\
    \        if (len < size() && len < a.size()) {\n            return get(len).val()\
    \ < a.get(len).val();\n        } else {\n            return len < a.size();\n\
    \        }\n    }\n};\n\nrhash cal_rhash(string S) { return Rhash(S).prod(0, S.size());\
    \ }\n\nrhash connect(rhash mae, rhash usiro, ll len_of_usiro) {\n    if (len_of_usiro\
    \ <= MAX_SIZE) {\n        return mae * pw[len_of_usiro] + usiro;\n    } else {\n\
    \        return mae * brh.pow(len_of_usiro) + usiro;\n    }\n}\n\nrhash rhash_pow(rhash\
    \ x, ll y, ll len) {\n    rhash res = 0;\n    rhash len_pw;\n    if (len <= MAX_SIZE)\n\
    \        len_pw = pw[len];\n    else\n        len_pw = brh.pow(len);\n\n    while\
    \ (y) {\n        if (y & 1) {\n            res = res * len_pw + x;\n        }\n\
    \        x = x * len_pw + x;\n        y /= 2;\n        len_pw *= len_pw;\n   \
    \ }\n    return res;\n}\n\n/*\n\u4E8C\u5206\u63A2\u7D22\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u304C\u5FC5\u8981\n\n\n\nsubstring \u3053\u3063\u3061\u306E\u65B9\u304C\
    2~3\u500D\u307B\u3069sort\u304C\u901F\u3044\nstruct str {\n    ll l, r;\n    ll\
    \ size() const {\n        return r - l;\n    }\n};\nRhash sh(S);\n\nauto lcp =\
    \ [&](str a, str b) {\n    ll len = min(a.size(), b.size());\n    if (len == 0)\n\
    \        return 0LL;\n    auto pred = [&](ll x) {\n        return sh.prod(a.l,\
    \ a.l + x) == sh.prod(b.l, b.l + x);\n    };\n    return max_right(0LL, len +\
    \ 1, pred) - 1;\n};\nauto cmp = [&](str a, str b) {\n    assert(a.size() == b.size());\n\
    \    ll l = lcp(a, b);\n    if (l < a.size() && l < b.size()) {\n        return\
    \ S[a.l + l] < S[b.l + l];\n    }\n    return l < b.size();\n};\n\n\nvector<ll>\
    \ lcp_array_back(vector<Rhash> const &S) {\n    ll n = S.size();\n    vector<ll>\
    \ ret(n);\n    ret[0] = 0;\n    rep(i, 1, n) {\n        ll len = min(S[i - 1].size(),\
    \ S[i].size());\n        auto pred = [&](ll x) {\n            return S[i - 1].prod(S[i\
    \ - 1].size() - x, S[i - 1].size()) ==\n                   S[i].prod(S[i].size()\
    \ - x, S[i].size());\n        };\n        ret[i] = max_right(0LL, len + 1, pred)\
    \ - 1;\n    }\n    return ret;\n}\n\nvector<ll> lcp_array(vector<Rhash> const\
    \ &S) {\n    ll n = S.size();\n    vector<ll> ret(n);\n    ret[0] = 0;\n    rep(i,\
    \ 1, n) {\n        ll len = min(S[i - 1].size(), S[i].size());\n        auto pred\
    \ = [&](ll x) {\n            return S[i-1].prod(0, x) == S[i].prod(0, x);\n  \
    \      };\n        ret[i] = max_right(0LL, len + 1, pred) - 1;\n    }\n    return\
    \ ret;\n}\n*/\n}  // namespace rolling_hash\n/*\n@brief rolling_hash\n@docs doc/Rhash.md\n\
    */\n"
  code: "namespace rolling_hash {\nstruct rhash {\n    static const uint64_t mod =\
    \ (1LL << 61) - 1;\n    using mm = rhash;\n    uint64_t x;\n\n    rhash() : x(0)\
    \ {}\n    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {\n        if (x\
    \ >= mod) x -= mod;\n    }\n\n    uint64_t val() const { return x; }\n\n    friend\
    \ mm operator+(mm a, mm b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x\
    \ -= mod;\n        return a;\n    }\n    friend mm operator-(mm a, mm b) {\n \
    \       a.x -= b.x;\n        if (a.x >= mod) a.x += mod;\n        return a;\n\
    \    }\n\n    friend mm operator*(mm a, mm b) {\n        __uint128_t t = (__uint128_t)(a.x)\
    \ * b.x;\n        t = (t >> 61) + (t & mod);\n        return (t >= mod) ? t -\
    \ mod : t;\n    }\n    friend mm &operator+=(mm &a, mm b) { return a = a + b;\
    \ }\n    friend mm &operator-=(mm &a, mm b) { return a = a - b; }\n    friend\
    \ mm &operator*=(mm &a, mm b) { return a = a * b; }\n\n    mm pow(ll y) const\
    \ {\n        mm res = 1;\n        mm v = *this;\n        while (y) {\n       \
    \     if (y & 1) res *= v;\n            v *= v;\n            y /= 2;\n       \
    \ }\n        return res;\n    }\n\n    friend istream &operator>>(istream &is,\
    \ mm &a) {\n        ll t;\n        cin >> t;\n        a = mm(t);\n        return\
    \ is;\n    }\n    friend ostream &operator<<(ostream &os, mm a) { return os <<\
    \ a.x; }\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n    bool operator<(const mm &a) const { return x <\
    \ a.x; }\n};\n// using rhash = atcoder::static_modint<998244853>;\nconst rhash\
    \ brh = 200224;\nconst int MAX_SIZE = 10'000'000;\narray<rhash, MAX_SIZE + 1>\
    \ pw;\nstruct Initializer {\n    Initializer() {\n        pw[0] = 1;\n       \
    \ rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }\n    }\n};\n\nInitializer\
    \ initializer;\nstruct Rhash {\n    int n;\n    vec<rhash> H;\n    Rhash(string\
    \ S = \"\") : n(S.size()) {\n        H = vec<rhash>(n, 0);\n\n        rep(i, 0,\
    \ n) {\n            H[i] += S[i];\n            if (i) {\n                H[i]\
    \ += H[i - 1] * brh;\n            }\n        }\n    }\n    void push_back(char\
    \ a) {\n        n++;\n        H.resize(n, 0);\n        H[n - 1] = a;\n       \
    \ if (n - 1) {\n            H[n - 1] += H[n - 2] * brh;\n        }\n    }\n  \
    \  rhash prod(ll l, ll r) const {\n        assert(0 <= l && r <= n);\n       \
    \ rhash res = 0;\n        if (r) res = H[r - 1];\n        if (l) res -= H[l -\
    \ 1] * pw[r - l];\n        return res;\n    }\n\n    rhash get(int p) const {\
    \ return prod(p, p + 1); }\n\n    pair<ll, ll> conv(ll l, ll r) const { return\
    \ make_pair(n - r, n - l); }\n\n    ll size() const { return n; }\n};\n\nstruct\
    \ substring {\n    const Rhash *S;\n    ll l, r;\n    substring() { S = nullptr;\
    \ }\n    substring(Rhash const &S, ll l, ll r) : S(&S), l(l), r(r) {\n       \
    \ assert(0 <= l && l <= r && r <= S.size());\n    }\n    ll size() const { return\
    \ r - l; }\n    rhash prod(ll s, ll t) const {\n        assert(l + t <= r);\n\
    \        return S->prod(l + s, l + t);\n    }\n    rhash get(int p) const { return\
    \ prod(p, p + 1); }\n    ll lcp(substring const &a) const {\n        ll len =\
    \ min(size(), a.size());\n        ll ok = 0, ng = len + 1;\n        while (ng\
    \ - ok > 1) {\n            ll mid = (ng + ok) >> 1;\n            (prod(0, mid)\
    \ == a.prod(0, mid) ? ok : ng) = mid;\n        }\n        return ok;\n    }\n\
    \    /* \u8981\u4EF6: 1\u6587\u5B57\u30CF\u30C3\u30B7\u30E5\u306E\u5927\u5C0F\
    \ \u21D4\u3000\u5143\u306E\u6587\u5B57\u5217\u3067\u306E1\u6587\u5B57\u6BD4\u8F03\
    */\n    bool operator<(substring const &a) const {\n        ll len = lcp(a);\n\
    \        if (len < size() && len < a.size()) {\n            return get(len).val()\
    \ < a.get(len).val();\n        } else {\n            return len < a.size();\n\
    \        }\n    }\n};\n\nrhash cal_rhash(string S) { return Rhash(S).prod(0, S.size());\
    \ }\n\nrhash connect(rhash mae, rhash usiro, ll len_of_usiro) {\n    if (len_of_usiro\
    \ <= MAX_SIZE) {\n        return mae * pw[len_of_usiro] + usiro;\n    } else {\n\
    \        return mae * brh.pow(len_of_usiro) + usiro;\n    }\n}\n\nrhash rhash_pow(rhash\
    \ x, ll y, ll len) {\n    rhash res = 0;\n    rhash len_pw;\n    if (len <= MAX_SIZE)\n\
    \        len_pw = pw[len];\n    else\n        len_pw = brh.pow(len);\n\n    while\
    \ (y) {\n        if (y & 1) {\n            res = res * len_pw + x;\n        }\n\
    \        x = x * len_pw + x;\n        y /= 2;\n        len_pw *= len_pw;\n   \
    \ }\n    return res;\n}\n\n/*\n\u4E8C\u5206\u63A2\u7D22\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u304C\u5FC5\u8981\n\n\n\nsubstring \u3053\u3063\u3061\u306E\u65B9\u304C\
    2~3\u500D\u307B\u3069sort\u304C\u901F\u3044\nstruct str {\n    ll l, r;\n    ll\
    \ size() const {\n        return r - l;\n    }\n};\nRhash sh(S);\n\nauto lcp =\
    \ [&](str a, str b) {\n    ll len = min(a.size(), b.size());\n    if (len == 0)\n\
    \        return 0LL;\n    auto pred = [&](ll x) {\n        return sh.prod(a.l,\
    \ a.l + x) == sh.prod(b.l, b.l + x);\n    };\n    return max_right(0LL, len +\
    \ 1, pred) - 1;\n};\nauto cmp = [&](str a, str b) {\n    assert(a.size() == b.size());\n\
    \    ll l = lcp(a, b);\n    if (l < a.size() && l < b.size()) {\n        return\
    \ S[a.l + l] < S[b.l + l];\n    }\n    return l < b.size();\n};\n\n\nvector<ll>\
    \ lcp_array_back(vector<Rhash> const &S) {\n    ll n = S.size();\n    vector<ll>\
    \ ret(n);\n    ret[0] = 0;\n    rep(i, 1, n) {\n        ll len = min(S[i - 1].size(),\
    \ S[i].size());\n        auto pred = [&](ll x) {\n            return S[i - 1].prod(S[i\
    \ - 1].size() - x, S[i - 1].size()) ==\n                   S[i].prod(S[i].size()\
    \ - x, S[i].size());\n        };\n        ret[i] = max_right(0LL, len + 1, pred)\
    \ - 1;\n    }\n    return ret;\n}\n\nvector<ll> lcp_array(vector<Rhash> const\
    \ &S) {\n    ll n = S.size();\n    vector<ll> ret(n);\n    ret[0] = 0;\n    rep(i,\
    \ 1, n) {\n        ll len = min(S[i - 1].size(), S[i].size());\n        auto pred\
    \ = [&](ll x) {\n            return S[i-1].prod(0, x) == S[i].prod(0, x);\n  \
    \      };\n        ret[i] = max_right(0LL, len + 1, pred) - 1;\n    }\n    return\
    \ ret;\n}\n*/\n}  // namespace rolling_hash\n/*\n@brief rolling_hash\n@docs doc/Rhash.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: String/Rhash.hpp
  requiredBy:
  - example/rhash.example.cpp
  timestamp: '2025-03-31 23:50:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Rhash_more.test.cpp
  - verify/Rhash.test.cpp
documentation_of: String/Rhash.hpp
layout: document
redirect_from:
- /library/String/Rhash.hpp
- /library/String/Rhash.hpp.html
title: rolling_hash
---
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
    - 備考
        - 文字数がmodに近くなっていくにつれ、ローリングハッシュの衝突の可能性は高くなる
        - 例えば、rhash_pow(???, mod - 1, ???)はなかなかの確率で0になる
- `rhash cal_rhash(string S)`...string Sのハッシュを計算して返す。
    - 計算量
        - $O(|S|)$
  
## 使用例

```
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

using namespace rolling_hash;

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
