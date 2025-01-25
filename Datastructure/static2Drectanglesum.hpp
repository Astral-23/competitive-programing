template <typename T> struct static2Drectunglesum {
    using node_t = pair<long long, T>;

    vector<long long> xs, ys, nxs;  // 点の情報(indexベースで扱うと便利)
    vector<T> ws;
    vector<vector<T>> sum;

    bool built = false;

    int n;
    vector<vector<node_t>> dat;

  private:
    int get(long long x) const {
        return lower_bound(nxs.begin(), nxs.end(), x) - nxs.begin();
    }

  public:
    void init() {
        assert(built == false);
        built = true;
        sort(all(nxs));
        nxs.erase(unique(all(nxs)), nxs.end());
        n = nxs.size();
        dat.resize(n);
        sum.resize(n);

        for (int i = 0; i < int(xs.size()); i++) {
            int id = get(xs[i]);
            id++;
            while (id <= n) {
                dat[id - 1].emplace_back(ys[i], ws[i]);
                id += id & -id;
            }
        }

        for (int i = 0; i < n; i++) {
            sort(dat[i].begin(), dat[i].end(),
                 [](const node_t &a, const node_t &b) {
                     return a.first < b.first;
                 });
        }

        for (int i = 0; i < int(dat.size()); i++) {
            if (dat[i].size() == 0) continue;
            sum[i].resize(dat[i].size() + 1, 0);
            for (int j = 1; j <= int(dat[i].size()); j++) {
                sum[i][j] = sum[i][j - 1] + dat[i][j-1].second;
            }
        }
    }
      T prod(long long r, long long sy, long long ty) const {
        assert(built);
        T res = T();
        while (r > 0) {
            int li = lower_bound(dat[r - 1].begin(), dat[r - 1].end(),
                                 node_t{sy, -1},
                                 [&](const node_t &a, const node_t &b) {
                                     return a.first < b.first;
                                 }) -
                     dat[r - 1].begin();
            int ri = lower_bound(dat[r - 1].begin(), dat[r - 1].end(),
                                 node_t{ty, -1},
                                 [&](const node_t &a, const node_t &b) {
                                     return a.first < b.first;
                                 }) -
                     dat[r - 1].begin();
            res += sum[r - 1][ri];
            res -= sum[r - 1][li];
            r -= r & -r;
        }
        return res;
    }

    T prod(long long sx, long long tx, long long sy, long long ty) const {
        assert(built);
        int l = get(sx);
        int r = get(tx);
        return prod(r, sy, ty) - prod(l, sy, ty);
    }

    void add(long long x, long long y, T w) {
        assert(built == false);
        xs.push_back(x);
        ys.push_back(y);
        ws.push_back(w);
        nxs.push_back(x);
    }
};
