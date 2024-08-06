struct rhash {
    static const uint64_t mod = (1LL << 61) - 1;
    using mm = rhash;
    uint64_t x;

    rhash() : x(0) {}
    TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {
        if (x >= mod) x -= mod;
    }

    friend mm operator+(mm a, mm b) {
        a.x += b.x;
        if (a.x >= mod) a.x -= mod;
        return a;
    }
    friend mm operator-(mm a, mm b) {
        a.x -= b.x;
        if (a.x >= mod) a.x += mod;
        return a;
    }

    friend mm operator*(mm a, mm b) {
        __uint128_t t = (__uint128_t)(a.x) * b.x;
        t = (t >> 61) + (t & mod);
        return (t >= mod) ? t - mod : t;
    }
    friend mm &operator+=(mm &a, mm b) { return a = a + b; }
    friend mm &operator-=(mm &a, mm b) { return a = a - b; }
    friend mm &operator*=(mm &a, mm b) { return a = a * b; }

    mm pow(ll y) const {
        mm res = 1;
        mm v = *this;
        while (y) {
            if (y & 1) res *= v;
            v *= v;
            y /= 2;
        }
        return res;
    }

    friend istream &operator>>(istream &is, mm &a) {
        ll t;

        cin >> t;
        a = mm(t);
        return is;
    }

    friend ostream &operator<<(ostream &os, mm a) { return os << a.x; }

    bool operator==(mm a) { return x == a.x; }
    bool operator!=(mm a) { return x != a.x; }
    bool operator<(const mm &a) const { return x < a.x; }
};

struct Rhash {
    static const rhash brh;
    static vec<rhash> pw;
    static const int MAX_SIZE;
    int n;
    vec<rhash> H;

    static void initialize_pow() {
        pw.resize(MAX_SIZE + 1);
        pw[0] = 1;
        rep(i, 1, MAX_SIZE + 1) { pw[i] = pw[i - 1] * brh; }
    }

    Rhash() {
        if (pw.empty()) initialize_pow();
    }

    Rhash(string S) : n(S.size()) {
        if (pw.empty()) initialize_pow();
        H = vec<rhash>(n, 0);

        rep(i, 0, n) {
            H[i] += S[i];
            if (i) {
                H[i] += H[i - 1] * brh;
            }
        }
    }

    rhash prod(ll l, ll r) {
        assert(0 <= l && r <= n);
        if (l >= r) return 0;
        rhash res = H[r - 1];
        if (l) res -= H[l - 1] * pw[r - l];
        return res;
    }

    rhash get(int p) { return prod(p, p + 1); }

    pair<ll, ll> conv(ll l, ll r) { return make_pair(n - r, n - l); }
};

const rhash Rhash::brh = 200224;
const int Rhash::MAX_SIZE = 500000;
vec<rhash> Rhash::pw;

rhash connect(rhash mae, rhash usiro, ll len_of_usiro) {
    if (len_of_usiro <= Rhash::MAX_SIZE) {
        return mae * Rhash::pw[len_of_usiro] + usiro;
    } else {
        return mae * Rhash::brh.pow(len_of_usiro) + usiro;
    }
}

rhash rhash_pow(rhash x, ll y, ll len) {
    rhash res = 0;
    rhash len_pw;
    if (len <= Rhash::MAX_SIZE)
        len_pw = Rhash::pw[len];
    else
        len_pw = Rhash::brh.pow(len);

    while (y) {
        if (y & 1) {
            res = res * len_pw + x;
        }
        x = x * len_pw + x;
        y /= 2;
        len_pw *= len_pw;
    }
    return res;
}

/*
@brief Rolling_hash
@docs doc/Rhash.md
*/