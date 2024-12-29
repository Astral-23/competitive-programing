#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"
using mint = modint998244353;

int main() {
    int h, w;
    cin >> h >> w;
    Matrix<mint> mat(h, w);
    rep(i, 0, h) rep(j, 0, w) cin >> mat[i][j];
    cout << mat.rank() << endl;
}