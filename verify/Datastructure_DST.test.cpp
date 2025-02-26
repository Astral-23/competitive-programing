#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../Utility/template.hpp"
#include "../Datastructure/disjoint_sparse_table.hpp"

using S = int;
S op(S l, S r) { return min(l, r); }
S e() { return INT_MAX; }
using stable = disjoint_sparse_table<S, op, e>;

int main() {
    int n, q;
    cin >> n >> q;
    vec<S> A(n);
    rep(i, 0, n) cin >> A[i];
    stable st(A);
    stable st2(n);
    rep(i, 0, n) st2.set(i, A[i]);
    st.build(); st2.build();
    while(q--) {
        int l, r;
        cin >> l >> r;
        assert(st.prod(l, r) == st2.prod(l, r));
        cout << st.prod(l, r) << '\n';
    }
}