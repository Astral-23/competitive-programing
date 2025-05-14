---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/gcd_convolution.hpp
    title: Convolution/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/lcm_convolution.hpp
    title: Convolution/lcm_convolution.hpp
  - icon: ':warning:'
    path: verify/Convolution_gcd_convolution_test.cpp
    title: verify/Convolution_gcd_convolution_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Convolution_gcd_convolution.test.cpp
    title: verify/Convolution_gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/Convolution_lcm_convolution.test.cpp
    title: verify/Convolution_lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/sieve.hpp\"\nstruct notlinear_sieve {\n    int n;\n\
    \    vector<int> sm;\n\n    notlinear_sieve(int max_n) : n(max_n), sm(max_n +\
    \ 1) {\n        assert(1 <= n);\n        iota(sm.begin(), sm.end(), 0);\n    \
    \    if (n >= 2) sm[2] = 2;\n        for (int j = 4; j <= n; j += 2) sm[j] = 2;\n\
    \        for (int i = 3; i * i <= n; i += 2) {\n            if (sm[i] != i) continue;\n\
    \            for (int j = i * 2; j <= n; j += i) {\n                if (sm[j]\
    \ == j) sm[j] = i;\n            }\n        }\n    }\n\n    bool is_prime(int v)\
    \ const noexcept {\n        assert(v <= n);\n        if (v <= 1) return false;\n\
    \        return sm[v] == v;\n    }\n\n    vector<int> primes(int max_n) const\
    \ noexcept {\n        assert(1 <= max_n && max_n <= n);\n        vector<int> ret;\n\
    \        for (int i = 2; i <= max_n; i++)\n            if (is_prime(i)) ret.push_back(i);\n\
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
    \u3046\u3068\u826F\u3044\u3002\u8A08\u7B97\u91CF\u306FO(nloglogn)\n    // zeta_transform...\
    \ \u7D50\u5408\u5247 + \u4EA4\u63DB\u5247 \u306A\u3089\u306A\u3093\u3067\u3082\
    \u4E57\u308B\n    // mobius_transform ... \u7D50\u5408 + \u4EA4\u63DB + \u9006\
    \u5143\u306E\u5B58\u5728 \u306A\u3089\u306A\u3093\u3067\u3082\u4E57\u308B\n  \
    \  // f -> F   \u7D04\u6570\u306E\u6DFB\u5B57\u3092add\n    template <typename\
    \ T> vector<T> divisor_zeta_transform(vector<T> A) const {\n        int N = int(A.size())\
    \ - 1;\n        assert(N <= n);\n        for (int p = 2; p <= N; p++) {\n    \
    \        if (is_prime(p)) {\n                for (int k = 1; k * p <= N; k++)\
    \ {\n                    A[k * p] += A[k];\n                }\n            }\n\
    \        }\n        return A;\n    }\n\n    // F -> f\n    template <typename\
    \ T>\n    vector<T> divisor_mobius_transform(vector<T> A) const {\n        int\
    \ N = int(A.size()) - 1;\n        assert(N <= n);\n        for (int p = 2; p <=\
    \ N; p++) {\n            if (is_prime(p)) {\n                for (int k = N /\
    \ p; k >= 1; k--) {\n                    A[k * p] -= A[k];\n                }\n\
    \            }\n        }\n        return A;\n    }\n\n    // f -> F \u500D\u6570\
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
    };\n"
  code: "struct notlinear_sieve {\n    int n;\n    vector<int> sm;\n\n    notlinear_sieve(int\
    \ max_n) : n(max_n), sm(max_n + 1) {\n        assert(1 <= n);\n        iota(sm.begin(),\
    \ sm.end(), 0);\n        if (n >= 2) sm[2] = 2;\n        for (int j = 4; j <=\
    \ n; j += 2) sm[j] = 2;\n        for (int i = 3; i * i <= n; i += 2) {\n     \
    \       if (sm[i] != i) continue;\n            for (int j = i * 2; j <= n; j +=\
    \ i) {\n                if (sm[j] == j) sm[j] = i;\n            }\n        }\n\
    \    }\n\n    bool is_prime(int v) const noexcept {\n        assert(v <= n);\n\
    \        if (v <= 1) return false;\n        return sm[v] == v;\n    }\n\n    vector<int>\
    \ primes(int max_n) const noexcept {\n        assert(1 <= max_n && max_n <= n);\n\
    \        vector<int> ret;\n        for (int i = 2; i <= max_n; i++)\n        \
    \    if (is_prime(i)) ret.push_back(i);\n        return ret;\n    }\n\n    //\
    \ sorted\n    vector<pair<int, int>> factorize(int v) const noexcept {\n     \
    \   assert(1 <= v && v <= n);\n        vector<pair<int, int>> ret;\n        while\
    \ (sm[v] != v) {\n            int tmp = v;\n            int c = 0;\n         \
    \   while (tmp % sm[v] == 0) c++, tmp /= sm[v];\n            ret.emplace_back(sm[v],\
    \ c);\n            v = tmp;\n        }\n        if (v != 1) ret.emplace_back(v,\
    \ 1);\n        return ret;\n    }\n\n    int divcnt(int v) const noexcept {\n\
    \        assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n        int\
    \ ret = 1;\n        for (auto [p, c] : ps) ret *= (c + 1);\n        return ret;\n\
    \    }\n\n    // not sorted\n    vector<int> divs(int v) const noexcept {\n  \
    \      assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n        int\
    \ sz = 1;\n        for (auto [p, c] : ps) sz *= (c + 1);\n        vector<int>\
    \ ret(sz);\n        ret[0] = 1;\n        int r = 1;\n        for (auto [p, c]\
    \ : ps) {\n            int nr = r;\n            for (int j = 0; j < c; j++) {\n\
    \                for (int k = 0; k < r; k++) {\n                    ret[nr] =\
    \ p * ret[nr - r];\n                    nr++;\n                }\n           \
    \ }\n            r = nr;\n        }\n        return ret;\n    }\n\n    // \u5076\
    \u6570...+1 \u5947\u6570...-1 p^2...0\n    template <typename T> vector<T> mobius(int\
    \ N) const {\n        assert(N <= n);\n        vector<T> ret(N + 1, 1);\n    \
    \    for (int p = 2; p <= N; p++)\n            if (is_prime(p)) {\n          \
    \      for (int q = p; q <= N; q += p) {\n                    if ((q / p) % p\
    \ == 0)\n                        ret[q] = 0;\n                    else\n     \
    \                   ret[q] = -ret[q];\n                }\n            }\n    \
    \    return ret;\n    }\n\n    // \u4EE5\u4E0B4\u3064\u306F\u7D20\u56E0\u6570\u3054\
    \u3068\u306E\u7D2F\u7A4D\u548C\u3068\u601D\u3046\u3068\u826F\u3044\u3002\u8A08\
    \u7B97\u91CF\u306FO(nloglogn)\n    // zeta_transform... \u7D50\u5408\u5247 + \u4EA4\
    \u63DB\u5247 \u306A\u3089\u306A\u3093\u3067\u3082\u4E57\u308B\n    // mobius_transform\
    \ ... \u7D50\u5408 + \u4EA4\u63DB + \u9006\u5143\u306E\u5B58\u5728 \u306A\u3089\
    \u306A\u3093\u3067\u3082\u4E57\u308B\n    // f -> F   \u7D04\u6570\u306E\u6DFB\
    \u5B57\u3092add\n    template <typename T> vector<T> divisor_zeta_transform(vector<T>\
    \ A) const {\n        int N = int(A.size()) - 1;\n        assert(N <= n);\n  \
    \      for (int p = 2; p <= N; p++) {\n            if (is_prime(p)) {\n      \
    \          for (int k = 1; k * p <= N; k++) {\n                    A[k * p] +=\
    \ A[k];\n                }\n            }\n        }\n        return A;\n    }\n\
    \n    // F -> f\n    template <typename T>\n    vector<T> divisor_mobius_transform(vector<T>\
    \ A) const {\n        int N = int(A.size()) - 1;\n        assert(N <= n);\n  \
    \      for (int p = 2; p <= N; p++) {\n            if (is_prime(p)) {\n      \
    \          for (int k = N / p; k >= 1; k--) {\n                    A[k * p] -=\
    \ A[k];\n                }\n            }\n        }\n        return A;\n    }\n\
    \n    // f -> F \u500D\u6570\u306E\u6DFB\u5B57\u3092add\n    template <typename\
    \ T> vector<T> multiple_zeta_transform(vector<T> A) const {\n        int N = int(A.size())\
    \ - 1;\n        assert(N <= n);\n        for (int p = 2; p <= N; p++) {\n    \
    \        if (is_prime(p)) {\n                for (int k = N / p; k >= 1; k--)\
    \ {\n                    A[k] += A[k * p];\n                }\n            }\n\
    \        }\n        return A;\n    }\n\n    // F -> f\n    template <typename\
    \ T>\n    vector<T> multiple_mobius_transform(vector<T> A) const {\n        int\
    \ N = int(A.size()) - 1;\n        assert(N <= n);\n        for (int p = 2; p <=\
    \ N; p++) {\n            if (is_prime(p)) {\n                for (int k = 1; k\
    \ <= N / p; k++) {\n                    A[k] -= A[k * p];\n                }\n\
    \            }\n        }\n        return A;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.hpp
  requiredBy:
  - verify/Convolution_gcd_convolution_test.cpp
  - Convolution/gcd_convolution.hpp
  - Convolution/lcm_convolution.hpp
  timestamp: '2025-01-11 07:38:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Convolution_lcm_convolution.test.cpp
  - verify/Convolution_gcd_convolution.test.cpp
documentation_of: Math/sieve.hpp
layout: document
redirect_from:
- /library/Math/sieve.hpp
- /library/Math/sieve.hpp.html
title: Math/sieve.hpp
---
