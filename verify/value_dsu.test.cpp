#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "../Utility/template.hpp"
#include "../Datastructure/value_dsu.hpp"
#include "../Datastructure/offline_connectivity.hpp"

using S = ll;
S op(S l, S r) {
    return l + r;
}

S e() {
    return 0LL;
}


S f(dsu<S, op, e> &uf, int v) {
    return uf.get(v);
}

int main() {
    int n, q;
    cin >> n >> q;
    vec<ll> A(n);
    rep(i, 0, n) cin >> A[i];
    offline_connectivity<dsu<S, op, e>, S, int, false> uf(n);
    rep(i, 0, n) uf.set(i, A[i]);

    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int u, v;
            cin >> u >> v;
            uf.link(u, v);
        }
        else if(t == 1) {
            int u, v;
            cin >> u >> v;
            uf.cut(u, v);
        }
        else if(t == 2) {
            int v; ll x;
            cin >> v >> x;
            A[v] += x;
            uf.set(v, A[v]);
        }
        else {
            int v;
            cin >> v;
            uf.query(v);
        }
    }

    uf.build();
    auto res = uf.run(f);
    for(ll x : res) cout << x << "\n";


}