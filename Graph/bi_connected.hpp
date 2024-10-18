struct bi_connected_components : lowlink {
    using lowlink::aux;
    using lowlink::in;
    using lowlink::low;
    using lowlink::n;
    using lowlink::tr;

    int sz;            // 成分の個数。
    vec<vec<int>> vs;  // 頂点リスト。
    vec<vec<pair<int, int>>> bc;  // 辺リスト。vs[i] と bc[i]は同じグループ。
    vec<bool> seen;    // 補助

    bi_connected_components(const vvi &G)
        : lowlink(G), sz(0), vs(n), bc(n), seen(n, false) {
        auto dfs_make = [&](auto f, int v) -> void {
            vs[sz].push_back(v);
            seen[v] = true;
            for (int to : tr[v]) {
                if (seen[to] == false) {
                    bc[sz].emplace_back(minmax(v, to));
                    f(f, to);
                }
            }
            for (int to : aux[v]) {
                bc[sz].emplace_back(minmax(v, to));
            }
        };

        auto dfs = [&](auto f, int v, int root) -> void {
            for (int to : tr[v]) {
                f(f, to, root);
            }

            for (int to : tr[v])
                if (low[to] >= in[v]) {
                    dfs_make(dfs_make, to);
                    bc[sz].emplace_back(minmax(v, to));
                    vs[sz].push_back(v);
                    sz++;
                }

            if (v == root && tr[v].size() == 0) {
                dfs_make(dfs_make, v);
                sz++;
            }
        };

        rep(i, 0, n) if (seen[i] == false) { dfs(dfs, i, i); }
        vs.resize(sz);
        bc.resize(sz);
    }
};

struct block_cut_tree : bi_connected_components {
    using bi_connected_components::vs;
    using lowlink::aux;
    using lowlink::in;
    using lowlink::low;
    using lowlink::n;
    using lowlink::tr;

    vec<vec<int>> bct;
    vec<int> bct_rev;
    vec<vec<int>> bct_vs;
    int vsz;
    block_cut_tree(const vvi &G)
        : bi_connected_components(G),
          bct(joints.size() + vs.size()),
          bct_rev(n),
          bct_vs(joints.size() + vs.size()) {
        int id = 0;
        rep(i, 0, n) if (is_joint(i)) {
            bct_vs[id].push_back(i);
            bct_rev[i] = id;
            id++;
        }

        rep(i, 0, vs.size()) {
            for (int v : vs[i]) {
                if (is_joint(v)) {
                    bct[id].push_back(bct_rev[v]);
                    bct[bct_rev[v]].push_back(id);
                } else {
                    bct_vs[id].push_back(v);
                    bct_rev[v] = id;
                }
            }
            id++;
        }
    }

    int operator()(int v) const { return bct_rev[v]; }
};

/*
@brief 二重辺連結成分分解・BCT Tree
*/