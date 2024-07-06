#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B" 
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
    auto ans = llink.bridges;
    for(auto& [l, r] : ans) if(l > r) swap(l, r);
    sort(all(ans));
    for(auto [l, r] : ans) cout << l << " " << r << '\n';


}