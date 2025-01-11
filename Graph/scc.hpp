#include "../Graph/graph.hpp"

namespace SCC {
template <typename T> vector<int> ids(const Graph<T, true> &g) {
    int n = g.size();
    vector<int> vs, cmp(n, -1);
    vec<bool> seen(n, false), nees(n, false);
    Graph<T, true> rg(n);

    rep(i, 0, n) for (auto e : g[i]) rg.add(e.to, i, e.cost, e.id);

    auto dfs = [&](auto f, int v) -> void {
        seen[v] = true;
        for (auto e : g[v])
            if (!seen[e.to]) f(f, e.to);
        vs.push_back(v);
        return;
    };

    int k = 0;

    auto sfd = [&](auto f, int v) -> void {
        nees[v] = true;
        cmp[v] = k;
        for (auto e : rg[v])
            if (!nees[e.to]) f(f, e.to);
        return;
    };

    rep(i, 0, n) if (!seen[i]) dfs(dfs, i);
    rrep(i, 0, vs.size()) if (!nees[vs[i]]) sfd(sfd, vs[i]), k++;
    return cmp;
}

template <typename T> vector<vector<int>> groups(const Graph<T, true> &g) {
    int n = g.size();
    vector<int> id = ids<T>(g);
    vector<vector<int>> gs(n);
    rep(i, 0, n) gs[id[i]].push_back(i);
    while (gs.empty() == false && gs.back().empty() == true) {
        gs.pop_back();
    }
    return gs;
}

template <typename T> Graph<T, true> graph(const Graph<T, true> &g) {
    vector<int> id = ids<T>(g);
    int n = 0;
    rep(i, 0, g.size()) chmax(n, id[i] + 1);
    
    Graph<T, true> ng(n);
    rep(i, 0, g.size()) for (auto e : g[i]) {
        if (id[i] == id[e.to]) continue;
        ng.add(id[i], id[e.to], e.cost, e.id);
    }
    return ng;
}

template <typename T> Graph<T, true> graph_rev(const Graph<T, true> &g) {
    auto ser = graph<T>(g);
    int n = ser.size();
    Graph<T, true> res(n);
    rep(i, 0, n) for (auto e : ser[i]) { res.add(e.to, i, e.w, e.id); }
    return res;
}

}  // namespace SCC

/*
@brief scc(強連結成分分解)
@docs doc/scc.md
*/
