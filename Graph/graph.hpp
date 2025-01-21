template <typename T> struct Edge {
    int to;
    T cost;
    int id;
    static constexpr T INF = numeric_limits<T>::max() / 2;
    Edge(int to = 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id) {}
};

template <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {
#define n int(this->size())
#define inf Edge<T>::INF
    using vector<vector<Edge<T>>>::vector;

  private:
    bool chmin(T &x, T y) const { return x > y ? (x = y, true) : false; }
    bool chmax(T &x, T y) const { return x < y ? (x = y, true) : false; }

  public:
    void add(int s, int t, T w = 0, int id = -1) {
        (*this)[s].emplace_back(t, w, id);
        if constexpr (directed == false) {
            (*this)[t].emplace_back(s, w, id);
        }
    }

    
#undef n
#undef inf
};

template <typename T> struct Tree : Graph<T, false> {
#define n int(this->size())
#define inf Edge<T>::INF
    using vector<vector<Edge<T>>>::vector;

    vector<T> dist(int s) const {
        vector<T> res(n, inf);
        res[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &e : (*this)[v])
                if (chmin(res[e.to], res[v] + e.cost)) {
                    que.push(e.to);
                }
        }
        return res;
    }

    vector<Edge<T>> path(int s, int t) const {
        vector<Edge<T>> res;
        auto dfs = [&](auto f, int v, int p = -1) -> bool {
            if (v == t) {
                res.push_back(v);
                return true;
            }

            for (auto &e : (*this)[v])
                if (e.to != p) {
                    if (f(f, e.to, v)) {
                        res.push_back(e);
                        return true;
                    }
                }
            return false;
        };

        dfs(dfs, s);
        return res;
    }

    // diam() ... (直径, (直径の端u, 直径の端v))
    pair<T, pair<int, int>> diam() const {
        int u, v;
        T d, tmp;
        vector<T> ds = dist(0);
        tmp = ds[0], u = 0;
        for (int i = 1; i < n; i++) {
            if (chmax(tmp, ds[i])) u = i;
        }

        vector<T> ds2 = dist(u);
        d = ds2[0], v = 0;
        for (int i = 1; i < n; i++) {
            if (chmax(d, ds2[i])) v = i;
        }
        pair<T, pair<int, int>> res;
        res.first = d;
        res.second.first = u;
        res.second.second = v;
        return res;
    }

#undef n
#undef inf
};

namespace Graph_lib {

#define inf Edge<T>::INF
template <typename T, bool directed>
vector<T> DFS(Graph<T, directed> const &g, int s) {
    int n = g.size();
    assert(0 <= s && s < n);
    vector<T> d(n, inf);
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        for (auto &e : g[v]) {
            assert(e.cost == 1);
            if (chmin(d[e.to], d[v] + e.cost)) {
                que.push(e.to);
            }
        }
    }
    return d;
}

template <typename T, bool directed>
vector<T> dijkstra(Graph<T, directed> const &g, int s) {
    int n = g.size();
    vector<T> d(n, inf);
    d[s] = 0;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>
        que;
    que.push({d[s], s});
    while (que.empty() == false) {
        auto [c, v] = que.top();
        que.pop();
        if (d[v] < c) continue;
        for (auto &e : g[v]) {
            assert(e.cost >= 0);
            if (chmin(d[e.to], d[v] + e.cost)) {
                que.push({d[e.to], e.to});
            }
        }
    }
    return d;
}

template <typename T, bool directed>
pair<bool, vector<T>> bellman_ford(Graph<T, directed> const &g, int s) {
    int n = g.size();
    vector<T> d(n, inf);
    d[s] = 0;
    int last = -1;
    for (int i = 0; i <= n; i++) {
        bool f = false;
        for (int v = 0; v < n; v++)
            if (d[v] != inf) {
                for (auto &e : g[v]) {
                    if (chmin(d[e.to], d[v] + e.cost)) {
                        f = true;
                    }
                }
            }
        if (f) last = i;
    }

    if (last == n)
        return {true, d};
    else
        return {false, d};
}

template <typename T, bool directed>
bool has_negative_cycle(Graph<T, directed> const &g) {
    if (g.size() == 0) return false;
    auto [f, d] = bellman_ford(g, 0);
    return f;
}

template <typename T, bool directed>
vector<vector<T>> warshall(Graph<T, directed> const &g) {
    int n = g.size();
    vector<vector<T>> d(n, vector<T>(n, inf));
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
        for (auto& e : g[i]) {
            chmin(d[i][e.to], e.cost);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i][k] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (d[k][j] == inf) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

template <typename T, bool directed>
pair<vector<int>, vector<int>> cycle_detection(Graph<T, directed> const &g, int v = -1) {
    int n = g.size();
    vector<bool> in(n, false), out(n, false);
    vector<int> vs, es;
    const int fin = INT_MAX;
    auto dfs = [&](auto f, int v, int p) -> int {
        bool prev_edge = false;
        in[v] = true;
        for (auto e : g[v]) {
            if constexpr (directed == false) {
                if (e.to == p) {
                    if (prev_edge == false) {
                        prev_edge = true;
                        continue;
                    } else {
                        vs.push_back(v);
                        es.push_back(e.id);
                        out[v] = true;
                        return e.to;
                    }
                }
            }

            if (in[e.to] && out[e.to] == false) {
                vs.push_back(v);
                es.push_back(e.id);
                out[v] = true;
                return v == e.to ? fin : e.to;
            }

            if (in[e.to] == false) {
                int root = f(f, e.to, v);
                if (root != -1 && root != fin) {
                    vs.push_back(v);
                    es.push_back(e.id);
                    out[v] = true;
                    return (v == root ? fin : root);
                } else if (root == fin) {
                    out[v] = true;
                    return fin;
                }
            }
        }
        out[v] = true;
        return -1;
    };

    int s = 0, t = n;
    if (v != -1) s = v, t = v + 1;

    for (int i = s; i < t; i++) {
        if (in[i] == false) {
            dfs(dfs, i, -1);
            if (vs.empty() == false) {
                reverse(vs.begin(), vs.end());
                reverse(es.begin(), es.end());
                return make_pair(vs, es);
            }
        }
    }
    return make_pair(vs, es);
}
#undef inf
}; 


