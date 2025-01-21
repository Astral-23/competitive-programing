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

    if (Graph_lib::has_negative_cycle(g)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    auto d = Graph_lib::warshall(g);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] == Edge<ll>::INF) {
                cout << "INF";
            } else {
                cout << d[i][j];
            }
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
}