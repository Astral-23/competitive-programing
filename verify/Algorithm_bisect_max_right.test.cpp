#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "../Utility/template.hpp"
#include "../Algorithm/bisect.hpp"
/*
n/x - n/(x+1) >= 1
⇔
n >= x(x+1)
*/
int main() {
    ll n;
    cin >> n;

    auto pred = [&](ll r) { return n >= __int128_t(r) * (r + 1); };

    ll x = max_right(0LL, n + 1, pred);
    x--;
    vec<ll> ans;
    rep(i, 1, x + 1) ans.push_back(n / i);

    for (ll i = n / (x + 1); i >= 1; i--) ans.push_back(i);

    reverse(all(ans));
    cout << ans.size() << endl;
    rep(i, 0, ans.size()) cout << ans[i] << " ";
}