#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "../Utility/template.hpp"
#include "../Gragh/Chromatic_Number.hpp"
int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = chromatic_number(g);

    cout << ans << endl;

}