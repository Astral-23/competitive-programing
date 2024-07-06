#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../Utility/template.hpp"
#include "../Algorithm/hld.hpp"



int main() {
    int N, Q;
    cin >> N >> Q;
    vec<vec<int>> G(N);
    rep(i, 1, N) {
        int p;
        cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }

    HLD hld(G, 0);

    while(Q--) {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << '\n';
    }
}
