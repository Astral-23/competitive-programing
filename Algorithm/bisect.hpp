
template <typename T, typename F> T max_right(T l, T max_r_plus_one, F pred) {
    assert(l < max_r_plus_one);

    if (!pred(l)) return l;

    while (max_r_plus_one > l + 1) {
        T mid = ((l ^ max_r_plus_one) >> 1) + (l & max_r_plus_one);
        (pred(mid) ? l : max_r_plus_one) = mid;
    }
    return max_r_plus_one;
};

template <typename T, typename F> T min_left(T min_l, T r, F pred) {
    assert(min_l < r);

    if (pred(min_l)) return min_l;

    while (r > min_l + 1) {
        T mid = ((min_l ^ r) >> 1) + (min_l & r);
        (pred(mid) ? r : min_l) = mid;
    }
    return r;
}
/*
@brief 抽象化二分探索
@docs doc/bisect.md
*/