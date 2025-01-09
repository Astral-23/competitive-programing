#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../Utility/template.hpp"
#include "../Datastructure/fastset.hpp"

int main() {
    fastset<4> cnt;
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) {
        char a;
        cin >> a;
        if(a == '1') cnt.insert(i);
    }

    while(q--) {
        int t, k;
        cin >> t >> k;

        if(t == 0) {
            cnt.insert(k);
        }
        else if(t == 1) {
            cnt.erase(k);
        }
        else if(t == 2) {
            if(cnt.count(k)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(t == 3) {
            cout << cnt.lower_bound(k) << '\n';
        }
        else {
            cout << cnt.lower_left_bound(k) << '\n';
        }

    }
}