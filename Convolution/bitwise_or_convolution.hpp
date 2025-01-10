#include "../Algorithm/subset_transform.hpp"

// i or j = k <-> i or j が k の subset (⇔ i, jがともにkのsubset)
template<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S> A, vec<S> B) {
    ll lg = 1;
    while(A.size() > (1LL << lg)) lg++;
    while(B.size() > (1LL << lg)) lg++;
    A.resize(1LL << lg, zero());
    B.resize(1LL << lg, zero());

    vec<S> FA = subset_zeta_transform<S, op>(A, lg);
    vec<S> FB = subset_zeta_transform<S, op>(B, lg);
    rep(i, 0, 1 << lg) FA[i] *= FB[i];
    vec<S> f = subset_mobius_transform<S, op, inv>(FA, lg);
    return f;
}
//以降の項について、0である。