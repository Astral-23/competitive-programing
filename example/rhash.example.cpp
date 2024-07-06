#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

int main() {
    string s = "abc";
    Rhash S(s); //sのローリングハッシュを持つ構造体を宣言した。

    string t = "abcde";
    Rhash T(t);
    
    cout << S.get(0, 2) << endl; //s の [0, 2)、つまり"ab"に対応するハッシュを出力

    if(S.get(0, 3) == T.get(0, 3)) {
        cout << "一致" << endl;
    }

    if(S.get(0, 3) != T.get(2, 5)) {
        cout << "不一致" << endl;
    }

    if(S.get(0) == T.get(0)) {
        cout << "一致" << endl;
    }

    if(S.get(0) != T.get(1)) {
        cout << "不一致" << endl;
    }

    string k = "abcbd";
    string reverse_k = "dbcba";

    Rhash K(k);
    Rhash RK(reverse_k);

    auto[rl, rr] = K.conv(1, 4);//Kの[1, 4)は、そのreverse文字列のどこに対応するか

    if(K.get(1, 4) == RK.get(rl, rr)) {
        cout << "bcbは回文" << endl;
    }
}
