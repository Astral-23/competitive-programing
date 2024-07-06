#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../Utility/template.hpp"
#include "../Utility/modint.hpp"
#include "../Algorithm/treedp.hpp"
vec<ll> A;

using mint = modint998244353;

struct S {
    mint val; int siz;
    S(){}
    S(mint v, int s) : val(v), siz(s){}
};

S op(S l, S r) {
    l.val += r.val;
    l.siz += r.siz;
    return l;
}

S e() {
    return S(0, 0);
}

S addroot(S res, int v) {
    res.val += A[v];
    res.siz += 1;
    return res;
}

struct F{
    mint b, c;
    F(){}
    F(mint t, mint y) : b(t), c(y) {}
};

S mp(F f, S s) {
    s.val = s.val * f.b + f.c * s.siz;
    return s;
}

int main() {
    int n;
    cin >> n;
    A = vec<ll>(n, 0);
    rep(i, 0, n) cin >> A[i];

    TDP<S, op, e, addroot, F, mp> tdp(n);
    rep(i, 0, n-1) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        tdp.add_edge(u, v, F(b, c));
        tdp.add_edge(v, u, F(b, c));
    }

    auto ans = tdp.exe();
    rep(i, 0, n) cout << ans[i].val.x << '\n';

}