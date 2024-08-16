ll floor_sum(ll n, ll m, ll a, ll b) {
    assert(0 <= n && n < (1LL << 32));
    assert(1 <= m && m < (1LL << 32));
    using ull = unsigned long long;

    ull ans = 0;
    if (a < 0) {
        ull a2 = (a % m + m) % m;
        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0) {
        ull b2 = (b % m + m) % m;
        ans -= 1ULL * n * ((b2 - b) / m);
        b = b2;
    }

    auto uns_fl = [](ull n, ull m, ull a, ull b) {
        ull res = 0;
        while (1) {
            if (a >= m) {
                res += n * (n - 1) / 2 * (a / m);
                a %= m;
            }
            if (b >= m) {
                res += n * (b / m);
                b %= m;
            }

            ull y = a * n + b;
            if (y < m) break;
            n = (ull)(y / m);
            b = (ull)(y % m);
            swap(m, a);
        }
        return res;
    };

    return ans + uns_fl(n, m, a, b);
}

/*
@brief floor_sum
@docs doc/floor_sum.md
*/