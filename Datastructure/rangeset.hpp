template <typename T, bool merge_adju> struct rangeset : public std::map<T, T> {
    rangeset() {}
    auto get(T p) const {
        auto it = (*this).upper_bound(p);
        if (it == (*this).begin() || (--it)->second <= p) return (*this).end();
        return it;
    }

    //[l, r)
    pair<T, T> insert(T l, T r) {
        if (l == r) return make_pair(l, r);
        assert(l <= r);
        auto itl = (*this).upper_bound(l),
             itr = (*this).lower_bound(r + merge_adju);
        if (itl != (*this).begin() && (--itl)->second + merge_adju <= l) {
            ++itl;
        }

        if (itl != itr) {
            if (itl->first < l) l = itl->first;
            if (prev(itr)->second > r) r = prev(itr)->second;
            map<T, T>::erase(itl, itr);
        }
        (*this)[l] = r;
        return make_pair(l, r);
    }

    pair<T, T> insert(T p) { insert(p, p + 1); }

    //[l, r)
    void erase(T l, T r) {
        if (l == r) return;
        assert(l <= r);
        auto itl = (*this).upper_bound(l), itr = (*this).lower_bound(r);
        if (itl != (*this).begin() && (--itl)->second <= l) {
            ++itl;
        }
        if (itl == itr) return;
        T tl = l, tr = r;
        if (itl->first < l) tl = itl->first;
        if (prev(itr)->second > r) tr = prev(itr)->second;
        map<T, T>::erase(itl, itr);
        if (tl < l) (*this)[tl] = l;
        if (tr > r) (*this)[r] = tr;
    }

    void erase(T p) { erase(p, p + 1); }

    // pを含む区間があるか
    bool contains(T p) const { return get(p) != (*this).end(); }

    //[l, r)のうち1要素でも含まれているか
    bool contains(T l, T r) const {
        auto itl = (*this).upper_bound(l), itr = (*this).lower_bound(r);
        if (itl != (*this).begin() && (--itl)->second <= l) {
            ++itl;
        }
        if (itl == itr)
            return false;
        else
            return true;
    }

    // aとbを共に含む区間があるか
    bool same(T a, T b) const {
        if (a > b) swap(a, b);

        auto it = get(a);
        if (it == (*this).end()) return false;
        return b < it->second;
    }

    T mex(T x = 0) const {
        auto it = get(x);
        if (it == (*this).end())
            return x;
        else
            return it->second;
    }

    template <typename TYPE, bool ME>
    friend ostream &operator<<(ostream &os, rangeset<TYPE, ME> const &rhs) {
        for (auto [l, r] : rhs) os << "[" << l << ", " << r << ")";
        return os;
    }
};