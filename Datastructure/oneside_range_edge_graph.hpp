/*
注意: これにより得られたグラフで最短距離を求める場合、頂点番号をずらして利用する必要がある。
理由: セグ木の最下段を生の頂点として扱っている。
*/
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
        return edge(to, 0, LLONG_MAX);
    }
  
    int n;
    int sz = 1;
    int node;
    vec<vec<edge>> g;

    range_edge_graph(int N) : n(N) {
        while(sz < n) sz <<= 1;

        g = vec<vec<edge>>(2 * sz);
        node = 2 * sz;
        rep(i, 1, sz) {
            g[i].pb( e(i * 2) );
            g[i].pb( e(i * 2 + 1 ) );
        }
    }

    void point_range(int s, int tl, int tr, ll cost) {
        s += sz;
        tl += sz;
        tr += sz;

        while(tl < tr) {
            if(tl & 1) g[s].pb( edge(tl, cost, 0) ), tl++;
            if(tr & 1) tr--, g[s].pb( edge(tr, cost, 0) ); 
            tl >>= 1, tr >>= 1;
        }
    }

    void range_point(int sl, int sr, int t, ll cost) {
        sl += sz;
        sr += sz;
        t += sz;

        while(sl < sr) {
            if(sl & 1) g[sl].pb( edge(t, cost, 0) ), sl++;
            if(sr & 1) sr--, g[sr].pb ( edge(t, cost, 0) );
            sl >>= 1, sr >>= 1;
        }
    }

    void add_edge(int s, int t, ll cost, ll cap) {
        s += sz, t += sz;
        g[s].pb( edge(t, cost, cap) );
    }

    vec<vec<edge>> graph() {
        return g;
    }

    #undef pb
};

/*
@brief 区間に辺を貼るテク(特殊版)
*/