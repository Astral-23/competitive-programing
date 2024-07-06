vec<int> SCC (vec<vec<int>> g) {
    using vi = vec<int>;
    using vvi = vec<vi>;

    int n = g.size();
    vvi rg(n);
    vi vs, cmp(n, -1);
    vec<bool> seen(n, false), nees(n, false);

    rep(i, 0, n) for(int to : g[i]) rg[to].push_back(i);

    auto dfs = [&](auto f, int v) -> void {
        seen[v] = true;
        for(auto to : g[v]) if(!seen[to]) f(f, to);
        vs.push_back(v);
        return;
    };

    int k = 0;

    auto sfd = [&](auto f, int v) -> void {
        nees[v] = true;
        cmp[v] = k;
        for(int to : rg[v]) if(!nees[to]) f(f, to);
        return;
    };

    
    rep(i, 0, n) if(!seen[i]) dfs(dfs, i);
    rrep(i, 0, vs.size()) if(!nees[vs[i]]) sfd(sfd, vs[i]), k++;
    return cmp;
}

/*
@brief 強連結成分分解
@docs doc/scc.md
*/