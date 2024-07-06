---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: doc/mp.md
    document_title: "mp\u6CD5"
    links: []
  bundledCode: "#line 1 \"String/mp.hpp\"\nvec<int> MP(string S) {\n    int n = S.size();\n\
    \    vec<int> res(n+1, -1);\n    int j = -1;\n    rep(i, 0, n) {\n        while(j\
    \ >= 0 && S[i] != S[j]) j = res[j];\n        j++;\n        res[i+1] = j;\n   \
    \ }\n    res.erase(res.begin());\n    return res;\n}\n\n\nint shortest_run(vec<int>\
    \ &mp, int i) {\n    return i + 1 - mp[i];\n}\n/*\n@brief mp\u6CD5\n@docs doc/mp.md\n\
    */\n"
  code: "vec<int> MP(string S) {\n    int n = S.size();\n    vec<int> res(n+1, -1);\n\
    \    int j = -1;\n    rep(i, 0, n) {\n        while(j >= 0 && S[i] != S[j]) j\
    \ = res[j];\n        j++;\n        res[i+1] = j;\n    }\n    res.erase(res.begin());\n\
    \    return res;\n}\n\n\nint shortest_run(vec<int> &mp, int i) {\n    return i\
    \ + 1 - mp[i];\n}\n/*\n@brief mp\u6CD5\n@docs doc/mp.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/mp.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/mp.hpp
layout: document
redirect_from:
- /library/String/mp.hpp
- /library/String/mp.hpp.html
title: "mp\u6CD5"
---
## 概要
mp法を行う。
参考:https://snuke.hatenablog.com/entry/2014/12/01/235807



## 関数

- **vec\<int\> MP(string s)**...mp法を行った配列mpを返す。 mp[i] := [0, i]の接頭辞と接尾辞の最大共通文字列であって、i+1未満の長さの物の長さ
    - 計算量  $O(\|S\|)$

- **int shortest_run(vec\<int\> &mp, int i)** ...[0, i]の最**小**周期長。mpには、MPの返り値を渡す。
    - 計算量 $O(1)$


## shortest_runの説明
長さが $n$ の文字列 $S$ について、次の命題が成立する。<br>

**Sが周期長kを持つ⇔Sと、Sをk文字右にずらした文字列の共通部分が一致する⇔S[0, n-k] = S[k, n]**<br>

また、次の命題も成立する<br>

**S[0, n-k] = S[k, n] ⇔ Sの最長共通文字列であって、n未満の長さの物の長さ >= n-k**

合わせて、
**Sが周期kを持つ ⇔ mp[n-1] >= n - k**<br>


これを、mp法の形式に合わせると、<br>

**S[0, i]が周期kを持つ ⇔ mp[i] >= i+1 - k**
<br>

となって
<br>

**S[0, i]の最小周期長 = i+1 - mp[i]**