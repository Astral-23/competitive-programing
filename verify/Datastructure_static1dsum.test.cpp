#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../Utility/template.hpp"
#include "../Datastructure/static1dsum.hpp"



int main() {
    int n, q;
    cin >> n >> q;
    static1dsum<ll> sum1(n);


    rep(i, 0, n) {
        ll a;
        cin >> a;
        sum1.add(i, a);
    }

    sum1.build();

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum1.prod(l, r) << endl;
    }
    
}