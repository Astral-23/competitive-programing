#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "../Utility/template.hpp"
#include "../atcoder/all"
#include "../Fps/fps.hpp"
#include "../Fps/count_subset_sum.hpp"


int main() {
    ll n, t;
    cin >> n >> t;
    vec<ll> items(n);
    rep(i, 0, n) cin >> items[i];
    auto ret = count_subset_sum(items, t);
    rep(i, 1, t + 1) {
        cout << ret[i].val() << " ";
    }
    cout << endl;
}