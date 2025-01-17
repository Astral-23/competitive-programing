---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/bisect.hpp
    title: "\u62BD\u8C61\u5316\u4E8C\u5206\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"verify/Algorithm_bisect_max_right.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n#line 1 \"Utility/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define rrep(i, s, t) for (ll\
    \ i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x), end(x)\n\n#define\
    \ TT template <typename T>\nTT using vec = vector<T>;\ntemplate <class T1, class\
    \ T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true) : false;\n}\n\
    template <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return x < y ? (x\
    \ = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n\
    \        std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n\
    \    }\n} io_setup;\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n*/\n#line 1 \"Algorithm/bisect.hpp\"\n\ntemplate <typename T, typename F> T\
    \ max_right(T l, T max_r_plus_one, F pred) {\n    assert(l < max_r_plus_one);\n\
    \n    if (!pred(l)) return l;\n\n    while (max_r_plus_one > l + 1) {\n      \
    \  T mid = ((l ^ max_r_plus_one) >> 1) + (l & max_r_plus_one);\n        (pred(mid)\
    \ ? l : max_r_plus_one) = mid;\n    }\n    return max_r_plus_one;\n};\n\ntemplate\
    \ <typename T, typename F> T min_left(T min_l, T r, F pred) {\n    assert(min_l\
    \ < r);\n\n    if (pred(min_l)) return min_l;\n\n    while (r > min_l + 1) {\n\
    \        T mid = ((min_l ^ r) >> 1) + (min_l & r);\n        (pred(mid) ? r : min_l)\
    \ = mid;\n    }\n    return r;\n}\n/*\n@brief \u62BD\u8C61\u5316\u4E8C\u5206\u63A2\
    \u7D22\n@docs doc/bisect.md\n*/\n#line 4 \"verify/Algorithm_bisect_max_right.test.cpp\"\
    \n/*\nn/x - n/(x+1) >= 1\n\u21D4\nn >= x(x+1)\n*/\nint main() {\n    ll n;\n \
    \   cin >> n;\n\n    auto pred = [&](ll r) { return n >= __int128_t(r) * (r +\
    \ 1); };\n\n    ll x = max_right(0LL, n + 1, pred);\n    x--;\n    vec<ll> ans;\n\
    \    rep(i, 1, x + 1) ans.push_back(n / i);\n\n    for (ll i = n / (x + 1); i\
    \ >= 1; i--) ans.push_back(i);\n\n    reverse(all(ans));\n    cout << ans.size()\
    \ << endl;\n    rep(i, 0, ans.size()) cout << ans[i] << \" \";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    #include \"../Utility/template.hpp\"\n#include \"../Algorithm/bisect.hpp\"\n/*\n\
    n/x - n/(x+1) >= 1\n\u21D4\nn >= x(x+1)\n*/\nint main() {\n    ll n;\n    cin\
    \ >> n;\n\n    auto pred = [&](ll r) { return n >= __int128_t(r) * (r + 1); };\n\
    \n    ll x = max_right(0LL, n + 1, pred);\n    x--;\n    vec<ll> ans;\n    rep(i,\
    \ 1, x + 1) ans.push_back(n / i);\n\n    for (ll i = n / (x + 1); i >= 1; i--)\
    \ ans.push_back(i);\n\n    reverse(all(ans));\n    cout << ans.size() << endl;\n\
    \    rep(i, 0, ans.size()) cout << ans[i] << \" \";\n}"
  dependsOn:
  - Utility/template.hpp
  - Algorithm/bisect.hpp
  isVerificationFile: true
  path: verify/Algorithm_bisect_max_right.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 20:14:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Algorithm_bisect_max_right.test.cpp
layout: document
redirect_from:
- /verify/verify/Algorithm_bisect_max_right.test.cpp
- /verify/verify/Algorithm_bisect_max_right.test.cpp.html
title: verify/Algorithm_bisect_max_right.test.cpp
---
