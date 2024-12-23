vector<mint> count_subset_sum(vector<ll> items, ll t) {
    mint ret = 1;
    vector<ll> cnt(t + 1, 0);
    vector<mint> inv(t + 1, 1);
    for (int i = 1; i <= t; i++) {
        inv[i] = inv[i - 1] * i;
    }
    inv[t] = inv[t].inv();
    for (int i = t - 1; i >= 0; i--) {
        mint tmp = inv[i];
        inv[i] = inv[i + 1] * (i + 1);
        inv[i + 1] = tmp * inv[i + 1];
    }

    for (auto w : items) {
        if (w > t) continue;
        if (w == 0) {
            ret *= 2;
        } else {
            cnt[w]++;
        }
    }

    fps f;
    for (int i = 1; i <= t; i++)
        if (cnt[i] != 0) {
            for (int k = 1; k * i <= t; k++) {
                if (k & 1) {
                    f[k*i] += inv[k] * cnt[i];
                } else {
                    f[k*i] -= inv[k] * cnt[i];
                }
            }
        }

    f = f.exp(t + 1);
    vector<mint> ans(t + 1, 1);
    for (int i = 0; i <= t; i++) {
        ans[i] = f[i] * ret;
    }
    return ans;
}