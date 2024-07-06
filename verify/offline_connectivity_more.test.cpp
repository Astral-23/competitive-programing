#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235&lang=jp"
#include "../Utility/template.hpp"
#include "../Datastructure/undabledsu.hpp"
#include "../Datastructure/offline_connectivity.hpp"


bool f(dsu &uf, pair<int,int> p) {
    return uf.same(p.first, p.second);
}
int main() {
    int n, k;
    cin >> n >> k;
    offline_connectivity<dsu, bool, pair<int, int>, false> uf(n);
    while(k--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            uf.link(u, v);
        }
        else if(t == 2) {
            uf.cut(u, v);
        }
        else {
            uf.query(make_pair(u, v));
        }
    }
    uf.build();
    auto res = uf.run(f);
    for(bool e : res) {
        if(e) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}