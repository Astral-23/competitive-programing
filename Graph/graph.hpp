template <typename T> struct Edge {
    int to;
    T cost;
    int id;
    static constexpr T inf = numeric_limits<T>::max() / 2;
    Edge(int to = 0, T cost = 0, int id = -1) : to(to), cost(cost), id(id) {}
};

template <typename T, bool directed> struct Graph : vector<vector<Edge<T>>> {
    using vector<vector<Edge<T>>>::vector;

  private:
    bool chmin(T &x, T y) const { return x > y ? (x = y, true) : false; }

  public:
    void add(int s, int t, T w) { add_edge(s, t, w); }
    void add_edge(int s, int t, T w) {
        (*this)[s].emplace_back(t, w);
        if constexpr (directed == false) {
            (this)[t].emplace_back(s, w);
        }
    }

    vector<T> dfs(int s) const {
        assert(0 <= s && s < this->size());
        vector<T> d(this->size());
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while (que.empty() == false) {
            int v = que.front();
            que.pop();
            for (auto e : (*this)[v]) {
                assert(e.cost == 1);
                if (chmin(d[e.to], d[v] + e.cost)) {
                    que.push(e.to);
                }
            }
        }
    }

    vector<T> dijkstra(int s) const {
        vector<T> d(this->size(), Edge<T>::inf);
        d[s] = 0;
        priority_queue<pair<T, int>, vector<pair<T, int>>,
                       greater<pair<T, int>>>
            que;
        que.push({d[s], s});
        while (que.empty() == false) {
            auto [c, v] = que.top();
            que.pop();
            if (d[v] < c) continue;
            for (auto e : (*this)[v]) {
                assert(e.cost >= 0);
                if (chmin(d[e.to], d[v] + e.cost)) {
                    que.push({d[e.to], e.to});
                }
            }
        }
        return d;
    }

    pair<bool, vector<T>> bellman_ford(int s) const {
        vector<T> d(this->size(), Edge<T>::inf);
        d[s] = 0;
        int last = -1;
        for (int i = 0; i <= int(this->size()); i++) {
            bool f = false;
            for (int v = 0; v < int(this->size()); v++)
                if (d[v] != Edge<T>::inf) {
                    for (auto e : (*this)[v]) {
                        if (chmin(d[e.to], d[v] + e.cost)) {
                            f = true;
                        }
                    }
                }
            if (f) last = i;
        }

        if (last == int(this->size()))
            return {true, d};
        else
            return {false, d};
    }

    bool has_negative_cycle() const {
        if (this->size() == 0) return false;
        auto [f, d] = bellman_ford(0);
        return f;
    }

    vector<vector<T>> warshall() const {
        vector<vector<T>> d(this->size(),
                            vector<T>(this->size(), Edge<T>::inf));
        for (int i = 0; i < int(this->size()); i++) {
            d[i][i] = 0;
            for (auto e : (*this)[i]) {
                chmin(d[i][e.to], e.cost);
            }
        }

        for (int k = 0; k < int(this->size()); k++) {
            for (int i = 0; i < int(this->size()); i++) {
                if (d[i][k] == Edge<T>::inf) continue;
                for (int j = 0; j < int(this->size()); j++) {
                    if (d[k][j] == Edge<T>::inf) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        return d;
    }
};
