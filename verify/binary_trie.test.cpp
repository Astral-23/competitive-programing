#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../Utility/template.hpp"
#include "../Datastructure/binarytrie.hpp"

int main() {
    binary_trie<int, int, 25> tr;
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;
    rep(i, 0, n) if(t[i] == '1') tr.insert(i, 1);

    while(q--) {
        int ty, k;
        cin >> ty >> k;
        if(ty == 0) {
            if(!tr.count(k)) tr.insert(k, 1);
        }
        else if(ty == 1) {
            int cnt = tr.count(k);
            if(cnt > 0) tr.erase(k, 1);
        }
        else if(ty == 2) {
            if(tr.count(k)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(ty == 3) {
            cout << tr.lower_bound(k) << '\n';
        }
        else {
            cout << tr.lower_left_bound(k) << "\n";

        }
    }
}