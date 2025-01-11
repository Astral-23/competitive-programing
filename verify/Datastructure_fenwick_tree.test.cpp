#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../Utility/template.hpp"
#include "../Datastructure/fenwick_tree.hpp"

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    fenwick_tree<ll> fw(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

	while(Q--) {
		int t;
		cin >> t;
		if(t==0) {
			ll p, x;
			cin >> p >> x;
            fw.add(p, x);
		}
		else {
			ll l, r;
			cin >> l >> r;
			cout << fw.prod(l, r) << '\n';
		}
	}
}