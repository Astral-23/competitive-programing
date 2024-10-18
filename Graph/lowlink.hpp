struct lowlink {
    using vi = vec<int>;
    using vvi = vec<vi>;
    using pii = pair<int, int>;

    int n;
    vvi tr;  // dfs木に使われる辺のみ 上から下
    vvi aux;  // dfs木に使われない辺のみ  下から上 自己辺もココ
    vi low, in, par;
    vec<pii> bridges;
    vec<int> joints;
    vec<bool> inner_is_joint;
    vec<int> self_edge_cnt;
    
    lowlink(const vvi &g)
        : n(g.size()),
          tr(n),
          aux(n),
          low(n, 1001001001),
          in(n, -1),
          par(n, -1),
          inner_is_joint(n, false),
          self_edge_cnt(n, 0) {
        int t = 0;
        int r = 0;
        auto dfs = [&](auto f, int v, int p) -> void {
            par[v] = p;
            in[v] = low[v] = t++;
            bool duplication = false;
            for (int to : g[v]) {
                if (in[to] == -1) {
                    tr[v].push_back(to);
                    f(f, to, v);
                } else {
                    if (to != p) {
                        if (in[to] < in[v])
                            aux[v].push_back(to);
                        else if (to == v) {
                            if ((++self_edge_cnt[v]) & 1) aux[v].push_back(to);
                        }
                        chmin(low[v], in[to]);
                    } else if (duplication == false)
                        duplication = true;
                    else {
                        aux[v].push_back(to);
                        chmin(low[v], in[to]);
                    }
                }
            }

            for (int to : tr[v]) {
                chmin(low[v], low[to]);
            }
            // 部分木について、low/inが求まった
            bool isjoint = false;
            for (int to : tr[v]) {
                if (low[to] > in[v]) bridges.emplace_back(v, to);
                if (low[to] >= in[v]) isjoint = true;
            }

            if (v != r && isjoint)
                joints.push_back(v), inner_is_joint[v] = true;
            else if (v == r) {
                if (tr[v].size() > 1)
                    joints.push_back(v), inner_is_joint[v] = true;
            }
        };

        rep(i, 0, n) if (in[i] == -1) {
            r = i;
            dfs(dfs, i, -1);
        }
    }

    bool is_bridge(int u, int v) {
        if (in[u] > in[v]) swap(u, v);
        if (par[v] != u) return false;
        if (low[v] > in[u])
            return true;
        else
            return false;
    }

    bool is_joint(int v) { return inner_is_joint[v]; }
};

/*
@brief lowlink
@docs doc/lowlink.md
*/