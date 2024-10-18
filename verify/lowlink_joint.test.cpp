#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A" 
#include "../Utility/template.hpp"
#include "../Graph/lowlink.hpp"

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
    set<int> J;
    for(int v : js) J.insert(v);
    rep(i, 0, v) {
        if(llink.is_joint(i)) assert(J.count(i));
        else assert(!(J.count(i)));
    }
    for(auto v : js) cout << v << endl;

}