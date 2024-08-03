#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0360?year=2017"

#include "../Utility/template.hpp"
#include "../Datastructure/imos1d.hpp"


int main() {
    imos1d<ll> imos(1001);
    int a, b;
    cin >> a >> b;
    imos.imos_add(a, b, 1);

    int n;
    cin >> n;
    while(n--) {
        int s, f;
        cin >> s >> f;
        imos.imos_add(s, f, 1);
    }

    imos.build();

    rep(i, 0, 1001) {
        if(imos[i] > 1) {
            cout << 1 << endl;
            exit(0);
        }
    }
    cout << 0 << endl;
    exit(0);
}