#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja"
#include "../Utility/template.hpp"
#include "../Datastructure/2dsegtree.hpp"



using S = ll;
S op(ll l, ll r) {
    return l + r;
}

S e() {
    return 0LL;
}

int main() {
    int N;
    cin >> N;
    int H = 1000, W = 1000;
    segtree2d<S, op, e> seg(H+2, W+2);

    rep(i, 0, N) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        tx--, ty--;
        seg.set(ty + 1, tx + 1, seg.get(ty + 1, tx + 1) + 1);
        seg.set(sy, sx, seg.get(sy, sx) + 1);
        seg.set(ty + 1, sx, seg.get(ty + 1, sx) - 1);
        seg.set(sy, tx + 1, seg.get(sy, tx + 1) - 1);
    }

    ll ans = 0;
    rep(i, 0, H) rep(j, 0, W) chmax(ans, seg.prod(0, i+1, 0, j+1));
   
    cout << ans << endl;

}