template <typename T> struct min_distance {
    using pll = pair<ll, ll>;

  private:
    int n, s;
    vec<vec<pll>> g;
    vec<ll> dist;
    vec<T> cnt;
    vec<int> pre;
    int built;
    ll inf = LLONG_MAX / 4;

    void init() {
        fill(all(dist), inf);
        fill(all(cnt), 0);
        fill(all(pre), -1);
    }

  public:
    min_distance(int n) : n(n), dist(n), cnt(n), pre(n), built(0) {};
    min_distance(int n, vec<vec<pll>> &g)
        : n(n), g(g), dist(n), cnt(n), pre(n), built(0) {}

    void add_edge(int from, int to, ll cost) { g[from].emplace_back(cost, to); }

    void run_dijkstra(int S) {
        built = 1;
        init();
        s = S;
        dist[s] = 0;
        cnt[s] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            que;
        que.push({dist[s], s});
        while (que.empty() == false) {
            auto [c, v] = que.top();
            que.pop();
            if (dist[v] < c) continue;
            for (auto [cost, to] : g[v]) {
                if (chmin(dist[to], cost + c)) {
                    cnt[to] = cnt[v];
                    pre[to] = v;
                    que.push({dist[to], to});

                } else if (dist[to] == cost + c) {
                    cnt[to] += cnt[v];
                }
            }
        }
    }

    bool run_bellman_ford(int S) {
        built = 2;
        init();
        s = S;
        dist[s] = 0;
        cnt[s] = 1;
        int last = -1;
        rep(i, 0, n) {
            bool found = false;
            rep(v, 0, n) if(dist[v] != inf) {
                for (auto [cost, to] : g[v]) {
                    if (chmin(dist[to], dist[v] + cost)) {
                        found = true;
                        pre[to] = v;
                    }
                }
            }
            if(found) last = i;
        }

        if(last == n - 1) return true;
        return false;
    }

    vec<ll> distance() {
        assert(built != 0);
        return dist;
    }

    vec<T> count_path() {
        assert(built == 1);
        return cnt;
    }

    vec<int> path(int t) {
        assert(built != 0);
        vec<int> res;
        while (1) {
            res.push_back(t);
            if (t == s) break;
            t = pre[t];
        }
        reverse(all(res));
        return res;
    }
};
/*
@brief 最短経路
@docs doc/min_distance.md

*/