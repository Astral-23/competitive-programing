#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../Utility/template.hpp"
#include "../Convolution/gcd_convolution.hpp"
#include "../atcoder/all"
using mint = atcoder::modint998244353;
int main() {
    int n;
    cin >> n;
    vector<mint> A(n + 1), B(n + 1);
    rep(i, 1, n + 1) {
        ll a;
        cin >> a;
        A[i] = a;
    }
    rep(i, 1, n + 1) {
        ll a;
        cin >> a;
        B[i] = a;
    }
    auto ret = gcd_convolution(A, B);
    for (int i = 1; i <= n; i++) cout << ret[i].val() << " ";
    cout << endl;
}