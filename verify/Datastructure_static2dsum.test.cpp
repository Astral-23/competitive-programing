#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include "../Utility/template.hpp"
#include "../Datastructure/static2dsum.hpp"

int main() {
    int h, w;
    cin >> h >> w;
    int k;
    cin >> k;
    static2dsum<ll> J(h, w);
    static2dsum<ll> O(h, w);
    static2dsum<ll> I(h, w);


    rep(i, 0, h) rep(j, 0, w) {
        char a;
        cin >> a;
        if(a=='J') J.add(i, j, 1);
        if(a=='O') O.add(i, j, 1);
        if(a=='I') I.add(i, j, 1);
    }

    J.build();O.build();I.build();


    while(k--) {
        int sy, sx, ty, tx;
        cin >> sy >> sx >> ty >> tx;
        sy--, sx--;
        cout << J.prod(sx, tx, sy, ty) << " ";
        cout << O.prod(sx, tx, sy, ty) << " ";
        cout << I.prod(sx, tx, sy, ty) << endl;

    }
	

}