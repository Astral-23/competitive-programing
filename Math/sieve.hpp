struct notlinear_sieve {
    int n;
    vector<int> sm;

    notlinear_sieve(int max_n) : n(max_n), sm(max_n + 1) {
        assert(1 <= n);
        iota(sm.begin(), sm.end(), 0);
        if (n >= 2) sm[2] = 2;
        for (int j = 4; j <= n; j += 2) sm[j] = 2;
        for (int i = 3; i * i <= n; i += 2) {
            if (sm[i] != i) continue;
            for (int j = i * 2; j <= n; j += i) {
                if (sm[j] == j) sm[j] = i;
            }
        }
    }

    bool is_prime(int v) const noexcept {
        assert(v <= n);
        if (v <= 1) return false;
        return sm[v] == v;
    }

    vector<int> primes(int max_n) const noexcept {
        assert(1 <= max_n && max_n <= n);
        vector<int> ret;
        for (int i = 2; i <= max_n; i++)
            if (is_prime(i)) ret.push_back(i);
        return ret;
    }

    // sorted
    vector<pair<int, int>> factorize(int v) const noexcept {
        assert(1 <= v && v <= n);
        vector<pair<int, int>> ret;
        while (sm[v] != v) {
            int tmp = v;
            int c = 0;
            while (tmp % sm[v] == 0) c++, tmp /= sm[v];
            ret.emplace_back(sm[v], c);
            v = tmp;
        }
        if (v != 1) ret.emplace_back(v, 1);
        return ret;
    }

    int divcnt(int v) const noexcept {
        assert(1 <= v && v <= n);
        auto ps = factorize(v);
        int ret = 1;
        for (auto [p, c] : ps) ret *= (c + 1);
        return ret;
    }

    // not sorted
    vector<int> divs(int v) const noexcept {
        assert(1 <= v && v <= n);
        auto ps = factorize(v);
        int sz = 1;
        for (auto [p, c] : ps) sz *= (c + 1);
        vector<int> ret(sz);
        ret[0] = 1;
        int r = 1;
        for (auto [p, c] : ps) {
            int nr = r;
            for (int j = 0; j < c; j++) {
                for (int k = 0; k < r; k++) {
                    ret[nr] = p * ret[nr - r];
                    nr++;
                }
            }
            r = nr;
        }
        return ret;
    }

    // 偶数...+1 奇数...-1 p^2...0
    template <typename T> vector<T> mobius(int N) const {
        assert(N <= n);
        vector<T> ret(N + 1, 1);
        for (int p = 2; p <= N; p++)
            if (is_prime(p)) {
                for (int q = p; q <= N; q += p) {
                    if ((q / p) % p == 0)
                        ret[q] = 0;
                    else
                        ret[q] = -ret[q];
                }
            }
        return ret;
    }

    // 以下4つは素因数ごとの累積和と思うと良い。計算量はO(nloglogn)
    // zeta_transform... 結合則 + 交換則 ならなんでも乗る
    // mobius_transform ... 結合 + 交換 + 逆元の存在 ならなんでも乗る
    // f -> F   約数の添字をadd
    template <typename T> vector<T> divisor_zeta_transform(vector<T> A) const {
        int N = int(A.size()) - 1;
        assert(N <= n);
        for (int p = 2; p <= N; p++) {
            if (is_prime(p)) {
                for (int k = 1; k * p <= N; k++) {
                    A[k * p] += A[k];
                }
            }
        }
        return A;
    }

    // F -> f
    template <typename T>
    vector<T> divisor_mobius_transform(vector<T> A) const {
        int N = int(A.size()) - 1;
        assert(N <= n);
        for (int p = 2; p <= N; p++) {
            if (is_prime(p)) {
                for (int k = N / p; k >= 1; k--) {
                    A[k * p] -= A[k];
                }
            }
        }
        return A;
    }

    // f -> F 倍数の添字をadd
    template <typename T> vector<T> multiple_zeta_transform(vector<T> A) const {
        int N = int(A.size()) - 1;
        assert(N <= n);
        for (int p = 2; p <= N; p++) {
            if (is_prime(p)) {
                for (int k = N / p; k >= 1; k--) {
                    A[k] += A[k * p];
                }
            }
        }
        return A;
    }

    // F -> f
    template <typename T>
    vector<T> multiple_mobius_transform(vector<T> A) const {
        int N = int(A.size()) - 1;
        assert(N <= n);
        for (int p = 2; p <= N; p++) {
            if (is_prime(p)) {
                for (int k = 1; k <= N / p; k++) {
                    A[k] -= A[k * p];
                }
            }
        }
        return A;
    }
};