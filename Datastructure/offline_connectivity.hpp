template<class dsu, class S, class qif, bool multi_edge>
struct offline_connectivity {
    using pii = pair<int, int>;
    using edge = array<int, 4>;
    using que = pair<int, qif>;
    int n, t, sz, qi, li;
    dsu uf;
    vec<vec<pii>> dat;
    vec<multiset<pii>> es;
    vec<edge> lrs;
    vec<que> qs;
    vec<array<ll, 3>> lz;//{t, 頂点, 作用素}  作用素がllではない場合、頑張る。
    vec<S> res;

    offline_connectivity(int N) : n(N), es(N), qi(0), li(0), t(0), sz(1), uf(N) { }

    void build() {
        rep(u, 0, n) {
            for(auto [v, l] : es[u]) {
                lrs.push_back(edge{l, t, int(u), v});
            }
        }
       
        while(sz < t) sz <<= 1;
        dat.resize(2 * sz);

        for(auto [l, r, u, v] : lrs) {
            l += sz;
            r += sz;
            while(l < r) {
                if(l & 1) dat[l++].emplace_back(u, v);
                if(r & 1) dat[--r].emplace_back(u, v);
                l >>= 1, r >>= 1;
            }
        }
    }

    TT void dfs(T f, int v) {
        for(auto [a, b] : dat[v]) uf.merge(a, b);
        if(v >= sz) {
            while(li < lz.size() && lz[li][0] == v - sz) uf.set(lz[li][1], lz[li][2]), li++;//set→ applyにする必要があるかも(dsuに合わせる)
            if(qi < qs.size() && qs[qi].first == v - sz) res.push_back(f(uf, qs[qi++].second));
        }
        else {
            dfs(f, v * 2);
            dfs(f, v * 2 + 1);
        }
        rep(i, 0, dat[v].size()) uf.undo();
    }
    

    TT vec<S> run(T f) {
        dfs(f, 1);
        return res;
    }

    void link(int u, int v) {
        if(u > v) swap(u, v);
        if(multi_edge == true) es[u].insert(pii(v, t));
        else {
            auto it = es[u].lower_bound(pii(v, -1));
            if(it != es[u].end() && (*it).first == v) return;
            es[u].insert(pii(v, t));
        }
    }

    void cut(int u, int v) {
        if(u > v) swap(u, v);
        auto it = es[u].lower_bound(pii(v, -1));
        if(it == es[u].end()) return;
        auto [tar, l] = *it;
        if(tar != v) return;
        es[u].erase(it);
        lrs.push_back(edge{l, t, u, v});
        
    }

    void query(qif q) {
        qs.push_back(que(t++, q));
    }

    void apply(int v, ll f) {
        lz.push_back({t, v, f});
    }

    void set(int v, ll f) {//ufのapplyに相当する関数名がsetだった時用
        lz.push_back({t, v, f});
    }

};
/*
S f(dsu &uf, qif q) {
    return 答え
}
をrunに渡す
&を付ける事を忘れずに（計算量こわれる）

@brief offline_connectivity
@docs doc/offline_connectivity.md
*/