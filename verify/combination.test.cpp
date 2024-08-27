#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/4020"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Math/combination.hpp"


/*
@brief コンビネーション
*/
using mint = modint998244353;
CMB<mint> cmb(1000000, 998244353);

int main() {
	ll N, M, T;
	cin >> N >> M >> T;

	mint p = 0;


	rep(k, 1, N+1) {
		mint s = 1;
		mint ue = M * N - k * M;


		rep(t, 1, T+1) {
			mint rev = M*N - (t-1);
			s *= ue * (rev.inv());
			ue -= 1;
		}

        s *= cmb.C(N, k);
		if(k%2==1) p += s;
		else p -= s;

	}

	cout << (1 - p).x << endl;

}