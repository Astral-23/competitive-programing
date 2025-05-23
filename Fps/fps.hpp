using mint = atcoder::modint998244353;
using vm = vector<mint>;
struct fps : vm {
#define d (*this)
#define s int(vm::size())
    fps() {}
    fps(vector<mint> a) : vm(a.begin(), a.end()) {}
    void rsz(int n, mint val = 0) {
        if (s < n) resize(n, val);
    }
    fps &low_(int n) {
        resize(n);
        return d;
    }
    fps low(int n) const { return fps(d).low_(n); }
    fps &shrink_(int n) {
        if (s > n) resize(n);
        return d;
    }
    fps shrink(int n) const { return fps(d).shrink_(n); }
    mint &operator[](int i) {
        rsz(i + 1);
        return vm::operator[](i);
    }
    mint operator[](int i) const { return i < s ? vm::operator[](i) : 0; }
    mint operator()(mint x) const {
        mint r;
        for (int i = s - 1; i >= 0; --i) r = r * x + d[i];
        return r;
    }
    fps operator>>(int sz) const {
        if (s <= sz) return {};
        fps r = d;
        r.erase(r.begin(), r.begin() + sz);
        return r;
    }
    fps operator<<(int sz) const {
        fps r = d;
        r.insert(r.begin(), sz, mint(0));
        return r;
    }
    fps operator-() const {
        fps r(d);
        for (int i = 0; i < s; i++) r[i] = -r[i];
        return r;
    }
    fps &operator+=(const fps &a) {
        rsz(a.size());
        for (int i = 0; i < int(a.size()); i++) d[i] += a[i];
        return d;
    }
    fps &operator+=(const mint &a) {
        d[0] += a;
        return d;
    }
    fps &operator-=(const fps &a) {
        rsz(a.size());
        for (int i = 0; i < int(a.size()); i++) d[i] -= a[i];
        return d;
    }
    fps &operator-=(const mint &a) {
        d[0] -= a;
        return d;
    }
    fps &operator*=(const fps &a) { return d = atcoder::convolution(d, a); }
    fps &operator*=(mint a) {
        for (int i = 0; i < s; i++) d[i] *= a;
        return d;
    }
    fps &operator/=(mint a) {
        mint a_inv = 1 / a;
        for (int i = 0; i < s; i++) d[i] *= a_inv;
        return d;
    }
    fps operator+(const fps &a) const { return fps(d) += a; }
    fps operator-(const fps &a) const { return fps(d) -= a; }
    fps operator+(const mint &a) const { return fps(d) += a; }
    fps operator-(const mint &a) const { return fps(d) -= a; }
    fps operator*(const fps &a) const { return fps(d) *= a; }
    fps operator*(mint a) const { return fps(d) *= a; }
    fps operator/(mint a) const { return fps(d) /= a; }
    fps inv(int n = -1) const {
        if (n == -1) n = s;
        assert(d[0] != mint(0));

        fps r({d[0].inv()});
        for (int i = 1; i < n; i <<= 1)
            r = r * mint(2) - (r * r * low(i << 1)).low_(i << 1);
        return r.low_(n);
    }
    fps &operator/=(const fps &a) {
        assert(a[0] != mint(0));
        int w = s + a.size();

        d *= a.inv(w);
        return d;
    }
    fps operator/(const fps &a) const { return fps(d) /= a; }
    fps integral(int n = -1) const {
        fps r;
        if (n == -1) n = s;
        r.rsz(n, 1);
        rep(i, 2, n) r[i] = r[i - 1] * i;
        mint v = mint(1) / r.back();
        rrep(i, 0, n - 1) {
            r[i + 1] = d[i] * r[i] * v;
            v *= (i + 1);
        }
        r[0] = 0;
        return r;
    }
    fps diff(int n = -1) const {
        fps r;
        if (n == -1) n = s;
        rep(i, 0, n - 1) r[i] = d[i + 1] * (i + 1);
        return r;
    }

    fps log(int n = -1) const {
        assert(d[0] == mint(1));
        if (n == -1) n = s;
        return (diff(n) * inv(n)).low_(n).integral(n).low_(n);
    }

    fps exp(int n = -1) const {
        assert(d[0] == mint(0));
        if (n == -1) n = s;
        fps r({1});
        for (int i = 1; i < n; i <<= 1) {
            r = (r * (-(r.log(i << 1)) + mint(1) + low(i << 1))).low(i << 1);
        }
        return r.low_(n);
    }

    fps pow(ll y, int n = -1) const {
        if (n == -1) {
            if (s == 0) {
                n = 0;
            } else {
                n = (s - 1) * y + 1;
            }
            if (y == 0) n = 1;
        }
        if (!y) return fps({1}).low_(n);

        fps r;

        int l = 0;
        while (l < n && d[l].val() == 0) ++l;
        if (l > (s - 1) / y || l == n) {
            r.resize(n);
            return r;
        }

        mint a = d[l];
        r = (d >> l) / a;
        r = (r.log(n - l * y) * mint(y)).exp();
        r *= a.pow(y);
        r = r << (l * y);
        return r.low_(n);
    }
#undef s
#undef d
};
ostream &operator<<(ostream &o, const fps &a) {
    rep(i, 0, a.size()) o << (i ? " " : "") << a[i].val();
    return o;
}