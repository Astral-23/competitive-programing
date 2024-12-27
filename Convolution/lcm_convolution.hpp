#include "../Math/sieve.hpp"
template <typename T>
vector<T> lcm_convolution(vector<T> A, vector<T> B) {
    if (A.empty() || B.empty()) return {};
    int n = max<int>(A.size(), B.size()) - 1;
    notlinear_sieve sieve(n);
    A.resize(n + 1, 0);
    B.resize(n + 1, 0);
    vector<T> div_A = sieve.divisor_zeta_transform<T>(A);
    vector<T> div_B = sieve.divisor_zeta_transform<T>(B);
    for(int i = 1; i <= n; i += 1) {
        div_A[i] *= div_B[i];
    }
    return sieve.divisor_mobius_transform<T>(div_A);
}