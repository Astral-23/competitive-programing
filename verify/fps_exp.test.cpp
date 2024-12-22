#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
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
    fps f_exp = f.exp(n);
    cout << f_exp << endl;
}