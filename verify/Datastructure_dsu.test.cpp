#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../Utility/template.hpp"
#include "../Datastructure/dsu.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    while(Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t==0) {
            d.merge(u, v);
        }
        else {
            if(d.same(u, v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

    }
}