TT struct offset_manager {
    T offset;

    offset_manager() {
        offset = T();
    }

    void add_all(T x) {
        offset += x;
    }

    T push(T x) {// 生の値 → 補正値
        return x - offset;
    }

    T pop(T x) {// 補正値 → 生の値
        return x + offset;
    }
};

/*
@brief offset_manager
@docs doc/offset_manager.md
*/
