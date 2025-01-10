#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)
#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)
#define all(x) begin(x), end(x)

#define TT template<typename T>
TT using vec = vector<T>;
template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }
template<class T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }

template<class S, S (*op)(S, S)> vector<S> subset_zeta_transform (vector<S> f, int n) {
    rep(i, 0, n) {
        rep(s, 0, 1LL << n) {
            if((s & (1 << i)) != 0) { // if i in s
                f[s] = op(f[s], f[s ^ (1 << i)]);
            }
        }
    }
    return f;
}

template<class S, S (*op)(S, S), S (*inv)(S)> vector<S> subset_mobius_transform (vector<S> f, int n) {
    rrep(i, 0, n) {
        rep(s, 0, 1LL << n) {
            if((s & (1 << i)) != 0) { // if i in s
                f[s] = op(f[s], inv(f[s ^ (1 << i)]));
            }
        }
    }
    return f;
}


template<class S, S (*op)(S, S), S (*inv)(S),  S(*zero)()> vec<S> bitwise_or_convolution(vec<S> A, vec<S> B) {
    ll lg = 1;
    while(A.size() > (1LL << lg)) lg++;
    while(B.size() > (1LL << lg)) lg++;
    A.resize(1LL << lg, zero());
    B.resize(1LL << lg, zero());

    vec<S> FA = subset_zeta_transform<S, op>(A, lg);
    vec<S> FB = subset_zeta_transform<S, op>(B, lg);
    rep(i, 0, 1 << lg) FA[i] *= FB[i];
    vec<S> f = subset_mobius_transform<S, op, inv>(FA, lg);
    return f;
}



int main() {
    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n);
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [ans, col] = chromatic_number(g);

    vec<int> cnt(ans, 0);

    rep(i, 0, n) {
        assert(0 <= col[i]);
        assert(col[i] < ans);
        cnt[col[i]]++;
        for(int to : g[i]) {
            assert(col[i] != col[to]);
        }
    }

    rep(i, 0, ans) assert(cnt[i] != 0);

    cout << ans << endl;

}

