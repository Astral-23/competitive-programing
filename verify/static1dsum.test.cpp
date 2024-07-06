#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../Utility/template.hpp"
#include "../Datastructure/static1dsum.hpp"
#include "../Datastructure/static2dsum.hpp"


int main() {
    int n, q;
    cin >> n >> q;
    static1dsum<ll> sum1(n);
    static2dsum<ll> sum2(1, n);

    rep(i, 0, n) {
        ll a;
        cin >> a;
        sum1.add(i, a);
        sum2.add(0, i, a);
    }

    sum1.build();
    sum2.build();

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum1.prod(l, r) << endl;
        assert(sum1.prod(l, r) == sum2.prod(0, 1, l, r));
    }
    
}