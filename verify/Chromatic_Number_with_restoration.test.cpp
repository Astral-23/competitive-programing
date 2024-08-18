#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "../Utility/template.hpp"
#include "../Gragh/Chromatic_Number_with_restoration.hpp"

int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [ans, col] = chromatic_number(g);

    vec<int> cnt(ans, 0);

    rep(i, 0, n) {
        assert(0 <= col[i]);
        assert(col[i] < ans);
        cnt[col[i]]++;
        for(int to : g[i]) {
            assert(col[i] != col[to]);
        }
    }

    rep(i, 0, ans) assert(cnt[i] != 0);

    cout << ans << endl;

}