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
  bundledCode: "#line 1 \"Datastructure/static2Drectanglesum.hpp\"\ntemplate <typename\
    \ T> struct static2Drectunglesum {\n    using node_t = pair<long long, T>;\n\n\
    \    vector<long long> xs, ys, nxs; // \u70B9\u306E\u60C5\u5831(index\u30D9\u30FC\
    \u30B9\u3067\u6271\u3046\u3068\u4FBF\u5229)\n    vector<T> ws;\n    vector<vector<T>>\
    \ sum;\n\n    bool built = false;\n\n    int n;\n    vector<vector<node_t>> dat;\n\
    \n  private:\n    int get(long long x) const {\n        return lower_bound(nxs.begin(),\
    \ nxs.end(), x) - nxs.begin();\n    }\n\n  public:\n    void init() {\n      \
    \  assert(built == false);\n        built = true;\n        sort(all(nxs));\n \
    \       nxs.erase(unique(all(nxs)), nxs.end());\n        n = nxs.size();\n   \
    \     dat.resize(n);\n        sum.resize(n);\n\n        for (int i = 0; i < int(xs.size());\
    \ i++) {\n            int id = get(xs[i]);\n            id++;\n            while\
    \ (id <= n) {\n                dat[id - 1].emplace_back(ys[i], ws[i]);\n     \
    \           id += id & -id;\n            }\n        }\n\n        for (int i =\
    \ 0; i < n; i++) {\n            sort(dat[i].begin(), dat[i].end(),\n         \
    \        [](const node_t &a, const node_t &b) {\n                     return a.first\
    \ < b.first;\n                 });\n        }\n\n        for (int i = 0; i < int(dat.size());\
    \ i++) {\n            if (dat[i].size() == 0)\n                continue;\n   \
    \         sum[i].resize(dat[i].size() + 1, 0);\n            for (int j = 1; j\
    \ <= int(dat[i].size()); j++) {\n                sum[i][j] = sum[i][j - 1] + dat[i][j\
    \ - 1].second;\n            }\n        }\n    }\n    T prod(long long r, long\
    \ long sy, long long ty) const {\n        assert(built);\n        if (sy >= ty)\n\
    \            return T();\n        T res = T();\n        while (r > 0) {\n    \
    \        int li = lower_bound(dat[r - 1].begin(), dat[r - 1].end(),\n        \
    \                         node_t{sy, -1},\n                                 [&](const\
    \ node_t &a, const node_t &b) {\n                                     return a.first\
    \ < b.first;\n                                 }) -\n                     dat[r\
    \ - 1].begin();\n            int ri = lower_bound(dat[r - 1].begin(), dat[r -\
    \ 1].end(),\n                                 node_t{ty, -1},\n              \
    \                   [&](const node_t &a, const node_t &b) {\n                \
    \                     return a.first < b.first;\n                            \
    \     }) -\n                     dat[r - 1].begin();\n            res += sum[r\
    \ - 1][ri];\n            res -= sum[r - 1][li];\n            r -= r & -r;\n  \
    \      }\n        return res;\n    }\n\n    T prod(long long sx, long long tx,\
    \ long long sy, long long ty) const {\n        assert(built);\n        if (sx\
    \ >= tx)\n            return T();\n\n        int l = get(sx);\n        int r =\
    \ get(tx);\n        return prod(r, sy, ty) - prod(l, sy, ty);\n    }\n\n    //(x,\
    \ y) \u306B += w\u3002 \u540C\u3058(x, y)\u30922\u56DE\u4EE5\u4E0A\u547C\u3093\
    \u3067\u3082ok\n    void add(long long x, long long y, T w) {\n        assert(built\
    \ == false);\n        xs.push_back(x);\n        ys.push_back(y);\n        ws.push_back(w);\n\
    \        nxs.push_back(x);\n    }\n};\n"
  code: "template <typename T> struct static2Drectunglesum {\n    using node_t = pair<long\
    \ long, T>;\n\n    vector<long long> xs, ys, nxs; // \u70B9\u306E\u60C5\u5831\
    (index\u30D9\u30FC\u30B9\u3067\u6271\u3046\u3068\u4FBF\u5229)\n    vector<T> ws;\n\
    \    vector<vector<T>> sum;\n\n    bool built = false;\n\n    int n;\n    vector<vector<node_t>>\
    \ dat;\n\n  private:\n    int get(long long x) const {\n        return lower_bound(nxs.begin(),\
    \ nxs.end(), x) - nxs.begin();\n    }\n\n  public:\n    void init() {\n      \
    \  assert(built == false);\n        built = true;\n        sort(all(nxs));\n \
    \       nxs.erase(unique(all(nxs)), nxs.end());\n        n = nxs.size();\n   \
    \     dat.resize(n);\n        sum.resize(n);\n\n        for (int i = 0; i < int(xs.size());\
    \ i++) {\n            int id = get(xs[i]);\n            id++;\n            while\
    \ (id <= n) {\n                dat[id - 1].emplace_back(ys[i], ws[i]);\n     \
    \           id += id & -id;\n            }\n        }\n\n        for (int i =\
    \ 0; i < n; i++) {\n            sort(dat[i].begin(), dat[i].end(),\n         \
    \        [](const node_t &a, const node_t &b) {\n                     return a.first\
    \ < b.first;\n                 });\n        }\n\n        for (int i = 0; i < int(dat.size());\
    \ i++) {\n            if (dat[i].size() == 0)\n                continue;\n   \
    \         sum[i].resize(dat[i].size() + 1, 0);\n            for (int j = 1; j\
    \ <= int(dat[i].size()); j++) {\n                sum[i][j] = sum[i][j - 1] + dat[i][j\
    \ - 1].second;\n            }\n        }\n    }\n    T prod(long long r, long\
    \ long sy, long long ty) const {\n        assert(built);\n        if (sy >= ty)\n\
    \            return T();\n        T res = T();\n        while (r > 0) {\n    \
    \        int li = lower_bound(dat[r - 1].begin(), dat[r - 1].end(),\n        \
    \                         node_t{sy, -1},\n                                 [&](const\
    \ node_t &a, const node_t &b) {\n                                     return a.first\
    \ < b.first;\n                                 }) -\n                     dat[r\
    \ - 1].begin();\n            int ri = lower_bound(dat[r - 1].begin(), dat[r -\
    \ 1].end(),\n                                 node_t{ty, -1},\n              \
    \                   [&](const node_t &a, const node_t &b) {\n                \
    \                     return a.first < b.first;\n                            \
    \     }) -\n                     dat[r - 1].begin();\n            res += sum[r\
    \ - 1][ri];\n            res -= sum[r - 1][li];\n            r -= r & -r;\n  \
    \      }\n        return res;\n    }\n\n    T prod(long long sx, long long tx,\
    \ long long sy, long long ty) const {\n        assert(built);\n        if (sx\
    \ >= tx)\n            return T();\n\n        int l = get(sx);\n        int r =\
    \ get(tx);\n        return prod(r, sy, ty) - prod(l, sy, ty);\n    }\n\n    //(x,\
    \ y) \u306B += w\u3002 \u540C\u3058(x, y)\u30922\u56DE\u4EE5\u4E0A\u547C\u3093\
    \u3067\u3082ok\n    void add(long long x, long long y, T w) {\n        assert(built\
    \ == false);\n        xs.push_back(x);\n        ys.push_back(y);\n        ws.push_back(w);\n\
    \        nxs.push_back(x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static2Drectanglesum.hpp
  requiredBy: []
  timestamp: '2025-02-18 17:38:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Datastructure/static2Drectanglesum.hpp
layout: document
redirect_from:
- /library/Datastructure/static2Drectanglesum.hpp
- /library/Datastructure/static2Drectanglesum.hpp.html
title: Datastructure/static2Drectanglesum.hpp
---
