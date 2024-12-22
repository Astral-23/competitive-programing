#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../Utility/template.hpp"
#include <atcoder/all>
#include "../Fps/fps.hpp"

int main() {
    int n;
    cin >> n;
    vec<mint> A(n);
    rep(i, 0, n) {
        ll a;
        cin >> a;
        A[i] = a;
    }

    fps f(A);
    fps f_inv = f.inv();
    cout << f_inv << endl;

}