---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/lcm_convolution.hpp
    title: Convolution/lcm_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Math/sieve.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"verify/Convolution_lcm_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Math/sieve.hpp\"\nstruct notlinear_sieve {\n    int n;\n    vector<int>\
    \ sm;\n\n    notlinear_sieve(int max_n) : n(max_n), sm(max_n + 1) {\n        assert(1\
    \ <= n);\n        iota(sm.begin(), sm.end(), 0);\n        if (n >= 2) sm[2] =\
    \ 2;\n        for (int j = 4; j <= n; j += 2) sm[j] = 2;\n        for (int i =\
    \ 3; i * i <= n; i += 2) {\n            if (sm[i] != i) continue;\n          \
    \  for (int j = i * 2; j <= n; j += i) {\n                if (sm[j] == j) sm[j]\
    \ = i;\n            }\n        }\n    }\n\n    bool is_prime(int v) const noexcept\
    \ {\n        assert(v <= n);\n        if (v <= 1) return false;\n        return\
    \ sm[v] == v;\n    }\n\n    vector<int> primes(int max_n) const noexcept {\n \
    \       assert(1 <= max_n && max_n <= n);\n        vector<int> ret;\n        for\
    \ (int i = 2; i <= max_n; i++)\n            if (is_prime(i)) ret.push_back(i);\n\
    \        return ret;\n    }\n\n    // sorted\n    vector<pair<int, int>> factorize(int\
    \ v) const noexcept {\n        assert(1 <= v && v <= n);\n        vector<pair<int,\
    \ int>> ret;\n        while (sm[v] != v) {\n            int tmp = v;\n       \
    \     int c = 0;\n            while (tmp % sm[v] == 0) c++, tmp /= sm[v];\n  \
    \          ret.emplace_back(sm[v], c);\n            v = tmp;\n        }\n    \
    \    if (v != 1) ret.emplace_back(v, 1);\n        return ret;\n    }\n\n    int\
    \ divcnt(int v) const noexcept {\n        assert(1 <= v && v <= n);\n        auto\
    \ ps = factorize(v);\n        int ret = 1;\n        for (auto [p, c] : ps) ret\
    \ *= (c + 1);\n        return ret;\n    }\n\n    // not sorted\n    vector<int>\
    \ divs(int v) const noexcept {\n        assert(1 <= v && v <= n);\n        auto\
    \ ps = factorize(v);\n        int sz = 1;\n        for (auto [p, c] : ps) sz *=\
    \ (c + 1);\n        vector<int> ret(sz);\n        ret[0] = 1;\n        int r =\
    \ 1;\n        for (auto [p, c] : ps) {\n            int nr = r;\n            for\
    \ (int j = 0; j < c; j++) {\n                for (int k = 0; k < r; k++) {\n \
    \                   ret[nr] = p * ret[nr - r];\n                    nr++;\n  \
    \              }\n            }\n            r = nr;\n        }\n        return\
    \ ret;\n    }\n\n    // \u5076\u6570...+1 \u5947\u6570...-1 p^2...0\n    template\
    \ <typename T> vector<T> mobius(int N) const {\n        assert(N <= n);\n    \
    \    vector<T> ret(N + 1, 1);\n        for (int p = 2; p <= N; p++)\n        \
    \    if (is_prime(p)) {\n                for (int q = p; q <= N; q += p) {\n \
    \                   if ((q / p) % p == 0)\n                        ret[q] = 0;\n\
    \                    else\n                        ret[q] = -ret[q];\n       \
    \         }\n            }\n        return ret;\n    }\n\n    // \u4EE5\u4E0B\
    4\u3064\u306F\u7D20\u56E0\u6570\u3054\u3068\u306E\u7D2F\u7A4D\u548C\u3068\u601D\
    \u3046\u3068\u826F\u3044\u3002\u8A08\u7B97\u91CF\u306FO(nloglogn)\n    // f ->\
    \ F   \u7D04\u6570\u306E\u6DFB\u5B57\u3092add\n    template <typename T> vector<T>\
    \ divisor_zeta_transform(vector<T> A) const {\n        int N = int(A.size()) -\
    \ 1;\n        assert(N <= n);\n        for (int p = 2; p <= N; p++) {\n      \
    \      if (is_prime(p)) {\n                for (int k = 1; k * p <= N; k++) {\n\
    \                    A[k * p] += A[k];\n                }\n            }\n   \
    \     }\n        return A;\n    }\n\n    // F -> f\n    template <typename T>\n\
    \    vector<T> divisor_mobius_transform(vector<T> A) const {\n        int N =\
    \ int(A.size()) - 1;\n        assert(N <= n);\n        for (int p = 2; p <= N;\
    \ p++) {\n            if (is_prime(p)) {\n                for (int k = N / p;\
    \ k >= 1; k--) {\n                    A[k * p] -= A[k];\n                }\n \
    \           }\n        }\n        return A;\n    }\n\n    // f -> F \u500D\u6570\
    \u306E\u6DFB\u5B57\u3092add\n    template <typename T> vector<T> multiple_zeta_transform(vector<T>\
    \ A) const {\n        int N = int(A.size()) - 1;\n        assert(N <= n);\n  \
    \      for (int p = 2; p <= N; p++) {\n            if (is_prime(p)) {\n      \
    \          for (int k = N / p; k >= 1; k--) {\n                    A[k] += A[k\
    \ * p];\n                }\n            }\n        }\n        return A;\n    }\n\
    \n    // F -> f\n    template <typename T>\n    vector<T> multiple_mobius_transform(vector<T>\
    \ A) const {\n        int N = int(A.size()) - 1;\n        assert(N <= n);\n  \
    \      for (int p = 2; p <= N; p++) {\n            if (is_prime(p)) {\n      \
    \          for (int k = 1; k <= N / p; k++) {\n                    A[k] -= A[k\
    \ * p];\n                }\n            }\n        }\n        return A;\n    }\n\
    };\n#line 2 \"Convolution/lcm_convolution.hpp\"\n// lcm(a, b) = l  <-> lcm(a,\
    \ b) \u304C l\u306E\u7D04\u6570 (\u21D4 a, b\u3068\u3082\u306Bl\u306E\u7D04\u6570\
    (\u7D20\u56E0\u6570\u6BCE\u306Bmax\u3092\u3068\u3063\u3066\u3044\u308B\u4E8B\u3088\
    \u308A\u81EA\u660E))\ntemplate <typename T>\nvector<T> lcm_convolution(vector<T>\
    \ A, vector<T> B) {\n    if (A.empty() || B.empty()) return {};\n    int n = max<int>(A.size(),\
    \ B.size()) - 1;\n    notlinear_sieve sieve(n);\n    A.resize(n + 1, 0);\n   \
    \ B.resize(n + 1, 0);\n    vector<T> div_A = sieve.divisor_zeta_transform<T>(A);\n\
    \    vector<T> div_B = sieve.divisor_zeta_transform<T>(B);\n    for(int i = 1;\
    \ i <= n; i += 1) {\n        div_A[i] *= div_B[i];\n    }\n    return sieve.divisor_mobius_transform<T>(div_A);\n\
    }\n#line 1 \"Utility/modint.hpp\"\n\n// \u52D5\u7684mod : template<int mod> \u3092\
    \u6D88\u3057\u3066\u3001\u4E0A\u306E\u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\
    \ntemplate <uint32_t mod> struct modint {\n    using mm = modint;\n    uint32_t\
    \ x;\n    modint() : x(0) {}\n    TT modint(T a = 0) : x((ll(a) % mod + mod))\
    \ {\n        if (x >= mod) x -= mod;\n    }\n\n    friend mm operator+(mm a, mm\
    \ b) {\n        a.x += b.x;\n        if (a.x >= mod) a.x -= mod;\n        return\
    \ a;\n    }\n    friend mm operator-(mm a, mm b) {\n        a.x -= b.x;\n    \
    \    if (a.x >= mod) a.x += mod;\n        return a;\n    }\n\n    mm operator-()\
    \ const { return mod - x; }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\u306A\
    \u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\u3067\
    \u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x) *\
    \ b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n    friend mm &operator/=(mm &a, mm b) { return a = a * b.inv();\
    \ }\n\n    mm inv() const {\n        assert(x != 0);\n        return pow(mod -\
    \ 2);\n    }\n    mm pow(ll y) const {\n        mm res = 1;\n        mm v = *this;\n\
    \        while (y) {\n            if (y & 1) res *= v;\n            v *= v;\n\
    \            y /= 2;\n        }\n        return res;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, mm &a) {\n        ll t;\n        cin >> t;\n      \
    \  a = mm(t);\n        return is;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, mm a) { return os << a.x; }\n\n    bool operator==(mm a) { return x ==\
    \ a.x; }\n    bool operator!=(mm a) { return x != a.x; }\n\n    bool operator<(const\
    \ mm &a) const { return x < a.x; }\n};\nusing modint998244353 = modint<998244353>;\n\
    using modint1000000007 = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line\
    \ 5 \"verify/Convolution_lcm_convolution.test.cpp\"\n\n\nusing mint = modint998244353;\n\
    int main() {\n    int n;\n    cin >> n;\n    vector<mint> A(n + 1), B(n + 1);\n\
    \    rep(i, 1, n + 1) cin >> A[i];\n    rep(i, 1, n + 1) cin >> B[i];\n    auto\
    \ ret = lcm_convolution<mint>(A, B);\n    rep(i, 1, n + 1) cout << ret[i] << \"\
    \ \";\n    cout << endl;\n\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Convolution/lcm_convolution.hpp\"\
    \n#include \"../Utility/modint.hpp\"\n\n\nusing mint = modint998244353;\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vector<mint> A(n + 1), B(n + 1);\n    rep(i,\
    \ 1, n + 1) cin >> A[i];\n    rep(i, 1, n + 1) cin >> B[i];\n    auto ret = lcm_convolution<mint>(A,\
    \ B);\n    rep(i, 1, n + 1) cout << ret[i] << \" \";\n    cout << endl;\n\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Convolution/lcm_convolution.hpp
  - Math/sieve.hpp
  - Utility/modint.hpp
  isVerificationFile: true
  path: verify/Convolution_lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 02:41:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Convolution_lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/Convolution_lcm_convolution.test.cpp
- /verify/verify/Convolution_lcm_convolution.test.cpp.html
title: verify/Convolution_lcm_convolution.test.cpp
---
