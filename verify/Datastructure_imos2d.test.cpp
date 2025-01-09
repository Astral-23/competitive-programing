#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja"
#include "../Utility/template.hpp"
#include "../Datastructure/imos2d.hpp"

int main() { 
    int n;
    cin >> n;
    imos2d<ll> sum(1001, 1001);

    rep(i, 0, n) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        sum.imos_add(sy, ty, sx, tx, 1);
    }

    sum.build();
    int ans = 0;
    rep(i, 0, 1001) {
        rep(j, 0, 1001){ 
            chmax(ans, sum.imos_get(i, j));
        }
    }

    cout << ans << endl;

}