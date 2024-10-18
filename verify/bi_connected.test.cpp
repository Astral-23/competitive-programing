#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "../Utility/template.hpp"
#include "../Graph/lowlink.hpp"
#include "../Graph/bi_connected.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }

    bi_connected_components bi(g);
    cout << bi.sz << endl;
    int e_cnt = 0;
    rep(i, 0, bi.sz) e_cnt += bi.bc[i].size();
    assert(e_cnt == m);

    rep(i, 0, bi.sz) {
        vec<int> vvv;
        for (auto [u, v] : bi.bc[i]) vvv.push_back(u), vvv.push_back(v);
        sort(all(vvv));
        vvv.erase(unique(all(vvv)), vvv.end());
        sort(all(bi.vs[i]));
        if (bi.vs[i].size() == 1) {
            assert(vvv.empty());
        } else {
            assert(vvv == bi.vs[i]);
        }

        cout << bi.vs[i].size() << " ";
        for (auto v : bi.vs[i]) cout << v << " ";
        cout << '\n';
    }
}