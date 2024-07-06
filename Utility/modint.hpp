
//動的mod : template<int mod> を消して、上の方で変数modを宣言
template<uint32_t mod>
struct modint{
    using mm = modint;
    uint32_t x;
    modint() : x(0) {}
    TT modint(T a=0) : x((a % mod + mod) % mod){}

    friend mm operator+(mm a, mm b) {
        a.x += b.x;
        if(a.x >= mod) a.x -= mod;
        return a;
    }
   friend mm operator-(mm a, mm b) {
        a.x -= b.x;
        if(a.x >= mod) a.x += mod;
        return a;
    }

    //+と-だけで十分な場合、以下は省略して良いです。

    friend mm operator*(mm a, mm b) { return (uint64_t)(a.x) * b.x; }
    friend mm operator/(mm a, mm b) { return a * b.inv(); }
    friend mm& operator+=(mm& a, mm b) { return a = a + b; }
    friend mm& operator-=(mm& a, mm b) { return a = a - b; }
    friend mm& operator*=(mm& a, mm b) { return a = a * b; }
    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }

    mm inv() const {return pow(mod-2);}
    mm pow(const ll& y) const {
        if(!y) return 1;
        mm res = pow(y >> 1);
        res *= res;
        if(y & 1) res *= *this;
        return res;
    }

    friend istream& operator>>(istream &is, mm &a) { 
        ll t;
        cin >> t;
        a = mm(t);
        return is;
    }

    friend ostream& operator<<(ostream &os,  mm a) {
        return os << a.x;
    }

    bool operator==(mm a) {return x == a.x;}
    bool operator!=(mm a) {return x != a.x;}

    //bool operator<(const mm& a) const {return x < a.x;}
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1'000'000'007>;

/*
@brief modint
*/