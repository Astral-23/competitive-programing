
/*
modintからの変更点:
[1] 1行目(templateの中身)
uint32_t mod → uint64_t mod

[2] 4行目(変数xの型)
uint32_t x → uint64_t x

[3]friend mm operator*について、
(uint64_t)(a.x) * b.x; → (__uint128_t)(a.x) * b.x;
*/

//動的mod : template<int mod> を消して、上の方で変数modを宣言
template<uint64_t mod>
struct modint{
    using mm = modint;
    uint64_t x;

    modint() : x(0){}
    TT modint(T a=0) : x((ll(a) % mod + mod) % mod){}

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

    // + と -だけならここまで

    friend mm operator*(mm a, mm b) { return (__uint128_t)(a.x) * b.x; }
    friend mm operator/(mm a, mm b) { return a * b.inv(); }
    friend mm& operator+=(mm& a, mm b) { return a = a + b; }
    friend mm& operator-=(mm& a, mm b) { return a = a - b; }
    friend mm& operator*=(mm& a, mm b) { return a = a * b; }
    friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }

    //ロリハならここまで(/演算と /= 演算はいらない)

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

    friend ostream& operator<<(ostream &os, mm a) {
        return os << a.x;
    }

    bool operator==(mm a) {return x == a.x;}
    bool operator!=(mm a) {return x != a.x;}
    //bool operator<(const mm& a) const {return x < a.x;}
};

using rhash = modint<(1LL << 61) - 1>;
/*
@brief big_modint
*/