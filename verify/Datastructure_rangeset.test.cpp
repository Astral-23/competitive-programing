#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2880"
#include "../Utility/template.hpp"
#include "../Datastructure/rangeset.hpp"

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    using P = array<ll, 4>;

    rangeset<ll, false> rs;
    vec<P> es;
    rep(i, 0, m) {
        ll d, a, b;
        cin >> d >> a >> b;
        a--;
        es.push_back(P{d, 1, a, b});
    }

    rep(i, 0, q) {
        ll e, s, t;
        cin >> e >> s >> t;
        s--;
        es.push_back(P{e, -i, s, t});
    }

    sort(all(es));
    vec<ll> ans(q);
    for (auto [d, type, a, b] : es) {
        if (type != 1) {
            ll id = -type;
            if(a >= b - 1) ans[id] = true;
            else ans[id] = rs.same(a, b - 1);
        } else {
            rs.insert(a, b);
        }
    }

    rep(i, 0, q) {
        if (ans[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
