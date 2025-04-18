struct HLD {
    using vi = vec<int>;
    using pi = pair<int, int>;
    using pll = pair<long long, long long>;
    vi in, out, par, root, rev, dep, pre_vs;
    vec<ll> dep_w;
    //          親/成分のtop/inの中身→頂点番号
    int n, r;  // 頂点数、根
    
    static vec<vec<int>> extract_graph(const vec<vec<pll>> &G) {
        vec<vec<int>> g(G.size());
        for (int i = 0; i < int(G.size()); i++) {
            for (auto [w, to] : G[i])
                if (i < to) {
                    g[i].push_back(to);
                    g[to].push_back(i);
                }
        }
        return g;
    }
    HLD(const vec<vec<pll>> &g, int a) : HLD(extract_graph(g), a) {
        auto dfs = [&](auto f, int v) -> void {
            for (auto [w, to] : g[v])
                if (to != par[v]) {
                    dep_w[to] = dep_w[v] + w;
                    f(f, to);
                }
        };
        dfs(dfs, r);
    }

    HLD(vec<vi> g, int a) : n(g.size()), r(a) {
        vi siz(n, 0);
        in = out = root = rev = vi(n);
        par = vi(n, -1);
        dep = vi(n, 0);
        dep_w = vec<ll>(n, 0);
        root[r] = r;

        auto dfs_siz = [&](auto f, int v) -> void {
            siz[v]++;
            for (int &to : g[v])
                if (to != par[v]) {
                    dep[to] = dep[v] + 1;
                    par[to] = v;
                    f(f, to);
                    siz[v] += siz[to];
                    if (siz[to] > siz[g[v][0]] || g[v][0] == par[v])
                        swap(to, g[v][0]);
                }
            return;
        };

        dfs_siz(dfs_siz, r);

        int t = 0;

        auto dfs_hld = [&](auto f, int v) -> void {
            rev[t] = v;
            in[v] = t++;
            for (int to : g[v])
                if (to != par[v]) {
                    root[to] = (to == g[v][0] ? root[v] : to);
                    f(f, to);
                }
            out[v] = t;
        };

        dfs_hld(dfs_hld, r);
        for (int i = 0; i < n; i++) dep_w[i] = dep[i];
    }

    // 以下、欲しいもののみ書く

    int operator()(int v) const { return in[v]; }
    int operator()(int u, int v) const {
        assert(par[u] == v || par[v] == u);
        if(par[u] == v) return in[u];
        else return in[v];
    }

    int lca(int a, int b) {
        while (1) {
            if (in[a] > in[b]) swap(a, b);
            if (root[a] == root[b]) return a;
            b = par[root[b]];
        }
    }

    ll dist(int a, int b) {
        int lc = lca(a, b);
        return dep_w[a] + dep_w[b] - 2 * dep_w[lc];
    }

    vec<pi> path(int s, int t, bool edge) {
        vec<pi> ls, rs;
        while (root[s] != root[t]) {
            if (dep[root[s]] > dep[root[t]]) {
                ls.emplace_back(in[s] + 1, in[root[s]]);  // 上り
                s = par[root[s]];
            } else {
                rs.emplace_back(in[root[t]], in[t] + 1);  // 下り
                t = par[root[t]];
            }
        }

        if (dep[s] > dep[t])
            ls.emplace_back(in[s] + 1, in[t] + edge);  // 上り
        else
            rs.emplace_back(in[s] + edge, in[t] + 1);  // 下り

        reverse(all(rs));
        for (auto &p : rs) ls.push_back(p);
        return ls;
    }

    pi subtree(int u, bool edge) { return pi(in[u] + edge, out[u]); }

    int kth_ancestor(int v, int k) {
        if (k > dep[v]) return -1;
        while (v >= 0) {
            if (k <= dep[v] - dep[root[v]]) {
                return rev[in[v] - k];
            } else {
                k -= dep[v] - dep[root[v]] + 1;
                v = par[root[v]];
            }
        }
    }

    int jump(int s, int t, int k) {
        int m = lca(s, t);
        int le = dep[s] - dep[m];
        int ri = dep[t] - dep[m];
        if (0 <= k && k <= le + ri) {
            if (k < le)
                return kth_ancestor(s, k);
            else
                return kth_ancestor(t, le + ri - k);
        }
        return -1;
    }

    int aux_tree(vi vs, vec<vi> &g) {
        if (vs.empty()) return -1;

        auto cmp = [&](int i, int j) { return in[i] < in[j]; };
        sort(all(vs), cmp);
        int m = vs.size();

        rep(i, 0, m - 1) vs.push_back(lca(vs[i], vs[i + 1]));
        sort(all(vs), cmp);
        vs.erase(unique(all(vs)), vs.end());

        vi st;
        for (auto v : vs) {
            while (st.size()) {
                int p = st.back();
                if (in[p] < in[v] && in[v] < out[p]) break;
                st.pop_back();
            }
            if (st.size()) {
                g[st.back()].push_back(v);
                g[v].push_back(st.back());
            }
            st.push_back(v);
        }

        swap(vs, pre_vs);
        return pre_vs[0];
    }

    void clean(vec<vi> &g) {
        for (auto v : pre_vs) g[v] = vi();
        pre_vs = vi();
        return;
    }
};
/*
@brief HLD
@docs doc/hld.md
*/
