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
  bundledCode: "#line 1 \"Algorithm/ternary_search.hpp\"\ntemplate <typename T, typename\
    \ S, bool max, typename F>\nT decimal_ternary_search(T l, T r, F f, int lim) {\n\
    \    int c = 0;\n    while (c < lim) {\n        c++;\n        T m1 = (l * 2 +\
    \ r) / 3, m2 = (l + r * 2) / 3;\n        S v1 = f(m1), v2 = f(m2);\n\n       \
    \ if constexpr (max) {\n            if (v1 > v2) {\n                r = m2;\n\
    \            } else {\n                l = m1;\n            }\n        } else\
    \ {\n            if (v1 < v2) {\n                r = m2;\n            } else {\n\
    \                l = m1;\n            }\n        }\n    }\n    return l;\n}\n\n\
    //\u9589\u3058\u305F\u533A\u9593\ntemplate <typename T, typename S, bool max,\
    \ typename F>\nT ternary_search(T l, T r, F f) {\n    while ((r - l) >= 3) {\n\
    \        T m1 = (l + r) / 2, m2 = m1 + 1;\n        S v1 = f(m1), v2 = f(m2);\n\
    \n        if constexpr (max) {\n            if (v1 > v2) {\n                r\
    \ = m2;\n            } else {\n                l = m1;\n            }\n      \
    \  } else {\n            if (v1 < v2) {\n                r = m2;\n           \
    \ } else {\n                l = m1;\n            }\n        }\n    }\n    T ret\
    \ = l;\n    S v = f(l);\n    for (T i = l + 1; i <= r; i++) {\n        S v2 =\
    \ f(i);\n        if constexpr (max) {\n            if (v < v2) {\n           \
    \     v = v2;\n                ret = i;\n            }\n        } else {\n   \
    \         if (v > v2) {\n                v = v2;\n                ret = i;\n \
    \           }\n        }\n    }\n    return ret;\n}\n\ntemplate <typename T, typename\
    \ S, bool max, typename F>\nT memo_ternary_search(T l, T r, F f) {\n    map<T,\
    \ S> memo;\n    auto get = [&](T x) {\n        if (memo.contains(x))\n       \
    \     return memo[x];\n        else {\n            memo[x] = f(x);\n         \
    \   return memo[x];\n        }\n    };\n\n    while ((r - l) >= 3) {\n       \
    \ T m1 = (l + r) / 2, m2 = m1 + 1;\n        S v1 = get(m1), v2 = get(m2);\n\n\
    \        if constexpr (max) {\n            if (v1 > v2) {\n                r =\
    \ m2;\n            } else {\n                l = m1;\n            }\n        }\
    \ else {\n            if (v1 < v2) {\n                r = m2;\n            } else\
    \ {\n                l = m1;\n            }\n        }\n    }\n\n    T ret = l;\n\
    \    S v = get(l);\n    for (T i = l + 1; i <= r; i++) {\n        S v2 = get(i);\n\
    \        if constexpr (max) {\n            if (v < v2) {\n                v =\
    \ v2;\n                ret = i;\n            }\n        } else {\n           \
    \ if (v > v2) {\n                v = v2;\n                ret = i;\n         \
    \   }\n        }\n    }\n    return ret;\n}\n"
  code: "template <typename T, typename S, bool max, typename F>\nT decimal_ternary_search(T\
    \ l, T r, F f, int lim) {\n    int c = 0;\n    while (c < lim) {\n        c++;\n\
    \        T m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;\n        S v1 = f(m1),\
    \ v2 = f(m2);\n\n        if constexpr (max) {\n            if (v1 > v2) {\n  \
    \              r = m2;\n            } else {\n                l = m1;\n      \
    \      }\n        } else {\n            if (v1 < v2) {\n                r = m2;\n\
    \            } else {\n                l = m1;\n            }\n        }\n   \
    \ }\n    return l;\n}\n\n//\u9589\u3058\u305F\u533A\u9593\ntemplate <typename\
    \ T, typename S, bool max, typename F>\nT ternary_search(T l, T r, F f) {\n  \
    \  while ((r - l) >= 3) {\n        T m1 = (l + r) / 2, m2 = m1 + 1;\n        S\
    \ v1 = f(m1), v2 = f(m2);\n\n        if constexpr (max) {\n            if (v1\
    \ > v2) {\n                r = m2;\n            } else {\n                l =\
    \ m1;\n            }\n        } else {\n            if (v1 < v2) {\n         \
    \       r = m2;\n            } else {\n                l = m1;\n            }\n\
    \        }\n    }\n    T ret = l;\n    S v = f(l);\n    for (T i = l + 1; i <=\
    \ r; i++) {\n        S v2 = f(i);\n        if constexpr (max) {\n            if\
    \ (v < v2) {\n                v = v2;\n                ret = i;\n            }\n\
    \        } else {\n            if (v > v2) {\n                v = v2;\n      \
    \          ret = i;\n            }\n        }\n    }\n    return ret;\n}\n\ntemplate\
    \ <typename T, typename S, bool max, typename F>\nT memo_ternary_search(T l, T\
    \ r, F f) {\n    map<T, S> memo;\n    auto get = [&](T x) {\n        if (memo.contains(x))\n\
    \            return memo[x];\n        else {\n            memo[x] = f(x);\n  \
    \          return memo[x];\n        }\n    };\n\n    while ((r - l) >= 3) {\n\
    \        T m1 = (l + r) / 2, m2 = m1 + 1;\n        S v1 = get(m1), v2 = get(m2);\n\
    \n        if constexpr (max) {\n            if (v1 > v2) {\n                r\
    \ = m2;\n            } else {\n                l = m1;\n            }\n      \
    \  } else {\n            if (v1 < v2) {\n                r = m2;\n           \
    \ } else {\n                l = m1;\n            }\n        }\n    }\n\n    T\
    \ ret = l;\n    S v = get(l);\n    for (T i = l + 1; i <= r; i++) {\n        S\
    \ v2 = get(i);\n        if constexpr (max) {\n            if (v < v2) {\n    \
    \            v = v2;\n                ret = i;\n            }\n        } else\
    \ {\n            if (v > v2) {\n                v = v2;\n                ret =\
    \ i;\n            }\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/ternary_search.hpp
  requiredBy: []
  timestamp: '2025-02-28 10:35:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/ternary_search.hpp
layout: document
redirect_from:
- /library/Algorithm/ternary_search.hpp
- /library/Algorithm/ternary_search.hpp.html
title: Algorithm/ternary_search.hpp
---
