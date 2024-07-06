#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../Utility/template.hpp"
#include "../Algorithm/scc.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    auto res = SCC(g);
    vec<vec<int>> vs(n);
    rep(i, 0, n) vs[res[i]].push_back(i);
    
    int c = 0;
    rep(i, 0, n) if(vs[i].size() > 0)c++;
    cout << c << endl;

     

    rep(i, 0, n) if(vs[i].size() > 0) {
        cout << vs[i].size() << " ";
        for(auto v : vs[i]) cout << v << " ";
        cout << endl;
    }
}

