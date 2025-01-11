#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja"
#include "../Utility/template.hpp"
#include "../Algorithm/bisect.hpp"

int main() {
    ll n;
    cin >> n;
    vector<ll> S(n);
    rep(i, 0, n) cin >> S[i];
    ll q;
    cin >> q;
    ll ans = 0;
    while(q--) {
        ll x;
        cin >> x;

        auto pred = [&](ll v) {
            return S[v] >= x;
        };

        auto l = min_left(0LL, n, pred);
        if(l == n || S[l] != x) {
        }
        else {
            ans++;
        }
    }
    cout << ans << endl;
}