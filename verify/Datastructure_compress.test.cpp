#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Datastructure/compress.hpp"
#include "../Datastructure/segtree.hpp"

using mint = modint998244353;


struct S{
    mint a, b;
    S(){}
    S(mint d, mint t) : a(d), b(t){}
};

S op(S l, S r) {
	S res;
    res.a = l.a * r.a;
    res.b = r.a * l.b + r.b;
    return res;
}

S e() {
	return S(1, 0);
}

int main() {
    ll n, q;
    cin >> n >> q;
    compress<int> cm;
    using P = array<ll, 4>;
    vector<P> qs;
    rep(qi, 0, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0) {
            b--;
        } else {
            b--, c--;
        }
        qs.push_back({a, b, c, d});
        cm.add(b);
    }
    cm.build();

    segtree<S, op, e> seg(cm.size());
    rep(qi, 0, q) {
        auto [t, p, c, d] = qs[qi];

        if (t == 0) {
            p = cm.get(p);
            seg.set(p, {c, d});
        } else {
            p = cm(p);
            c = cm(c);
            auto [a, b] = seg.prod(p, c);
            cout << a * d + b << '\n';
        }
    }
}