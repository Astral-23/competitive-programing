template <typename T, typename S, bool max, typename F>
T decimal_ternary_search(T l, T r, F f, int lim) {
    int c = 0;
    while (c < lim) {
        c++;
        T m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
        S v1 = f(m1), v2 = f(m2);

        if constexpr (max) {
            if (v1 > v2) {
                r = m2;
            } else {
                l = m1;
            }
        } else {
            if (v1 < v2) {
                r = m2;
            } else {
                l = m1;
            }
        }
    }
    return l;
}
template <typename T, typename S, bool max, typename F>
T ternary_search(T l, T r, F f) {
    while ((r - l) >= 3) {
        T m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
        S v1 = f(m1), v2 = f(m2);

        if constexpr (max) {
            if (v1 > v2) {
                r = m2;
            } else {
                l = m1;
            }
        } else {
            if (v1 < v2) {
                r = m2;
            } else {
                l = m1;
            }
        }
    }

    T ret = l;
    S v = f(l);
    for (T i = l + 1; i <= r; i++) {
        S v2 = f(i);
        if constexpr (max) {
            if (v < v2) {
                v = v2;
                ret = i;
            }
        } else {
            if (v > v2) {
                v = v2;
                ret = i;
            }
        }
    }
    return ret;
}