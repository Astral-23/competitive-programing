vec<int> maximum_independent_set(vec<vec<int>> &ngs) {
	int n = ngs.size();

	int sl = n/2;
	int sr = n - sl;

	vec<ll> ng(n, 0);
	rep(i, 0, n) rep(j, 0, n) if(ngs[i][j]) {
		ng[i] |= 1LL << j;
	}

	vec<int> dp,pre,self,dp2,pre2,self2;
	dp = pre = self = vec<int>(1LL << sl, 0);
	dp2 = pre2 = self2 = vec<int>(1LL << sr, 0);
	self = vec<int>(1LL << sl, -1);
	self2 = vec<int>(1LL << sr, -1);

	rep(s, 1, 1LL << sl) {
		rep(i, 0, sl) if(s >> i & 1) {
			ll ns = s ^ (1LL << i);
			if(chmax(dp[s], dp[ns])) {
				pre[s] = ns;
				self[s] = -1;
			}
			ns = ns & (ns ^ ng[i]);
			if(chmax(dp[s], dp[ns] + 1)) {
				pre[s] = ns;
				self[s] = i;
			}
		}
	}

	rep(s, 1, 1LL << sr) {
		rep(i, 0, sr) if(s >> i & 1) {
			ll ns = s ^ (1LL << i);
			if(chmax(dp2[s], dp2[ns])) {
				pre2[s] = ns;
				self2[s] = -1;
			}
			ns = ns & (ns ^ (ng[i + sl] >> sl));
			if(chmax(dp2[s], dp2[ns] + 1)) {
				pre2[s] = ns;
				self2[s] = i + sl;
			}
		}
	}
     
	int sz = -1;
	vec<ll> id(2, 0);
	vec<int> res;
	rep(s, 0, 1LL << sl) {
		ll out = 0;
		rep(i, 0, sl) if(s >> i & 1) out |= ng[i];
		ll ns = (((1LL << n) - 1) ^ out) >> sl;
		if(chmax(sz, dp[s] + dp2[ns])) {
			id[0] = s;
			id[1] = ns;
		}
	}

	while(id[0] != 0) {
		if(self[id[0]] != -1) res.push_back(self[id[0]]);
		id[0] = pre[id[0]];
	}

	while(id[1] != 0) {
		if(self2[id[1]] != -1) res.push_back(self2[id[1]]);
		id[1] = pre2[id[1]];
	}
	return res;
}

/*
@brief 最大独立集合
*/