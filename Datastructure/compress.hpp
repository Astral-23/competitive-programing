template <typename T> struct compress {
    vector<T> vs;
    bool built = false;
    compress(vector<T> const &vs = {}) : vs(vs) {
    }
    void add(T const &v) {
        assert(built == false);
        vs.push_back(v);
    }
    void build() {
        assert(built == false);
        built = true;
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
    }

    ll operator()(T const &v) const {
        assert(built);
        return lower_bound(vs.begin(), vs.end(), v) - vs.begin();
    }

    ll get(T const &v) const {
        assert(built);
        ll ret = (*this)(v);
        assert(0 <= ret && ret < ll(vs.size()));
        assert(vs[ret] == v);
        return ret;
    }

    ll size() const {
        assert(built);
        return vs.size();
    }
};
