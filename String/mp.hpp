vec<int> MP(string S) {
    int n = S.size();
    vec<int> res(n+1, -1);
    int j = -1;
    rep(i, 0, n) {
        while(j >= 0 && S[i] != S[j]) j = res[j];
        j++;
        res[i+1] = j;
    }
    res.erase(res.begin());
    return res;
}


int shortest_run(vec<int> &mp, int i) {
    return i + 1 - mp[i];
}
/*
@brief mp法
@docs doc/mp.md
*/