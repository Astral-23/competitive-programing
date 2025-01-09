#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include "../Utility/template.hpp"
#include "../Datastructure/2dbit.hpp"

int main() {
    int h, w;
    cin >> h >> w;
    int k;
    cin >> k;
    bit2d<ll> J(h, w);
    bit2d<ll> O(h, w);
    bit2d<ll> I(h, w);


    rep(i, 0, h) rep(j, 0, w) {
        char a;
        cin >> a;
        if(a=='J') J.add(i, j, 1);
        if(a=='O') O.add(i, j, 1);
        if(a=='I') I.add(i, j, 1);
    }



    while(k--) {
        int sy, sx, ty, tx;
        cin >> sy >> sx >> ty >> tx;
        sy--, sx--;
        cout << J.prod(sy, ty, sx, tx) << " ";
        cout << O.prod(sy, ty, sx, tx) << " ";
        cout << I.prod(sy, ty, sx, tx) << endl;

    }
	

}
