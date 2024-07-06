
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/matrix.hpp"
using mint = modint998244353;

int main() {
    int n = 3; 
    Matrix<mint>  mat(n, n, 3); // n * nで初期値が mint(0) の行列を生成

    mat[0][0] = 1; // (0, 0)成分を 1 に変更
    mat[0][1] += 10; //(0, 1)成分に 10　加算
    //mat[3][3] = 100; //配列外参照 assert 無し

    auto pow_mat = mat.pow(5); // matの 100 乗を受け取る。 matは破壊されない。

    auto print_vec = [](vec<vec<mint>> v) {
        rep(i, 0, v.size()) {
            rep(j, 0, v[i].size()) cout << v[i][j] << " ";
            cout << endl;
        }
    };

    print_vec(mat.dump());// dumpで返された二次元配列を出力
    print_vec(pow_mat.dump());// 5乗されている。

    Matrix<mint> v(n, 1, 1); //n * 1の行列。擬似的なベクトルとして扱える。

    Matrix<mint> res = mat * v;//行列同士の掛け算。行列累乗の際、このような処理を書くかもしれない。
    print_vec(res.dump());
    cout << res[0][0] << endl;

}
