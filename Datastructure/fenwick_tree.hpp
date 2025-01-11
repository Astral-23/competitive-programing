template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : n(0) {}
    explicit fenwick_tree(int n) : n(n), data(n), raw(n, T()), S(T()) {}

    void add(int p, T x) {
        assert(0 <= p && p < n);
        raw[p] += x;
        S += x;

        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int r) const {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }

    T all_prod() const { return S; }

    T get(int p) const { return raw[p]; }

    template <class F> int max_right(F f) const {
        assert(f(0));
        T s = 0;
        int p = 0;
        for (int i = 32 - __builtin_clz(n) - 1; i >= 0; i--) {
            int k = p + (1 << i);
            if (k <= n && f(s + data[k - 1])) {
                s += data[k - 1];
                p = k;
            }
        }
        return p;
    }

  private:
    int n;
    vector<T> data;
    vector<T> raw;
    T S;
};