template<class S, S (*op)(S, S), S (*e) ()> struct dsu {
    using vi = vec<int>;
    using vvi = vec<vi>;   

    struct dat {
        int r, u, v, p;
        dat(){}
        dat(int a, int b, int c, int d) : r(a), u(b), v(c), p(d) {}
    };
   
    int cc;
    vi par, sz, es, lv, lch, rch, rank;
    vec<S> A, acc;
    stack<dat> his;
   

    dsu(int n) {
        cc = n;
        par = vi(n);
        lv = rank = es = vi(n, 0);
        sz = vi(n, 1);
        lch = rch = vi(n, -1);
        A = acc = vec<S>(n, e());
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

    int update(int v) {
        while(1) {
            if(rch[v] != -1) {
                lv[v] = min(lv[lch[v]], lv[rch[v]]) + 1;
                acc[v] = op(A[v], op(acc[lch[v]], acc[rch[v]]));
            }
            else if(lch[v] != -1) {
                lv[v] = 0;
                acc[v] = op(A[v], acc[lch[v]]);
            }
            else {
                lv[v] = 0;
                acc[v] = A[v];
            }
            if(v == par[v]) break;
            v = par[v];
        }
        return v;
    }

    
    bool merge(int a, int b) {
        a = leader(a), b = leader(b);
    
        if(max(rank[a], rank[b] + lv[a] + 1)  > max(rank[b], rank[a] + lv[b] + 1)) swap(a, b);
     
        if(a == b) {
            es[a]++;
            his.push(dat(a, -1, -1, -1));
            return false;
        }

        cc--;
        int r = a;
        int p = rank[a];
        rank[a] = max(rank[a], lv[a] + rank[b] + 1);
        sz[a] += sz[b];
        es[a] += es[b] + 1;

        while(lch[a] != -1 && rch[a] != -1) {
            if(lv[lch[a]] < lv[rch[a]]) a = lch[a];
            else a = rch[a];
        }

        par[b] = a;
        if(lch[a] == -1) lch[a] = b;
        else rch[a] = b;
        his.push(dat(r, a, b, p));
        update(a);
        return true;
    }

    bool undo () {
        if(his.empty()) return false;
        dat pre = his.top();
        his.pop();
        es[pre.r]--;

        if(pre.u >= 0) {
            cc++;
            sz[pre.r] -= sz[pre.v];
            es[pre.r] -= es[pre.v];
            rank[pre.r] = pre.p;
            par[pre.v] = pre.v;
            if(lch[pre.u] == pre.v) lch[pre.u] = -1;
            else rch[pre.u] = -1;
            update(pre.u);
        }
        return true;
    }

    S get(int u) {
        return acc[leader(u)];
    }

    void set(int u, S s) {
        A[u] = s;
        update(u);
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
@brief 値集約・変更可能なdsu
@docs doc/value_dsu.md
*/