#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using bint = __int128_t;
#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)
#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define TT template<typename T>
TT using vec = vector<T>;
TT using minheap = priority_queue<T, vector<T>, greater<T>>;
TT using maxheap = priority_queue<T>;
template<class T> bool chmin(T &x, T y) { return x > y ? (x = y, true) : false; }
template<class T> bool chmax(T &x, T y) { return x < y ? (x = y, true) : false; }
struct io_setup {
    io_setup() {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} io_setup;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (size_t i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

std::istream &operator>>(std::istream &dest, __int128_t &value) {
    string s;
    dest >> s;
    value = parse(s);
    return dest;
}

int main() {

}