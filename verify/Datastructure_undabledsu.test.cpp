#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../Utility/template.hpp"
#include "../Datastructure/undabledsu.hpp"



int main() {
    int N, Q;
    cin >> N >> Q;
    dsu o(N);
    vector<vector<vector<int>>> ivs(Q+1);

    rep(qi, 0, Q) {
        int t, k, u, v;
        cin >> t >> k >> u >> v;
        k++;
        ivs[k].push_back({t, int(qi)+1, u, v});
       
    }

    vector<int> ans(Q+1, -1);

    auto dfs = [&](auto f, int k, dsu& d) -> void {
        for(auto a : ivs[k]) {
            if(a[0] == 1) {
                if(d.same(a[2], a[3])) ans[a[1]-1] = 1;
                else ans[a[1]-1] = 0;
                continue;
            }
            else {
                d.merge(a[2], a[3]);
                f(f, a[1], d);
                d.undo();
            }
        }
    };


    dfs(dfs, 0, o);
    rep(qi,0 ,Q) if(ans[qi] != -1) cout << ans[qi] << '\n';
}