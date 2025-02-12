---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_compress.test.cpp
    title: verify/Datastructure_compress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/compress.hpp\"\ntemplate <typename T> struct\
    \ compress {\n    vector<T> vs;\n    bool built = false;\n    compress(vector<T>\
    \ const &vs = {}) : vs(vs) {\n    }\n    void add(T const &v) {\n        assert(built\
    \ == false);\n        vs.push_back(v);\n    }\n    void build() {\n        assert(built\
    \ == false);\n        built = true;\n        sort(vs.begin(), vs.end());\n   \
    \     vs.erase(unique(vs.begin(), vs.end()), vs.end());\n    }\n\n    ll operator()(T\
    \ const &v) const {\n        assert(built);\n        return lower_bound(vs.begin(),\
    \ vs.end(), v) - vs.begin();\n    }\n\n    ll get(T const &v) const {\n      \
    \  assert(built);\n        ll ret = (*this)(v);\n        assert(0 <= ret && ret\
    \ < ll(vs.size()));\n        assert(vs[ret] == v);\n        return ret;\n    }\n\
    \n    ll size() const {\n        assert(built);\n        return vs.size();\n \
    \   }\n};\n"
  code: "template <typename T> struct compress {\n    vector<T> vs;\n    bool built\
    \ = false;\n    compress(vector<T> const &vs = {}) : vs(vs) {\n    }\n    void\
    \ add(T const &v) {\n        assert(built == false);\n        vs.push_back(v);\n\
    \    }\n    void build() {\n        assert(built == false);\n        built = true;\n\
    \        sort(vs.begin(), vs.end());\n        vs.erase(unique(vs.begin(), vs.end()),\
    \ vs.end());\n    }\n\n    ll operator()(T const &v) const {\n        assert(built);\n\
    \        return lower_bound(vs.begin(), vs.end(), v) - vs.begin();\n    }\n\n\
    \    ll get(T const &v) const {\n        assert(built);\n        ll ret = (*this)(v);\n\
    \        assert(0 <= ret && ret < ll(vs.size()));\n        assert(vs[ret] == v);\n\
    \        return ret;\n    }\n\n    ll size() const {\n        assert(built);\n\
    \        return vs.size();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/compress.hpp
  requiredBy: []
  timestamp: '2025-02-13 05:24:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_compress.test.cpp
documentation_of: Datastructure/compress.hpp
layout: document
redirect_from:
- /library/Datastructure/compress.hpp
- /library/Datastructure/compress.hpp.html
title: Datastructure/compress.hpp
---
