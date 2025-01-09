#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1068"
#include "../Utility/template.hpp"

#include "../Datastructure/2dsegtree.hpp"

using S = int;
S op(S l, S r) {
    return min(l, r);
}

S e() {
    return INT_MAX;
}

int main() {
    int r, c, q;
    while(cin >> r >> c >> q) {
        if(r==0) break;

        vec<vec<int>> grid(r, vec<int>(c));
        rep(i, 0, r) rep(j, 0, c) cin >> grid[i][j];
    
        segtree2d<S, op, e> seg(r, c);
        rep(i, 0, r) rep(j, 0, c) seg.preset(i, j, grid[i][j]);
        seg.build();
        while(q--) {
            int sy, sx, ty, tx;
            cin >> sy >> sx >> ty >> tx;
            cout << seg.prod(sy, ty+1, sx, tx+1) << '\n';
        }
    }
}