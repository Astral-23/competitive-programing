#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"
using mint = modint998244353;
int main() {
    ll N, K;
    cin >> N >> K;
    Matrix<mint> A(N, N, 0);
    rep(i, 0, N) rep(j, 0, N) {
        cin >> A[i][j];
    }
    A = A.pow(K);
    rep(i, 0, N) {
        rep(j, 0, N) {
            cout << A[i][j].x << " ";
        }
        cout << '\n';
    }
}