---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: rolling_hash
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/Rhash_more.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"String/Rhash.hpp\"\
    \nnamespace rolling_hash {\nstruct rhash {\n    static const uint64_t mod = (1LL\
    \ << 61) - 1;\n    using mm = rhash;\n    uint64_t x;\n\n    rhash() : x(0) {}\n\
    \    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {\n        if (x >= mod)\
    \ x -= mod;\n    }\n\n    uint64_t val() const { return x; }\n\n    friend mm\
    \ operator+(mm a, mm b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -=\
    \ mod;\n        return a;\n    }\n    friend mm operator-(mm a, mm b) {\n    \
    \    a.x -= b.x;\n        if (a.x >= mod) a.x += mod;\n        return a;\n   \
    \ }\n\n    friend mm operator*(mm a, mm b) {\n        __uint128_t t = (__uint128_t)(a.x)\
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
    */\n#line 4 \"verify/Rhash_more.test.cpp\"\nusing namespace rolling_hash;\nint\
    \ main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n    reverse(all(S));\n\
    \    Rhash rev(S);\n    reverse(all(S));\n\n    rep(ti, 0, ll(S.size()) * 2 -\
    \ 1) {\n        if(ti%2==0) {//\u6587\u5B57\n            int i = ti/2;\n     \
    \       ll li = 1;\n            ll ri = min<int>(i+1, (ll)S.size() - i);\n   \
    \         while(li < ri) {//oooxxx\n                ll mid = (li + ri + 1) >>\
    \ 1;\n                auto [l, r] = rs.conv(i - mid + 1, i + mid);\n         \
    \       if(rs.prod(i - mid + 1, i + mid).x == rev.prod(l, r).x) {\n          \
    \          li = mid;\n                }\n                else {\n            \
    \        ri = mid - 1;\n                }\n            }\n            cout <<\
    \ li*2-1 << \" \";\n        }\n        else {\n            int i = ti/2;\n   \
    \         ll li = 0;\n            ll ri = min<int>(i+1, (ll)S.size() - i - 1);\n\
    \            while(li < ri) {\n                ll mid = (li + ri + 1) >> 1;\n\
    \                auto [l, r] = rs.conv(i - mid + 1, i + mid + 1);\n          \
    \      if(rs.prod(i - mid + 1, i + mid + 1).x == rev.prod(l, r).x) {\n       \
    \             li = mid;\n                }\n                else {\n         \
    \           ri = mid - 1;\n                }\n            }\n            cout\
    \ << li*2 << \" \";\n        }\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\nusing\
    \ namespace rolling_hash;\nint main() {\n    string S;\n    cin >> S;\n\n    Rhash\
    \ rs(S);\n    reverse(all(S));\n    Rhash rev(S);\n    reverse(all(S));\n\n  \
    \  rep(ti, 0, ll(S.size()) * 2 - 1) {\n        if(ti%2==0) {//\u6587\u5B57\n \
    \           int i = ti/2;\n            ll li = 1;\n            ll ri = min<int>(i+1,\
    \ (ll)S.size() - i);\n            while(li < ri) {//oooxxx\n                ll\
    \ mid = (li + ri + 1) >> 1;\n                auto [l, r] = rs.conv(i - mid + 1,\
    \ i + mid);\n                if(rs.prod(i - mid + 1, i + mid).x == rev.prod(l,\
    \ r).x) {\n                    li = mid;\n                }\n                else\
    \ {\n                    ri = mid - 1;\n                }\n            }\n   \
    \         cout << li*2-1 << \" \";\n        }\n        else {\n            int\
    \ i = ti/2;\n            ll li = 0;\n            ll ri = min<int>(i+1, (ll)S.size()\
    \ - i - 1);\n            while(li < ri) {\n                ll mid = (li + ri +\
    \ 1) >> 1;\n                auto [l, r] = rs.conv(i - mid + 1, i + mid + 1);\n\
    \                if(rs.prod(i - mid + 1, i + mid + 1).x == rev.prod(l, r).x) {\n\
    \                    li = mid;\n                }\n                else {\n  \
    \                  ri = mid - 1;\n                }\n            }\n         \
    \   cout << li*2 << \" \";\n        }\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  isVerificationFile: true
  path: verify/Rhash_more.test.cpp
  requiredBy: []
  timestamp: '2025-03-31 23:50:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Rhash_more.test.cpp
layout: document
redirect_from:
- /verify/verify/Rhash_more.test.cpp
- /verify/verify/Rhash_more.test.cpp.html
title: verify/Rhash_more.test.cpp
---
