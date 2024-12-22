#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../Utility/template.hpp"
#include <atcoder/all>
#include "../Fps/fps.hpp"


int main() {
    ll n, m;
    cin >> n >> m;
    vec<mint> A(n);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        A[i] = a;
    }
    fps f(A);
    f = f.pow(m, n);
    cout << f << endl;
}