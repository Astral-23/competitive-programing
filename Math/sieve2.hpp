#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
std::ostream &operator<<(std::ostream &os, const atcoder::modint998244353 &v) {
    os << v.val();
    return os;
}
std::istream &operator>>(std::istream &is, atcoder::modint998244353 &v) {
    long long x;
    is >> x;
    v = x;
    return is;
}
std::ostream &operator<<(std::ostream &os, const atcoder::modint1000000007 &v) {
    os << v.val();
    return os;
}
std::istream &operator>>(std::istream &is, atcoder::modint1000000007 &v) {
    long long x;
    is >> x;
    v = x;
    return is;
}
#endif

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define el '\n';
#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)
#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define TT template <typename T>
TT using vec = vector<T>;
TT using vvec = vec<vec<T>>;
TT using vvvec = vec<vvec<T>>;
TT using minheap = priority_queue<T, vector<T>, greater<T>>;
TT using maxheap = priority_queue<T>;
template <class T1, class T2> bool chmin(T1 &x, T2 y) {
    return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, T2 y) {
    return x < y ? (x = y, true) : false;
}
template <class T1, class T2, class T3> bool rng(T1 l, T2 x, T3 r) {
    return l <= x && x < r;
}
TT T flr(T a, T b) {
    if (b < 0) a = -a, b = -b;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}

TT T cil(T a, T b) {
    if (b < 0) a = -a, b = -b;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}
struct io_setup {
    io_setup() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} io_setup;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << " " << p.second;
    return os;
}

TT ostream &operator<<(ostream &os, const vec<T> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template <typename T, ll n>
ostream &operator<<(ostream &os, const array<T, n> &v) {
    for (size_t i = 0; i < n; i++) {
        os << v[i] << (i + 1 != n ? " " : "");
    }
    return os;
}

template <typename T> ostream &operator<<(ostream &os, const vvec<T> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? "\n" : "");
    }
    return os;
}

TT istream &operator>>(istream &is, vec<T> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        is >> v[i];
    }
    return is;
}

#if __has_include(<debug/debug.hpp>)
#include <debug/debug.hpp>
#else
#define dbg(...) true
#define DBG(...) true
#define OUT(...) true
#endif
struct sectional_primes {
    /*
    [L, R]の整数を素数判定：素因数分解する。
    コンストラクタ：素数判定
    O(√Rloglog√R + (R - L)loglog(R-L))？
    [1, 10^6]で134ms [10^12, 10^12 + 10^6]で350ms程

    conduct()を実行すると、素因数分解が実行される。
    O((R - L)log(R))
    参考 : 区間長とRの大きさが速度に影響。
    [1, 10^6]で300ms, [10^12, 10^12 + 10^6]で550ms程
    isprime[i]で、iが素数かどうかがわかる。  L <= i <= R || 1 <= i <= √R O(1)
    get[i]で、iの素因数分解の結果が得られる  L <= i <= R  O(log(i))
    */
    long long L, R, M;
    bool conducted = false;
    vector<bool> small;  // small[i] := iが素数かどうか i <= √R
    vector<vector<long long>> large;  // large[i] := i+L の相異なる素因数の集合
    vector<vector<pair<long long, long long>>> large_res;
    vector<vector<long long>> aux;  // aux[i] := large[i]の素因数の積、つまりi +
                                    // Lの素因数の積（素数判定用）

    sectional_primes(long long _L, long long _R) : L(_L), R(_R) {
        assert(R >= 1 && L <= R);
        M = sqrt(R);
        small.resize(M + 1, true);
        small[0] = false;
        small[1] = false;
        large.resize(R - L + 1);
        large_res.resize(R - L + 1);

        for (long long i = 2; i * i <= R; i++) {
            if (!small[i]) continue;
            for (long long j = i * 2; j <= M; j += i) {
                small[j] = false;
            }
            for (long long j = (L + i - 1) / i * i; j <= R; j += i) {
                large[j - L].push_back(i);
            }
        }
        // √R以下の素因数は全て列挙し終えた。ここからは√R以上の素因数を列挙。ちなみに、√R以上の素因数は各数につき最大て1つ。
        // ここまでO(√Rloglog√R + (R - L)loglog(R-L))
    }

  private:
    void conduct() {
        conducted = true;
        for (long long i = L; i <= R; i++) {
            long long num = i;
            for (long long x : large[i - L]) {
                if (num < x) break;
                long long cnt = 0;
                while (num % x == 0) num /= x, cnt++;
                large_res[i - L].emplace_back(x, cnt);
            }
            if (num != 1)
                large[i - L].push_back(num),
                    large_res[i - L].emplace_back(num, 1);
        }
        // O((R - L)log(R))
    }

    vector<ll> divs__(ll x) {
        if (!conducted) conduct();
        vector<ll> res;
        auto ps = get(x);

        auto dfs = [&](auto dfs, long long id, long long val) -> void {
            if (id == ps.size()) {
                res.push_back(val);
                return;
            }

            auto [p, c] = ps[id];
            for (int i = 0; i <= c; i++) {
                dfs(dfs, id + 1, val);
                val *= p;
            }
        };

        dfs(dfs, 0, 1);
        return res;
    }

  public:
    bool isprime(long long x) {  //[-無限, √R] または [L, R]について、素数判定
                                 // それ以外は未定義
        if (x <= 1) return false;
        if (x <= M) return small[x];
        if (!conducted)
            return large[x - L].size() == 0;  // √R以下の素因数がない⇔xが素数
        else
            return large[x - L].size() == 1;  // 素因数分解済み。
    }  // O(1)

    vector<pair<long long, long long>> get(
        long long
            x) {  //[L, R]について、素因数分解の結果を返す {素因数, 指数}の配列
        if (!conducted) conduct();
        assert(L <= x && x <= R);
        return large_res[x - L];
    }  // 初回いっぱい 以降O(1)

    vector<ll> divs(ll x) {  // xの約数を適当な順で入れた配列を返す。
        return divs__(x);
    }  // O(約数の個数)  x <= 10^18で大凡 O(x ^ (1/3))  注 : 初回O(NlogN)
};

/*
@brief 素数篩(左端任意)
*/
int main() {}
// s -> 0, 0 -> 9, 9 -> t, 1