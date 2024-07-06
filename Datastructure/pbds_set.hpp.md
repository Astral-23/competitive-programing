---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/pbds_set.test.cpp
    title: verify/pbds_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "pdbs\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 1 \"Datastructure/pbds_set.hpp\"\n//\u3053\u3053\u304B\u3089\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    using namespace __gnu_pbds;\nTT using TR = tree<T, null_type, less<T>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\nTT using MTR = tree<T, null_type, less_equal<T>,\
    \ rb_tree_tag, tree_order_statistics_node_update>;\n\n// set\n// insert, erase,\
    \ find, find_by_order, order_of_key, size\n\n/*\n--set--\ninsert(\u8981\u7D20\
    )\nerase(find(\u8981\u7D20)), erase(\u8981\u7D20)\nfind(\u8981\u7D20)\nfind_by_order(\u6570\
    \u5B57)\norder_of_key(\u8981\u7D20)\nsize()\n*/\n\n/* \n--multiset--\ninsert(\u8981\
    \u7D20)\nerase(find_by_order(order_of_key(\u8981\u7D20)))\n  \u6CE8:  erase(\u8981\
    \u7D20), erase(find(\u8981\u7D20))\u306F\u610F\u5473\u304C\u306A\u304B\u3063\u305F\
    \nfind(\u8981\u7D20)\nfind_by_order(\u6570\u5B57)\norder_of_key(\u8981\u7D20)\n\
    size()\n*/\n\n/*\n@brief pdbs\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n"
  code: "//\u3053\u3053\u304B\u3089\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
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
    \u30F3\u30D7\u30EC\u30FC\u30C8\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/pbds_set.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/pbds_set.test.cpp
documentation_of: Datastructure/pbds_set.hpp
layout: document
redirect_from:
- /library/Datastructure/pbds_set.hpp
- /library/Datastructure/pbds_set.hpp.html
title: "pdbs\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
