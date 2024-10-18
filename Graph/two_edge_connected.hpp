struct two_edge_connected_components : lowlink {
    using lowlink::aux;
    using lowlink::in;
    using lowlink::low;
    using lowlink::n;
    using lowlink::tr;
    int sz;  // 成分の個数
    vi rev;  // 頂点iが属する成分の番号
    vvi g;   // 縮約グラフ
    two_edge_connected_components(const vvi &G)
        : lowlink(G), sz(0), rev(n, -1), g(n) {
        auto dfs = [&](auto f, int v, int this_id) -> void {
            rev[v] = this_id;
            for (int to : G[v])
                if (rev[to] == -1) {
                    if (is_bridge(v, to)) {
                        sz++;
                        g[this_id].push_back(sz - 1);
                        g[sz - 1].push_back(this_id);
                        f(f, to, sz - 1);
                    } else {
                        f(f, to, this_id);
                    }
                }
        };

        rep(i, 0, n) if (rev[i] == -1) {
            sz++;
            dfs(dfs, i, sz - 1);
        }
        g.resize(sz);
    }

    int operator()(int v) const { return rev[v]; }
};
/*
@brief 二重辺連結成分分解
*/