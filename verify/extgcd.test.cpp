#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja"
#include "../Utility/template.hpp"
#include "../Math/ext_gcd.hpp"

int main() {
    ll a, b;
    cin >> a >> b;
    ll x, y;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;
}