#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../Utility/template.hpp"
#include "../Graph/graph.hpp"
int main() {
    ll n, m, r;
    cin >> n >> m >> r;
    Graph<ll, true> g(n);
    rep(i, 0, m) {
        ll s, t, w;
        cin >> s >> t >> w;
        g.add(s, t, w);
    }

    auto d = g.dijkstra(r);
    for(int i = 0; i < n; i++) {
        if(d[i] == Edge<ll>::INF) {
            cout << "INF" << endl;
        }
        else {
            cout << d[i] << endl;
        }
    }
}