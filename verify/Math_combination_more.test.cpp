#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"
#include "../Utility/template.hpp"
#include "../atcoder/all"
#include "../Utility/modint.hpp"
#include "../Math/combination.hpp"



using pll = pair<long long, long long>;
using mint = modint<1'00'000'007>;
//グリッドで → から半時計 注 : 座標だと→から時計回り
vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1, 0};
vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1, 0};

int main() {
    combination<mint, 1'00'000'007> cmb;
    ll h, w, sy, sx, ty, tx;
    cin >> h >> w >> sy >> sx >> ty >> tx;
    map<ll, vec<pll>> tar;
    rep(k, 0, 9) {
        ll ny = ty + dy[k] * h;
        ll nx = tx + dx[k] * w;
        tar[abs(sx - nx) + abs(ny - sy)].emplace_back(nx, ny);
    }

    mint ret = 0;

    auto v = *tar.begin();
    for(auto [x, y] : v.second) {
         ret += cmb(abs(sx - x) + abs(sy - y), abs(sx - x));

    }
   
    cout << ret << endl;


}