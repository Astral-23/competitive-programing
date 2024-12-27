---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/pbds_set.hpp
    title: "pdbs\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/pbds_set.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/pbds_set.hpp\"\
    \n//\u3053\u3053\u304B\u3089\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\nTT using TR = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\nTT using\
    \ MTR = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \n// set\n// insert, erase, find, find_by_order, order_of_key, size\n\n/*\n--set--\n\
    insert(\u8981\u7D20)\nerase(find(\u8981\u7D20)), erase(\u8981\u7D20)\nfind(\u8981\
    \u7D20)\nfind_by_order(\u6570\u5B57)\norder_of_key(\u8981\u7D20)\nsize()\n*/\n\
    \n/* \n--multiset--\ninsert(\u8981\u7D20)\nerase(find_by_order(order_of_key(\u8981\
    \u7D20)))\n  \u6CE8:  erase(\u8981\u7D20), erase(find(\u8981\u7D20))\u306F\u610F\
    \u5473\u304C\u306A\u304B\u3063\u305F\nfind(\u8981\u7D20)\nfind_by_order(\u6570\
    \u5B57)\norder_of_key(\u8981\u7D20)\nsize()\n*/\n\n/*\n@brief pdbs\u306E\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 4 \"verify/pbds_set.test.cpp\"\n\nint\
    \ main () {\n\n\n    TR<int> cnt;\n\n    int N, Q;\n    cin >> N >> Q;\n    string\
    \ T;\n    cin >> T;\n\n    rep(t, 0, N) if(T[t] == '1') cnt.insert(t);\n    \n\
    \n    while(Q--) {\n        int t, k;\n        cin >> t >> k;\n        if(t ==\
    \ 0) {\n            cnt.insert(k);\n        }\n        else if(t==1) {\n\t\t \
    \ cnt.erase(k);\n        }\n        else if(t==2) {\n            int it = cnt.order_of_key(k);\n\
    \            if(it < cnt.size() && *cnt.find_by_order(it) == k) cout << 1 << '\\\
    n';\n            else cout << 0 << \"\\n\";\n        }\n        else if(t==3)\
    \ {\n            int it = cnt.order_of_key(k);\n            if(it < cnt.size())\
    \ cout << *cnt.find_by_order(it) << '\\n';\n            else cout << -1 << '\\\
    n';\n        }\n        else {\n            int it = cnt.order_of_key(k);\n  \
    \          if(it < cnt.size() && *cnt.find_by_order(it) == k) cout << k << '\\\
    n';\n            else {\n                it--;\n                if(it >= 0) cout\
    \ << *cnt.find_by_order(it) << '\\n';\n                else cout << -1 << '\\\
    n';\n            }\n\n        }\n    }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Datastructure/pbds_set.hpp\"\
    \n\nint main () {\n\n\n    TR<int> cnt;\n\n    int N, Q;\n    cin >> N >> Q;\n\
    \    string T;\n    cin >> T;\n\n    rep(t, 0, N) if(T[t] == '1') cnt.insert(t);\n\
    \    \n\n    while(Q--) {\n        int t, k;\n        cin >> t >> k;\n       \
    \ if(t == 0) {\n            cnt.insert(k);\n        }\n        else if(t==1) {\n\
    \t\t  cnt.erase(k);\n        }\n        else if(t==2) {\n            int it =\
    \ cnt.order_of_key(k);\n            if(it < cnt.size() && *cnt.find_by_order(it)\
    \ == k) cout << 1 << '\\n';\n            else cout << 0 << \"\\n\";\n        }\n\
    \        else if(t==3) {\n            int it = cnt.order_of_key(k);\n        \
    \    if(it < cnt.size()) cout << *cnt.find_by_order(it) << '\\n';\n          \
    \  else cout << -1 << '\\n';\n        }\n        else {\n            int it =\
    \ cnt.order_of_key(k);\n            if(it < cnt.size() && *cnt.find_by_order(it)\
    \ == k) cout << k << '\\n';\n            else {\n                it--;\n     \
    \           if(it >= 0) cout << *cnt.find_by_order(it) << '\\n';\n           \
    \     else cout << -1 << '\\n';\n            }\n\n        }\n    }\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/pbds_set.hpp
  isVerificationFile: true
  path: verify/pbds_set.test.cpp
  requiredBy: []
  timestamp: '2024-12-28 00:04:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/pbds_set.test.cpp
layout: document
redirect_from:
- /verify/verify/pbds_set.test.cpp
- /verify/verify/pbds_set.test.cpp.html
title: verify/pbds_set.test.cpp
---
