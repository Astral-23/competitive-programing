#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../Utility/template.hpp"
#include "../Algorithm/lowlink.hpp"

using pii = pair<int, int>;
int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    lowlink llink(g);
    vec<int> seen(n, 0);
    vec<int> idx(n, -1);
    int t = 0;
    set<pii> bs;
    for(auto [l, r] : llink.bridges) {
        bs.insert(pii(l, r));
        bs.insert(pii(r, l));
    }

    auto dfs = [&](auto f, int v) -> void {
        seen[v] = 1;
        idx[v] = t;

        for(int to : g[v]) if(!seen[to]) {
            if(!bs.count(pii(v, to))) {
                f(f, to);
            }
        }
    };

    rep(i, 0, n) if(!seen[i]) {
        dfs(dfs, i);
        t++;
    }

    vec<vec<int>> vs(n);
    rep(i, 0, n) vs[idx[i]].push_back(i);

    int c = 0;
    rep(i, 0, n) if(!vs[i].empty()) c++;

    cout << c << endl;

    rep(i, 0, n) {
        if(vs[i].size() == 0) continue;
        cout << vs[i].size() << " ";
        for(auto v : vs[i]) cout << v << " ";
        cout << '\n';
    }
}