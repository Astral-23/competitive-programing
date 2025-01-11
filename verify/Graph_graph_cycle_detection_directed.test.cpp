#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../Utility/template.hpp"
#include "../Graph/graph.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    Graph<int, true> cyc(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        cyc.add_edge(u, v, 0, i);
    }
    auto [vs, es] = cyc.cycle_detection();
    if (vs.empty()) {
        cout << -1 << endl;
    } else {
        cout << vs.size() << endl;
        // cout << vs << endl;
        for (int id : es) {
            cout << id << endl;
        }
    }
}