---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/Math_combination.test.cpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination_more.test.cpp
    title: verify/Math_combination_more.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/combination.hpp\"\ntemplate <typename T, long long\
    \ mod> struct combination {\n    vector<long long> fac, ifac, inv;\n    long long\
    \ N;\n    combination() {\n        fac.resize(2, 1);\n        ifac.resize(2, 1);\n\
    \        inv.resize(2, 1);\n        N = 1;\n    }\n\n    void reserve(long long\
    \ n) { expand(n); }\n\n    T operator()(int n, int k) { return C(n, k); }\n\n\
    \    T raw(long long n, long long k) const {\n        if (k < 0) return 0;\n \
    \       if (k == 0) return 1;\n        if (n < k) return 0;\n\n        if (n -\
    \ k < k) {\n            k = n - k;\n        }\n        long long p = 1, q = 1;\n\
    \        for (long long i = 0; i < k; i++) {\n            p *= (n - i) % mod;\n\
    \            p %= mod;\n            q *= (k - i) % mod;\n            q %= mod;\n\
    \        }\n        return p * modinv(q) % mod;\n    }\n\n    T C(int n, int k)\
    \ {\n        if (k < 0) return 0;\n        if (k == 0) return 1;\n        if (n\
    \ < k) return 0;\n        if (N < n) expand(n);\n        return fac[n] * ifac[n\
    \ - k] % mod * ifac[k] % mod;\n    }\n\n    T P(int n, int k) {\n        if (k\
    \ < 0) return 0;\n        if (k == 0) return 1;\n        if (n < k) return 0;\n\
    \        if (N < n) expand(n);\n        return fac[n] * ifac[n - k] % mod;\n \
    \   }\n\n    T B(int n) {\n        if (N < n) expand(n);\n        return (n <\
    \ 0 ? 0 : fac[n]);\n    }\n    T invB(int n) {\n        if (N < n) expand(n);\n\
    \        return (n < 0 ? 0 : ifac[n]);\n    }\n\n    T H(int n, int k) { return\
    \ C(n + k - 1, k); }\n\n    T Cn(int n) { return C(2 * n, n) * inv[n + 1] % mod;\
    \ }\n\n  private:\n    constexpr static bool is_prime_constexpr(long long x) {\n\
    \        if (x <= 1) return false;\n        for (long long i = 2; i * i <= x;\
    \ i++) {\n            if (x % i == 0) return false;\n        }\n        return\
    \ true;\n    }\n\n    static_assert(is_prime_constexpr(mod), \"mod must be prime\"\
    );\n    static_assert(__int128_t(mod - 1) * (mod - 1) <= __int128_t(LLONG_MAX),\n\
    \                  \"(mod - 1) * (mod - 1) <= LLONG_MAX must be satisfied\");\n\
    \n    long long extgcd(long long a,\n                     long long b,\n     \
    \                long long &x,\n                     long long &y) const {\n \
    \       if (b == 0) {\n            x = 1;\n            y = 0;\n            return\
    \ a;\n        }\n        auto d = extgcd(b, a % b, y, x);\n        y -= a / b\
    \ * x;\n        return d;\n    }\n\n    long long modinv(long long a) const {\n\
    \        long long x, y;\n        extgcd(a, mod, x, y);\n        x %= mod;\n \
    \       if (x < 0) x += mod;\n        return x;\n    }\n\n    void expand(long\
    \ long new_max_n) {\n        if (new_max_n <= N) return;\n        long long nx\
    \ = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\u3066\u3044\u304F\u3002\
    \n        while (nx < new_max_n) nx <<= 1;\n        new_max_n = nx;\n\n      \
    \  long long pre = N;\n        N = new_max_n;\n        fac.resize(N + 1);\n  \
    \      ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for (long long\
    \ i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i % mod;\n  \
    \      }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N] * fac[N\
    \ - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n      \
    \      ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i] *\
    \ fac[i - 1] % mod;\n        }\n        return;\n    }\n};\n"
  code: "template <typename T, long long mod> struct combination {\n    vector<long\
    \ long> fac, ifac, inv;\n    long long N;\n    combination() {\n        fac.resize(2,\
    \ 1);\n        ifac.resize(2, 1);\n        inv.resize(2, 1);\n        N = 1;\n\
    \    }\n\n    void reserve(long long n) { expand(n); }\n\n    T operator()(int\
    \ n, int k) { return C(n, k); }\n\n    T raw(long long n, long long k) const {\n\
    \        if (k < 0) return 0;\n        if (k == 0) return 1;\n        if (n <\
    \ k) return 0;\n\n        if (n - k < k) {\n            k = n - k;\n        }\n\
    \        long long p = 1, q = 1;\n        for (long long i = 0; i < k; i++) {\n\
    \            p *= (n - i) % mod;\n            p %= mod;\n            q *= (k -\
    \ i) % mod;\n            q %= mod;\n        }\n        return p * modinv(q) %\
    \ mod;\n    }\n\n    T C(int n, int k) {\n        if (k < 0) return 0;\n     \
    \   if (k == 0) return 1;\n        if (n < k) return 0;\n        if (N < n) expand(n);\n\
    \        return fac[n] * ifac[n - k] % mod * ifac[k] % mod;\n    }\n\n    T P(int\
    \ n, int k) {\n        if (k < 0) return 0;\n        if (k == 0) return 1;\n \
    \       if (n < k) return 0;\n        if (N < n) expand(n);\n        return fac[n]\
    \ * ifac[n - k] % mod;\n    }\n\n    T B(int n) {\n        if (N < n) expand(n);\n\
    \        return (n < 0 ? 0 : fac[n]);\n    }\n    T invB(int n) {\n        if\
    \ (N < n) expand(n);\n        return (n < 0 ? 0 : ifac[n]);\n    }\n\n    T H(int\
    \ n, int k) { return C(n + k - 1, k); }\n\n    T Cn(int n) { return C(2 * n, n)\
    \ * inv[n + 1] % mod; }\n\n  private:\n    constexpr static bool is_prime_constexpr(long\
    \ long x) {\n        if (x <= 1) return false;\n        for (long long i = 2;\
    \ i * i <= x; i++) {\n            if (x % i == 0) return false;\n        }\n \
    \       return true;\n    }\n\n    static_assert(is_prime_constexpr(mod), \"mod\
    \ must be prime\");\n    static_assert(__int128_t(mod - 1) * (mod - 1) <= __int128_t(LLONG_MAX),\n\
    \                  \"(mod - 1) * (mod - 1) <= LLONG_MAX must be satisfied\");\n\
    \n    long long extgcd(long long a,\n                     long long b,\n     \
    \                long long &x,\n                     long long &y) const {\n \
    \       if (b == 0) {\n            x = 1;\n            y = 0;\n            return\
    \ a;\n        }\n        auto d = extgcd(b, a % b, y, x);\n        y -= a / b\
    \ * x;\n        return d;\n    }\n\n    long long modinv(long long a) const {\n\
    \        long long x, y;\n        extgcd(a, mod, x, y);\n        x %= mod;\n \
    \       if (x < 0) x += mod;\n        return x;\n    }\n\n    void expand(long\
    \ long new_max_n) {\n        if (new_max_n <= N) return;\n        long long nx\
    \ = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\u3066\u3044\u304F\u3002\
    \n        while (nx < new_max_n) nx <<= 1;\n        new_max_n = nx;\n\n      \
    \  long long pre = N;\n        N = new_max_n;\n        fac.resize(N + 1);\n  \
    \      ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for (long long\
    \ i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i % mod;\n  \
    \      }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N] * fac[N\
    \ - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n      \
    \      ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i] *\
    \ fac[i - 1] % mod;\n        }\n        return;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.hpp
  requiredBy: []
  timestamp: '2025-01-16 07:36:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/Math_combination.test.cpp
  - verify/Math_combination_more.test.cpp
documentation_of: Math/combination.hpp
layout: document
redirect_from:
- /library/Math/combination.hpp
- /library/Math/combination.hpp.html
title: Math/combination.hpp
---
