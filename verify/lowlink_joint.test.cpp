#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A" 
#include "../Utility/template.hpp"
#include "../Algorithm/lowlink.hpp"

int main() {
    int v, e;
    cin >> v >> e;
    vec<vec<int>> g(v);
    rep(i, 0, e) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }

    lowlink llink(g);
    auto js = llink.joints;
    sort(all(js));
    for(auto v : js) cout << v << endl;

}