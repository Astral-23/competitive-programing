template <class S,
          S (*op)(S, S),
          S (*e)(),
          S (*addroot)(S, int),
          class F,
          S (*mp)(F, S)>
struct TDP {
    using pif = pair<int, F>;
    using vs = vec<S>;
    using vvs = vec<vs>;

    int n;
    vec<vec<pif>> g;
    vvs dp;
    // dp[v][i] :=  (v → g[v][i])の辺について、
    // g[v][i]を根とする部分木の結果
    vs ans;

    TDP(int n) : n(n) {
        g.resize(n);
        dp = vvs(n);
        ans = vs(n, e());
    }

  private:
    S dfs(int v, int p) {
        S res = e();
        int d = g[v].size();
        dp[v].resize(d);
        rep(i, 0, d) {
            int to = g[v][i].first;
            if (to == p) continue;
            dp[v][i] = dfs(to, v);
            res = op(res, mp(g[v][i].second, dp[v][i]));
            // 部分木の結果を集約。
            // 本実装では辺を加味 ->
            // 部分木集約の順を徹底している(辻褄が合うならいつでも良い)
        }
        // 辺・頂点をaddした影響を反映したものを返す。
        return addroot(res, v);
    }

    void bfs(int v, S par, int p) {
        int d = g[v].size();
        rep(i, 0, d) if (g[v][i].first == p) dp[v][i] = par;
        // 親の結果を渡しておく。

        vs L(d + 1, e());
        vs R(d + 1, e());

        rep(i, 0, d) L[i + 1] = op(L[i], mp(g[v][i].second, dp[v][i]));
        rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i + 1]);
        // 本実装では辺を加味 ->
        // 部分木集約の順を徹底している(辻褄が合うならいつでも良い)

        ans[v] = addroot(L[d], v);
        // 辺・頂点をaddした影響を反映したものを返す。ansに格納する時だけ何か弄りたいならここを弄る。

        rep(i, 0, d) {
            int to = g[v][i].first;
            if (to == p) continue;
            S nx = op(L[i], R[i + 1]);
            // 本実装では辺を加味 ->
            // 部分木集約の順を徹底している(辻褄が合うならいつでも良い)

            bfs(to, addroot(nx, v), v);
            // to -> vの向きに辺・頂点をaddした影響を反映したものを返す。
        }
    }

  public:
    // s -> t に重みfの辺、 t -> sに重みhの辺
    void add_edge(int s, int t, F f, F h) {
        g[s].emplace_back(t, f);
        g[t].emplace_back(s, h);
    }

    vec<S> exe() {
        dfs(0, -1);
        bfs(0, e(), -1);
        return ans;
    }
};

/*
@brief 全方位木DP
@docs doc/treedp.md
*/