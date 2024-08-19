#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../Utility/template.hpp"
#include "../Datastructure/sparse_table.hpp"

using S = int;
S op(S l, S r) { return min(l, r); }
S e() { return INT_MAX; }
using stable = sparse_table<S, op, e>;

int main() {
    int n, q;
    cin >> n >> q;
    vec<S> A(n);
    rep(i, 0, n) cin >> A[i];
    stable st(A);
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
}