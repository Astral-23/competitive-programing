#include <atcoder/all>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/rational.hpp>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)
#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define TT template<typename T>
TT using vec = vector<T>;
TT using minheap = priority_queue<T, vector<T>, greater<T>>;
TT using maxheap = priority_queue<T>;
TT T safe_floor(T a, T b) {
    if (b < 0) a = -a, b = -b;
    return a >= 0 ? a / b : (a + 1) / b - 1;
}
TT T safe_ceil(T a, T b) {
    if (b < 0) a = -a, b = -b;
    return a > 0 ? (a - 1) / b + 1 : a / b;
}

template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y, true) : false; }
template<class T1, class T2> bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }
struct io_setup {
    io_setup() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} io_setup;


// 任意長整数型
using Bint = boost::multiprecision::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;
using Rat = boost::rational<Bint>;




