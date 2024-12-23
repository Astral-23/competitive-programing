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
  bundledCode: "#line 1 \"Others/mypair.hpp\"\ntemplate<typename T1, typename T2>\n\
    struct MYPAIR {\n\tT1 FIRST_V; \n\tT2 SECOND_V;\n\tMYPAIR () {}\n\tMYPAIR (T1\
    \ _FIRST_V, T2 _SECOND_V) : FIRST_V(_FIRST_V), SECOND_V(_SECOND_V) {}\n\tbool\
    \ operator<(const MYPAIR& a) {\n\t\tif(FIRST_V != a.FIRST_V) return FIRST_V <\
    \ a.FIRST_V;\n\t\telse return SECOND_V < a.SECOND_V;\n\t}\n\tbool operator>(const\
    \ MYPAIR& a) {\n\t\tif(FIRST_V != a.FIRST_V) return FIRST_V > a.FIRST_V;\n\t\t\
    else return SECOND_V > a.SECOND_V;\n\t}\n\tbool operator==(const MYPAIR& a) {\n\
    \t\treturn (FIRST_V==a.FIRST_V) && (SECOND_V == a.SECOND_V);\n\t}\n\tbool operator!=(const\
    \ MYPAIR& a) {\n\t\treturn !(*this == a);\n\t}\n}; \n\n/*\n@ brief \u81EA\u4F5C\
    \u306Epair\n*/\n"
  code: "template<typename T1, typename T2>\nstruct MYPAIR {\n\tT1 FIRST_V; \n\tT2\
    \ SECOND_V;\n\tMYPAIR () {}\n\tMYPAIR (T1 _FIRST_V, T2 _SECOND_V) : FIRST_V(_FIRST_V),\
    \ SECOND_V(_SECOND_V) {}\n\tbool operator<(const MYPAIR& a) {\n\t\tif(FIRST_V\
    \ != a.FIRST_V) return FIRST_V < a.FIRST_V;\n\t\telse return SECOND_V < a.SECOND_V;\n\
    \t}\n\tbool operator>(const MYPAIR& a) {\n\t\tif(FIRST_V != a.FIRST_V) return\
    \ FIRST_V > a.FIRST_V;\n\t\telse return SECOND_V > a.SECOND_V;\n\t}\n\tbool operator==(const\
    \ MYPAIR& a) {\n\t\treturn (FIRST_V==a.FIRST_V) && (SECOND_V == a.SECOND_V);\n\
    \t}\n\tbool operator!=(const MYPAIR& a) {\n\t\treturn !(*this == a);\n\t}\n};\
    \ \n\n/*\n@ brief \u81EA\u4F5C\u306Epair\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Others/mypair.hpp
  requiredBy: []
  timestamp: '2024-08-22 21:20:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/mypair.hpp
layout: document
redirect_from:
- /library/Others/mypair.hpp
- /library/Others/mypair.hpp.html
title: Others/mypair.hpp
---