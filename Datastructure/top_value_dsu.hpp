template<class S, S (*op)(S, S)> struct dsu {
    using vi = vector<int>;   
    using vvi = vector<vector<int>>;
    vi par, sz, es;
    int cc;
    vector<S> dat;

    dsu(const vector<S> d) : dat(d) {
        int n = d.size();
        par = vi(n);
        sz = vi(n, 1);
        es = vi(n, 0);
        cc = n;
        iota(all(par), 0);
    }
  
    int leader(int u) {
        if (par[u] != u) {
            return par[u] = leader(par[u]);
        }    
         return u;
    }
    
    bool same(int a, int b) {
        return leader(a) == leader(b);
    }
    
    bool merge(int a, int b) {
        a = leader(a), b = leader(b);
        if(sz[a] < sz[b]) swap(a, b);

        if(a == b) {
            ++es[a];
            return false;
        }
        else {
            cc--;
            par[b] = leader(a);
            sz[a] += sz[b];
            es[a] += es[b] + 1;
            dat[a] = op(dat[a], dat[b]);
            return true;
        }
    }

    //以下、必要な物を書く

    int size(int u) {
        return sz[leader(u)];
    }

    S value(int u) {
        return dat[leader(u)];
    }
    
    int componentcnt() {
        return cc;
    }
    
    int edgecnt(int u) {
        return es[leader(u)];
    }

    vvi groups() {
        int n = par.size();
        vvi ms(n);
        rep(v, 0, n) {
            ms[leader(v)].push_back(v);
        }

        vvi res;
        rep(i, 0, n) if(ms[i].size() > 0) {
            res.push_back(ms[i]);
        }

        return res;
    }

};

/*
@brief dsu
@docs doc/dsu.md
*/
