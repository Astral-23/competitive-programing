template <typename T> struct Edge {
    int to;
    T cost;
    int id;
    static constexpr T INF = numeric_limits<T>::max() / 2;
    Edge(int to = 0, T cost = 1, int id = -1) : to(to), cost(cost), id(id) {}
};

template <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {
#define n int(this->size())
    using vector<vector<Edge<T>>>::vector;
    void add(int s, int t, T w = 1, int id = -1) {
        (*this)[s].emplace_back(t, w, id);
        if constexpr (directed == false) {
            (*this)[t].emplace_back(s, w, id);
        }
    }
#undef n
};

template <typename T> struct Tree : Graph<T, false> {
#define n int(this->size())
    using Graph<T, false>::Graph;
#undef n
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
        for (auto &e : g[i]) {
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
pair<vector<int>, vector<int>> cycle_detection(Graph<T, directed> const &g,
                                               int v = -1) {
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

// ret[v] := vを含む連結成分が
//  -1 : 二部グラフでない  0 : 色塗ったら0  1 : 色塗ったら1
// 　色塗りは0から始める
template <typename T, bool directed>
vector<int> bipartite_check(Graph<T, directed> const &g) {
    int n = g.size();
    vector<int> col(n, -1);
    vector<vector<int>> gs;

    auto dfs = [&](auto f, int v, int c, vector<int> &vs) -> void {
        col[v] = c;
        vs.push_back(v);
        for (auto &e : g[v])
            if (col[e.to] == -1) {
                f(f, e.to, c ^ 1, vs);
            }
    };

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            vector<int> vs;
            dfs(dfs, i, 0, vs);
            gs.push_back(vs);
        }
    }

    for (auto &vs : gs) {
        bool ng = false;
        for (auto v : vs) {
            for (auto &e : g[v]) {
                if (col[v] == col[e.to]) {
                    ng = true;
                }
            }
        }
        if (ng) {
            for (auto v : vs) col[v] = -1;
        }
    }

    return col;
}

#undef inf
};  // namespace Graph_lib

namespace Tree_lib {
#define inf Edge<T>::INF
template <typename T> vector<T> dist(Tree<T> const &tr, int s) {
    int n = tr.size();
    vector<T> res(n, inf);
    res[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &e : tr[v])
            if (chmin(res[e.to], res[v] + e.cost)) {
                que.push(e.to);
            }
    }
    return res;
}

template <typename T> vector<int> path(Tree<T> const &tr, int s, int t) {
    vector<int> res;
    auto dfs = [&](auto f, int v, int p = -1) -> bool {
        if (v == t) {
            return true;
        }

        for (auto &e : tr[v])
            if (e.to != p) {
                if (f(f, e.to, v)) {
                    res.push_back(e.to);
                    return true;
                }
            }
        return false;
    };

    dfs(dfs, s);
    res.push_back(s);
    reverse(res.begin(), res.end());
    return res;
}

// diam() ... (直径, (直径の端u, 直径の端v))
template <typename T> pair<T, pair<int, int>> diam(Tree<T> const &tr) {
    int n = tr.size();
    int u, v;
    T d, tmp;
    vector<T> ds = dist(tr, 0);
    tmp = ds[0], u = 0;
    for (int i = 1; i < n; i++) {
        if (chmax(tmp, ds[i])) u = i;
    }

    vector<T> ds2 = dist(tr, u);
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

// {直径0, 直径1 or -1}
template <typename T> pair<int, int> center(Tree<T> const &tr) {
    auto [d, p] = diam(tr);
    auto ph = path(tr, p.first, p.second);
    int m = (ph.size() + 1) / 2 - 1;
    if (ph.size() % 2 == 1)
        return {ph[m], -1};
    else
        return {ph[m], ph[m + 1]};
}

template <typename T>
vector<pair<int, int>> maximum_matching(Tree<T> const &tr) {
    vector<pair<int, int>> ret;
    auto dfs = [&](auto f, int v, int p) -> bool {
        bool used = false;
        for (auto &e : tr[v])
            if (e.to != p) {
                bool used_to = f(f, e.to, v);
                if (used_to == false && used == false) {
                    used = true;
                    ret.emplace_back(v, e.to);
                }
            }
        return used;
    };

    dfs(dfs, 0, -1);

    return ret;
}

//{存在するか、頂点のペアの集合}
template <typename T>
pair<bool, vector<pair<int, int>>> perfect_matching(Tree<T> const &tr) {
    if (tr.size() % 2 == 1) return {false, {}};

    auto match = maximum_matching(tr);
    if (match.size() * 2 == tr.size()) {
        return {true, match};
    } else {
        return {false, match};
    }
}
#undef inf
};  // namespace Tree_lib
