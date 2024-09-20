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
    
    auto ok = [&](ll x) {
        return n >= __int128_t(x)*(x+1);
    };

    ll x = bisect(0LL, n + 1, ok);

    vec<ll> ans;
    rep(i, 1, x) ans.push_back(n / i);
   
    for(ll i = n/x; i >= 1; i--) ans.push_back(i);

    reverse(all(ans));
    cout << ans.size() << endl;
    rep(i, 0, ans.size()) cout << ans[i] <<" ";


}