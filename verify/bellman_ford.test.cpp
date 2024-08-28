#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Graph/min_distance.hpp"


int main() {
    
    
    int n, m, r;
    cin >> n >> m >> r;
    vec<vec<pair<long long, long long>>> g(n);
    rep(i, 0, m) {
        ll s, t, d;
        cin >> s >> t >> d;
        g[s].push_back({d, t});
    }
    min_distance<modint998244353> G(n, g);
    if(G.run_bellman_ford(r)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    else {
        for(ll x : G.distance()) {
            if(x == LLONG_MAX / 4) cout << "INF" << endl;
else             cout << x << endl;
        }
    }
}