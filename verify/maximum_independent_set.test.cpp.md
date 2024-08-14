---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/maximum_independent_set.hpp
    title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408"
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
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"verify/maximum_independent_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for(ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template<typename T>\nTT using vec = vector<T>;\ntemplate<class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class\
    \ T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false;\
    \ }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line\
    \ 1 \"Algorithm/maximum_independent_set.hpp\"\nvec<int> maximum_independent_set(vec<vec<int>>\
    \ &ngs) {\n\tint n = ngs.size();\n\n\tint sl = n/2;\n\tint sr = n - sl;\n\n\t\
    vec<ll> ng(n, 0);\n\trep(i, 0, n) rep(j, 0, n) if(ngs[i][j]) {\n\t\tng[i] |= 1LL\
    \ << j;\n\t}\n\n\tvec<int> dp,pre,self,dp2,pre2,self2;\n\tdp = pre = self = vec<int>(1LL\
    \ << sl, 0);\n\tdp2 = pre2 = self2 = vec<int>(1LL << sr, 0);\n\tself = vec<int>(1LL\
    \ << sl, -1);\n\tself2 = vec<int>(1LL << sr, -1);\n\n\trep(s, 1, 1LL << sl) {\n\
    \t\trep(i, 0, sl) if(s >> i & 1) {\n\t\t\tll ns = s ^ (1LL << i);\n\t\t\tif(chmax(dp[s],\
    \ dp[ns])) {\n\t\t\t\tpre[s] = ns;\n\t\t\t\tself[s] = -1;\n\t\t\t}\n\t\t\tns =\
    \ ns & (ns ^ ng[i]);\n\t\t\tif(chmax(dp[s], dp[ns] + 1)) {\n\t\t\t\tpre[s] = ns;\n\
    \t\t\t\tself[s] = i;\n\t\t\t}\n\t\t}\n\t}\n\n\trep(s, 1, 1LL << sr) {\n\t\trep(i,\
    \ 0, sr) if(s >> i & 1) {\n\t\t\tll ns = s ^ (1LL << i);\n\t\t\tif(chmax(dp2[s],\
    \ dp2[ns])) {\n\t\t\t\tpre2[s] = ns;\n\t\t\t\tself2[s] = -1;\n\t\t\t}\n\t\t\t\
    ns = ns & (ns ^ (ng[i + sl] >> sl));\n\t\t\tif(chmax(dp2[s], dp2[ns] + 1)) {\n\
    \t\t\t\tpre2[s] = ns;\n\t\t\t\tself2[s] = i + sl;\n\t\t\t}\n\t\t}\n\t}\n     \n\
    \tint sz = -1;\n\tvec<ll> id(2, 0);\n\tvec<int> res;\n\trep(s, 0, 1LL << sl) {\n\
    \t\tll out = 0;\n\t\trep(i, 0, sl) if(s >> i & 1) out |= ng[i];\n\t\tll ns = (((1LL\
    \ << n) - 1) ^ out) >> sl;\n\t\tif(chmax(sz, dp[s] + dp2[ns])) {\n\t\t\tid[0]\
    \ = s;\n\t\t\tid[1] = ns;\n\t\t}\n\t}\n\n\twhile(id[0] != 0) {\n\t\tif(self[id[0]]\
    \ != -1) res.push_back(self[id[0]]);\n\t\tid[0] = pre[id[0]];\n\t}\n\n\twhile(id[1]\
    \ != 0) {\n\t\tif(self2[id[1]] != -1) res.push_back(self2[id[1]]);\n\t\tid[1]\
    \ = pre2[id[1]];\n\t}\n\treturn res;\n}\n\n/*\n@brief \u6700\u5927\u72EC\u7ACB\
    \u96C6\u5408\n*/\n#line 4 \"verify/maximum_independent_set.test.cpp\"\n\nint main()\
    \ {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> ng(n, vec<int>(n, 0));\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        ng[u][v]\
    \ = 1;\n        ng[v][u] = 1;\n    }\n\n    auto res = maximum_independent_set(ng);\n\
    \    cout << res.size() << endl;\n    for(int x : res) cout << x << \" \";\n \
    \   cout << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Algorithm/maximum_independent_set.hpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> ng(n, vec<int>(n,\
    \ 0));\n    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n      \
    \  ng[u][v] = 1;\n        ng[v][u] = 1;\n    }\n\n    auto res = maximum_independent_set(ng);\n\
    \    cout << res.size() << endl;\n    for(int x : res) cout << x << \" \";\n \
    \   cout << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/maximum_independent_set.hpp
  isVerificationFile: true
  path: verify/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2024-07-09 04:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/verify/maximum_independent_set.test.cpp
- /verify/verify/maximum_independent_set.test.cpp.html
title: verify/maximum_independent_set.test.cpp
---
