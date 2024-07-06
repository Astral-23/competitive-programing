
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=4021"
#include "../Utility/template.hpp"
#include "../Datastructure/lazysegtree.hpp"


struct S{
	ll idx;
	ll x;
};
S op(S a,S b){
    if(a.x==b.x){
        if(a.idx>b.idx) return a;
        return b;
    }
	if(a.x>b.x) return a;
	return b;
}
S e(){
	return {-1,(ll)(-1e18)};
}
using F = ll;
S mapping(F f,S a){
    a.x+=f;
    return a;
}
F comb(F f,F g){
    return f+g;
}
F id(){
    return 0;
}

using segtree = lazysegtree<S,op,e,F,mapping,comb,id>;

int main(){
	int h,w;
	cin>>h>>w;
	vector<string> s(h);
	rep(i,0, h) cin>>s.at(i);
	vector<vector<ll>> dp(h+1,vector<ll>(w+1,0));
	{
		vector<vector<ll>> dp1(h+1,vector<ll>(w+1,0));
		vector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));
		for(int i=h-1;i>=0;i--){
			for(int j=w-1;j>=0;j--){
				if(s.at(i).at(j)=='0') continue;
				dp1.at(i).at(j)=dp1.at(i+1).at(j)+1;
				dp2.at(i).at(j)=dp2.at(i).at(j+1)+1;
				dp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));
			}
		}
	}
	vector<string> rs(h);
	rep(i,0, h) rep(j,0, w){
		rs.at(i)+=s.at(h-1-i).at(w-1-j);
	}
	vector<vector<ll>> rdp(h+1,vector<ll>(w+1,0));
	{
		vector<vector<ll>> rrdp(h+1,vector<ll>(w+1,0));
		vector<vector<ll>> dp1(h+1,vector<ll>(w+1,0));
		vector<vector<ll>> dp2(h+1,vector<ll>(w+1,0));
		for(int i=h-1;i>=0;i--){
			for(int j=w-1;j>=0;j--){
				if(rs.at(i).at(j)=='0') continue;
				dp1.at(i).at(j)=dp1.at(i+1).at(j)+1;
				dp2.at(i).at(j)=dp2.at(i).at(j+1)+1;
				rrdp.at(i).at(j)=min(dp1.at(i).at(j),dp2.at(i).at(j));
			}
		}
		rep(i,0, h) rep(j,0, w){
			rdp.at(i).at(j)=rrdp.at(h-1-i).at(w-1-j);
		}
	}
    ll ans=0;
	for(int k=-h+1;k<w;k++){
		vector<S> tmp;
        int d=0;
		for(int i=0;i<h;i++){
			int j=i+k;
			if(j<0||j>=w) continue;
			tmp.push_back({d,rdp.at(i).at(j)-d});
            d++;
		}
        segtree seg(tmp);
        d=0;
		for(int i=0;i<h;i++){
			int j=i+k;
			if(j<0||j>=w) continue;
            //if(dp.at(i).at(j)==0) continue;
			auto ch = [&](S now) {
				return now.x < 0;
			};
            ll v =seg.min_left(dp.at(i).at(j)+d,ch);
			//cout << dp.at(i).at(j) << endl;
            if(v > 0){
				v--;
                ans=max(ans,v-d+1);
            }
            d++;
            seg.apply(0,tmp.size(),1);
		}
	}
    cout<<ans<<endl;
}


