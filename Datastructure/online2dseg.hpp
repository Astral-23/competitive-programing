template <class S, S (*op)(S, S), S (*e)(), class W> struct online2dseg {

    W minh, maxh, minw, maxw;
    online2dseg(W sy, W ty, W sx, W tx) : minh(sy), maxh(ty), minw(sx), maxw(tx) {};

    private:
        struct Node {
            dynamicsegtree<S, op, e, W> st;
            Node* l;
            Node* r;
            
            Node(W L, W R) {
              st = dynamicsegtree<S, op, e, W>(L, R);
              l = nullptr;
              r = nullptr;
            }
        };

        using np = Node*;

        Node* root = nullptr;

        np apply(np v, W h, W w, S &s, W L, W R) {
            if(!v) v = new Node(minw, maxw);
            v -> st.set(w, op(v -> st.prod(w, w+1),  s));

            if(R - L == 1) return v;
            
            W M = (L + R) >> 1;
            if(h < M) v -> l = apply(v -> l, h, w, s, L, M);
            else v -> r = apply(v -> r, h, w, s, M, R);
            return v;
        }

        S query(np v, W sy, W ty, W sx, W tx, W L, W R) {
            if(R <= sy || ty <= L) return e();
            if(!v) return e();
            if(sy <= L && R <= ty) return v -> st.prod(sx, tx);

            W M = (L + R) >> 1;
            S l = query(v -> l, sy, ty, sx, tx, L, M);
            S r = query(v -> r, sy, ty, sx, tx, M, R);
            return op(l, r);
        }
        
    public:
        void apply(W y, W x, S s) {
            root = apply(root, y, x, s, minh, maxh);
            return;
        }

        S prod(W sy, W ty, W sx, W tx) {
            return query(root, sy, ty, sx, tx, minh, maxh);
        }

        
};


/*
@docs doc/2dseg.md
@brief 巨大なグリッドへの1点加算・矩形和
*/