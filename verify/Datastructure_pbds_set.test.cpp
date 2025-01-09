#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../Utility/template.hpp"
#include "../Datastructure/pbds_set.hpp"

int main () {


    TR<int> cnt;

    int N, Q;
    cin >> N >> Q;
    string T;
    cin >> T;

    rep(t, 0, N) if(T[t] == '1') cnt.insert(t);
    

    while(Q--) {
        int t, k;
        cin >> t >> k;
        if(t == 0) {
            cnt.insert(k);
        }
        else if(t==1) {
		  cnt.erase(k);
        }
        else if(t==2) {
            int it = cnt.order_of_key(k);
            if(it < cnt.size() && *cnt.find_by_order(it) == k) cout << 1 << '\n';
            else cout << 0 << "\n";
        }
        else if(t==3) {
            int it = cnt.order_of_key(k);
            if(it < cnt.size()) cout << *cnt.find_by_order(it) << '\n';
            else cout << -1 << '\n';
        }
        else {
            int it = cnt.order_of_key(k);
            if(it < cnt.size() && *cnt.find_by_order(it) == k) cout << k << '\n';
            else {
                it--;
                if(it >= 0) cout << *cnt.find_by_order(it) << '\n';
                else cout << -1 << '\n';
            }

        }
    }

}