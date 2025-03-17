---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Rhash.hpp
    title: rolling_hash
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/Rhash.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \nnamespace rolling_hash {\n    struct rhash {\n        static const uint64_t\
    \ mod = (1LL << 61) - 1;\n        using mm = rhash;\n        uint64_t x;\n   \
    \ \n        rhash() : x(0) {\n        }\n        TT rhash(T a = 0) : x((__int128_t(a)\
    \ % mod + mod)) {\n            if (x >= mod)\n                x -= mod;\n    \
    \    }\n    \n        friend mm operator+(mm a, mm b) {\n            a.x += b.x;\n\
    \            if (a.x >= mod)\n                a.x -= mod;\n            return\
    \ a;\n        }\n        friend mm operator-(mm a, mm b) {\n            a.x -=\
    \ b.x;\n            if (a.x >= mod)\n                a.x += mod;\n           \
    \ return a;\n        }\n    \n        friend mm operator*(mm a, mm b) {\n    \
    \        __uint128_t t = (__uint128_t)(a.x) * b.x;\n            t = (t >> 61)\
    \ + (t & mod);\n            return (t >= mod) ? t - mod : t;\n        }\n    \
    \    friend mm &operator+=(mm &a, mm b) {\n            return a = a + b;\n   \
    \     }\n        friend mm &operator-=(mm &a, mm b) {\n            return a =\
    \ a - b;\n        }\n        friend mm &operator*=(mm &a, mm b) {\n          \
    \  return a = a * b;\n        }\n    \n        mm pow(ll y) const {\n        \
    \    mm res = 1;\n            mm v = *this;\n            while (y) {\n       \
    \         if (y & 1)\n                    res *= v;\n                v *= v;\n\
    \                y /= 2;\n            }\n            return res;\n        }\n\
    \    \n        friend istream &operator>>(istream &is, mm &a) {\n            ll\
    \ t;\n    \n            cin >> t;\n            a = mm(t);\n            return\
    \ is;\n        }\n    \n        friend ostream &operator<<(ostream &os, mm a)\
    \ {\n            return os << a.x;\n        }\n    \n        bool operator==(mm\
    \ a) {\n            return x == a.x;\n        }\n        bool operator!=(mm a)\
    \ {\n            return x != a.x;\n        }\n        bool operator<(const mm\
    \ &a) const {\n            return x < a.x;\n        }\n    };\n    \n    const\
    \ rhash brh = 200224;\n    const int MAX_SIZE = 10'000'000;\n    array<rhash,\
    \ MAX_SIZE + 1> pw;\n    struct Initializer {\n        Initializer() {\n     \
    \       pw[0] = 1;\n            rep(i, 1, MAX_SIZE + 1) {\n                pw[i]\
    \ = pw[i - 1] * brh;\n            }\n        }\n    };\n    \n    Initializer\
    \ initializer;\n    struct Rhash {\n        int n;\n        vec<rhash> H;\n  \
    \  \n        Rhash(string S = \"\") : n(S.size()) {\n            H = vec<rhash>(n,\
    \ 0);\n    \n            rep(i, 0, n) {\n                H[i] += S[i];\n     \
    \           if (i) {\n                    H[i] += H[i - 1] * brh;\n          \
    \      }\n            }\n        }\n    \n        void push_back(char a) {\n \
    \           n++;\n            H.resize(n, 0);\n            H[n - 1] = a;\n   \
    \         if (n - 1) {\n                H[n - 1] += H[n - 2] * brh;\n        \
    \    }\n        }\n    \n        rhash prod(ll l, ll r) const {\n            assert(0\
    \ <= l && r <= n);\n            rhash res = H[r - 1];\n            if (l)\n  \
    \              res -= H[l - 1] * pw[r - l];\n            return res;\n       \
    \ }\n    \n        rhash get(int p) const {\n            return prod(p, p + 1);\n\
    \        }\n    \n        pair<ll, ll> conv(ll l, ll r) const {\n            return\
    \ make_pair(n - r, n - l);\n        }\n    \n        ll size() const {\n     \
    \       return n;\n        }\n    };\n    \n    rhash cal_rhash(string S) {\n\
    \        return Rhash(S).prod(0, S.size());\n    }\n    \n    rhash connect(rhash\
    \ mae, rhash usiro, ll len_of_usiro) {\n        if (len_of_usiro <= MAX_SIZE)\
    \ {\n            return mae * pw[len_of_usiro] + usiro;\n        } else {\n  \
    \          return mae * brh.pow(len_of_usiro) + usiro;\n        }\n    }\n   \
    \ \n    rhash rhash_pow(rhash x, ll y, ll len) {\n        rhash res = 0;\n   \
    \     rhash len_pw;\n        if (len <= MAX_SIZE)\n            len_pw = pw[len];\n\
    \        else\n            len_pw = brh.pow(len);\n    \n        while (y) {\n\
    \            if (y & 1) {\n                res = res * len_pw + x;\n         \
    \   }\n            x = x * len_pw + x;\n            y /= 2;\n            len_pw\
    \ *= len_pw;\n        }\n        return res;\n    }\n    \n    /*\n    \u4E8C\u5206\
    \u63A2\u7D22\u30E9\u30A4\u30D6\u30E9\u30EA\u304C\u5FC5\u8981\n    vector<ll> lcp_array_back(vector<Rhash>\
    \ const &S) {\n        ll n = S.size();\n        vector<ll> ret(n);\n        ret[0]\
    \ = 0;\n        rep(i, 1, n) {\n            ll len = min(S[i - 1].size(), S[i].size());\n\
    \            auto pred = [&](ll x) {\n                return S[i - 1].prod(S[i\
    \ - 1].size() - x, S[i - 1].size()) ==\n                       S[i].prod(S[i].size()\
    \ - x, S[i].size());\n            };\n            ret[i] = max_right(0LL, len\
    \ + 1, pred) - 1;\n        }\n        return ret;\n    }\n    \n    vector<ll>\
    \ lcp_array(vector<Rhash> const &S) {\n        ll n = S.size();\n        vector<ll>\
    \ ret(n);\n        ret[0] = 0;\n        rep(i, 1, n) {\n            ll len = min(S[i\
    \ - 1].size(), S[i].size());\n            auto pred = [&](ll x) {\n          \
    \      return S[i-1].prod(0, x) == S[i].prod(0, x);\n            };\n        \
    \    ret[i] = max_right(0LL, len + 1, pred) - 1;\n        }\n        return ret;\n\
    \    }\n    */\n    } // namespace rolling_hash\n    /*\n    @brief rolling_hash\n\
    \    @docs doc/Rhash.md\n    */\n#line 4 \"verify/Rhash.test.cpp\"\nusing namespace\
    \ rolling_hash;\nint main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n\
    \n    rep(i, 0, S.size()) {\n        int li = 0;\n        int ri = int(S.size())\
    \ - i;\n\n        while(li < ri) {//ooxxxx   \n            int mid = (li + ri\
    \ + 1) >> 1;\n            if(rs.prod(i, i + mid) == rs.prod(0, mid)) {\n     \
    \           li = mid;\n            }\n            else {\n                ri =\
    \ mid - 1;\n            }\n        }\n\n        cout << li << \" \";\n    }\n\
    \    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../String/Rhash.hpp\"\nusing namespace\
    \ rolling_hash;\nint main() {\n    string S;\n    cin >> S;\n\n    Rhash rs(S);\n\
    \n    rep(i, 0, S.size()) {\n        int li = 0;\n        int ri = int(S.size())\
    \ - i;\n\n        while(li < ri) {//ooxxxx   \n            int mid = (li + ri\
    \ + 1) >> 1;\n            if(rs.prod(i, i + mid) == rs.prod(0, mid)) {\n     \
    \           li = mid;\n            }\n            else {\n                ri =\
    \ mid - 1;\n            }\n        }\n\n        cout << li << \" \";\n    }\n\
    \    \n}"
  dependsOn:
  - Utility/template.hpp
  - String/Rhash.hpp
  isVerificationFile: true
  path: verify/Rhash.test.cpp
  requiredBy: []
  timestamp: '2025-03-17 14:23:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Rhash.test.cpp
layout: document
redirect_from:
- /verify/verify/Rhash.test.cpp
- /verify/verify/Rhash.test.cpp.html
title: verify/Rhash.test.cpp
---
