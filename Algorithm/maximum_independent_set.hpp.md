---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/maximum_independent_set.test.cpp
    title: verify/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408"
    links: []
  bundledCode: "#line 1 \"Algorithm/maximum_independent_set.hpp\"\nvec<int> maximum_independent_set(vec<vec<int>>\
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
    \u96C6\u5408\n*/\n"
  code: "vec<int> maximum_independent_set(vec<vec<int>> &ngs) {\n\tint n = ngs.size();\n\
    \n\tint sl = n/2;\n\tint sr = n - sl;\n\n\tvec<ll> ng(n, 0);\n\trep(i, 0, n) rep(j,\
    \ 0, n) if(ngs[i][j]) {\n\t\tng[i] |= 1LL << j;\n\t}\n\n\tvec<int> dp,pre,self,dp2,pre2,self2;\n\
    \tdp = pre = self = vec<int>(1LL << sl, 0);\n\tdp2 = pre2 = self2 = vec<int>(1LL\
    \ << sr, 0);\n\tself = vec<int>(1LL << sl, -1);\n\tself2 = vec<int>(1LL << sr,\
    \ -1);\n\n\trep(s, 1, 1LL << sl) {\n\t\trep(i, 0, sl) if(s >> i & 1) {\n\t\t\t\
    ll ns = s ^ (1LL << i);\n\t\t\tif(chmax(dp[s], dp[ns])) {\n\t\t\t\tpre[s] = ns;\n\
    \t\t\t\tself[s] = -1;\n\t\t\t}\n\t\t\tns = ns & (ns ^ ng[i]);\n\t\t\tif(chmax(dp[s],\
    \ dp[ns] + 1)) {\n\t\t\t\tpre[s] = ns;\n\t\t\t\tself[s] = i;\n\t\t\t}\n\t\t}\n\
    \t}\n\n\trep(s, 1, 1LL << sr) {\n\t\trep(i, 0, sr) if(s >> i & 1) {\n\t\t\tll\
    \ ns = s ^ (1LL << i);\n\t\t\tif(chmax(dp2[s], dp2[ns])) {\n\t\t\t\tpre2[s] =\
    \ ns;\n\t\t\t\tself2[s] = -1;\n\t\t\t}\n\t\t\tns = ns & (ns ^ (ng[i + sl] >> sl));\n\
    \t\t\tif(chmax(dp2[s], dp2[ns] + 1)) {\n\t\t\t\tpre2[s] = ns;\n\t\t\t\tself2[s]\
    \ = i + sl;\n\t\t\t}\n\t\t}\n\t}\n     \n\tint sz = -1;\n\tvec<ll> id(2, 0);\n\
    \tvec<int> res;\n\trep(s, 0, 1LL << sl) {\n\t\tll out = 0;\n\t\trep(i, 0, sl)\
    \ if(s >> i & 1) out |= ng[i];\n\t\tll ns = (((1LL << n) - 1) ^ out) >> sl;\n\t\
    \tif(chmax(sz, dp[s] + dp2[ns])) {\n\t\t\tid[0] = s;\n\t\t\tid[1] = ns;\n\t\t\
    }\n\t}\n\n\twhile(id[0] != 0) {\n\t\tif(self[id[0]] != -1) res.push_back(self[id[0]]);\n\
    \t\tid[0] = pre[id[0]];\n\t}\n\n\twhile(id[1] != 0) {\n\t\tif(self2[id[1]] !=\
    \ -1) res.push_back(self2[id[1]]);\n\t\tid[1] = pre2[id[1]];\n\t}\n\treturn res;\n\
    }\n\n/*\n@brief \u6700\u5927\u72EC\u7ACB\u96C6\u5408\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/maximum_independent_set.test.cpp
documentation_of: Algorithm/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/Algorithm/maximum_independent_set.hpp
- /library/Algorithm/maximum_independent_set.hpp.html
title: "\u6700\u5927\u72EC\u7ACB\u96C6\u5408"
---
