#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../Utility/template.hpp"
#include "../Graph/graph.hpp"
int main() {
    ll n, m;
    cin >> n >> m;
    Graph<ll, true> g(n);
    rep(i, 0, m) {
        ll s, t, w;
        cin >> s >> t >> w;
        g.add(s, t, w);
    }

    if (g.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    auto d = g.warshall();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == Edge<ll>::inf) {
                cout << "INF";
            } else {
                cout << d[i][j];
            }
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
}