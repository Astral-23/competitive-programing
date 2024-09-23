namespace RNG {
static mt19937_64 engine(clock());
template <typename T = long long> T rnd(T l, T r) {
    return engine() % (r - l) + l;
}
string rndstr(ll len, char l, char r) {
    string res;
    for (int i = 0; i < len; i++) res += l + rnd(0, int(r - l));
    return res;
}
template <typename T> vector<T> rndvec(ll len, T l, T r) {
    vector<T> res(len);
    for (T &x : res) x = rnd<T>(l, r);
    return res;
}
vector<pair<int, int>> rndtree(int n) {
    vector<pair<int, int>> res;
    atcoder::dsu uf(n);
    while (uf.size(0) != n) {
        int u = rnd(0, n);
        int v = rnd(0, n - 1);
        if (v >= u) v++;
        if (uf.same(u, v))
            continue;
        else {
            uf.merge(u, v);
            res.emplace_back(u, v);
        }
    }
    return res;
}

template <bool simple> vector<pair<int, int>> rndgraph(int n, int m) {
    vector<pair<int, int>> res;
    set<pair<int, int>> cnt;
    while (res.size() < m) {
        int u = rnd(0, n);
        int v = rnd(0, n);
        if (u == v && simple) continue;
        if (u > v) swap(u, v);
        if (simple && cnt.count(make_pair(u, v))) continue;
        res.emplace_back(u, v);
        if(simple) cnt.insert(make_pair(u, v));
    }
    return res;
}//連結とは限らないから注意

template <bool simple> vector<pair<int, int>> rndgraph_connected(int n) {
    vector<pair<int, int>> res;
    set<pair<int, int>> cnt;
    atcoder::dsu uf(n);
    while(uf.size(0) != n) {
        int u = rnd(0, n):
        int v = rnd(0, n);
        if(u == v && simple) continue;
        if(u > v) swap(u, v);
        if(simple && cnt.count(make_pair(u, v)))continue;
        res.emplace_back(u, v);
        uf.merge(u, v);
        if(simple) cnt.insert(make_pair(u, v));
    }
    return res;
}
}  // namespace RNG
using namespace RNG;