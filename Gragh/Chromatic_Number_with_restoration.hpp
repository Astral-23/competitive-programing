#include "../Convolution/bitwise_or_convolution.hpp"

using S = ll;
S op(S a, S b) { return a + b; }
S inv(S x) { return -x; }
S zero() { return 0; }

pair<int, vec<int>> chromatic_number(const vec<vec<int>> &g) {
    if (g.empty()) return {0, {}};
    int n = g.size();

    vec<vec<ll>> dps(1, vec<ll>(1 << n, 0));
    dps[0][0] = 1;

    vec<ll> dp(1 << n, -1);  // dp[i][S] := S は i 色彩色可能か？
    dp[0] = 1;
    rep(i, 0, n) dp[1 << i] = 1;

    rep(s, 0, 1 << n) if (dp[s] == -1) {
        int lat = -1;
        rep(i, 0, n) if (s >> i & 1) lat = i;

        int sub = s ^ (1 << lat);
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

    dps.push_back(dp);

    while (dps.back()[(1 << n) - 1] == 0) {
        dps.push_back(bitwise_or_convolution<S, op, inv, zero>(
            dps[1], dps[dps.size() - 1]));
        rep(i, 0, n) if (dps[dps.size() - 1][i] != 0) dps[dps.size() - 1][i] =
            1;
    }

    int K = dps.size() - 1;
    vec<int> res(n, -1);

    auto dfs = [&](auto f, int sup,
                   int l) -> void {  // 集合 Sを、 [l, K)を使って彩色。
        if (sup == 0) return;
        int sub = sup;
        do {
            if (dps[1][sub] && dps[K - l - 1][sup ^ sub]) {
                rep(i, 0, n) if (sub >> i & 1) res[i] = l;

                f(f, sup ^ sub, l + 1);
                break;
            }

            sub = (sub - 1) & sup;
        } while (sub != sup);
    };

    dfs(dfs, (1 << n) - 1, 0);

    return {K, res};
}
/*
@brief 彩色数(復元付き)
*/