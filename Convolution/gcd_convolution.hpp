#include "../Math/sieve.hpp"
template<typename T>
vector<T> gcd_convolution(vector<T> A, vector<T> B) {
    if(A.empty() || B.empty()) return {};
    int n = min<int>(A.size(), B.size()) - 1;
    A.resize(n+1, 0); B.resize(n+1, 0);
    notlinear_sieve sieve(n);

    vector<T> mul_A = sieve.multiple_zeta_transform<T>(A);
    vector<T> mul_B = sieve.multiple_zeta_transform<T>(B);
    for(int i = 1; i <= n; i += 1) mul_A[i] *= mul_B[i];
    return sieve.multiple_mobius_transform<T>(mul_A);
}