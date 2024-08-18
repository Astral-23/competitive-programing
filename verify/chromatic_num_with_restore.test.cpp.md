---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Convolution/bitwise_or_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../Utility/template.hpp\"\n#include \"../Gragh/Chromatic_Number_with_restoration.hpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vec<vec<int>> g(n);\n\
    \    rep(i, 0, m) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    auto [ans, col] = chromatic_number(g);\n\
    \n    vec<int> cnt(ans, 0);\n\n    rep(i, 0, n) {\n        assert(0 <= col[i]);\n\
    \        assert(col[i] < ans);\n        cnt[col[i]]++;\n        for(int to : g[i])\
    \ {\n            assert(col[i] != col[to]);\n        }\n    }\n\n    rep(i, 0,\
    \ ans) assert(cnt[i] != 0);\n\n    cout << ans << endl;\n\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/chromatic_num_with_restore.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/chromatic_num_with_restore.test.cpp
layout: document
redirect_from:
- /verify/verify/chromatic_num_with_restore.test.cpp
- /verify/verify/chromatic_num_with_restore.test.cpp.html
title: verify/chromatic_num_with_restore.test.cpp
---
