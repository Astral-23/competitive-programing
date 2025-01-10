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


//動的mod : template<int mod> を消して、上の方で変数modを宣言
template<uint32_t mod>
struct modint{
    using mm = modint;
    uint32_t x;
    modint() : x(0) {}
    TT modint(T a=0) : x((ll(a) % mod + mod) % mod){}

    friend mm operator+(mm a, mm b) {
        a.x += b.x;
        if(a.x >= mod) a.x -= mod;
        return a;
    }
   friend mm operator-(mm a, mm b) {
        a.x -= b.x;
        if(a.x >= mod) a.x += mod;
        return a;
    }

    //+と-だけで十分な場合、以下は省略して良いです。

    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }
    friend mm operator/(mm a, mm b) { return a * b.inv(); }
    friend mm& operator+=(mm& a, mm b) { return a = a + b; }
    friend mm& operator-=(mm& a, mm b) { return a = a - b; }
    friend mm& operator*=(mm& a, mm b) { return a = a * b; }
    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }

    mm inv() const {return pow(mod-2);}
    mm pow(const ll& y) const {
        if(!y) return 1;
        mm res = pow(y >> 1);
        res *= res;
        if(y & 1) res *= *this;
        return res;
    }

    friend istream& operator>>(istream &is, mm &a) { 
        ll t;
        cin >> t;
        a = mm(t);
        return is;
    }

    friend ostream& operator<<(ostream &os,  mm a) {
        return os << a.x;
    }

    bool operator==(mm a) {return x == a.x;}
    bool operator!=(mm a) {return x != a.x;}

    //bool operator<(const mm& a) const {return x < a.x;}
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1'000'000'007>;


using mint = modint998244353;
using S = mint;
S op(S a, S b) { return a + b; }
S inv(S x) { return -1*x; }
S zero() { return 0; }

int chromatic_number(const vec<vec<int>> &g) {
    if (g.empty()) return 0;
    int n = g.size();

    vec<mint> dp(1LL << n, -1);  // dp[i][S] := S は i 色彩色可能か？
    dp[0] = 1;
    rep(i, 0, n) dp[1LL << i] = 1;

    rep(s, 0, 1LL << n) if (dp[s] == -1) {
        int lat = -1;
        rep(i, 0, n) if (s >> i & 1) lat = i;

        ll sub = s ^ (1LL << lat);
        if (dp[sub] == 0) {
            dp[s] = 0;
            continue;
        }

        bool ng = false;
        for (int to : g[lat])
            if (s >> to & 1) ng = true;

        if (ng)
            dp[s] = 0;
        else
            dp[s] = 1;
    }

    if(dp[(1 << n) - 1] != 0) {
        return 1;
    }

    vec<mint> DP = subset_zeta_transform<S, op>(dp, n);
    vec<mint> DPK = DP;

    rep(k, 2, n + 1) {
        rep(i, 0, 1 << n) DPK[i] *= DP[i];
        mint v = 0;
        ll sup = (1LL << n) - 1;
        ll sub = sup;
        do {

            ll diff = sup ^ sub;
            ll p = __builtin_popcountll(diff);
            if(p%2==0) p = 1;
            else p = -1;

            v += p * DPK[sub];
         
            sub = (sub - 1) & sup;
        } while (sub != sup);

        if(v != 0) return k;
        else continue;
    }
    return -1;
}

/*
@brief 彩色数(復元付き)
*/
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

    int ans = chromatic_number(g);

    vec<int> cnt(ans, 0);


    cout << ans << endl;

}

