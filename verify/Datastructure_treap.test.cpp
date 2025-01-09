#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Datastructure/treap.hpp"
using mint = modint<998244353>;

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
    return F{l.a * r.a,  l.a * r.b + l.b};
}

F id() {
    return F{1, 0};
}


int main() {
    treap<S, op, e, F, mapping, composition, id> tr;
    ll N, Q;
    cin >> N >> Q;
    for(int i = 0; i <= N-1; i++) {
        ll t;
        cin >> t;
        mint a = t;
        tr.push_back(S{a,1});
    }

    while(Q--) {
        assert(tr.size() == N);
        int type;
        cin >> type;
        if(type == 0) {
            ll i, x;
            cin >> i >> x;
            tr.insert(i, S{x, 1});
            N++;
        }
        else if(type==1) {
            int i;
            cin >> i;
            tr.erase(i);
            N--;
        }
        else if(type==2) {
            ll l, r;
            cin >> l >> r;
            tr.reverse(l,r);
        }
        else if(type==3) {
            ll l, r;
            mint b, c;
            cin >> l >> r >> b >> c;
            tr.apply(l, r, F{b, c});
        }
        else {
            ll l, r;
            cin >> l >> r;
            if(l==0 && r == tr.size()) {
                cout << tr.all_prod().s.x << " ";
                continue;
            }
            cout << tr.prod(l, r).s.x << " ";
        }
    }
}