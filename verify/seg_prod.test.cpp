#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
//#include "../Datastructure/dynamicseg.hpp"
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
	int N, Q;
	cin >> N >> Q;
    vec<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i] >> B[i];
    vec<S> C(N);
    rep(i, 0, N) C[i] = S(A[i], B[i]);

    segtree<S, op, e> seg(C);


    while(Q--) {
        int t;
        cin >> t;
        if(t==0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.set(p, S(c, d));
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            auto [a, b] = seg.prod(l ,r);
            cout << (x * a + b).x << '\n';
        }
    }
   

}