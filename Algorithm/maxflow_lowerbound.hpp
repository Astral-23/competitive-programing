struct mf_graph_with_lowerbound {
    int n;
    mf_graph<ll> mf;  // atcoder::mf_graphでも良い。
    int S, T;
    ll sum;
    vector<ll> lows, d;
    ll total_flow;

    mf_graph_with_lowerbound(int n)
        : n(n), mf(n + 2), S(n), T(n + 1), sum(0), d(n, 0), total_flow(0) {}

    int add_edge(int from, int to, ll low, ll high) {
        lows.push_back(low);
        d[from] -= low;
        d[to] += low;
        return mf.add_edge(from, to, high - low);
    }

    void build() {
        rep(i, 0, n) {
            if (d[i] > 0) {
                mf.add_edge(S, i, d[i]);
                sum += d[i];
            } else
                mf.add_edge(i, T, -d[i]);
        }
    }

    bool is_feasable(int s, int t) {
        build();
        mf.add_edge(t, s, LLONG_MAX / 4);  // INF = LLONG_MAX / 4
        total_flow += mf.flow(S, T);
        return total_flow == sum;
    }

    ll flow(int s, int t) {
        if (is_feasable(s, t) == false) return -1;
        mf.add_edge(S, s, LLONG_MAX / 4);
        mf.add_edge(t, T, LLONG_MAX / 4);
        return (total_flow += mf.flow(S, T)) - sum;
    }

    vector<ll> output() {  // not verified
        vector<ll> res;
        rep(i, 0, lows.size()) { res.push_back(lows[i] + mf.get_edge(i).flow); }
        return res;
    }
};