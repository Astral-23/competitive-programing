struct range_edge_graph {
    #define pb push_back
    struct edge {
        int to;
        ll cost;
        //ll cap; フローならこれも使う。
        edge(){}
        edge(int a, ll b, ll c) : to(a), cost(b) {}
        //edge(int a, ll b, ll c) : to(a), cost(b), cap(c) {}
        //フローの時のコンストラクタ
    };

    edge e(int to) {
        return edge(to, 0, LLONG_MAX/4);
    }
  
    int n;
    int sz = 1;
    int node;
    vec<vec<edge>> g;

    range_edge_graph(int N) : n(N) {
        while(sz < n) sz <<= 1;

        g = vec<vec<edge>>(n + 4 * sz);
        node = n + 4 * sz;

        rep(i, 1, sz) {
            g[i + n].pb( e(i * 2 + n) );
            g[i + n].pb( e(i * 2 + 1 + n) );

            g[i * 2 + n + 2 * sz].pb( e(i + n + 2 * sz) );
            g[i * 2 + 1 + n + 2 * sz].pb( e(i + n + 2 * sz) );
        }

        rep(i, 0, n) {
            g[i + n + sz].pb( e(i) );
            g[i].pb( e(i + n + 3 * sz) );
        }
    }

    void add_edge(int sl, int sr, int tl, int tr, ll cost, ll cap) {
        int nw = node++;
        int nw2 = node++;
        g.pb({ edge( nw2, cost, cap ) });
        g.pb(vec<edge>());

        sl += sz;
        sr += sz;
        while(sl < sr) {
            if(sl & 1) g[sl + n + 2 * sz].pb( e(nw) ), sl++;
            if(sr & 1) sr--, g[sr + n + 2 * sz].pb( e(nw) );
            sl >>= 1; sr >>= 1;
        }

        tl += sz;
        tr += sz;
        while(tl < tr) {
            if(tl & 1) g[nw2].pb( e(tl + n) ), tl++;
            if(tr & 1) tr--, g[nw2].pb( e(tr + n) ); 
            tl >>= 1, tr >>= 1;
        }
    }

    void add_edge(int s, int t, ll cost, ll cap) {
        g[s].pb( edge(t, cost, cap) );
    }

    vec<vec<edge>> graph() {
        return g;
    }

    #undef pb
};

/*
@brief 区間に辺を貼るテク
@docs doc/range_edge_graph.md
*/
