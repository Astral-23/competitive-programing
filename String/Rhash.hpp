namespace rolling_hash {
    struct rhash {
        static const uint64_t mod = (1LL << 61) - 1;
        using mm = rhash;
        uint64_t x;
    
        rhash() : x(0) {
        }
        TT rhash(T a = 0) : x((__int128_t(a) % mod + mod)) {
            if (x >= mod)
                x -= mod;
        }
    
        friend mm operator+(mm a, mm b) {
            a.x += b.x;
            if (a.x >= mod)
                a.x -= mod;
            return a;
        }
        friend mm operator-(mm a, mm b) {
            a.x -= b.x;
            if (a.x >= mod)
                a.x += mod;
            return a;
        }
    
        friend mm operator*(mm a, mm b) {
            __uint128_t t = (__uint128_t)(a.x) * b.x;
            t = (t >> 61) + (t & mod);
            return (t >= mod) ? t - mod : t;
        }
        friend mm &operator+=(mm &a, mm b) {
            return a = a + b;
        }
        friend mm &operator-=(mm &a, mm b) {
            return a = a - b;
        }
        friend mm &operator*=(mm &a, mm b) {
            return a = a * b;
        }
    
        mm pow(ll y) const {
            mm res = 1;
            mm v = *this;
            while (y) {
                if (y & 1)
                    res *= v;
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
    
        friend ostream &operator<<(ostream &os, mm a) {
            return os << a.x;
        }
    
        bool operator==(mm a) {
            return x == a.x;
        }
        bool operator!=(mm a) {
            return x != a.x;
        }
        bool operator<(const mm &a) const {
            return x < a.x;
        }
    };
    
    const rhash brh = 200224;
    const int MAX_SIZE = 10'000'000;
    array<rhash, MAX_SIZE + 1> pw;
    struct Initializer {
        Initializer() {
            pw[0] = 1;
            rep(i, 1, MAX_SIZE + 1) {
                pw[i] = pw[i - 1] * brh;
            }
        }
    };
    
    Initializer initializer;
    struct Rhash {
        int n;
        vec<rhash> H;
    
        Rhash(string S = "") : n(S.size()) {
            H = vec<rhash>(n, 0);
    
            rep(i, 0, n) {
                H[i] += S[i];
                if (i) {
                    H[i] += H[i - 1] * brh;
                }
            }
        }
    
        void push_back(char a) {
            n++;
            H.resize(n, 0);
            H[n - 1] = a;
            if (n - 1) {
                H[n - 1] += H[n - 2] * brh;
            }
        }
    
        rhash prod(ll l, ll r) const {
            assert(0 <= l && r <= n);
            rhash res = H[r - 1];
            if (l)
                res -= H[l - 1] * pw[r - l];
            return res;
        }
    
        rhash get(int p) const {
            return prod(p, p + 1);
        }
    
        pair<ll, ll> conv(ll l, ll r) const {
            return make_pair(n - r, n - l);
        }
    
        ll size() const {
            return n;
        }
    };
    
    rhash cal_rhash(string S) {
        return Rhash(S).prod(0, S.size());
    }
    
    rhash connect(rhash mae, rhash usiro, ll len_of_usiro) {
        if (len_of_usiro <= MAX_SIZE) {
            return mae * pw[len_of_usiro] + usiro;
        } else {
            return mae * brh.pow(len_of_usiro) + usiro;
        }
    }
    
    rhash rhash_pow(rhash x, ll y, ll len) {
        rhash res = 0;
        rhash len_pw;
        if (len <= MAX_SIZE)
            len_pw = pw[len];
        else
            len_pw = brh.pow(len);
    
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
    二分探索ライブラリが必要
    vector<ll> lcp_array_back(vector<Rhash> const &S) {
        ll n = S.size();
        vector<ll> ret(n);
        ret[0] = 0;
        rep(i, 1, n) {
            ll len = min(S[i - 1].size(), S[i].size());
            auto pred = [&](ll x) {
                return S[i - 1].prod(S[i - 1].size() - x, S[i - 1].size()) ==
                       S[i].prod(S[i].size() - x, S[i].size());
            };
            ret[i] = max_right(0LL, len + 1, pred) - 1;
        }
        return ret;
    }
    
    vector<ll> lcp_array(vector<Rhash> const &S) {
        ll n = S.size();
        vector<ll> ret(n);
        ret[0] = 0;
        rep(i, 1, n) {
            ll len = min(S[i - 1].size(), S[i].size());
            auto pred = [&](ll x) {
                return S[i-1].prod(0, x) == S[i].prod(0, x);
            };
            ret[i] = max_right(0LL, len + 1, pred) - 1;
        }
        return ret;
    }
    */
    } // namespace rolling_hash
    /*
    @brief rolling_hash
    @docs doc/Rhash.md
    */