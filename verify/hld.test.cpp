#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../Utility/template.hpp"
#include "../Algorithm/hld.hpp"
#include "../Datastructure/segtree.hpp"


using S = ll;
S op(S l, S r) {
    return l + r;
}

S e() {
    return 0LL;
}



int main() {
    int N, Q;
    cin >> N >> Q;
    vec<ll> A(N);
    rep(i,0,N) cin >> A[i];
    vec<vec<int>> G(N);
    rep(i, 0, N-1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    
    HLD hld(G, 0);
    vec<ll> B(N);
    rep(i,0,N) B[hld.in[i]] = A[i];
    segtree<S, op, e> seg(B);

    while(Q--) {
        int t;
        cin >> t;
        if(t==0) {
            int p, x;
            cin >> p >> x;
            p = hld.in[p];
            seg.set(p, seg.get(p) + x);
        }
        else {
            int u, v;
            cin >> u >> v;
            auto ps = hld.path(u, v, false);
            ll res = 0;
            for(auto [l, r] : ps) {
                if(l >= r) swap(l, r);
                res += seg.prod(l, r);
            }
            cout << res << '\n';
        }
    }
}