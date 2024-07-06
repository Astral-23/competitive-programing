// O(nw)
// require : offset_manager / swag
// constrains : V[i] >= 0, W[i] > 0 
// if 0 >= W[i] && V[i] >= 0  全て使う。
// if 0 >= V[i] && W[i] >= 0  使わない
// if 0 >= V[i] && 0 >= W[i]  負の方向を持つ。 modを absでやる。他にある？


ll op_knapsack(ll l, ll r) {return max(l, r);}
const ll INF_k = 1001001001001001001;

ll limited_knapsack(vec<ll> V, vec<ll> W, vec<ll> M, ll w) {
    int n = V.size();
    vec<ll> dp(w + 1, -INF_k);
    dp[0] = 0;
    rep(i, 0, n) {
        assert(W[i] > 0);
        //assert(V[i] > 0);
    }

    rep(i, 0, n) {
        vec<ll> pre(w + 1, -INF_k);
        swap(dp, pre);
        rep(mod, 0, W[i]) {
            offset_manager<ll> ofs;
            SWAG<ll, op_knapsack> swag; 

            rep(bi, 0, w + 1) {//使う個数のmax
                ll si = bi * W[i] + mod;
                if(si > w) break;

                ofs.add_all(V[i]);
                ll v = pre[si];
                v = ofs.push(v); 
                swag.push_back(v);
                if(bi > M[i]) swag.pop_front();
                if(swag.empty() == false) chmax(dp[si], ofs.pop(swag.get()));
            }
        }
    }


    ll res = -1;
    rep(i, 0, w + 1) chmax(res, dp[i]);

    return res;
}

