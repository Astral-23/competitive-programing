#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../Utility/template.hpp"
#include "../Algorithm/maximum_independent_set.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> ng(n, vec<int>(n, 0));
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        ng[u][v] = 1;
        ng[v][u] = 1;
    }

    auto res = maximum_independent_set(ng);
    cout << res.size() << endl;
    for(int x : res) cout << x << " ";
    cout << endl;

}