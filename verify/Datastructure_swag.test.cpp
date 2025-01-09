#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../Utility/template.hpp"
#include "../Datastructure/swag.hpp"
#include "../Utility/modint.hpp"

using mint = modint998244353;

struct S {
    mint a, b;
    S() {}
    S(mint c, mint d) : a(c), b(d) {}
};

S op(S l, S r) {
    l.a *= r.a;
    l.b *= r.a;
    l.b += r.b;
    return l;
}


int main() {
    SWAG<S, op> swag;
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            mint a, b;
            cin >> a >> b;
            swag.push_back(S(a, b));
        }
        else if(t == 1) {
            swag.pop_front();
        }
        else {
            mint x;
            cin >> x;
            if(!swag.empty()) {
              auto [a, b] = swag.get();
              cout << a * x + b << '\n';
            }
            else {
                cout << x << '\n';
            }
        } 
    }
}