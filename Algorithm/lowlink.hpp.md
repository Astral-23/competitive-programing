---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lowlink_bridge.test.cpp
    title: verify/lowlink_bridge.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lowlink_joint.test.cpp
    title: verify/lowlink_joint.test.cpp
  - icon: ':heavy_check_mark:'
    path: "verify/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3.test.cpp"
    title: "verify/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3.test.cpp"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/lowlink.md
    document_title: lowlink
    links: []
  bundledCode: "#line 1 \"Algorithm/lowlink.hpp\"\nstruct lowlink {\n    using vi\
    \ = vec<int>;\n    using vvi = vec<vi>;\n    using pii = pair<int, int>;\n   \
    \ \n    int n;\n    vvi tr;\n    vi low, in;\n    vec<pii> bridges;\n    vec<int>\
    \ joints;\n\n    lowlink(vvi g) : n(g.size()) {\n        low = vi(n, 1001001001);\n\
    \        in = vi(n, -1);\n        tr.resize(n);\n    \n        \n        int t\
    \ = 0;\n        int r = 0;\n        auto dfs = [&](auto f, int v, int p) -> void\
    \ {\n            in[v] = low[v] = t++;\n            bool duplication = false;\n\
    \            for(int to: g[v]) {\n                if(in[to] == -1) {\n       \
    \             tr[v].push_back(to);\n                    f(f, to, v);\n       \
    \         }\n                else {\n                    if(to != p) chmin(low[v],\
    \ in[to]);\n                    else if(duplication == false) duplication = true;\n\
    \                    else {\n                        chmin(low[v], in[to]);\n\
    \                    }\n                }\n            }\n\n            for(int\
    \ to : tr[v]) {\n                chmin(low[v], low[to]);\n            }\n    \
    \        //\u90E8\u5206\u6728\u306B\u3064\u3044\u3066\u3001low/in\u304C\u6C42\u307E\
    \u3063\u305F\n            bool isjoint = false;\n            for(int to : tr[v])\
    \ {\n                if(low[to] > in[v]) bridges.emplace_back(v, to);\n      \
    \          if(low[to] >= in[v]) isjoint = true;\n            }\n\n           \
    \ if(v != r && isjoint) joints.push_back(v);\n            else if(v == r) {\n\
    \                if(tr[v].size() > 1) joints.push_back(v);\n            }\n  \
    \      };\n\n        rep(i, 0, n) if(in[i] == -1) {\n            r = i;\n    \
    \        dfs(dfs, i, -1);\n        }\n    }\n\n};\n\n/*\n@brief lowlink\n@docs\
    \ doc/lowlink.md\n*/\n"
  code: "struct lowlink {\n    using vi = vec<int>;\n    using vvi = vec<vi>;\n  \
    \  using pii = pair<int, int>;\n    \n    int n;\n    vvi tr;\n    vi low, in;\n\
    \    vec<pii> bridges;\n    vec<int> joints;\n\n    lowlink(vvi g) : n(g.size())\
    \ {\n        low = vi(n, 1001001001);\n        in = vi(n, -1);\n        tr.resize(n);\n\
    \    \n        \n        int t = 0;\n        int r = 0;\n        auto dfs = [&](auto\
    \ f, int v, int p) -> void {\n            in[v] = low[v] = t++;\n            bool\
    \ duplication = false;\n            for(int to: g[v]) {\n                if(in[to]\
    \ == -1) {\n                    tr[v].push_back(to);\n                    f(f,\
    \ to, v);\n                }\n                else {\n                    if(to\
    \ != p) chmin(low[v], in[to]);\n                    else if(duplication == false)\
    \ duplication = true;\n                    else {\n                        chmin(low[v],\
    \ in[to]);\n                    }\n                }\n            }\n\n      \
    \      for(int to : tr[v]) {\n                chmin(low[v], low[to]);\n      \
    \      }\n            //\u90E8\u5206\u6728\u306B\u3064\u3044\u3066\u3001low/in\u304C\
    \u6C42\u307E\u3063\u305F\n            bool isjoint = false;\n            for(int\
    \ to : tr[v]) {\n                if(low[to] > in[v]) bridges.emplace_back(v, to);\n\
    \                if(low[to] >= in[v]) isjoint = true;\n            }\n\n     \
    \       if(v != r && isjoint) joints.push_back(v);\n            else if(v == r)\
    \ {\n                if(tr[v].size() > 1) joints.push_back(v);\n            }\n\
    \        };\n\n        rep(i, 0, n) if(in[i] == -1) {\n            r = i;\n  \
    \          dfs(dfs, i, -1);\n        }\n    }\n\n};\n\n/*\n@brief lowlink\n@docs\
    \ doc/lowlink.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/lowlink.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - "verify/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3.test.cpp"
  - verify/lowlink_bridge.test.cpp
  - verify/lowlink_joint.test.cpp
documentation_of: Algorithm/lowlink.hpp
layout: document
redirect_from:
- /library/Algorithm/lowlink.hpp
- /library/Algorithm/lowlink.hpp.html
title: lowlink
---
## 概要
**無向**グラフに対し、lowlinkと呼ばれるアルゴリズムを実行する。<br>非連結・多重辺・自己ループok。
参考 : https://kntychance.hatenablog.jp/entry/2022/09/16/161858 <br>

## コンストラクタ
**lowlink llink(g)** ... グラフgに対して実行する。計算量 $O(頂点数 + 辺の本数)$

## 関数
基本的に、関数はない。その代わり、lowlink構造体のメンバ変数にアクセスしてする事で所望のデータを得る。
- **vec\<pair\<int, int\>\> bridges**... 橋を列挙した配列を返す。この際、pairに格納される順番/ どちらがfirst, どちらがsecondかは未定義。重複辺がない時、各辺は1回限り格納される。
- **vec\<int\> joints** ... 関節線を入れた配列を返す。頂点の順番は未定義。
    - **計算量** $O(1)$

## 説明
特に、根付き木において

「sがtの先祖」の定義: ｔから上方向の辺のみを辿ってsに到達できる<br>

より、

DFS木において無視される辺が後退辺のみであるとうことは、「上方向に辿るような移動をする辺しか無視されていない」と解釈する事ができる。<br>

これにより、

辺u-vがサイクルに含まれている⇔無視された辺のうち、「vから初めて上に登る動きをするような辺が存在する」

事となり、ここから<br>

low[v] > ord[u]

の式が容易に導ける。

或いは、

low[u] == ord[u]　⇔ uから根の方向に伸びる辺は橋
<br>

また、頂点の場合は少し複雑になる。そもそも、頂点の場合は連結性とサイクルに含まれるかどうかということに綺麗な関係が見当たらない。<br>
この場合、「もし連結成分が増えるのならば、根と非連結になる: 定義→根にたどり着けない頂点が誕生する」事を利用する(注意: 根を取り除く場合は別に考える。)。<br>
まず、$u$を取り除いた場合について考える時、考えるのは$u$の子だけで良い。(逆に、それ以外を考えると複雑になる)<br>
ある頂点vが根にたどり着くためには上向の辺を辿っていくしかない。そのため、頂点uが削除された際には、uの子v全てについて「u -> v の辺を逆走せずに、uより上に行けるか？」を判定すれば良く、この計算はlow/inで既に実行済みである。

また、
**命題 : 無向グラフに橋が存在しない　⇔ 辺の向きの付け方であって、グラフが強連結であるものが存在する。**
が成立する。この時の辺の向きの付け方はdfs木がその条件を満たす。<br>

**橋についての条件は、dfs木をとってlow/ordの条件に還元すると議論が進む事がある（そもそも、検出がそれをしている)**

特に、dfs木を取った際、無視された辺は後退辺であると言う性質から、他の部分木を無視して考えられる場合がある。
