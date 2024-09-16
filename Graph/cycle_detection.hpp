template <bool directed> struct cycle_detection {
    int n, ec;
    vector<vector<pair<int, int>>> g;
    cycle_detection(int n) : n(n), ec(0), g(n) {}

    void add_edge(int u, int v) {
        g[u].emplace_back(v, ec);
        if (directed == false) g[v].emplace_back(u, ec);
        ec++;
    }

    pair<vector<int>, vector<int>> run() {
        vector<bool> in(n, false);
        vector<bool> out(n, false);
        vector<int> vs;
        vector<int> es;
        const int fin = INT_MAX;
        auto dfs = [&](auto f, int v, int p) -> int {
            bool prev_edge = false;
            in[v] = true;

            for (auto [to, id] : g[v]) {
                if (to == p) {
                    if (directed == false) {
                        if (prev_edge == false) {
                            prev_edge = true;
                            continue;
                        } else {
                            vs.push_back(v);
                            es.push_back(id);
                            out[v] = true;
                            return to;
                        }
                    }
                }

                if (in[to] == true && out[to] == false) {
                    vs.push_back(v);
                    es.push_back(id);
                    out[v] = true;
                    return (v == to ? fin : to);
                }

                if (in[to] == false) {
                    int root = f(f, to, v);
                    if (root != -1 && root != fin) {
                        vs.push_back(v);
                        es.push_back(id);
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

        for (int i = 0; i < n; i++) {
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
};
