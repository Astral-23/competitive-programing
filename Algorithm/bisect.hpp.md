---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/bisect.test.cpp
    title: verify/bisect.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"Algorithm/bisect.hpp\"\ntemplate <typename T, typename F>\
    \ T bisect(T ok, T ng, F pred) {\n    if(ok <= ng) ng++;\n    else ng--;\n   \
    \ \n    if (!pred(ok)) return ok;\n\n    while (ng > ok + 1 || ok > ng + 1) {\n\
    \        T mid = midpoint(ok, ng);\n        (pred(mid) ? ok : ng) = mid;\n   \
    \ }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22\n\
    */\n"
  code: "template <typename T, typename F> T bisect(T ok, T ng, F pred) {\n    if(ok\
    \ <= ng) ng++;\n    else ng--;\n    \n    if (!pred(ok)) return ok;\n\n    while\
    \ (ng > ok + 1 || ok > ng + 1) {\n        T mid = midpoint(ok, ng);\n        (pred(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\
    \u5206\u63A2\u7D22\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/bisect.hpp
  requiredBy: []
  timestamp: '2024-08-16 18:11:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/bisect.test.cpp
documentation_of: Algorithm/bisect.hpp
layout: document
redirect_from:
- /library/Algorithm/bisect.hpp
- /library/Algorithm/bisect.hpp.html
title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
---
