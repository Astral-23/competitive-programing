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

int main() {
    int n;
    cin >> n;
    vec<mint> A(1 << n), B(1 << n);
    rep(i, 0, 1 << n) cin >> A[i];
    rep(i, 0, 1 << n) cin >> B[i];

    vec<mint> FA = superset_zeta_transform<S, op>(A, n);
    vec<mint> FB = superset_zeta_transform<S, op>(B, n);

    rep(i, 0, 1 << n) FA[i] *= FB[i];

    vec<mint> f = superset_mobius_transform<S, op, inv>(FA, n);

    rep(i, 0, 1 << n) cout << f[i] << " ";
    cout << endl;

}