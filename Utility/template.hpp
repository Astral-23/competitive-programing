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