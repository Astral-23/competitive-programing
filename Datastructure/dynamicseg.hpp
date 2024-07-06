template <class S, S (*op)(S, S), S (*e)(), class W> struct dynamicsegtree {
    W  min_pos;
    W  max_pos;
    dynamicsegtree(){} 
    dynamicsegtree(W l, W r) :  min_pos(l), max_pos(r) {};

    private:
        struct Node {
            W p;
            S x;
            S prod;
            Node* l;
            Node* r;
        
            Node(W pos, S v) : p(pos), x(v), prod(v) {
                l = nullptr;
                r = nullptr;
            }
        };
        using np = Node*;
        
        np root = nullptr;

        S val(np v) {
            return v != nullptr ? v -> prod : e(); 
        }

        np apply(np v, W p, S &s, W L, W R) {
            if(!v) {
                v = new Node(p, s);
                return v;
            }
            if(v-> p == p) {
                v -> x = s;
                v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));
                return v;
            }
            
            W M = (L + R) >> 1;

            if(p < M) {
                if(v -> p < p) swap(p, v -> p), swap(s, v -> x);
                v -> l = apply(v -> l, p, s,  L, M);
            }
            else {
                if(v -> p > p) swap(p, v -> p), swap(s, v -> x);
                v -> r = apply(v -> r, p, s, M, R);
            }
            v -> prod = op(val(v -> l), op(v -> x, val(v -> r)));
            return v; 
        }

        S query(np v, W l, W r, W L, W R) {
            if(r <= L || R <= l) return e();
            if(!v) return e();
            if(l <= L && R <= r) return v -> prod;

            W M = (L + R) >> 1;
            S res = query(v -> l, l, r, L, M);
            if(l <= v -> p && v -> p < r) res = op(res, v -> x);
            return op(res, query(v -> r, l, r, M, R));
        }

    public:
        void set(W pos, S s) {
           root = apply(root, pos, s, min_pos, max_pos);
        }

        S  prod(W l, W r) {
            return query(root, l, r, min_pos, max_pos);
        }

};

/*
    @brief 動的セグ木
    @docs doc/dynamicseg.md
        
*/