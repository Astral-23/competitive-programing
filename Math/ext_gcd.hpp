ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll modinv(ll a, ll MOD) {
    ll x, y;
    extgcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

/*
@brief ext_ecd
*/