TT struct potential_dsu {
    using vi = vec<int>;
    using vvi = vec<vi>;
    vi par, sz, es;
    vec<T> h;
    int cc;
    int root;

    potential_dsu(int n, int ROOT) : root(ROOT) {
        par = vi(n);
        sz = vi(n, 1);
        es = vi(n, 0);
        cc = n;
        iota(all(par), 0);

        h = vec<T>(n, 0);
    }

    int leader(int u) {
        if(par[u] != u) {
            int r = leader(par[u]);
            h[u] += h[par[u]];
            return par[u] = r;
        }
        return u;
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    bool merge(int s, int t, T w) {
        w += weight(s), w -= weight(t);
        s = leader(s), t = leader(t);
        if(s == t) {
            es[s]++;
            return false;
        }

        if(sz[s] < sz[t] && s != root) {
            swap(s, t);
            w *= -1;
        }

        cc--;
        par[t] = s;
        sz[s] += sz[t];
        es[s] += es[t] + 1;

        h[t] = w;
        return true;
        
    }

    T weight(int v) {
        leader(v);
        return h[v];
    }

    T diff(int s, int t) {
        return weight(t) - weight(s);
    }

};

/*
@brief potential dsu
*/

