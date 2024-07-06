struct HLD {
    using vi = vec<int>;
    using pi = pair<int, int>;
    vi in, out, par, root, rev, dep, pre_vs;
    //          親/成分のtop/inの中身→頂点番号
    int n, r;//頂点数、根
    
  
    HLD(vec<vi> &g, int a): n(g.size()), r(a) {
        vi siz(n, 0);
        in = out = root = rev = vi(n);
        par = vi(n, -1);
        dep = vi(n, 0);
        root[r] = r;

        auto dfs_siz = [&](auto f, int v) -> void {
            siz[v]++;
            for(int& to : g[v]) if(to != par[v]) {
                dep[to] = dep[v] + 1;
                par[to] = v;
                f(f, to);
                siz[v] += siz[to];
                if(siz[to] > siz[g[v][0]] || g[v][0] == par[v]) swap(to, g[v][0]);
            }
            return;
        };

        dfs_siz(dfs_siz, r);
        
        int t = 0;

        auto dfs_hld = [&](auto f, int v) -> void {
            rev[t] = v;
            in[v]=t++;
            for(int to : g[v]) if(to != par[v]) {
                root[to] = (to == g[v][0] ? root[v] : to);
                f(f, to);
            }
            out[v] = t;
        };

        dfs_hld(dfs_hld, r);
    }


    //以下、欲しいもののみ書く


    int lca(int a, int b) {
        while(1) {
            if(in[a] > in[b]) swap(a, b);
            if(root[a] == root[b]) return a;
            b = par[root[b]];
        }
    }

    int dist(int a, int b) {
        int lc = lca(a, b);
        return dep[a] + dep[b] - 2 * dep[lc];
    }

    vec<pi> path(int s, int t, bool edge) {
        vec<pi> ls, rs;
        while(root[s] != root[t]) {
            if(dep[root[s]] > dep[root[t]]) {
                ls.emplace_back(in[s] + 1, in[root[s]]);//上り
                s = par[root[s]];
            }
            else {
                rs.emplace_back(in[root[t]], in[t] + 1);//下り
                t = par[root[t]];
            }
        }

        if(dep[s] > dep[t]) ls.emplace_back(in[s] + 1, in[t] + edge);//上り
        else rs.emplace_back(in[s] + edge, in[t] + 1);//下り
        
        reverse(all(rs));
        for(auto &p : rs) ls.push_back(p);
        return ls;
    }

    pi subtree(int u, bool edge) {
        return pi(in[u]+edge, out[u]);
    }

    int kth_ancestor(int v, int k) {
        if(k > dep[v]) return -1;
        while(v >= 0) {
            if(k <= dep[v] - dep[root[v]]) {
                return rev[in[v] - k];
            }
            else {
                k -= dep[v] - dep[root[v]] + 1;
                v = par[root[v]];
            }
        }
    }

    int jump(int s, int t, int k) {
        int m = lca(s, t);
        int le = dep[s] - dep[m];
        int ri = dep[t] - dep[m];
        if(0 <= k && k <= le + ri) {
            if(k < le) return kth_ancestor(s, k);
            else return kth_ancestor(t, le + ri - k);
        }
        return -1;
    }

    int aux_tree(vi vs, vec<vi> &g) {
        if(vs.empty()) return -1;
        
        auto cmp = [&](int i, int j) { return in[i] < in[j]; };
        sort(all(vs), cmp);
        int m = vs.size();

        rep(i, 0, m-1) vs.push_back(lca(vs[i], vs[i + 1]));
        sort(all(vs), cmp);
        vs.erase(unique(all(vs)), vs.end());

        vi st;
        for(auto v : vs) {
            while(st.size()) {
                int p = st.back();
                if(in[p] < in[v] && in[v] < out[p]) break;
                st.pop_back();
            }
            if(st.size()) {
                g[st.back()].push_back(v);
                g[v].push_back(st.back());
            }
            st.push_back(v);
        }

        swap(vs, pre_vs);
        return pre_vs[0];
    }

    void clean(vec<vi> &g) {
        for(auto v : pre_vs) g[v] = vi();
        pre_vs = vi();
        return;
    }
};  



/*
@brief HLD
@docs doc/hld.md
*/
