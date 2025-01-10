#include "../Algorithm/superset_transform.hpp"
// i and j = k <-> i and j が k の superset (⇔ i, jがともにkのsuperset)
template<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_and_convolution(vec<S> A, vec<S> B) {
    ll lg = 1;
    while(A.size() > (1LL << lg)) lg++;
    while(B.size() > (1LL << lg)) lg++;
    A.resize(1LL << lg, zero());
    B.resize(1LL << lg, zero());

    vec<S> FA = superset_zeta_transform<S, op>(A, lg);
    vec<S> FB = superset_zeta_transform<S, op>(B, lg);
    rep(i, 0, 1 << lg) FA[i] *= FB[i];
    vec<S> f = superset_mobius_transform<S, op, inv>(FA, lg);
    return f;
}
//以降の項について、0である。