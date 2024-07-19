#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615"
#include "../Utility/template.hpp"
#include "../Algorithm/maxflow.hpp"
#include "../Algorithm/maxflow_lowerbound.hpp"


using pll = pair<ll, ll>;

int main() {
    int n, m;
    while (1) {
        cin >> n >> m;

        if (n == 0) break;

        vector<pll> es;
        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            es.emplace_back(u, v);
        }

        int w = n + 100;
        int ans_m = -1;
        int ans_M = -1;

        rrep(mi, 0, m + 1) {
            rrep(Mi, 0, m + 1) if (mi <= Mi) {
                int s = n + m;
                int t = s + 1;

                mf_graph_with_lowerbound mf(t + 1);

                rep(i, 0, m) {
                    mf.add_edge(s, i, 1, 1);
                    mf.add_edge(i, m + es[i].first, 0, 1);
                    mf.add_edge(i, m + es[i].second, 0, 1);
                }

                rep(i, 0, n) { mf.add_edge(m + i, t, mi, Mi); }

                if (mf.is_feasable(s, t)) {
                    if (chmin(w, Mi - mi)) {
                        ans_m = mi;
                        ans_M = Mi;
                    }
                }
            }
        }

        cout << ans_m << " " << ans_M << endl;
    }
}