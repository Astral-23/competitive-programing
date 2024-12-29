#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"
using mint = modint998244353;

int main() {
    ll n;
    cin >> n;
    Matrix<mint> mat(n, n);
    rep(i, 0, n) rep(j, 0, n) cin >> mat[i][j];
    auto [ret, exi] = mat.inv();
    if(exi == false) {
        cout << -1 << endl;
    }
    else {
        cout << ret << endl;
    }
}