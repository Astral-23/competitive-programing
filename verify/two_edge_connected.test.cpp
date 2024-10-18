#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../Utility/template.hpp"
#include "../Graph/lowlink.hpp"
#include "../Graph/two_edge_connected.hpp"

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

    two_edge_connected_components two(g);
    vec<vec<int>> vs(two.sz);
    rep(i, 0, n) vs[two(i)].push_back(i);

    cout << two.sz << '\n';

    rep(i, 0, two.sz) {
        cout << vs[i].size() << " ";
        for (int v : vs[i]) cout << v << " ";
        cout << '\n';
    }
}