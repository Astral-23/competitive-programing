
struct Mo {
    int n, q;
    vec<pair<int, int>> qs;
    vec<int> qi;
    Mo(int N, vec<pair<int, int>> QS) : n(N), qs(QS), q(QS.size()) {   
        qi = vec<int>(q);
        iota(all(qi), 0);
        int width = max<int>(1, 1.0 * n / max(1.0, sqrt(q * 2.0 / 3.0)));
        sort(all(qi), [&](int i, int j) {
            if(qs[i].first/width != qs[j].first/width) {
                return qs[i].first < qs[j].first;
            }
            else {
                int g = qs[i].first / width;
                if(g % 2 == 0) {
                    return qs[i].second < qs[j].second;
                }
                else {
                    return qs[i].second > qs[j].second;
                }
            }
        });
    }
    
    template<class AL, class AR, class DL, class DR, class REM> void run(AL addL, AR addR, DL delL, DR delR, REM rem) {
        int l = 0, r = 0;
        for(int i : qi) {
            while(l > qs[i].first) addL(--l);
            while(l < qs[i].first) delL(l++);
            while(r < qs[i].second)addR(r++);
            while(r > qs[i].second)delR(--r);
            rem(i, l, r);            
        }
    }
};

/*
@brief Moアルゴリズム
*/