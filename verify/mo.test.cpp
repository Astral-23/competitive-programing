#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../Utility/template.hpp"
#include "../Algorithm/Mo.hpp"
#include "../Datastructure/segtree.hpp"
using S = ll;
S op(S l, S r) {return l + r;}
S e() {return 0;}

ll ans = 0;
vec<ll> res;

int main() {
    int n, q;
    cin >> n >> q;
    res = vec<ll>(q);
    vec<ll> A(n);
    rep(i, 0, n) cin >> A[i];

    vec<ll> cmp = A;
    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());

    auto get = [&](int x) {
        return lower_bound(all(cmp), x) - cmp.begin();
    };

    segtree<S, op, e> seg(n);

    auto addL = [&](int id) {
        int i = get(A[id]);
        ans += seg.prod(0, i);
        seg.set(i, seg.get(i) + 1);
    };

    auto addR = [&](int id) {
        int i = get(A[id]);
        ans += seg.prod(i + 1, n);
        seg.set(i, seg.get(i) + 1);
    };

    auto delL = [&](int id) {
        int i = get(A[id]);
        seg.set(i, seg.get(i) - 1);
        ans -= seg.prod(0, i);
    };

    auto delR = [&](int id) {
        int i = get(A[id]);
        seg.set(i, seg.get(i) - 1);
        ans -= seg.prod(i + 1, n);
    };

    auto rem = [&](int id, int l, int r) {//id番目に格納された区間のクエリに対する答えをどうするか。
        res[id] = ans;
    };

    vec<pair<int, int>> qs;
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        qs.emplace_back(l, r);
    }

    Mo mo(n, qs);
    mo.run(addL, addR, delL, delR, rem);

    rep(i, 0, q) {
        cout << res[i] << '\n';
    }

}




