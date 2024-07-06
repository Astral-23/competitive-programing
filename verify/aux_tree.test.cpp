#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0439"
#include "../Utility/template.hpp"
#include "../Algorithm/hld.hpp"

const int inf = 1001001001;
int main() {
    int n;
    cin >> n;
    vec<int> C(n);
    rep(i, 0, n) cin >> C[i], C[i]--;
    vec<vec<int>> G(n);
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vec<vec<int>> dp(n);
    vec<int> ans(n, inf);
    HLD hld(G, 0);

    vec<vec<int>> cv(n);
    rep(i, 0, n) cv[C[i]].push_back(i);

    vec<vec<int>> g(n);

    rep(c, 0, n) {
        int r = hld.aux_tree(cv[c], g);
        if(r == -1) continue;

        auto dfs = [&](auto f, int v, int p) -> int {
            int res = inf;
            int d = g[v].size();
            dp[v].resize(d);
            
            rep(i, 0, d) {
                int to = g[v][i];
                if(to == p) continue;
                dp[v][i] = f(f, to, v);
                int nw = dp[v][i] + hld.dist(v, to);//ここで到達済み
                chmin(res, nw);
            }
            //res++;
            if(C[v] == c) res = 0;
            return res;
        };

        auto bfs = [&](auto f, int v,  int par, int p) -> void {
            int d =  g[v].size();
            rep(i, 0, d) if(g[v][i] == p) dp[v][i] = par;

            vec<int> L(d+1, inf);
            vec<int> R(d+1, inf);
            rep(i, 0, d) {
                int nw = dp[v][i] + hld.dist(v, g[v][i]);
                L[i+1] = min(L[i], nw);
            }

            rrep(i, 0, d) {
                int nw = dp[v][i] + hld.dist(v, g[v][i]);
                R[i] = min(R[i+1], nw);
            }

            if(C[v] == c) {
                ans[v] = L[d];
            }

            rep(i, 0, d) {
                int to = g[v][i];
                if(to == p) continue;
                int nx = min(L[i], R[i+1]);
                if(C[v] == c) nx = 0;
                f(f, to, nx, v);
            }
        };

        dfs(dfs, r, -1);
        bfs(bfs, r, inf, -1);
        hld.clean(g);
    }

    rep(i, 0, n) cout << ans[i] << '\n';
        

}