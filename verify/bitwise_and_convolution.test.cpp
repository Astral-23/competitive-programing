#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Convolution/bitwise_and_convolution.hpp"

using mint = modint998244353;

using S = mint;
S op(S l, S r) {
    return l + r;
}

S inv(S x) {
    return -1 * x;
}

S zero() {
    return 0;
}



int main() {
    int n;
    cin >> n;
    vec<mint> A(1 << n), B(1 << n);
    rep(i, 0, 1 << n) cin >> A[i];
    rep(i, 0, 1 << n) cin >> B[i];

    auto f = bitwise_and_convolution<S, op, inv, zero>(A, B);
    rep(i, 0, 1 << n) cout << f[i] << " ";
    cout << endl;

}