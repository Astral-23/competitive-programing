namespace SCC {
vec<int> ids(const vec<vec<int>> &g) {
    using vi = vec<int>;
    using vvi = vec<vi>;

    int n = g.size();
    vvi rg(n);
    vi vs, cmp(n, -1);
    vec<bool> seen(n, false), nees(n, false);

    rep(i, 0, n) for (int to : g[i]) rg[to].push_back(i);

    auto dfs = [&](auto f, int v) -> void {
        seen[v] = true;
        for (auto to : g[v])
            if (!seen[to]) f(f, to);
        vs.push_back(v);
        return;
    };

    int k = 0;

    auto sfd = [&](auto f, int v) -> void {
        nees[v] = true;
        cmp[v] = k;
        for (int to : rg[v])
            if (!nees[to]) f(f, to);
        return;
    };

    rep(i, 0, n) if (!seen[i]) dfs(dfs, i);
    rrep(i, 0, vs.size()) if (!nees[vs[i]]) sfd(sfd, vs[i]), k++;
    return cmp;
}

vec<vec<int>> groups(const vec<vec<int>> &g) {
    int n = g.size();
    vec<int> id = ids(g);

    vec<vec<int>> gs(n);
    rep(i, 0, n) gs[id[i]].push_back(i);
    while (gs.empty() == false && gs.back().empty() == true) {
        gs.pop_back();
    }
    return gs;
}

vec<vec<int>> graph(const vec<vec<int>> &g) {
    vec<int> id = ids(g);
    int n = 0;
    rep(i, 0, g.size()) chmax(n, id[i] + 1);

    vec<vec<int>> ng(n);
    rep(i, 0, g.size()) for (int to : g[i]) {
        if (id[i] == id[to]) continue;
        ng[id[i]].push_back(id[to]);
    }
    return ng;
}

vec<vec<int>> graph_rev(const vec<vec<int>> &g) {
    auto ser = graph(g);
    int n = ser.size();
    vec<vec<int>> res(n);
    rep(i, 0, n) for(int to : ser[i]) {
        res[to].push_back(i);
    }
    return res;
}

}  // namespace SCC

/*
@brief scc(強連結成分分解)
@docs doc/scc.md
*/