struct dsu {
    using vi = vector<int>;   
    using vvi = vec<vi>;
    struct dat {
        int u, v;
        ll x;
        dat(){}
        dat(int a, int b, ll c) : u(a), v(b), x(c) {}
    };
   
    vi par, sz, es;
    vec<ll> val;
    stack<dat> his;
    int cc;
   
    ll op(ll l, ll r) {return l + r;}
    ll inv(ll x) {return -x;}

    dsu(int n) {
        par = vi(n);
        sz = vi(n, 1);
        es = vi(n, 0);
        val = vec<ll>(n, 0);
        cc = n;
        iota(all(par), 0);
    }
  
    int leader(int u) {
        while(par[u] != u) {
            u = par[u];
        }
        return u;
    }
    
    bool same(int a, int b) {
        return leader(a) == leader(b);
    }
    
    bool merge(int a, int b) {
        a = leader(a), b = leader(b);
        if(sz[a] < sz[b]) swap(a, b);
        his.push(dat(a, b, val[a]));

        if(a == b) {
            es[a]++;
            return false;
        }
        else {
            cc--;
            par[b] = a;
            sz[a] += sz[b];
            es[a] += es[b] + 1;
            val[a] = op(val[a] , val[b]);
            return true;
        }
    }

    bool undo() {
        if(his.empty()) return false;
        dat p = his.top();
        auto [u, v, x] = p; 
        his.pop();
        par[v] = v;
        es[u]--;
        if(u != v) {
            cc++;
            sz[u] -= sz[v];
            es[u] -= es[v];
            val[u] = op(val[u], inv( val[v] ));
        }
        return true;
    }

    //以下、必要ないなら省く。

    void set(int v, ll f) {//注意: 代入では無い
        while(1) {
            val[v] = op(val[v], f);
            if(v == par[v]) break;
            v = par[v];
        }
    }

    ll get(int u) {
        return val[leader(u)];
    }

    int size(int u) {//uが含まれる連結成分のサイズを返す
        return sz[leader(u)];
    }

    int edgecnt(int u) {
        return es[leader(u)];
    }

    int component_count() {
        return cc;
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
@brief undable dsu
@docs doc/undodsu.md
*/