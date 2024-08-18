
#line 1 "verify/limited_knapsack.test.cpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp"
#line 1 "Utility/template.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)
#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)
#define all(x) begin(x), end(x)

#define TT template <typename T>
TT using vec = vector<T>;
template <class T1, class T2> bool chmin(T1 &x, T2 y) {
    return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, T2 y) {
    return x < y ? (x = y, true) : false;
}
/*
@brief verify用テンプレート
*/
#line 1 "Datastructure/swag.hpp"

template<class S, S (*op)(S, S)>  struct SWAG {
    struct foldable_stack {
        stack<S> data;
        stack<S> res;
        foldable_stack(){}

        void push(S a, int type) {//type == 1 : 配列の右に追加、つまりR  type == 0 : 配列の左に追加、つまりL 
            data.push(a);
            if(!res.empty()) {
               if(type == 0) res.push(op(a, res.top()));//resが空ならそれを入れる
               else res.push(op(res.top(), a));
            }
            else res.push(a);
            return;
        }

        void pop() {
            assert(!data.empty());
            data.pop();
            res.pop();
            return;
        }

        S top() const {
            assert(!data.empty());
            return data.top(); 
        }

        S get() const { 
            assert(!data.empty());
            return res.top(); 
        }

        bool empty() {return data.empty();}
        int size() {return data.size();}
    };

    
    SWAG() {}
    foldable_stack L, R;
    private:

      void move(foldable_stack& s, foldable_stack& t, int type) {//sの要素を半分tの要素に移す。ここで、type == 0 : s = L, t = R  type == 1 s = R, t = L
        assert(t.empty());
        int oth = 1 - type;
        stack<S> tmp;
        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()), s.pop();
        while(!s.empty()) t.push(s.top(), oth), s.pop(); 
        while(!tmp.empty()) s.push(tmp.top(), type), tmp.pop(); 
      }
    
    public:
      void push_front(S a) {
          L.push(a, 0);
      }
  
      void push_back(S a) {
          R.push(a, 1);
      }
  
      void pop_front() {
          assert(!L.empty() || !R.empty());
          if(L.empty()) move(R, L, 1);
          L.pop();
      }
  
      void pop_back() {
          assert(!L.empty() || !R.empty());
          if(R.empty()) move(L, R, 0);
          R.pop();
      }
  

      S get()  {
        assert(!L.empty() || !R.empty());
        if(L.empty()) return R.get();
        if(R.empty()) return L.get();
        return op(L.get(), R.get());
      }

      int size() {
        return L.size() + R.size();
      }

      bool empty() {
        return size() == 0;
      }
};


/*
@brief SWAG
@docs doc/swag.md
*/
#line 1 "Datastructure/offset_manager.hpp"
TT struct offset_manager {
    T offset;

    offset_manager() {
        offset = T();
    }

    void add_all(T x) {
        offset += x;
    }

    T push(T x) {// 生の値 → 補正値
        return x - offset;
    }

    T pop(T x) {// 補正値 → 生の値
        return x + offset;
    }
};

/*
@brief offset_manager
@docs doc/offset_manager.md
*/
#line 1 "Algorithm/limited_knapsack.hpp"
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

#line 6 "verify/limited_knapsack.test.cpp"
int main() { //O(NW)
    ll n, w;
    cin >> n >> w;
    vec<ll> V(n), W(n), M(n);
    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];
    cout << limited_knapsack(V, W, M, w) << endl;

    
}
