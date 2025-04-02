---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_rangeset.test.cpp
    title: verify/Datastructure_rangeset.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/rangeset.hpp\"\ntemplate <typename T, bool\
    \ merge_adju> struct rangeset : public std::map<T, T> {\n    rangeset() {}\n \
    \   auto get(T p) const {\n        auto it = (*this).upper_bound(p);\n       \
    \ if (it == (*this).begin() || (--it)->second <= p) return (*this).end();\n  \
    \      return it;\n    }\n\n    //[l, r)\n    pair<T, T> insert(T l, T r) {\n\
    \        if (l == r) return make_pair(l, r);\n        assert(l <= r);\n      \
    \  auto itl = (*this).upper_bound(l),\n             itr = (*this).lower_bound(r\
    \ + merge_adju);\n        if (itl != (*this).begin() && (--itl)->second + merge_adju\
    \ <= l) {\n            ++itl;\n        }\n\n        if (itl != itr) {\n      \
    \      if (itl->first < l) l = itl->first;\n            if (prev(itr)->second\
    \ > r) r = prev(itr)->second;\n            map<T, T>::erase(itl, itr);\n     \
    \   }\n        (*this)[l] = r;\n        return make_pair(l, r);\n    }\n\n   \
    \ pair<T, T> insert(T p) { return insert(p, p + 1); }\n\n    //[l, r)\n    void\
    \ erase(T l, T r) {\n        if (l == r) return;\n        assert(l <= r);\n  \
    \      auto itl = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n    \
    \    if (itl != (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n\
    \        }\n        if (itl == itr) return;\n        T tl = l, tr = r;\n     \
    \   if (itl->first < l) tl = itl->first;\n        if (prev(itr)->second > r) tr\
    \ = prev(itr)->second;\n        map<T, T>::erase(itl, itr);\n        if (tl <\
    \ l) (*this)[tl] = l;\n        if (tr > r) (*this)[r] = tr;\n    }\n\n    void\
    \ erase(T p) { erase(p, p + 1); }\n\n    // p\u3092\u542B\u3080\u533A\u9593\u304C\
    \u3042\u308B\u304B\n    bool contains(T p) const { return get(p) != (*this).end();\
    \ }\n\n    //[l, r)\u306E\u3046\u30611\u8981\u7D20\u3067\u3082\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\n    bool contains(T l, T r) const {\n        auto itl\
    \ = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n        if (itl !=\
    \ (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n        }\n\
    \        if (itl == itr)\n            return false;\n        else\n          \
    \  return true;\n    }\n\n    // a\u3068b\u3092\u5171\u306B\u542B\u3080\u533A\u9593\
    \u304C\u3042\u308B\u304B\n    bool same(T a, T b) const {\n        if (a > b)\
    \ swap(a, b);\n\n        auto it = get(a);\n        if (it == (*this).end()) return\
    \ false;\n        return b < it->second;\n    }\n\n    T mex(T x = 0) const {\n\
    \        auto it = get(x);\n        if (it == (*this).end())\n            return\
    \ x;\n        else\n            return it->second;\n    }\n\n    template <typename\
    \ TYPE, bool ME>\n    friend ostream &operator<<(ostream &os, rangeset<TYPE, ME>\
    \ const &rhs) {\n        for (auto [l, r] : rhs) os << \"[\" << l << \", \" <<\
    \ r << \")\";\n        return os;\n    }\n};\n"
  code: "template <typename T, bool merge_adju> struct rangeset : public std::map<T,\
    \ T> {\n    rangeset() {}\n    auto get(T p) const {\n        auto it = (*this).upper_bound(p);\n\
    \        if (it == (*this).begin() || (--it)->second <= p) return (*this).end();\n\
    \        return it;\n    }\n\n    //[l, r)\n    pair<T, T> insert(T l, T r) {\n\
    \        if (l == r) return make_pair(l, r);\n        assert(l <= r);\n      \
    \  auto itl = (*this).upper_bound(l),\n             itr = (*this).lower_bound(r\
    \ + merge_adju);\n        if (itl != (*this).begin() && (--itl)->second + merge_adju\
    \ <= l) {\n            ++itl;\n        }\n\n        if (itl != itr) {\n      \
    \      if (itl->first < l) l = itl->first;\n            if (prev(itr)->second\
    \ > r) r = prev(itr)->second;\n            map<T, T>::erase(itl, itr);\n     \
    \   }\n        (*this)[l] = r;\n        return make_pair(l, r);\n    }\n\n   \
    \ pair<T, T> insert(T p) { return insert(p, p + 1); }\n\n    //[l, r)\n    void\
    \ erase(T l, T r) {\n        if (l == r) return;\n        assert(l <= r);\n  \
    \      auto itl = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n    \
    \    if (itl != (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n\
    \        }\n        if (itl == itr) return;\n        T tl = l, tr = r;\n     \
    \   if (itl->first < l) tl = itl->first;\n        if (prev(itr)->second > r) tr\
    \ = prev(itr)->second;\n        map<T, T>::erase(itl, itr);\n        if (tl <\
    \ l) (*this)[tl] = l;\n        if (tr > r) (*this)[r] = tr;\n    }\n\n    void\
    \ erase(T p) { erase(p, p + 1); }\n\n    // p\u3092\u542B\u3080\u533A\u9593\u304C\
    \u3042\u308B\u304B\n    bool contains(T p) const { return get(p) != (*this).end();\
    \ }\n\n    //[l, r)\u306E\u3046\u30611\u8981\u7D20\u3067\u3082\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\n    bool contains(T l, T r) const {\n        auto itl\
    \ = (*this).upper_bound(l), itr = (*this).lower_bound(r);\n        if (itl !=\
    \ (*this).begin() && (--itl)->second <= l) {\n            ++itl;\n        }\n\
    \        if (itl == itr)\n            return false;\n        else\n          \
    \  return true;\n    }\n\n    // a\u3068b\u3092\u5171\u306B\u542B\u3080\u533A\u9593\
    \u304C\u3042\u308B\u304B\n    bool same(T a, T b) const {\n        if (a > b)\
    \ swap(a, b);\n\n        auto it = get(a);\n        if (it == (*this).end()) return\
    \ false;\n        return b < it->second;\n    }\n\n    T mex(T x = 0) const {\n\
    \        auto it = get(x);\n        if (it == (*this).end())\n            return\
    \ x;\n        else\n            return it->second;\n    }\n\n    template <typename\
    \ TYPE, bool ME>\n    friend ostream &operator<<(ostream &os, rangeset<TYPE, ME>\
    \ const &rhs) {\n        for (auto [l, r] : rhs) os << \"[\" << l << \", \" <<\
    \ r << \")\";\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/rangeset.hpp
  requiredBy: []
  timestamp: '2025-04-03 05:20:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_rangeset.test.cpp
documentation_of: Datastructure/rangeset.hpp
layout: document
redirect_from:
- /library/Datastructure/rangeset.hpp
- /library/Datastructure/rangeset.hpp.html
title: Datastructure/rangeset.hpp
---
