---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/min_distance.hpp
    title: "\u6700\u77ED\u7D4C\u8DEF"
  - icon: ':heavy_check_mark:'
    path: Utility/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/dijkstra.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Utility/modint.hpp\"\n\n//\
    \ \u52D5\u7684mod : template<int mod> \u3092\u6D88\u3057\u3066\u3001\u4E0A\u306E\
    \u65B9\u3067\u5909\u6570mod\u3092\u5BA3\u8A00\ntemplate <uint32_t mod> struct\
    \ modint {\n    using mm = modint;\n    uint32_t x;\n    modint() : x(0) {}\n\
    \    TT modint(T a = 0) : x((ll(a) % mod + mod)) {\n        if (x >= mod) x -=\
    \ mod;\n    }\n\n    friend mm operator+(mm a, mm b) {\n        a.x += b.x;\n\
    \        if (a.x >= mod) a.x -= mod;\n        return a;\n    }\n    friend mm\
    \ operator-(mm a, mm b) {\n        a.x -= b.x;\n        if (a.x >= mod) a.x +=\
    \ mod;\n        return a;\n    }\n\n    //+\u3068-\u3060\u3051\u3067\u5341\u5206\
    \u306A\u5834\u5408\u3001\u4EE5\u4E0B\u306F\u7701\u7565\u3057\u3066\u826F\u3044\
    \u3067\u3059\u3002\n\n    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x)\
    \ * b.x; }\n    friend mm operator/(mm a, mm b) { return a * b.inv(); }\n    friend\
    \ mm &operator+=(mm &a, mm b) { return a = a + b; }\n    friend mm &operator-=(mm\
    \ &a, mm b) { return a = a - b; }\n    friend mm &operator*=(mm &a, mm b) { return\
    \ a = a * b; }\n    friend mm &operator/=(mm &a, mm b) { return a = a * b.inv();\
    \ }\n\n    mm inv() const { return pow(mod - 2); }\n    mm pow(ll y) const {\n\
    \        mm res = 1;\n        mm v = *this;\n        while (y) {\n           \
    \ if (y & 1) res *= v;\n            v *= v;\n            y /= 2;\n        }\n\
    \        return res;\n    }\n\n    friend istream &operator>>(istream &is, mm\
    \ &a) {\n        ll t;\n        cin >> t;\n        a = mm(t);\n        return\
    \ is;\n    }\n\n    friend ostream &operator<<(ostream &os, mm a) { return os\
    \ << a.x; }\n\n    bool operator==(mm a) { return x == a.x; }\n    bool operator!=(mm\
    \ a) { return x != a.x; }\n\n    bool operator<(const mm &a) const { return x\
    \ < a.x; }\n};\nusing modint998244353 = modint<998244353>;\nusing modint1000000007\
    \ = modint<1'000'000'007>;\n/*\n@brief modint\n*/\n#line 1 \"Graph/min_distance.hpp\"\
    \n\ntemplate <typename T> struct min_distance {\n    using pll = pair<ll, ll>;\n\
    \n  private:\n    int n, s;\n    vec<vec<pll>> g;\n    vec<ll> dist;\n    vec<T>\
    \ cnt;\n    vec<int> pre;\n    int built;\n    ll inf = LLONG_MAX / 4;\n\n   \
    \ void init() {\n        fill(all(dist), inf);\n        fill(all(cnt), 0);\n \
    \       fill(all(pre), -1);\n    }\n\n  public:\n    min_distance(int n) : n(n),\
    \ dist(n), cnt(n), pre(n), built(0) {};\n    min_distance(int n, vec<vec<pll>>\
    \ &g)\n        : n(n), g(g), dist(n), cnt(n), pre(n), built(0) {}\n\n    void\
    \ add_edge(int from, int to, ll cost) { g[from].emplace_back(cost, to); }\n\n\
    \    void run_dijkstra(int S) {\n        built = 1;\n        init();\n       \
    \ s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        priority_queue<pair<ll,\
    \ ll>, vector<pair<ll, ll>>,\n                       greater<pair<ll, ll>>>\n\
    \            que;\n        que.push({dist[s], s});\n        while (que.empty()\
    \ == false) {\n            auto [c, v] = que.top();\n            que.pop();\n\
    \            if (dist[v] < c) continue;\n            for (auto [cost, to] : g[v])\
    \ {\n                if (chmin(dist[to], cost + c)) {\n                    cnt[to]\
    \ = cnt[v];\n                    pre[to] = v;\n                    que.push({dist[to],\
    \ to});\n\n                } else if (dist[to] == cost + c) {\n              \
    \      cnt[to] += cnt[v];\n                }\n            }\n        }\n    }\n\
    \n    bool run_bellman_ford(int S) {\n        built = 2;\n        init();\n  \
    \      s = S;\n        dist[s] = 0;\n        cnt[s] = 1;\n        int last = -1;\n\
    \        rep(i, 0, n) {\n            bool found = false;\n            rep(v, 0,\
    \ n) if (dist[v] != inf) {\n                for (auto [cost, to] : g[v]) {\n \
    \                   if (chmin(dist[to], dist[v] + cost)) {\n                 \
    \       found = true;\n                        pre[to] = v;\n                \
    \    }\n                }\n            }\n            if (found) last = i;\n \
    \       }\n\n        if (last == n - 1) return true;\n        return false;\n\
    \    }\n\n    vec<vec<ll>> run_warshall_floyd() {\n        vec<vec<ll>> d(n, vec<ll>(n,\
    \ inf));\n        rep(i, 0, n) d[i][i] = 0;\n        rep(i, 0, n) for (auto [cost,\
    \ to] : g[i]) {\n            chmin(d[i][to], cost);\n            chmin(d[to][i],\
    \ cost);\n        }\n\n        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {\n    \
    \        chmin(d[i][j], d[i][k] + d[k][j]);\n        }\n        return d;\n  \
    \  }\n\n    vec<ll> distance() {\n        assert(built != 0);\n        return\
    \ dist;\n    }\n\n    vec<T> count_path() {\n        assert(built == 1);\n   \
    \     return cnt;\n    }\n\n    vec<int> path(int t) {\n        assert(built !=\
    \ 0);\n        vec<int> res;\n        while (1) {\n            res.push_back(t);\n\
    \            if (t == s) break;\n            t = pre[t];\n        }\n        reverse(all(res));\n\
    \        return res;\n    }\n};\n/*\n@brief \u6700\u77ED\u7D4C\u8DEF\n@docs doc/min_distance.md\n\
    */\n#line 5 \"verify/dijkstra.test.cpp\"\n\nint main() {\n    ll n, m, s, t;\n\
    \    cin >> n >> m >> s >> t;\n    vec<vec<pair<ll, ll>>> g(n);\n    rep(i, 0,\
    \ m) {\n        ll a, b, c;\n        cin >> a >> b >> c;\n        g[a].push_back({c,\
    \ b});\n    }\n    min_distance<modint998244353> G(n, g);\n\n   \n    G.run_dijkstra(s);\n\
    \    auto dist = G.distance();\n\n   \n    if (dist[t] == LLONG_MAX / 4) {\n \
    \       cout << -1 << endl;\n        return 0;\n    }\n\n    auto ps = G.path(t);\n\
    \    cout << dist[t] << \" \" << ps.size() - 1 << '\\n';\n\n    rep(i, 0, ps.size()\
    \ - 1) { cout << ps[i] << \" \" << ps[i + 1] << '\\n'; }\n    cout << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Utility/modint.hpp\"\n#include \"\
    ../Graph/min_distance.hpp\"\n\nint main() {\n    ll n, m, s, t;\n    cin >> n\
    \ >> m >> s >> t;\n    vec<vec<pair<ll, ll>>> g(n);\n    rep(i, 0, m) {\n    \
    \    ll a, b, c;\n        cin >> a >> b >> c;\n        g[a].push_back({c, b});\n\
    \    }\n    min_distance<modint998244353> G(n, g);\n\n   \n    G.run_dijkstra(s);\n\
    \    auto dist = G.distance();\n\n   \n    if (dist[t] == LLONG_MAX / 4) {\n \
    \       cout << -1 << endl;\n        return 0;\n    }\n\n    auto ps = G.path(t);\n\
    \    cout << dist[t] << \" \" << ps.size() - 1 << '\\n';\n\n    rep(i, 0, ps.size()\
    \ - 1) { cout << ps[i] << \" \" << ps[i + 1] << '\\n'; }\n    cout << endl;\n}"
  dependsOn:
  - Utility/template.hpp
  - Utility/modint.hpp
  - Graph/min_distance.hpp
  isVerificationFile: true
  path: verify/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 23:47:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/dijkstra.test.cpp
- /verify/verify/dijkstra.test.cpp.html
title: verify/dijkstra.test.cpp
---