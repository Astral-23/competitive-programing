#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../Utility/template.hpp"
#include "../atcoder/all"
#include "../Fps/fps.hpp"

int main() {
    ll n;
    cin >> n;

    vec<mint> A(n);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        A[i] = a;
    }
    fps f(A);
    fps f_log = f.log(n);
    cout << f_log << endl;
}