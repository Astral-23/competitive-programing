---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps_count_subset_sum.test.cpp
    title: verify/fps_count_subset_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Fps/count_subset_sum.hpp\"\nvector<mint> count_subset_sum(vector<ll>\
    \ items, ll t) {\n    mint ret = 1;\n    vector<ll> cnt(t + 1, 0);\n    vector<mint>\
    \ inv(t + 1, 1);\n    for (int i = 1; i <= t; i++) {\n        inv[i] = inv[i -\
    \ 1] * i;\n    }\n    inv[t] = inv[t].inv();\n    for (int i = t - 1; i >= 0;\
    \ i--) {\n        mint tmp = inv[i];\n        inv[i] = inv[i + 1] * (i + 1);\n\
    \        inv[i + 1] = tmp * inv[i + 1];\n    }\n\n    for (auto w : items) {\n\
    \        if (w > t) continue;\n        if (w == 0) {\n            ret *= 2;\n\
    \        } else {\n            cnt[w]++;\n        }\n    }\n\n    fps f;\n   \
    \ for (int i = 1; i <= t; i++)\n        if (cnt[i] != 0) {\n            for (int\
    \ k = 1; k * i <= t; k++) {\n                if (k & 1) {\n                  \
    \  f[k*i] += inv[k] * cnt[i];\n                } else {\n                    f[k*i]\
    \ -= inv[k] * cnt[i];\n                }\n            }\n        }\n\n    f =\
    \ f.exp(t + 1);\n    vector<mint> ans(t + 1, 1);\n    for (int i = 0; i <= t;\
    \ i++) {\n        ans[i] = f[i] * ret;\n    }\n    return ans;\n}\n"
  code: "vector<mint> count_subset_sum(vector<ll> items, ll t) {\n    mint ret = 1;\n\
    \    vector<ll> cnt(t + 1, 0);\n    vector<mint> inv(t + 1, 1);\n    for (int\
    \ i = 1; i <= t; i++) {\n        inv[i] = inv[i - 1] * i;\n    }\n    inv[t] =\
    \ inv[t].inv();\n    for (int i = t - 1; i >= 0; i--) {\n        mint tmp = inv[i];\n\
    \        inv[i] = inv[i + 1] * (i + 1);\n        inv[i + 1] = tmp * inv[i + 1];\n\
    \    }\n\n    for (auto w : items) {\n        if (w > t) continue;\n        if\
    \ (w == 0) {\n            ret *= 2;\n        } else {\n            cnt[w]++;\n\
    \        }\n    }\n\n    fps f;\n    for (int i = 1; i <= t; i++)\n        if\
    \ (cnt[i] != 0) {\n            for (int k = 1; k * i <= t; k++) {\n          \
    \      if (k & 1) {\n                    f[k*i] += inv[k] * cnt[i];\n        \
    \        } else {\n                    f[k*i] -= inv[k] * cnt[i];\n          \
    \      }\n            }\n        }\n\n    f = f.exp(t + 1);\n    vector<mint>\
    \ ans(t + 1, 1);\n    for (int i = 0; i <= t; i++) {\n        ans[i] = f[i] *\
    \ ret;\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Fps/count_subset_sum.hpp
  requiredBy: []
  timestamp: '2024-12-24 08:43:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps_count_subset_sum.test.cpp
documentation_of: Fps/count_subset_sum.hpp
layout: document
redirect_from:
- /library/Fps/count_subset_sum.hpp
- /library/Fps/count_subset_sum.hpp.html
title: Fps/count_subset_sum.hpp
---
