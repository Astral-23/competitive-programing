#include "../Utility/modint.hpp"

using mint = modint998244353;
int chromatic_number(const vec<vec<int>> &g) {
    if (g.empty()) return 0;
    int n = g.size();

    vec<mint> dp(1LL << n, -1);  // dp[i][S] := S は i 色彩色可能か？
    dp[0] = 1;
    rep(i, 0, n) dp[1LL << i] = 1;

    rep(s, 0, 1LL << n) if (dp[s] == -1) {
        int lat = -1;
        rep(i, 0, n) if (s >> i & 1) lat = i;

        ll sub = s ^ (1LL << lat);
        if (dp[sub] == 0) {
            dp[s] = 0;
            continue;
        }

        bool ng = false;
        for (int to : g[lat])
            if (s >> to & 1) ng = true;

        if (ng)
            dp[s] = 0;
        else
            dp[s] = 1;
    }

    if(dp[(1 << n) - 1] != 0) {
        return 1;
    }

    vec<mint> DP = dp;


    rep(i, 0, n) {
        rep(s, 0, 1LL << n) {
            if((s & (1 << i)) != 0) { // if i in s
                DP[s] += DP[s ^ (1 << i)];
            }
        }
    }


    vec<mint> DPK = DP;

    rep(k, 2, n + 1) {
        rep(i, 0, 1 << n) DPK[i] *= DP[i];
        mint v = 0;
        ll sup = (1LL << n) - 1;
        rep(s, 0, 1LL << n) {
            if(__builtin_popcountll(sup ^ s)%2 == 0) v += DPK[s];
            else v -= DPK[s];
        }
        if(v != 0) return k;
        else continue;
    }
    return -1;
}


