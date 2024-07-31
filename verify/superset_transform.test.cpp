#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Algorithm/superset_transform.hpp"

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

template<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_and_convolution(vec<S> A, vec<S> B) {
    ll lg = 1;
    while(A.size() > (1LL << lg)) lg++;
    while(B.size() > (1LL << lg)) lg++;
    A.resize(1LL << lg, zero());
    B.resize(1LL << lg, zero());

    vec<mint> FA = superset_zeta_transform<S, op>(A, lg);
    vec<mint> FB = superset_zeta_transform<S, op>(B, lg);
    rep(i, 0, 1 << lg) FA[i] *= FB[i];
    vec<mint> f = superset_mobius_transform<S, op, inv>(FA, lg);
    return f;
}
//以降の項について、0である。

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