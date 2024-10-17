#define PROBLEM "https://judge.yosupo.jp/submission/242966"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"


using mint = modint998244353;
using mat = Matrix<mint>;
int main() {
    ll n;
    cin >> n;
    mat S(n, n);
    rep(i, 0, n) rep(j, 0, n)cin>>S[i][j];
    cout << S.det() << endl;

    
   

}