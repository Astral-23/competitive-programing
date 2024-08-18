---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Convolution/bitwise_or_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../Convolution/bitwise_or_convolution.hpp\"\n\nusing S = ll;\n\
    S op(S a, S b) { return a + b; }\nS inv(S x) { return -x; }\nS zero() { return\
    \ 0; }\n\npair<int, vec<int>> chromatic_number(const vec<vec<int>> &g) {\n   \
    \ if (g.empty()) return {0, {}};\n    int n = g.size();\n\n    vec<vec<ll>> dps(1,\
    \ vec<ll>(1 << n, 0));\n    dps[0][0] = 1;\n\n    vec<ll> dp(1 << n, -1);  //\
    \ dp[i][S] := S \u306F i \u8272\u5F69\u8272\u53EF\u80FD\u304B\uFF1F\n    dp[0]\
    \ = 1;\n    rep(i, 0, n) dp[1 << i] = 1;\n\n    rep(s, 0, 1 << n) if (dp[s] ==\
    \ -1) {\n        int lat = -1;\n        rep(i, 0, n) if (s >> i & 1) lat = i;\n\
    \n        int sub = s ^ (1 << lat);\n        if (dp[sub] == 0) {\n           \
    \ dp[s] = 0;\n            continue;\n        }\n\n        bool ng = false;\n \
    \       for (int to : g[lat])\n            if (s >> to & 1) ng = true;\n\n   \
    \     if (ng)\n            dp[s] = 0;\n        else\n            dp[s] = 1;\n\
    \    }\n\n    dps.push_back(dp);\n\n    while (dps.back()[(1 << n) - 1] == 0)\
    \ {\n        dps.push_back(bitwise_or_convolution<S, op, inv, zero>(\n       \
    \     dps[1], dps[dps.size() - 1]));\n        rep(i, 0, n) if (dps[dps.size()\
    \ - 1][i] != 0) dps[dps.size() - 1][i] =\n            1;\n    }\n\n    int K =\
    \ dps.size() - 1;\n    vec<int> res(n, -1);\n\n    auto dfs = [&](auto f, int\
    \ sup,\n                   int l) -> void {  // \u96C6\u5408 S\u3092\u3001 [l,\
    \ K)\u3092\u4F7F\u3063\u3066\u5F69\u8272\u3002\n        if (sup == 0) return;\n\
    \        int sub = sup;\n        do {\n            if (dps[1][sub] && dps[K -\
    \ l - 1][sup ^ sub]) {\n                rep(i, 0, n) if (sub >> i & 1) res[i]\
    \ = l;\n\n                f(f, sup ^ sub, l + 1);\n                break;\n  \
    \          }\n\n            sub = (sub - 1) & sup;\n        } while (sub != sup);\n\
    \    };\n\n    dfs(dfs, (1 << n) - 1, 0);\n\n    return {K, res};\n}\n/*\n@brief\
    \ \u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Gragh/Chromatic_Number_with_restoration.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Gragh/Chromatic_Number_with_restoration.hpp
layout: document
redirect_from:
- /library/Gragh/Chromatic_Number_with_restoration.hpp
- /library/Gragh/Chromatic_Number_with_restoration.hpp.html
title: "\u5F69\u8272\u6570(\u5FA9\u5143\u4ED8\u304D)"
---
