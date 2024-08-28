#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Graph/min_distance.hpp"

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    vec<vec<pair<ll, ll>>> g(n);
    rep(i, 0, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
    min_distance<modint998244353> G(n, g);

   
    G.run_dijkstra(s);
    auto dist = G.distance();

   
    if (dist[t] == LLONG_MAX / 4) {
        cout << -1 << endl;
        return 0;
    }

    auto ps = G.path(t);
    cout << dist[t] << " " << ps.size() - 1 << '\n';

    rep(i, 0, ps.size() - 1) { cout << ps[i] << " " << ps[i + 1] << '\n'; }
    cout << endl;
}