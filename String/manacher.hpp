struct manacher {
    string s;
    int n, sz;
    vec<int> res;

    manacher(string S) : s(S) {
        n = s.size();
        string t = "";
        rep(i, 0, n) {
            t += s[i];
            if(i != n-1) t += "$";
        }
        sz = t.size();
        res = vec<int>(sz, 0);

        int c = 0;
        rep(i, 0, sz) {
            int l = 2 * c - i;
            if(i + res[l] < c + res[c]) res[i] = res[l];
            else {
                int j = c + res[c] - i;
                while(i - j >= 0 && i + j < sz && t[i-j] == t[i+j]) j++;
                res[i] = j;
                c = i;
            }
        }
    }

    int get(int p) {
        return (res[2 * p] + 1)/2;
    }

    int get(int l, int r) {
        int m = 2 * l + 1;
        return res[m]/2;
    }

};