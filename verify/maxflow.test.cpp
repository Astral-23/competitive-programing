#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja"
#include "../Utility/template.hpp"
#include "../Algorithm/maxflow.hpp"


int main() {
    
    int V, E;
    cin >>  V >> E;
    mf_graph<ll> flow(V);
    rep(i,0,E) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }

    ll res = flow.flow(0, V-1);
    cout << res << endl;
}