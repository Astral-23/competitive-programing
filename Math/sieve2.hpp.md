---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: atcoder/convolution.hpp
    title: atcoder/convolution.hpp
  - icon: ':x:'
    path: atcoder/dsu.hpp
    title: atcoder/dsu.hpp
  - icon: ':x:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':x:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':x:'
    path: atcoder/internal_csr.hpp
    title: atcoder/internal_csr.hpp
  - icon: ':x:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':x:'
    path: atcoder/internal_queue.hpp
    title: atcoder/internal_queue.hpp
  - icon: ':x:'
    path: atcoder/internal_scc.hpp
    title: atcoder/internal_scc.hpp
  - icon: ':x:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':x:'
    path: atcoder/lazysegtree.hpp
    title: atcoder/lazysegtree.hpp
  - icon: ':x:'
    path: atcoder/math.hpp
    title: atcoder/math.hpp
  - icon: ':x:'
    path: atcoder/maxflow.hpp
    title: atcoder/maxflow.hpp
  - icon: ':x:'
    path: atcoder/mincostflow.hpp
    title: atcoder/mincostflow.hpp
  - icon: ':x:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':x:'
    path: atcoder/scc.hpp
    title: atcoder/scc.hpp
  - icon: ':x:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  - icon: ':x:'
    path: atcoder/string.hpp
    title: atcoder/string.hpp
  - icon: ':x:'
    path: atcoder/twosat.hpp
    title: atcoder/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
    links: []
  bundledCode: "#line 1 \"Math/sieve2.hpp\"\n#include <bits/stdc++.h>\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nstd::ostream &operator<<(std::ostream &os, const atcoder::modint998244353\
    \ &v) {\n    os << v.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, atcoder::modint998244353 &v) {\n    long long x;\n    is >> x;\n    v =\
    \ x;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007\
    \ &v) {\n    os << v.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, atcoder::modint1000000007 &v) {\n    long long x;\n    is >> x;\n    v\
    \ = x;\n    return is;\n}\n#endif\n\nusing namespace std;\nusing ll = long long;\n\
    using pll = pair<ll, ll>;\n#define el '\\n';\n#define rep(i, s, t) for (ll i =\
    \ s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n#define eb emplace_back\n#define pb push_back\n\
    #define TT template <typename T>\nTT using vec = vector<T>;\nTT using vvec = vec<vec<T>>;\n\
    TT using vvvec = vec<vvec<T>>;\nTT using minheap = priority_queue<T, vector<T>,\
    \ greater<T>>;\nTT using maxheap = priority_queue<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2, class T3> bool rng(T1\
    \ l, T2 x, T3 r) {\n    return l <= x && x < r;\n}\nTT T flr(T a, T b) {\n   \
    \ if (b < 0) a = -a, b = -b;\n    return a >= 0 ? a / b : (a + 1) / b - 1;\n}\n\
    \nTT T cil(T a, T b) {\n    if (b < 0) a = -a, b = -b;\n    return a > 0 ? (a\
    \ - 1) / b + 1 : a / b;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\ntemplate <class T1, class T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p) {\n    os << p.first << \" \" << p.second;\n   \
    \ return os;\n}\n\nTT ostream &operator<<(ostream &os, const vec<T> &v) {\n  \
    \  for (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 != v.size()\
    \ ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T, ll n>\n\
    ostream &operator<<(ostream &os, const array<T, n> &v) {\n    for (size_t i =\
    \ 0; i < n; i++) {\n        os << v[i] << (i + 1 != n ? \" \" : \"\");\n    }\n\
    \    return os;\n}\n\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vvec<T> &v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        os << v[i]\
    \ << (i + 1 != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\nTT istream\
    \ &operator>>(istream &is, vec<T> &v) {\n    for (size_t i = 0; i < v.size();\
    \ i++) {\n        is >> v[i];\n    }\n    return is;\n}\n\n#if __has_include(<debug/debug.hpp>)\n\
    #include <debug/debug.hpp>\n#else\n#define dbg(...) true\n#define DBG(...) true\n\
    #define OUT(...) true\n#endif\nstruct sectional_primes {\n    /*\n    [L, R]\u306E\
    \u6574\u6570\u3092\u7D20\u6570\u5224\u5B9A\uFF1A\u7D20\u56E0\u6570\u5206\u89E3\
    \u3059\u308B\u3002\n    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1A\u7D20\
    \u6570\u5224\u5B9A\n    O(\u221ARloglog\u221AR + (R - L)loglog(R-L))\uFF1F\n \
    \   [1, 10^6]\u3067134ms [10^12, 10^12 + 10^6]\u3067350ms\u7A0B\n\n    conduct()\u3092\
    \u5B9F\u884C\u3059\u308B\u3068\u3001\u7D20\u56E0\u6570\u5206\u89E3\u304C\u5B9F\
    \u884C\u3055\u308C\u308B\u3002\n    O((R - L)log(R))\n    \u53C2\u8003 : \u533A\
    \u9593\u9577\u3068R\u306E\u5927\u304D\u3055\u304C\u901F\u5EA6\u306B\u5F71\u97FF\
    \u3002\n    [1, 10^6]\u3067300ms, [10^12, 10^12 + 10^6]\u3067550ms\u7A0B\n   \
    \ isprime[i]\u3067\u3001i\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u304C\u308F\
    \u304B\u308B\u3002  L <= i <= R || 1 <= i <= \u221AR O(1)\n    get[i]\u3067\u3001\
    i\u306E\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u304C\u5F97\u3089\u308C\
    \u308B  L <= i <= R  O(log(i))\n    */\n    long long L, R, M;\n    bool conducted\
    \ = false;\n    vector<bool> small;  // small[i] := i\u304C\u7D20\u6570\u304B\u3069\
    \u3046\u304B i <= \u221AR\n    vector<vector<long long>> large;  // large[i] :=\
    \ i+L \u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u306E\u96C6\u5408\n   \
    \ vector<vector<pair<long long, long long>>> large_res;\n    vector<vector<long\
    \ long>> aux;  // aux[i] := large[i]\u306E\u7D20\u56E0\u6570\u306E\u7A4D\u3001\
    \u3064\u307E\u308Ai +\n                                    // L\u306E\u7D20\u56E0\
    \u6570\u306E\u7A4D\uFF08\u7D20\u6570\u5224\u5B9A\u7528\uFF09\n\n    sectional_primes(long\
    \ long _L, long long _R) : L(_L), R(_R) {\n        assert(R >= 1 && L <= R);\n\
    \        M = sqrt(R);\n        small.resize(M + 1, true);\n        small[0] =\
    \ false;\n        small[1] = false;\n        large.resize(R - L + 1);\n      \
    \  large_res.resize(R - L + 1);\n\n        for (long long i = 2; i * i <= R; i++)\
    \ {\n            if (!small[i]) continue;\n            for (long long j = i *\
    \ 2; j <= M; j += i) {\n                small[j] = false;\n            }\n   \
    \         for (long long j = (L + i - 1) / i * i; j <= R; j += i) {\n        \
    \        large[j - L].push_back(i);\n            }\n        }\n        // \u221A\
    R\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u306F\u5168\u3066\u5217\u6319\u3057\u7D42\
    \u3048\u305F\u3002\u3053\u3053\u304B\u3089\u306F\u221AR\u4EE5\u4E0A\u306E\u7D20\
    \u56E0\u6570\u3092\u5217\u6319\u3002\u3061\u306A\u307F\u306B\u3001\u221AR\u4EE5\
    \u4E0A\u306E\u7D20\u56E0\u6570\u306F\u5404\u6570\u306B\u3064\u304D\u6700\u5927\
    \u30661\u3064\u3002\n        // \u3053\u3053\u307E\u3067O(\u221ARloglog\u221A\
    R + (R - L)loglog(R-L))\n    }\n\n  private:\n    void conduct() {\n        conducted\
    \ = true;\n        for (long long i = L; i <= R; i++) {\n            long long\
    \ num = i;\n            for (long long x : large[i - L]) {\n                if\
    \ (num < x) break;\n                long long cnt = 0;\n                while\
    \ (num % x == 0) num /= x, cnt++;\n                large_res[i - L].emplace_back(x,\
    \ cnt);\n            }\n            if (num != 1)\n                large[i - L].push_back(num),\n\
    \                    large_res[i - L].emplace_back(num, 1);\n        }\n     \
    \   // O((R - L)log(R))\n    }\n\n    vector<ll> divs__(ll x) {\n        if (!conducted)\
    \ conduct();\n        vector<ll> res;\n        auto ps = get(x);\n\n        auto\
    \ dfs = [&](auto dfs, long long id, long long val) -> void {\n            if (id\
    \ == ps.size()) {\n                res.push_back(val);\n                return;\n\
    \            }\n\n            auto [p, c] = ps[id];\n            for (int i =\
    \ 0; i <= c; i++) {\n                dfs(dfs, id + 1, val);\n                val\
    \ *= p;\n            }\n        };\n\n        dfs(dfs, 0, 1);\n        return\
    \ res;\n    }\n\n  public:\n    bool isprime(long long x) {  //[-\u7121\u9650\
    , \u221AR] \u307E\u305F\u306F [L, R]\u306B\u3064\u3044\u3066\u3001\u7D20\u6570\
    \u5224\u5B9A\n                                 // \u305D\u308C\u4EE5\u5916\u306F\
    \u672A\u5B9A\u7FA9\n        if (x <= 1) return false;\n        if (x <= M) return\
    \ small[x];\n        if (!conducted)\n            return large[x - L].size() ==\
    \ 0;  // \u221AR\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u304C\u306A\u3044\u21D4x\u304C\
    \u7D20\u6570\n        else\n            return large[x - L].size() == 1;  // \u7D20\
    \u56E0\u6570\u5206\u89E3\u6E08\u307F\u3002\n    }  // O(1)\n\n    vector<pair<long\
    \ long, long long>> get(\n        long long\n            x) {  //[L, R]\u306B\u3064\
    \u3044\u3066\u3001\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u3092\u8FD4\
    \u3059 {\u7D20\u56E0\u6570, \u6307\u6570}\u306E\u914D\u5217\n        if (!conducted)\
    \ conduct();\n        assert(L <= x && x <= R);\n        return large_res[x -\
    \ L];\n    }  // \u521D\u56DE\u3044\u3063\u3071\u3044 \u4EE5\u964DO(1)\n\n   \
    \ vector<ll> divs(ll x) {  // x\u306E\u7D04\u6570\u3092\u9069\u5F53\u306A\u9806\
    \u3067\u5165\u308C\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n        return divs__(x);\n\
    \    }  // O(\u7D04\u6570\u306E\u500B\u6570)  x <= 10^18\u3067\u5927\u51E1 O(x\
    \ ^ (1/3))  \u6CE8 : \u521D\u56DEO(NlogN)\n};\n\n/*\n@brief \u7D20\u6570\u7BE9\
    (\u5DE6\u7AEF\u4EFB\u610F)\n*/\nint main() {}\n// s -> 0, 0 -> 9, 9 -> t, 1\n"
  code: "#include <bits/stdc++.h>\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\n\
    std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &v)\
    \ {\n    os << v.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, atcoder::modint998244353 &v) {\n    long long x;\n    is >> x;\n    v =\
    \ x;\n    return is;\n}\nstd::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007\
    \ &v) {\n    os << v.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, atcoder::modint1000000007 &v) {\n    long long x;\n    is >> x;\n    v\
    \ = x;\n    return is;\n}\n#endif\n\nusing namespace std;\nusing ll = long long;\n\
    using pll = pair<ll, ll>;\n#define el '\\n';\n#define rep(i, s, t) for (ll i =\
    \ s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s);\
    \ i--)\n#define all(x) begin(x), end(x)\n#define eb emplace_back\n#define pb push_back\n\
    #define TT template <typename T>\nTT using vec = vector<T>;\nTT using vvec = vec<vec<T>>;\n\
    TT using vvvec = vec<vvec<T>>;\nTT using minheap = priority_queue<T, vector<T>,\
    \ greater<T>>;\nTT using maxheap = priority_queue<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\ntemplate <class T1, class T2, class T3> bool rng(T1\
    \ l, T2 x, T3 r) {\n    return l <= x && x < r;\n}\nTT T flr(T a, T b) {\n   \
    \ if (b < 0) a = -a, b = -b;\n    return a >= 0 ? a / b : (a + 1) / b - 1;\n}\n\
    \nTT T cil(T a, T b) {\n    if (b < 0) a = -a, b = -b;\n    return a > 0 ? (a\
    \ - 1) / b + 1 : a / b;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\ntemplate <class T1, class T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p) {\n    os << p.first << \" \" << p.second;\n   \
    \ return os;\n}\n\nTT ostream &operator<<(ostream &os, const vec<T> &v) {\n  \
    \  for (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 != v.size()\
    \ ? \" \" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename T, ll n>\n\
    ostream &operator<<(ostream &os, const array<T, n> &v) {\n    for (size_t i =\
    \ 0; i < n; i++) {\n        os << v[i] << (i + 1 != n ? \" \" : \"\");\n    }\n\
    \    return os;\n}\n\ntemplate <typename T> ostream &operator<<(ostream &os, const\
    \ vvec<T> &v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        os << v[i]\
    \ << (i + 1 != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\nTT istream\
    \ &operator>>(istream &is, vec<T> &v) {\n    for (size_t i = 0; i < v.size();\
    \ i++) {\n        is >> v[i];\n    }\n    return is;\n}\n\n#if __has_include(<debug/debug.hpp>)\n\
    #include <debug/debug.hpp>\n#else\n#define dbg(...) true\n#define DBG(...) true\n\
    #define OUT(...) true\n#endif\nstruct sectional_primes {\n    /*\n    [L, R]\u306E\
    \u6574\u6570\u3092\u7D20\u6570\u5224\u5B9A\uFF1A\u7D20\u56E0\u6570\u5206\u89E3\
    \u3059\u308B\u3002\n    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1A\u7D20\
    \u6570\u5224\u5B9A\n    O(\u221ARloglog\u221AR + (R - L)loglog(R-L))\uFF1F\n \
    \   [1, 10^6]\u3067134ms [10^12, 10^12 + 10^6]\u3067350ms\u7A0B\n\n    conduct()\u3092\
    \u5B9F\u884C\u3059\u308B\u3068\u3001\u7D20\u56E0\u6570\u5206\u89E3\u304C\u5B9F\
    \u884C\u3055\u308C\u308B\u3002\n    O((R - L)log(R))\n    \u53C2\u8003 : \u533A\
    \u9593\u9577\u3068R\u306E\u5927\u304D\u3055\u304C\u901F\u5EA6\u306B\u5F71\u97FF\
    \u3002\n    [1, 10^6]\u3067300ms, [10^12, 10^12 + 10^6]\u3067550ms\u7A0B\n   \
    \ isprime[i]\u3067\u3001i\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u304C\u308F\
    \u304B\u308B\u3002  L <= i <= R || 1 <= i <= \u221AR O(1)\n    get[i]\u3067\u3001\
    i\u306E\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u304C\u5F97\u3089\u308C\
    \u308B  L <= i <= R  O(log(i))\n    */\n    long long L, R, M;\n    bool conducted\
    \ = false;\n    vector<bool> small;  // small[i] := i\u304C\u7D20\u6570\u304B\u3069\
    \u3046\u304B i <= \u221AR\n    vector<vector<long long>> large;  // large[i] :=\
    \ i+L \u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u306E\u96C6\u5408\n   \
    \ vector<vector<pair<long long, long long>>> large_res;\n    vector<vector<long\
    \ long>> aux;  // aux[i] := large[i]\u306E\u7D20\u56E0\u6570\u306E\u7A4D\u3001\
    \u3064\u307E\u308Ai +\n                                    // L\u306E\u7D20\u56E0\
    \u6570\u306E\u7A4D\uFF08\u7D20\u6570\u5224\u5B9A\u7528\uFF09\n\n    sectional_primes(long\
    \ long _L, long long _R) : L(_L), R(_R) {\n        assert(R >= 1 && L <= R);\n\
    \        M = sqrt(R);\n        small.resize(M + 1, true);\n        small[0] =\
    \ false;\n        small[1] = false;\n        large.resize(R - L + 1);\n      \
    \  large_res.resize(R - L + 1);\n\n        for (long long i = 2; i * i <= R; i++)\
    \ {\n            if (!small[i]) continue;\n            for (long long j = i *\
    \ 2; j <= M; j += i) {\n                small[j] = false;\n            }\n   \
    \         for (long long j = (L + i - 1) / i * i; j <= R; j += i) {\n        \
    \        large[j - L].push_back(i);\n            }\n        }\n        // \u221A\
    R\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u306F\u5168\u3066\u5217\u6319\u3057\u7D42\
    \u3048\u305F\u3002\u3053\u3053\u304B\u3089\u306F\u221AR\u4EE5\u4E0A\u306E\u7D20\
    \u56E0\u6570\u3092\u5217\u6319\u3002\u3061\u306A\u307F\u306B\u3001\u221AR\u4EE5\
    \u4E0A\u306E\u7D20\u56E0\u6570\u306F\u5404\u6570\u306B\u3064\u304D\u6700\u5927\
    \u30661\u3064\u3002\n        // \u3053\u3053\u307E\u3067O(\u221ARloglog\u221A\
    R + (R - L)loglog(R-L))\n    }\n\n  private:\n    void conduct() {\n        conducted\
    \ = true;\n        for (long long i = L; i <= R; i++) {\n            long long\
    \ num = i;\n            for (long long x : large[i - L]) {\n                if\
    \ (num < x) break;\n                long long cnt = 0;\n                while\
    \ (num % x == 0) num /= x, cnt++;\n                large_res[i - L].emplace_back(x,\
    \ cnt);\n            }\n            if (num != 1)\n                large[i - L].push_back(num),\n\
    \                    large_res[i - L].emplace_back(num, 1);\n        }\n     \
    \   // O((R - L)log(R))\n    }\n\n    vector<ll> divs__(ll x) {\n        if (!conducted)\
    \ conduct();\n        vector<ll> res;\n        auto ps = get(x);\n\n        auto\
    \ dfs = [&](auto dfs, long long id, long long val) -> void {\n            if (id\
    \ == ps.size()) {\n                res.push_back(val);\n                return;\n\
    \            }\n\n            auto [p, c] = ps[id];\n            for (int i =\
    \ 0; i <= c; i++) {\n                dfs(dfs, id + 1, val);\n                val\
    \ *= p;\n            }\n        };\n\n        dfs(dfs, 0, 1);\n        return\
    \ res;\n    }\n\n  public:\n    bool isprime(long long x) {  //[-\u7121\u9650\
    , \u221AR] \u307E\u305F\u306F [L, R]\u306B\u3064\u3044\u3066\u3001\u7D20\u6570\
    \u5224\u5B9A\n                                 // \u305D\u308C\u4EE5\u5916\u306F\
    \u672A\u5B9A\u7FA9\n        if (x <= 1) return false;\n        if (x <= M) return\
    \ small[x];\n        if (!conducted)\n            return large[x - L].size() ==\
    \ 0;  // \u221AR\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u304C\u306A\u3044\u21D4x\u304C\
    \u7D20\u6570\n        else\n            return large[x - L].size() == 1;  // \u7D20\
    \u56E0\u6570\u5206\u89E3\u6E08\u307F\u3002\n    }  // O(1)\n\n    vector<pair<long\
    \ long, long long>> get(\n        long long\n            x) {  //[L, R]\u306B\u3064\
    \u3044\u3066\u3001\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u3092\u8FD4\
    \u3059 {\u7D20\u56E0\u6570, \u6307\u6570}\u306E\u914D\u5217\n        if (!conducted)\
    \ conduct();\n        assert(L <= x && x <= R);\n        return large_res[x -\
    \ L];\n    }  // \u521D\u56DE\u3044\u3063\u3071\u3044 \u4EE5\u964DO(1)\n\n   \
    \ vector<ll> divs(ll x) {  // x\u306E\u7D04\u6570\u3092\u9069\u5F53\u306A\u9806\
    \u3067\u5165\u308C\u305F\u914D\u5217\u3092\u8FD4\u3059\u3002\n        return divs__(x);\n\
    \    }  // O(\u7D04\u6570\u306E\u500B\u6570)  x <= 10^18\u3067\u5927\u51E1 O(x\
    \ ^ (1/3))  \u6CE8 : \u521D\u56DEO(NlogN)\n};\n\n/*\n@brief \u7D20\u6570\u7BE9\
    (\u5DE6\u7AEF\u4EFB\u610F)\n*/\nint main() {}\n// s -> 0, 0 -> 9, 9 -> t, 1"
  dependsOn:
  - atcoder/convolution.hpp
  - atcoder/internal_bit.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - atcoder/dsu.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/lazysegtree.hpp
  - atcoder/math.hpp
  - atcoder/maxflow.hpp
  - atcoder/internal_queue.hpp
  - atcoder/mincostflow.hpp
  - atcoder/internal_csr.hpp
  - atcoder/scc.hpp
  - atcoder/internal_scc.hpp
  - atcoder/segtree.hpp
  - atcoder/string.hpp
  - atcoder/twosat.hpp
  isVerificationFile: false
  path: Math/sieve2.hpp
  requiredBy: []
  timestamp: '2024-12-22 14:16:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sieve2.hpp
layout: document
redirect_from:
- /library/Math/sieve2.hpp
- /library/Math/sieve2.hpp.html
title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
---
