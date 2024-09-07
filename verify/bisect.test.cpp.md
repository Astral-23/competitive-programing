---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/bisect.hpp
    title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"verify/bisect.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Algorithm/bisect.hpp\"\ntemplate\
    \ <typename T, typename F> T bisect(T ok, T ng, F pred) {\n    if (ok <= ng)\n\
    \        ng++;\n    else\n        ng--;\n\n    if (!pred(ok)) {\n        if(ok\
    \ <= ng) {\n            return ok - 1;\n        }\n        else {\n          \
    \  return ok + 1;\n        }\n    }\n\n    while (ng > ok + 1 || ok > ng + 1)\
    \ {\n        T mid = ((ok ^ ng) >> 1) + (ok & ng);\n        (pred(mid) ? ok :\
    \ ng) = mid;\n    }\n    return ok;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\
    \u63A2\u7D22\n@docs doc/bisect.md\n*/\n#line 4 \"verify/bisect.test.cpp\"\n\n\
    /*\nn/x - n/(x+1) >= 1\n\u21D4\nn >= x(x+1)\n\n*/\nint main() {\n    ll n;\n \
    \   cin >> n;\n    \n    auto ok = [&](ll x) {\n        return n >= __int128_t(x)*(x+1);\n\
    \    };\n\n    ll x = bisect(0LL, n, ok);\n\n    vec<ll> ans;\n    rep(i, 1, x+1)\
    \ ans.push_back(n / i);\n   \n    for(ll i = n/(x+1); i >= 1; i--) ans.push_back(i);\n\
    \n    reverse(all(ans));\n    cout << ans.size() << endl;\n    rep(i, 0, ans.size())\
    \ cout << ans[i] <<\" \";\n\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Algorithm/bisect.hpp\"\n\n\
    /*\nn/x - n/(x+1) >= 1\n\u21D4\nn >= x(x+1)\n\n*/\nint main() {\n    ll n;\n \
    \   cin >> n;\n    \n    auto ok = [&](ll x) {\n        return n >= __int128_t(x)*(x+1);\n\
    \    };\n\n    ll x = bisect(0LL, n, ok);\n\n    vec<ll> ans;\n    rep(i, 1, x+1)\
    \ ans.push_back(n / i);\n   \n    for(ll i = n/(x+1); i >= 1; i--) ans.push_back(i);\n\
    \n    reverse(all(ans));\n    cout << ans.size() << endl;\n    rep(i, 0, ans.size())\
    \ cout << ans[i] <<\" \";\n\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/bisect.hpp
  isVerificationFile: true
  path: verify/bisect.test.cpp
  requiredBy: []
  timestamp: '2024-08-19 14:15:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/bisect.test.cpp
layout: document
redirect_from:
- /verify/verify/bisect.test.cpp
- /verify/verify/bisect.test.cpp.html
title: verify/bisect.test.cpp
---
