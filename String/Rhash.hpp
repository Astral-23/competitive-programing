#include "../Utility/bigmodint.hpp"


const ll brh = 2312312;
vec<rhash> pw(5000001, 1);

struct Rhash {
    int n;
    vec<rhash> H;

    TT Rhash(T S) : n(S.size()) {
        H = vec<rhash>(n, 0);
        pw[0] = 1;

        rep(i, 0, n) {
            H[i] += S[i];
            if(i) {
                H[i] += H[i-1] * brh;
                pw[i] = pw[i-1] * brh;
            }
        }
    }

    rhash get(int l, int r) {
        assert(0 <= l && r <= n);
        if(l >= r) return 0;
        rhash res = H[r-1];
        if(l) res -= H[l-1] * pw[r-l];
        return res;
    }

    rhash get(int p) {
        return get(p, p+1);
    }

    //reverseしたハッシュを逆方向として、正方向の[l, r)と対応する逆方向の区間を返す。
    //回文判定に使う。

    pair<int, int> conv(int l, int r) {
        return make_pair(n - r, n - l);
    }


    //要素追加したい時
    TT void push_back(T &h) {
        n++;
        H.resize(n);
        pw[n-1] = pw[n-2] * brh;
        H[n-1] = h + H[n-2] * brh;
    }
    
};


//ハッシュの結合
rhash unit(rhash mae, rhash usiro, int len_of_usiro) {
    return mae * pw[len_of_usiro] + usiro;
}

/*
@brief Rolling_hash
@docs doc/Rhash.md
*/