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

        int ans_m = -1;
        int ans_M = -1;

        auto che = [&](int mi, int Mi) {
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
                return true;
            } else
                return false;
        };

        ll w = 1e7;
        rrep(mi, 0, n + 1) {
            ll li = 0;
            ll ri = li + min<ll>(w, m);
            while (li < ri) {  /// xxxxoooo
                ll mid = (li + ri) / 2;
                if (che(mi, mi + mid)) {
                    ri = mid;
                } else {
                    li = mid + 1;
                }
            }
            if (che(mi, mi + li) && chmin(w, li - mi)) {
                ans_m = mi;
                ans_M = mi + li;
            }
        }

        cout << ans_m << " " << ans_M << endl;
    }
}