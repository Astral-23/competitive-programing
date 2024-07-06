
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


template<class S>
struct treap {
    xorshift rnd;
    int sz = 0;
    private:
        struct node_t{
            node_t* lch;
            node_t* rch;
            int pri, cnt;
            S val;
            bool rev;
 
            node_t(S v, int p) : pri(p), cnt(1), val(v) {
                lch = rch = nullptr;
                rev = false;
            }
        };

        using np = node_t*;

        np root = nullptr;

        int count(node_t* t) {return !t ? 0 : t -> cnt;}

        node_t* pushup(node_t* t) {
           if(t) t -> cnt = count(t -> lch) + count(t -> rch) + 1;
            return t;
        }

        void pushdown(node_t *t) {
            if(t && t -> rev) {
                swap(t -> lch, t -> rch);
                if(t -> lch) t -> lch -> rev ^= 1;
                if(t -> rch) t -> rch -> rev ^= 1;
                t -> rev = false;
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

        np pthptr(np t, int p) {
            pushdown(t);
            int c = count(t->lch), b = (p > c);
            if(p==c)return t;
            if(b) return pthptr(t -> rch, p - (c+1));
            else return pthptr(t -> lch, p);
        }

        
        void dump__(np t, vector<S>& res) {
            if(!t) return;
            pushdown(t);
            dump__(t -> lch, res);
            res.push_back(t -> val);
            dump__(t -> rch, res);
        }


    public:

        treap() {}
        treap(int n, S val = S()) {resize(n, val);}

        const S& operator[](const int &p) const {
            assert(0 <= p && p < sz);
            return pthptr(root, p) -> val;
        }

        S& operator[](const int &p) {
            assert(0 <= p && p < sz);
            return pthptr(root, p) -> val;
        }

    
        void insert(int p, S val) {
            assert(0 <= p && p <= sz);
            np nw = new node_t(val, rnd.random());
            np tl; np tr;
            split(root, p, tl, tr);
            merge(tl, tl, nw);
            merge(root, tl, tr);
            sz++;
        }
 
        void erase(int p) {
            assert(0 <= p && p < sz);
            np tl; np tm; np tr;
            split(root, p+1, tl, tm);
            split(tl, p, tl, tr);
            merge(root, tl, tm);
            sz--;
        }

        void push_back(S val) {insert(sz, val);}

        void pop_back() {
            assert(sz>0);
            erase(sz-1);
        }

        void reverse(int l, int r) {//[l, r)をreverse
            if(l >= r) return;
            assert(0 <= l && r <= sz);
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
            assert(0 <= l && r <= sz);
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

        void resize(int n, S val = S()) {
            while(n > sz) push_back(val);
            while(n < sz) pop_back();
        }
 
};
/*
@brief 値の集約をしないtreap
@docs doc/simpletreap.md
*/