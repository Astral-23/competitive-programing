struct doubling {
    int lg_t;
    static const int null = -1;
    vector<vector<int>> table;

    template <typename T> doubling(vector<T> nx, ll lim_t) {
        static_assert(std::is_arithmetic<T>::value,
                      "Error: T must be a numeric type");
        int n = nx.size();
        lg_t = 0;
        while (1LL << lg_t <= lim_t) lg_t++;
        table.resize(lg_t, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            table[0][i] = nx[i];
        }

        for (int k = 1; k < lg_t; k++) {
            for (int i = 0; i < n; i++) {
                if (table[k - 1][i] == null)
                    table[k][i] = null;
                else
                    table[k][i] = table[k - 1][table[k - 1][i]];
            }
        }
    }

    int jump(int k, ll t) const {
        for (int i = lg_t - 1; i >= 0; i--) {
            if ((t >> i) & 1 && k != null) k = table[i][k];
        }
        return k;
    }

    template <class F> pair<int, ll> max_right(int k, F pred) const {
        ll sum_t = 0;
        for (int i = lg_t - 1; i >= 0; i--) {
            int to = table[i][k];
            if (to == null) continue;
            if (pred(to) == true) {
                k = to;
                sum_t += 1LL << i;
            }
        }
        return make_pair(k, sum_t);
    }
};
