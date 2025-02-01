#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../Utility/template.hpp"
#include "../Algorithm/doubling.hpp"
#include "../Graph/graph.hpp"

int main() {
    ll n, q;
    cin >> n >> q;
    Tree<int> tr(n);
    vector<int> to(n,-1);
    rep(i, 1, n) {
        cin >> to[i];
        tr.add(i, to[i]);
    }
    vector<int> dep(n, 0);
    auto dfs = [&](auto f, int v, int p) -> void {
        for(auto e : tr[v]) if(e.to != p) {
            dep[e.to] = dep[v] + 1;
            f(f, e.to, v);
        }
    };
    dfs(dfs, 0, -1);
    doubling db(to, n + 10);

    auto lca = [&](int u, int v) -> ll {
        if(dep[u] > dep[v]) swap(u, v);
        if(dep[u] < dep[v]) {
            ll d = dep[v] - dep[u];
            v = db.jump(v, d);
        }

        rrep(i, 0, db.lg_t) {
            ll nu = db.table[i][v];
            ll nv = db.table[i][u];
            if(nu != -1 && nv != -1 && nu != nv) {
                u = nu;
                v = nv;
            }
        }
        if(u != v) {
            u = v = db.table[0][u];
        }
        return u;
    };
    while(q--) {
        ll u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}