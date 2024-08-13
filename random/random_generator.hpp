namespace RNG {
static mt19937_64 engine(clock());
template <typename T = long long> T rnd(T l, T r) {
    return engine() % (r - l) + l;
}
string rstr(ll len, char l, char r) {
    string res;
    for (int i = 0; i < len; i++) res += l + rnd(0, int(r - l));
    return res;
}
template <typename T> vector<T> rvec(ll len, T l, T r) {
    vector<T> res(len);
    for (T &x : res) x = rnd<T>(l, r);
    return res;
}
}  // namespace RNG
using namespace RNG;