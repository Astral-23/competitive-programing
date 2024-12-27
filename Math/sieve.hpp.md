---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/sieve.hpp\"\ntemplate<int n> struct notlinear_sieve\
    \ {\n    array<int, n+1> sm;\n\n    notlinear_sieve() {\n        assert(1 <= n);\n\
    \        iota(sm.begin(), sm.end(), 0);\n\n        sm[2] = 2;\n        for(int\
    \ j = 4; j <= n; j += 2) sm[j] = 2;\n        for(int i = 3; i * i <= n; i += 2)\
    \ {\n            if(sm[i] != i) continue;\n            for(int j = i * 2; j <=\
    \ n; j += i) {\n                if(sm[j] == j) sm[j] = i;\n            }\n   \
    \     }\n    }\n\n\n    bool isprime(int v) const noexcept {\n        assert(v\
    \ <= n);\n        if(v <= 1) return false;\n        return sm[v] == v;\n    }\n\
    \n    vector<int> primes(int max_n) const noexcept {\n        assert(1 <= max_n\
    \ && max_n <= n);\n        vector<int> ret;\n        for(int i = 2; i <= max_n;\
    \ i++) if(isprime(i)) ret.push_back(i);\n        return ret;\n    }\n\n    //sorted\n\
    \    vector<pair<int, int>> factorize(int v) const noexcept {\n        assert(1\
    \ <= v && v <= n);\n        vector<pair<int, int>> ret;\n        while(sm[v]!=\
    \ v) {\n            int tmp = v;\n            int c = 0;\n            while(tmp\
    \ % sm[v] == 0) c++, tmp /= sm[v];\n            ret.emplace_back(sm[v], c);\n\
    \            v = tmp;\n        }\n        if(v != 1) ret.emplace_back(v, 1);\n\
    \        return ret;\n    }\n\n    int divcnt(int v) const noexcept {\n      \
    \  assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n        int ret\
    \ = 1;\n        for(auto [p, c] : ps) ret *= (c + 1);\n        return ret;\n \
    \   }\n    \n    // not sorted\n    vector<int> divs(int v) const noexcept {\n\
    \        assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n        int\
    \ sz = 1;\n        for(auto [p, c] : ps) sz *= (c + 1);\n        vector<int> ret(sz);\n\
    \        ret[0] = 1;\n        int r = 1;\n        for(auto [p, c] : ps) {\n  \
    \          int nr = r;\n            for(int j = 0; j < c; j++) {\n           \
    \     for(int k = 0; k < r; k++) {\n                    ret[nr] = p * ret[nr -\
    \ r];\n                    nr++;\n                }\n            }\n         \
    \   r = nr;\n        }\n        return ret;\n    }\n};\n"
  code: "template<int n> struct notlinear_sieve {\n    array<int, n+1> sm;\n\n   \
    \ notlinear_sieve() {\n        assert(1 <= n);\n        iota(sm.begin(), sm.end(),\
    \ 0);\n\n        sm[2] = 2;\n        for(int j = 4; j <= n; j += 2) sm[j] = 2;\n\
    \        for(int i = 3; i * i <= n; i += 2) {\n            if(sm[i] != i) continue;\n\
    \            for(int j = i * 2; j <= n; j += i) {\n                if(sm[j] ==\
    \ j) sm[j] = i;\n            }\n        }\n    }\n\n\n    bool isprime(int v)\
    \ const noexcept {\n        assert(v <= n);\n        if(v <= 1) return false;\n\
    \        return sm[v] == v;\n    }\n\n    vector<int> primes(int max_n) const\
    \ noexcept {\n        assert(1 <= max_n && max_n <= n);\n        vector<int> ret;\n\
    \        for(int i = 2; i <= max_n; i++) if(isprime(i)) ret.push_back(i);\n  \
    \      return ret;\n    }\n\n    //sorted\n    vector<pair<int, int>> factorize(int\
    \ v) const noexcept {\n        assert(1 <= v && v <= n);\n        vector<pair<int,\
    \ int>> ret;\n        while(sm[v]!= v) {\n            int tmp = v;\n         \
    \   int c = 0;\n            while(tmp % sm[v] == 0) c++, tmp /= sm[v];\n     \
    \       ret.emplace_back(sm[v], c);\n            v = tmp;\n        }\n       \
    \ if(v != 1) ret.emplace_back(v, 1);\n        return ret;\n    }\n\n    int divcnt(int\
    \ v) const noexcept {\n        assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n\
    \        int ret = 1;\n        for(auto [p, c] : ps) ret *= (c + 1);\n       \
    \ return ret;\n    }\n    \n    // not sorted\n    vector<int> divs(int v) const\
    \ noexcept {\n        assert(1 <= v && v <= n);\n        auto ps = factorize(v);\n\
    \        int sz = 1;\n        for(auto [p, c] : ps) sz *= (c + 1);\n        vector<int>\
    \ ret(sz);\n        ret[0] = 1;\n        int r = 1;\n        for(auto [p, c] :\
    \ ps) {\n            int nr = r;\n            for(int j = 0; j < c; j++) {\n \
    \               for(int k = 0; k < r; k++) {\n                    ret[nr] = p\
    \ * ret[nr - r];\n                    nr++;\n                }\n            }\n\
    \            r = nr;\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.hpp
  requiredBy: []
  timestamp: '2024-12-27 13:57:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sieve.hpp
layout: document
redirect_from:
- /library/Math/sieve.hpp
- /library/Math/sieve.hpp.html
title: Math/sieve.hpp
---
