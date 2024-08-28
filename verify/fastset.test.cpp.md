---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/fastset.hpp
    title: "\u975E\u8CA0\u6574\u6570\u3092\u7BA1\u7406\u3059\u308B64\u5206\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/fastset.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/fastset.hpp\"\
    \ntemplate<int W>\nstruct fastset {\n    using ll = long long;\n    using ull\
    \ = unsigned long long;\n\n    ll siz;\n    vector<int> B = {0, 6, 12, 18, 24,\
    \ 30, 36, 42};\n    vector<ull> mask;\n    vector<ull> mask_rev;\n    vector<vector<ull>>\
    \ tr;\n\n    fastset() {\n        tr.resize(W);\n        mask.resize(65, 0);\n\
    \        mask_rev.resize(65, 18446744073709551615ULL);\n        siz = 0;\n   \
    \     for (int i = 0; i < W; i++) {\n            tr[i].resize(1ULL << B[W - i\
    \ - 1], 0);\n        }\n        for (int i = 1; i <= 64; i++) {\n            mask[i]\
    \ = mask[i - 1] << 1 | 1;\n        }\n        for (int i = 63; i >= 0; i--) {\n\
    \            mask_rev[i] = mask_rev[i + 1] << 1;\n        }\n    }\n\n  private:\n\
    \    ull Q(ull x, int w) {  // x \u3092 2^w \u3067\u5272\u3063\u305F\u5546\n \
    \       return x >> w;\n    }\n\n    ull lower_bound__(ull x, int i, ull res)\
    \ {\n        if (i < 0) return res;\n        if (res == Q(x, B[i + 1])) {\n  \
    \          if (tr[i][res] >> (Q(x, B[i]) & 63) & 1) {\n                if ((tr[i][res]\
    \ & mask_rev[63 - (Q(x, B[i]) & 63)]) == 0)\n                    return lower_bound__(\n\
    \                        x, i - 1,\n                        res << 6 |\n     \
    \                       __builtin_ctzll(tr[i][res] &\n                       \
    \                     mask_rev[64 - (Q(x, B[i]) & 63)]));\n                return\
    \ min(\n                    lower_bound__(\n                        x, i - 1,\n\
    \                        res << 6 |\n                            __builtin_ctzll(tr[i][res]\
    \ &\n                                            mask_rev[64 - (Q(x, B[i]) & 63)])),\n\
    \                    lower_bound__(\n                        x, i - 1,\n     \
    \                   res << 6 |\n                            __builtin_ctzll(tr[i][res]\
    \ &\n                                            mask_rev[63 - (Q(x, B[i]) & 63)])));\n\
    \            } else {\n                if ((tr[i][res] & mask_rev[63 - (Q(x, B[i])\
    \ & 63)]) == 0)\n                    return 18446744073709551615ULL;\n       \
    \         return lower_bound__(\n                    x, i - 1,\n             \
    \       res << 6 |\n                        __builtin_ctzll(tr[i][res] &\n   \
    \                                     mask_rev[63 - (Q(x, B[i]) & 63)]));\n  \
    \          }\n        } else {\n            return lower_bound__(x, i - 1,\n \
    \                                res << 6 | __builtin_ctzll(tr[i][res]));\n  \
    \      }\n    }\n\n    ull lower_left_bound__(ull x, int i, ull res) {\n     \
    \   if (i < 0) return res;\n        if (res == Q(x, B[i + 1])) {\n           \
    \ if (tr[i][res] >> (Q(x, B[i]) & 63) & 1) {\n                if ((tr[i][res]\
    \ & mask[(Q(x, B[i]) & 63)]) == 0)\n                    return lower_left_bound__(\n\
    \                        x, i - 1,\n                        res << 6 | (63 - __builtin_clzll(\n\
    \                                             tr[i][res] &\n                 \
    \                            mask[(Q(x, B[i]) & 63) + 1])));\n               \
    \ return max(\n                    lower_left_bound__(\n                     \
    \   x, i - 1,\n                        res << 6 |\n                          \
    \  (63 - __builtin_clzll(tr[i][res] &\n                                      \
    \            mask[(Q(x, B[i]) & 63)]))),\n                    lower_left_bound__(\n\
    \                        x, i - 1,\n                        res << 6 | (63 - __builtin_clzll(\n\
    \                                             tr[i][res] &\n                 \
    \                            mask[(Q(x, B[i]) & 63) + 1]))));\n            } else\
    \ {\n                if ((tr[i][res] & mask[(Q(x, B[i]) & 63)]) == 0) return 0ULL;\n\
    \                return lower_left_bound__(\n                    x, i - 1,\n \
    \                   res << 6 | (63 - __builtin_clzll(tr[i][res] &\n          \
    \                                           mask[(Q(x, B[i]) & 63)])));\n    \
    \        }\n        } else {\n            return lower_left_bound__(\n       \
    \         x, i - 1, res << 6 | (63 - __builtin_clzll(tr[i][res])));\n        }\n\
    \    }\n\n  public:\n    void insert(ll x) {\n        if (count(x)) return;\n\
    \        siz++;\n        for (int i = W - 1; i >= 0; i--) {\n            tr[i][Q(x,\
    \ B[i + 1])] |= 1ULL << (Q(x, B[i]) & 63);\n        }\n    }\n\n    void erase(ll\
    \ x) {\n        if (!count(x)) return;\n        siz--;\n        tr[0][Q(x, 6)]\
    \ ^= 1ULL << (x & 63);\n        for (int i = 1; i < W; i++) {\n            ull\
    \ d = (!tr[i - 1][Q(x, B[i])]);\n            tr[i][Q(x, B[i + 1])] ^= d << (Q(x,\
    \ B[i]) & 63);\n        }\n    }\n\n    int count(ll x) { return tr[0][Q(x, 6)]\
    \ >> (x & 63) & 1; }\n\n    ll min_element() {\n        assert(siz != 0);\n  \
    \      ull res = 0;\n        for (int i = W - 1; i >= 0; i--) {\n            res\
    \ = res << 6 | __builtin_ctzll(tr[i][res]);\n        }\n        return res;\n\
    \    }\n\n    ll max_element() {\n        assert(siz != 0);\n        ull res =\
    \ 0;\n        for (int i = W - 1; i >= 0; i--) {\n            res = res << 6 |\
    \ (63 - __builtin_clzll(tr[i][res]));\n        }\n        return res;\n    }\n\
    \n    ll lower_bound(ll x) {\n        if (siz == 0 || max_element() < x) return\
    \ -1LL;\n        return lower_bound__(x, W - 1, 0);\n    }\n\n    ll lower_left_bound(ll\
    \ x) {\n        if (siz == 0 || min_element() > x) return -1LL;\n        return\
    \ lower_left_bound__(x, W - 1, 0);\n    }\n\n    ll size() { return siz; }\n\n\
    \    bool empty() { return siz == 0; }\n\n    void dump() {\n        ll M = 1LL\
    \ << B[W];\n        M--;\n        for (int i = 0; i <= M; i++) {\n           \
    \ if (count(i)) cout << i << \" \";\n        }\n        cout << endl;\n    }\n\
    \n    /*\n        fastset(W)\n            @brief \u975E\u8CA0\u6574\u6570\u3092\
    \u7BA1\u7406\u3059\u308B64\u5206\u6728\n            W\u306F\u6728\u306E\u9AD8\u3055\
    \u3002\n            W = 2  [0, 4095]           \u5F8B\u901F : \u30B5\u30A4\u30BA\
    60\u306Ell\u914D\u5217\u3092\u69CB\u7BC9 0.5KB  \n            W = 3  [0, 262'143]\
    \        \u5F8B\u901F : \u30B5\u30A4\u30BA3600\u306Ell\u914D\u5217\u3092\u69CB\
    \u7BC9 0.03MB  \n            W = 4  [0, 16'777'215]     \u5F8B\u901F : \u30B5\u30A4\
    \u30BA2.5 * 10^5 \u306Ell\u914D\u5217\u3092\u69CB\u7BC9 2MB \n            W =\
    \ 5  [0, 1'073'741'823]  \u5F8B\u901F : \u30B5\u30A4\u30BA1.6 * 10^7 \u306Ell\u914D\
    \u5217\u3092\u69CB\u7BC9 130MB\n\n            insert(x) x\u3092\u633F\u5165\u3059\
    \u308B\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u306A\u306B\u3082\u3057\u306A\
    \u3044\u3002 O(W)\n            erase(x) x\u3092\u524A\u9664\u3002\u5B58\u5728\u3057\
    \u306A\u3044\u6642\u306A\u306B\u3082\u3057\u306A\u3044\u3002 O(W)\n          \
    \  count(x) x\u304C\u5B58\u5728\u3059\u308B\u304B\u3002O(1)\n            min_element()/max_element()\
    \ \u6700\u5C0F\u30FB\u6700\u5927\u8981\u7D20\u3002\u8981\u7D20\u65700\u306A\u3089\
    assert\u3002 O(W)\n            lower_bound(x) x\u4EE5\u4E0A\u6700\u5C0F\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089-1 O(W)\n            lower_left_bound(x) x\u4EE5\
    \u4E0B\u6700\u5927\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1. O(W)\n \
    \           size(), empty() ... O(1)\n\n    */\n};\n#line 4 \"verify/fastset.test.cpp\"\
    \n\nint main() {\n    fastset<4> cnt;\n    int n, q;\n    cin >> n >> q;\n   \
    \ rep(i, 0, n) {\n        char a;\n        cin >> a;\n        if(a == '1') cnt.insert(i);\n\
    \    }\n\n    while(q--) {\n        int t, k;\n        cin >> t >> k;\n\n    \
    \    if(t == 0) {\n            cnt.insert(k);\n        }\n        else if(t ==\
    \ 1) {\n            cnt.erase(k);\n        }\n        else if(t == 2) {\n    \
    \        if(cnt.count(k)) cout << 1 << '\\n';\n            else cout << 0 << '\\\
    n';\n        }\n        else if(t == 3) {\n            cout << cnt.lower_bound(k)\
    \ << '\\n';\n        }\n        else {\n            cout << cnt.lower_left_bound(k)\
    \ << '\\n';\n        }\n\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/fastset.hpp\"\
    \n\nint main() {\n    fastset<4> cnt;\n    int n, q;\n    cin >> n >> q;\n   \
    \ rep(i, 0, n) {\n        char a;\n        cin >> a;\n        if(a == '1') cnt.insert(i);\n\
    \    }\n\n    while(q--) {\n        int t, k;\n        cin >> t >> k;\n\n    \
    \    if(t == 0) {\n            cnt.insert(k);\n        }\n        else if(t ==\
    \ 1) {\n            cnt.erase(k);\n        }\n        else if(t == 2) {\n    \
    \        if(cnt.count(k)) cout << 1 << '\\n';\n            else cout << 0 << '\\\
    n';\n        }\n        else if(t == 3) {\n            cout << cnt.lower_bound(k)\
    \ << '\\n';\n        }\n        else {\n            cout << cnt.lower_left_bound(k)\
    \ << '\\n';\n        }\n\n    }\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/fastset.hpp
  isVerificationFile: true
  path: verify/fastset.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fastset.test.cpp
layout: document
redirect_from:
- /verify/verify/fastset.test.cpp
- /verify/verify/fastset.test.cpp.html
title: verify/fastset.test.cpp
---
