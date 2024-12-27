#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../Utility/template.hpp"
#include "../Convolution/lcm_convolution.hpp"
#include "../Utility/modint.hpp"


using mint = modint998244353;
int main() {
    int n;
    cin >> n;
    vector<mint> A(n + 1), B(n + 1);
    rep(i, 1, n + 1) cin >> A[i];
    rep(i, 1, n + 1) cin >> B[i];
    auto ret = lcm_convolution<mint>(A, B);
    rep(i, 1, n + 1) cout << ret[i] << " ";
    cout << endl;


}