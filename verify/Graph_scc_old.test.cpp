#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../Utility/template.hpp"
#include "../Graph/scc_old.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    auto res = SCC::groups(g);
    
    cout << res.size() << endl;

    rep(i, 0, res.size()) {
        cout << res[i].size() << " ";
        for(auto v : res[i]) cout << v << " ";
        cout << endl;
    }
}

