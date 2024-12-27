struct notlinear_sieve {
    int n;
    vector<int> sm;
    vector<vector<pair<int, int>>> fs;

    notlinear_sieve(int max_n) : n(max_n) {
        assert(1 <= n);
        sm.resize(n + 1);
        fs.resize(n + 1);
        iota(sm.begin(), sm.end(), 0);

        sm[2] = 2;
        for(int j = 4; j <= n; j += 2) sm[j] = 2;
        for(int i = 3; i * i <= n; i += 2) {
            if(sm[i] != i) continue;
            for(int j = i * 2; j <= n; j += i) {
                if(sm[j] == j) sm[j] = i;
            }
        }
    }


    bool isprime(int v) const {
        assert(v <= n);
        if(v <= 1) return false;
        return sm[v] == v;
    }


    vector<int> primes(int max_n) const {
        assert(1 <= max_n && max_n <= n);
        vector<int> ret;
        for(int i = 2; i <= max_n; i++) if(isprime(i)) ret.push_back(i);
        return ret;
    }

    //sorted
    vector<pair<int, int>> factorize(int v) {
        assert(1 <= v && v <= n);
        if(fs[v].empty() == false) return fs[v];
        int val =  v;
        vector<pair<int, int>> ret;
        while(sm[v]!= v) {
            int tmp = v;
            int c = 0;
            while(tmp % sm[v] == 0) c++, tmp /= sm[v];
            fs[val].emplace_back(sm[v], c);
            v = tmp;
        }
        if(v != 1) fs[val].emplace_back(v, 1);
        return fs[val];
    }

    int divcnt(int v) {
        assert(1 <= v && v <= n);
        auto ps = factorize(v);
        int ret = 1;
        for(auto [p, c] : ps) ret *= (c + 1);
        return ret;
    }
    
    // not sorted
    vector<int> divs(int v)  {
        assert(1 <= v && v <= n);
        auto ps = factorize(v);

        int sz = 1;
        for(auto [p, c] : ps) sz *= (c + 1);
        vector<int> ret(sz);
        ret[0] = 1;
        int r = 1;
        for(auto [p, c] : ps) {
            int nr = r;
            for(int j = 0; j < c; j++) {
                for(int k = 0; k < r; k++) {
                    ret[nr] = p * ret[nr - r];
                    nr++;
                }
            }
            r = nr;
        }
        return ret;
    }
};
