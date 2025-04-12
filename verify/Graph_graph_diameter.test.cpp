#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../Utility/template.hpp"
#include "../Graph/graph.hpp"


int main() {
    int n;
    cin >> n;
    Tree<ll> cyc(n);
    rep(i, 0, n-1) {
        ll u, v, c;
        cin >> u >> v >> c;
        cyc.add(u, v, c);
    }

    auto [len, uv] = Tree_lib::diam(cyc);
    auto [u, v] = uv;
    auto ps = Tree_lib::path(cyc, u, v);
    cout << len << " " << ps.size() << endl;
    for(auto vv : ps) cout << vv << " ";
}