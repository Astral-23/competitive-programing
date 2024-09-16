#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../Utility/template.hpp"
#include "../Graph/cycle_detection.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    cycle_detection<true> cyc(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        cyc.add_edge(u, v);
    }
    auto [vs, es] = cyc.run();
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