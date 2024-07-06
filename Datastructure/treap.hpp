class xorshift {
    uint64_t x;
    public:
        xorshift() {
            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
            x = rnd();
            for (int i = 0; i < 100; i++) {
                random();
            }
        }
        uint64_t random() {
            x = x ^ (x << 7);
            return x = x ^ (x >> 9);
    }
};


template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct treap {
    xorshift rnd;
    int sz = 0; 
    private:
        struct node_t{
            node_t* lch;
            node_t* rch;
            int pri, cnt;
            S val, acc;
            F lazy;
            bool rev;
 
            node_t(S v, int p) : val(v), pri(p), acc(v) , lch(nullptr), rch(nullptr), rev(false), cnt(1) {
                lch = rch = nullptr;
                rev = false;
                lazy = id();
            }
        };

        using np = node_t*;

        np root = nullptr;

        long long count(np t) {return !t ? 0 : t -> cnt;}
        
        S acc(np t) {return !t ? e() : t -> acc; }

        np pushup(np t) {
            if(t) {
                t -> cnt = count(t -> lch) + count(t -> rch) + 1;
                t -> acc = op(op(acc(t -> lch), t -> val),  acc(t -> rch));
            }
            return t;
        }
 
        void pushdown(node_t *t) {
            if(t && t -> rev) {
                swap(t -> lch, t -> rch);
                if(t -> lch) t -> lch -> rev ^= 1;
                if(t -> rch) t -> rch -> rev ^= 1;
                t -> rev = false;
            }

            if(t) {
                if(t -> lch) {
                    t -> lch-> lazy = composition(t -> lazy, t -> lch -> lazy);
                    t -> lch -> acc = mapping(t -> lazy, t -> lch -> acc);
                }

                if(t -> rch) {
                    t -> rch -> lazy = composition(t -> lazy, t -> rch -> lazy);
                    t -> rch -> acc = mapping(t -> lazy, t -> rch -> acc);
                }
                t -> val = mapping(t -> lazy, t -> val);
                t -> lazy = id();
            }
            pushup(t);
        }
 
        void merge(np& t, np l, np r) {
            pushdown(l), pushdown(r);
            if(!l || !r) t =  !l ? r : l;
            else if(l -> pri > r -> pri) {
                merge(l -> rch, l -> rch, r);
                t = l;
            } else {
               merge(r -> lch, l,r -> lch);
               t = r;
            }
            pushup(t);
        }

        void split(np t, int k, np& tl, np& tr) {// [0, k) [k, n)
            if(!t) {
                tl = nullptr, tr = nullptr;
                return;
            }
            pushdown(t);
 
            if(k <= count(t -> lch)) {
                split(t -> lch, k, tl, t -> lch);
                tr = t;
            }else {
                split(t -> rch, k - count(t -> lch) - 1, t -> rch, tr);
                tl = t;
            }
            pushup(t);
        }

        
        void dump__(np t, vector<S>& res) {
            if(!t) return;
            pushdown(t);
            dump__(t -> lch, res);
            res.push_back(t -> val);
            dump__(t -> rch, res);
        }


    public:
        void insert(int p, S val) {
            assert(0 <= p && p <= size());
            np nw = new node_t(val, rnd.random());
            np tl; np tr;
            split(root, p, tl, tr);
            merge(tl, tl, nw);
            merge(root, tl, tr);
            sz++;
        }

        void push_back(S val) {insert(size(), val);}
 
        void erase(int p) {
            assert(0 <= p && p < size());
            np tl; np tm; np tr;
            split(root, p+1, tl, tm);
            split(tl, p, tl, tr);
            merge(root, tl, tm);
            sz--;
        }

        void pop_back() {
            assert(size()>0);
            erase(size()-1);
        }


        S prod(int l, int r) {
            if(l >= r) return e();
            assert(0 <= l && r <= size());
            np tl; np tm; np tr;
            split(root, l, tl, tm);
            split(tm, r-l, tm, tr);
            S res = acc(tm);
            merge(tm, tm, tr);
            merge(root, tl, tm);
            return res;
        }

        S all_prod() {
            assert(size() > 0);
            pushdown(root);
            pushup(root);
            return root -> acc;
        }

        S get(int p) {
            assert(0 <= p && p < size());
            return prod(p, p+1);
        }

        void apply(int p, F f) {apply(p, p+1, f);}

        void apply(int l, int r, F f) {
            if(l >= r) return;
            assert(0 <= l && r <= size());
            np tl; np tm; np tr;
            split(root, l, tl, tm);
            split(tm, r - l, tm, tr);
            tm -> lazy = composition(tm -> lazy, f);
            tm -> acc = mapping(f, tm -> acc);
            merge(tm, tm, tr);
            merge(root, tl, tm);
        }


        void reverse(int l, int r) {//[l, r)をreverse
            if(l >= r) return;
            assert(0 <= l && r <= size());
            np tl; np tm; np tr;
            split(root, l, tl, tm);
            split(tm, r - l, tm, tr);
            tm -> rev ^= 1;
            merge(tm, tm, tr);
            merge(root, tl, tm);
        }
 
        void rotate(int l, int m, int r) {//[l, r) を mが先頭に来る様にreverse
            if(l >= r) return;
            assert(l <= m && m < r);
            assert(0 <= l && r <= size());
            reverse(l, r);
            reverse(l, l + r - m);
            reverse(l + r - m, r);
        }
      
        vector<S> dump() {
            vector<S> res;
            dump__(root, res);
            return res;
        }

        int size() {
            return sz;
        }
 
};


/*
@brief treap
@docs doc/treap.md
*/