#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../Utility/template.hpp"
#include "../Datastructure/dynamicseg.hpp"
#include "../Datastructure/online2dseg.hpp"

using S = ll;
S op(S l, S r) {
    return l + r;
}

S e() {
    return 0LL;
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    online2dseg<S, op, e, int> seg(0, 1000000001, 0, 1000000001);
    map<int, map<int, ll>> val;

    rep(i, 0, N) {
        ll x, y, w;
        cin >> x >> y >> w;
        seg.apply(y, x, w);
    }

    while(Q--) {
        int t;
        cin >> t;
        if(t==0) {
            ll x, y, w;
            cin >> x >> y >> w;
            seg.apply(y, x, w);
        }
        else {
            ll l, d, r, u;
            cin >> l >> d >> r >> u;
            cout << seg.prod(d, u, l, r) << '\n';
        }
    }

}
