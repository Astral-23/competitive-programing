//#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp"
#include "../Utility/template.hpp" 
#include "../Datastructure/swag.hpp"
#include "../Datastructure/offset_manager.hpp"
#include "../Algorithm/limited_knapsack.hpp"
int main() { //O(NW)
    ll n, w;
    cin >> n >> w;
    vec<ll> V(n), W(n), M(n);
    rep(i, 0, n) cin >> V[i] >> W[i] >> M[i];
    cout << limited_knapsack(V, W, M, w) << endl;

    
}
