---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp
  bundledCode: "#line 1 \"verify/limited_knapsack.test.cpp\"\n//#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp\"\n\
    //#include \"../Utility/template.hpp\" \n//#include \"../Datastructure/swag.hpp\"\
    \n//#include \"../Datastructure/offset_manager.hpp\"\n//#include \"../Algorithm/limited_knapsack.hpp\"\
    \nint main() { //O(NW)\n    ll n, w;\n    cin >> n >> w;\n    vec<ll> V(n), W(n),\
    \ M(n);\n    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];\n    cout << limited_knapsack(V,\
    \ W, M, w) << endl;\n\n    \n}\n"
  code: "//#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp\"\
    \n//#include \"../Utility/template.hpp\" \n//#include \"../Datastructure/swag.hpp\"\
    \n//#include \"../Datastructure/offset_manager.hpp\"\n//#include \"../Algorithm/limited_knapsack.hpp\"\
    \nint main() { //O(NW)\n    ll n, w;\n    cin >> n >> w;\n    vec<ll> V(n), W(n),\
    \ M(n);\n    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];\n    cout << limited_knapsack(V,\
    \ W, M, w) << endl;\n\n    \n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/limited_knapsack.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 17:12:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/limited_knapsack.test.cpp
layout: document
redirect_from:
- /verify/verify/limited_knapsack.test.cpp
- /verify/verify/limited_knapsack.test.cpp.html
title: verify/limited_knapsack.test.cpp
---
