#include "../Utility/bigmodint.hpp"

struct Rhash {
    static const rhash brh;
    static vec<rhash> pw;
    static const int MAX_SIZE;
    int n;
    vec<rhash> H;

    static void initialize_pow() {
        pw.resize(MAX_SIZE + 1);
        pw[0] = 1;
        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }
    }

    Rhash() {
        if (pw.empty()) initialize_pow();
    }

    Rhash(string S) : n(S.size()) {
        if (pw.empty()) initialize_pow();
        H = vec<rhash>(n, 0);

        rep(i, 0, n) {
            H[i] += S[i];
            if (i) {
                H[i] += H[i - 1] * brh;
            }
        }
    }

    rhash prod(ll l, ll r) {
        assert(0 <= l && r <= n);
        if (l >= r) return 0;
        rhash res = H[r - 1];
        if (l) res -= H[l - 1] * pw[r - l];
        return res;
    }

    rhash get(int p) {
        return prod(p, p + 1);
    }

    pair<ll, ll> conv(ll l, ll r) {
        return make_pair(n - r, n - l);
    }
};

const rhash Rhash::brh = 200224;
const int Rhash::MAX_SIZE = 500000;
vec<rhash> Rhash::pw;

rhash connect(rhash mae, rhash usiro, ll len_of_usiro) {
    if (len_of_usiro <= Rhash::MAX_SIZE) {
        return mae * Rhash::pw[len_of_usiro] + usiro;
    } else {
        return mae * Rhash::brh.pow(len_of_usiro) + usiro;
    }
}

rhash rhash_pow(const rhash &x, const ll &y, ll len) {
    if (!y) return 0;
    rhash res = rhash_pow(x, y / 2, len);
    res = connect(res, res, (y / 2) * len);
    if(y & 1) res = connect(res, x, len);
    return res;
}

/*
@brief Rolling_hash
@docs doc/Rhash.md
*/