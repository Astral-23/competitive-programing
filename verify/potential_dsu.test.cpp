#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
#include "../Utility/template.hpp"
#include "../Datastructure/potential_dsu.hpp"

int main() {
    int N, M;
    while(cin >> N >> M) {
        if(N==0) break;
        potential_dsu<ll> uf(N, 1);
        rep(i, 0, M) {
            char c;
            cin >> c;
            int a, b, w;
            if(c == '!') {
                cin >> a >> b >> w;
                --a, --b;
                uf.merge(a, b, w);
            }
            else {
                cin >> a >> b;
                --a, --b;
                if(!uf.same(a, b)) cout << "UNKNOWN" << endl;
                else cout << uf.diff(a, b) << endl;
            }
        }
    }
    
}