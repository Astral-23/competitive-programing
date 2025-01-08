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
  bundledCode: "#line 1 \"debug.hpp\"\n#ifdef _DEBUG\n\ntemplate <typename T> \nvoid\
    \ dbg_out_with_name(string var_name, const T &value) {\n    // \u524D\u5F8C\u306E\
    \u7A7A\u767D\u3092\u30C8\u30EA\u30E0\u3059\u308B\n    var_name.erase(var_name.begin(),\
    \ find_if(var_name.begin(), var_name.end(), [](unsigned char ch) { return !isspace(ch);\
    \ }));\n    var_name.erase(find_if(var_name.rbegin(), var_name.rend(), [](unsigned\
    \ char ch) { return !isspace(ch); }).base(), var_name.end());\n    cerr << var_name\
    \ << \" = \" << value << endl;\n}\n\ntemplate <typename T, typename... Args>\n\
    void dbg_out_with_name(string var_name, const T &value, const Args &...args) {\n\
    \    int pos = -1;\n    var_name.erase(var_name.begin(), find_if(var_name.begin(),\
    \ var_name.end(), [](unsigned char ch) { return !isspace(ch); }));\n    \n   \
    \ int bracket_count = 0;\n    for (size_t i = 0; i < var_name.size(); i++) {\n\
    \        if (var_name[i] == '(') {\n            bracket_count++;\n        } else\
    \ if (var_name[i] == ')') {\n            bracket_count--;\n        }\n       \
    \ \n        // \u30AB\u30F3\u30DE\u304C\u30CD\u30B9\u30C8\u3055\u308C\u305F\u62EC\
    \u5F27\u306E\u5916\u3067\u898B\u3064\u304B\u308B\u5834\u5408\u306E\u307F\u5206\
    \u5272\n        if (var_name[i] == ',' && bracket_count == 0) {\n            pos\
    \ = i;\n            break;\n        }\n    }\n    \n    if (pos == -1) pos = var_name.size();\n\
    \    cerr << var_name.substr(0, pos) << \" = \" << value << endl;\n    if (pos\
    \ + 1 < var_name.size()) {\n        dbg_out_with_name(var_name.substr(pos + 1),\
    \ args...);\n    }\n}\n\ntemplate <typename T> \nvoid dbg_out(const T &value)\
    \ { \n    cerr << value << endl; \n}\n\ntemplate <typename T, typename... Args>\n\
    void dbg_out(const T &value, const Args &...args) {\n    cerr << value << endl;\n\
    \    dbg_out(args...);\n}\n\n#define DBG(...)                       \\\n    cerr\
    \ << __LINE__ << \" : \" << endl; \\\n    dbg_out(__VA_ARGS__)\n\n#define dbg(...)\
    \                       \\\n    cerr << __LINE__ << \" : \" << endl; \\\n    dbg_out_with_name(#__VA_ARGS__,\
    \ __VA_ARGS__)\n\n#else\n#define dbg(...) true\n#define DBG(...) true\n#endif\n"
  code: "#ifdef _DEBUG\n\ntemplate <typename T> \nvoid dbg_out_with_name(string var_name,\
    \ const T &value) {\n    // \u524D\u5F8C\u306E\u7A7A\u767D\u3092\u30C8\u30EA\u30E0\
    \u3059\u308B\n    var_name.erase(var_name.begin(), find_if(var_name.begin(), var_name.end(),\
    \ [](unsigned char ch) { return !isspace(ch); }));\n    var_name.erase(find_if(var_name.rbegin(),\
    \ var_name.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), var_name.end());\n\
    \    cerr << var_name << \" = \" << value << endl;\n}\n\ntemplate <typename T,\
    \ typename... Args>\nvoid dbg_out_with_name(string var_name, const T &value, const\
    \ Args &...args) {\n    int pos = -1;\n    var_name.erase(var_name.begin(), find_if(var_name.begin(),\
    \ var_name.end(), [](unsigned char ch) { return !isspace(ch); }));\n    \n   \
    \ int bracket_count = 0;\n    for (size_t i = 0; i < var_name.size(); i++) {\n\
    \        if (var_name[i] == '(') {\n            bracket_count++;\n        } else\
    \ if (var_name[i] == ')') {\n            bracket_count--;\n        }\n       \
    \ \n        // \u30AB\u30F3\u30DE\u304C\u30CD\u30B9\u30C8\u3055\u308C\u305F\u62EC\
    \u5F27\u306E\u5916\u3067\u898B\u3064\u304B\u308B\u5834\u5408\u306E\u307F\u5206\
    \u5272\n        if (var_name[i] == ',' && bracket_count == 0) {\n            pos\
    \ = i;\n            break;\n        }\n    }\n    \n    if (pos == -1) pos = var_name.size();\n\
    \    cerr << var_name.substr(0, pos) << \" = \" << value << endl;\n    if (pos\
    \ + 1 < var_name.size()) {\n        dbg_out_with_name(var_name.substr(pos + 1),\
    \ args...);\n    }\n}\n\ntemplate <typename T> \nvoid dbg_out(const T &value)\
    \ { \n    cerr << value << endl; \n}\n\ntemplate <typename T, typename... Args>\n\
    void dbg_out(const T &value, const Args &...args) {\n    cerr << value << endl;\n\
    \    dbg_out(args...);\n}\n\n#define DBG(...)                       \\\n    cerr\
    \ << __LINE__ << \" : \" << endl; \\\n    dbg_out(__VA_ARGS__)\n\n#define dbg(...)\
    \                       \\\n    cerr << __LINE__ << \" : \" << endl; \\\n    dbg_out_with_name(#__VA_ARGS__,\
    \ __VA_ARGS__)\n\n#else\n#define dbg(...) true\n#define DBG(...) true\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2025-01-08 18:32:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
