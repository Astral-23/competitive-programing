#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../Utility/template.hpp"
#include "../Datastructure/segtree.hpp"

using S = int;
S op(S l, S r) {
	return l + r;
}

S e() {
	return 0;
}


int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> T(N, 0);
	string t;
	cin >> t;
    rep(i, 0, N) if(t[i] == '1') {
		T[i] = 1;
	}
	segtree<S, op, e> seg(T);

	while(Q--) {
		int t, k;
		cin >> t >> k;
		if(t==0) {
			seg.set(k, 1);
		}
		else if(t==1) {
			seg.set(k, 0);
		}
		else if(t==2) {
			if(seg.get(k)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(t==3) {
			auto nex = [&](int v) {
				return v == 0;
			};
			int res = seg.max_right(k, nex);
			if(res==N) cout << -1 << '\n';
            else  cout << res << '\n';
		}
		else if(t==4) {
			auto pre = [&](int v) {
				return v == 0;
			};
			int res = seg.min_left(k+1, pre);
			cout << res-1 << '\n';
		}
	}

}