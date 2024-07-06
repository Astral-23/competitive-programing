template<class S, S (*op)(S, S), S (*e)(), S (*addroot)(S, int),  class F, S (*mp)(F, S)> struct TDP {
    using pif = pair<int, F>;
    using vs = vec<S>;
    using vvs = vec<vs>;

    int n;
    vec<vec<pif>> g;
    vvs dp; //dp[now][i] :=  (now → g[r][i])の辺について、 g[r][i]を根とする部分木の結果
    vs ans; 

    TDP(int N) : n(N) {
        g.resize(n);
        dp = vvs(n);
        ans = vs(n, e());
    }
    
    //1から書く場合に必要な部分↓
    S dfs(int v, int p) {//普通に木DPするパート
        S res = e();//
        int d = g[v].size();
        dp[v].resize(d);
        rep(i, 0, d) {
            int to = g[v][i].first;
            if(to == p) continue;
            dp[v][i] = dfs(to, v);
            res = op(res, mp(g[v][i].second, dp[v][i])); //部分木の結果を集約。
            //本実装ではこの段階で辺の影響を加算しているが、辻褄が合うならいつでも良い。
        }
        //辺・頂点をaddした影響を反映したものを返す。つまり、「ｖを根とする部分木 / vをlcaとするパスの結果」を返す。
        return addroot(res, v);
    }

    void bfs(int v, S par, int p) {
        int d = g[v].size();
        rep(i, 0, d) if(g[v][i].first == p) dp[v][i] = par;//親の結果を渡しておく。

        vs L (d + 1, e());
        vs R (d + 1, e());

        rep(i, 0, d) L[i+1] = op(L[i], mp(g[v][i].second, dp[v][i])); //本実装ではこの段階で辺の影響を加算しているが、辻褄が合うならいつでも良い。
        rrep(i, 0, d) R[i] = op(mp(g[v][i].second, dp[v][i]), R[i+1]);

        ans[v] = addroot(L[d], v);//辺・頂点をaddした影響を反映したものを返す。つまり、「ｖを根とする部分木 / vをlcaとするパスの結果」を返す。

        rep(i, 0, d) {
            int to = g[v][i].first;
            if(to == p) continue;
            S nx = op(L[i], R[i+1]);//本実装ではこの段階で辺の影響を加算しているが、辻褄が合うならいつでも良い。
            bfs(to, addroot(nx, v), v);//辺・頂点をaddした影響を反映したものを返す。つまり、「to→ｖについて、vを根とする部分木 / vをlcaとするパスの結果」を返す。
        }

    }

    //1から書く場合に必要な部分

    void add_edge(int s, int t, F f) {
        g[s].emplace_back(t, f);
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