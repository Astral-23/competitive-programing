template <typename T, long long mod> struct combination {
    vector<long long> fac, ifac, inv;
    long long N;
    combination() {
        fac.resize(2, 1);
        ifac.resize(2, 1);
        inv.resize(2, 1);
        N = 1;
    }

    void reserve(long long n) { expand(n); }

    T operator()(int n, int k) { return C(n, k); }

    T C(int n, int k) {
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (n < k) return 0;
        if (N < n) expand(n);
        return fac[n] * ifac[n - k] % mod * ifac[k] % mod;
    }

    T P(int n, int k) {
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (n < k) return 0;
        if (N < n) expand(n);
        return fac[n] * ifac[n - k] % mod;
    }

    T B(int n) {
        if (N < n) expand(n);
        return (n < 0 ? 0 : fac[n]);
    }
    T invB(int n) {
        if (N < n) expand(n);
        return (n < 0 ? 0 : ifac[n]);
    }

    T H(int n, int k) {
        return C(n + k - 1, k);
    }

    T Cn(int n) { return C(2 * n, n) * inv[n + 1] % mod; }

  private:
    constexpr static bool is_prime_constexpr(long long x) {
        if (x <= 1) return false;
        for (long long i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    static_assert(is_prime_constexpr(mod), "mod must be prime");

    long long extgcd(long long a, long long b, long long &x, long long &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        auto d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    long long modinv(long long a) {
        long long x, y;
        extgcd(a, mod, x, y);
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }

    void expand(long long new_max_n) {
        if (new_max_n <= N) return;
        long long nx = N;

        // 2冪で大きくしていく。
        while (nx < new_max_n) nx <<= 1;
        new_max_n = nx;

        long long pre = N;
        N = new_max_n;
        fac.resize(N + 1);
        ifac.resize(N + 1);
        inv.resize(N + 1);
        for (long long i = pre + 1; i <= N; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        ifac[N] = modinv(fac[N]);
        inv[N] = ifac[N] * fac[N - 1] % mod;
        for (long long i = N - 1; i >= pre + 1; i--) {
            ifac[i] = ifac[i + 1] * (i + 1) % mod;
            inv[i] = ifac[i] * fac[i - 1] % mod;
        }
        return;
    }
};

using combination998244353 = combination<atcoder::modint998244353, 998244353>;
/*
@brief コンビネーション
@docs doc/cmb.md
*/