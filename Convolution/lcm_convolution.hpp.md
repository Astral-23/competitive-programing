---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/sieve.hpp
    title: Math/sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    }\n"
  code: "#include \"../Math/sieve.hpp\"\n// lcm(a, b) = l  <-> lcm(a, b) \u304C l\u306E\
    \u7D04\u6570 (\u21D4 a, b\u3068\u3082\u306Bl\u306E\u7D04\u6570(\u7D20\u56E0\u6570\
    \u6BCE\u306Bmax\u3092\u3068\u3063\u3066\u3044\u308B\u4E8B\u3088\u308A\u81EA\u660E\
    ))\ntemplate <typename T>\nvector<T> lcm_convolution(vector<T> A, vector<T> B)\
    \ {\n    if (A.empty() || B.empty()) return {};\n    int n = max<int>(A.size(),\
    \ B.size()) - 1;\n    notlinear_sieve sieve(n);\n    A.resize(n + 1, 0);\n   \
    \ B.resize(n + 1, 0);\n    vector<T> div_A = sieve.divisor_zeta_transform<T>(A);\n\
    \    vector<T> div_B = sieve.divisor_zeta_transform<T>(B);\n    for(int i = 1;\
    \ i <= n; i += 1) {\n        div_A[i] *= div_B[i];\n    }\n    return sieve.divisor_mobius_transform<T>(div_A);\n\
    }"
  dependsOn:
  - Math/sieve.hpp
  isVerificationFile: false
  path: Convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2025-01-11 02:41:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Convolution_lcm_convolution.test.cpp
documentation_of: Convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/Convolution/lcm_convolution.hpp
- /library/Convolution/lcm_convolution.hpp.html
title: Convolution/lcm_convolution.hpp
---
