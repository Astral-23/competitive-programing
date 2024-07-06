#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../Utility/template.hpp"
#include "../Algorithm/hld.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vec<vec<int>> G(N);
    rep(i, 0, N-1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    HLD hld(G, 0);

    while(Q--) {
        int s, t, i;
        cin >> s >> t >> i;
        cout << hld.jump(s, t, i) << '\n';

    }

}