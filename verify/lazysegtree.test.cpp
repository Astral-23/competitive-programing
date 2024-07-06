#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Datastructure/lazysegtree.hpp"
using mint = modint998244353;
struct S {
    mint s; int sz;
};

S op(S l, S r) {
    return S{l.s + r.s, l.sz + r.sz};
}

S e() {
    return S{mint(0), 0};
}

struct F {
    mint a, b;
};

S mapping(F f, S s) {
    S res;
    res.s = f.a * s.s + f.b * s.sz;
    res.sz = s.sz;
    return res;
}

F composition(F l, F r) {
    return F{r.a * l.a, r.b * l.a + l.b};
}

F id() {
    return F{1, 0};
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<S> V(N);
    rep(i, 0, N) {
        int a;
        cin >> a;
        V[i] = S{a, 1};
    }
    lazysegtree<S, op, e, F, mapping, composition, id> seg(V);
    while(Q--) {
       // rep(i, 0, N) cout << seg.prod(i, i+1).s.x << " ";
       // cout << endl;
        int t;
        cin >> t;
        if(t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, F{b, c});
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).s.x << '\n';
        }
    }
}