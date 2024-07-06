#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/4022"
#include "../Utility/template.hpp"
#include "../Datastructure/oneside_range_edge_graph.hpp"
#include "../Algorithm/hld.hpp"

using pll = pair<int, ll>;
int main() {
	ll N, s, t;
	cin >> N >> s >> t;
	s--, t--;
	vec<vec<pll>> g(N);
	vec<vec<int>> ng(N);
	rep(i, 0, N-1) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back(pll(b, c));
		g[b].push_back(pll(a, c));
		ng[a].push_back(b);
		ng[b].push_back(a);
	}

	vec<int> T(N), D(N);
	rep(i, 1, N) {
		cin >> T[i] >> D[i];
	}

	HLD hld(ng, 0);
	ng.clear();

	vec<int> ord(N, -1);
	vec<vec<pll>> ds(N);


	{   
		int id = 0;
		queue<int> que;
		que.push(0);
		ord[0] = id++;

		while(!que.empty()) {
			auto now = que.front();
			que.pop();
			ds[hld.dep[now]].push_back(pll(ord[now], now));

			for(auto [to, c] : g[now]) if(ord[to] == -1) {
				ord[to] = id++;
				que.push(to);
			}
		}

		rep(i, 0, N) sort(all(ds[i]));
	}

    
	vec<int> rev(N);
	rep(i, 0, N) {
		rep(j, 0, ds[i].size()) {
			rev[ds[i][j].second] = j;
		}
	}

	range_edge_graph gh(N);


	rep(i, 1, N) {//辺を貼るフェーズ
	    ll d = D[i];
		auto& vs = ds[hld.dep[i]];
		//自分がvsの中で m 番目とする。
		int m = rev[i];
		int l, r;
		{
			int li = 0;
			int ri = m;
			while(li < ri) {//xxxxooo
				int mid = (li + ri) >> 1;
				int dis = hld.dist(vs[mid].second, i);
				if(dis <= d) ri = mid;
				else li = mid + 1;
			}
			l = li;
		}


		{
			int li = m;
			int ri = vs.size()-1;
			while(li < ri) {
				int mid = (li + ri + 1) >> 1;
				int dis = hld.dist(vs[mid].second, i);
				if(dis <= d) li = mid;
				else ri = mid - 1;
			}
			r = li;
		}

		//[l, r]
		l = vs[l].first;
		r = vs[r].first;//ordに変換
		int now = ord[i];

		gh.point_range(now, l, r+1, T[i]);
	}

	rep(i, 0, N) {
		int now = ord[i];
		for(auto [to, c] : g[i]) {
			to = ord[to];
			gh.add_edge(now, to, c, 0);

		}
	}

	auto G = gh.graph();
	int M = G.size();

	s = ord[s] + gh.sz; t = ord[t] + gh.sz;
	vec<ll> ans(M, LLONG_MAX);
	ans[s] = 0;



	priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> que;
	que.push({0, s});
	while(!que.empty()) {
		auto [c, v] = que.top();
		que.pop();
		if(ans[v] < c) continue;
		for(auto e : G[v]) {
			ll cost = e.cost + ans[v];
			if(chmin(ans[e.to], cost)) {
				que.push({ans[e.to], e.to});
			}

		}
	}

	cout << ans[t] << endl;




	





}
