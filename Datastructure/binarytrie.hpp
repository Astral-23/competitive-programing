template<typename X, typename S, int W>
struct binary_trie {
    struct Node {
          Node* l = nullptr;
          Node* r = nullptr;
          S s = 0; 
          X lazy = 0;
          Node (){}
    };

	binary_trie(){}

    using np = Node*;
	
    np root = new Node;//Binary_Trie_Treeの根を表すノード。

    private:
        void eval(np t, int d) {
            X x = t -> lazy;
            if(d != W && x != 0) {
                if(t -> l)t -> l -> lazy ^= x;
                if(t -> r)t -> r -> lazy ^= x;
          
                if(x >> (W - d - 1) & 1) {
				    swap(t -> l, t -> r);
			    }
			}
            t -> lazy = 0;
            return ;
        }    
    
        void search_ie(np &t, S c, ll x, int d) {
		    if(!t) t = new Node;
            eval(t, d);
            t -> s += c;
            assert(t -> s >= 0);
            if(d != W) {
                if(x >> (W - d - 1) & 1) search_ie(t -> r, c, x, d + 1);
                else search_ie(t -> l,  c, x, d + 1);
			}
            return ;
        }

        ll search_maix(np t, bool M, int d) {
		    ll res = 0;
		    while(d < W) {
                eval(t, d);
                if(M) {
					if(t -> r && t -> r -> s != 0) {
						res += 1LL << (W - d - 1);
						t = t -> r;
					}
					else t = t -> l;
                }
                else {
                    if(t -> l && t -> l -> s != 0) {
						t = t -> l;
					}
                    else {
						res += 1LL << (W - d - 1);
						t = t -> r;
					} 
                }
                ++d;
			}
			return res;
        }
        
    
    public:
        void insert(ll x, S cnt) {
            if(cnt) search_ie(root, cnt, x, 0);
        }
    
        void erase(ll x, S cnt) {
            if(cnt) search_ie(root, cnt * -1, x, 0);
        }
        
        S count(ll x) {
            np t = root;
            int d = 0;
            while(d < W) {
                if(!t) break;
                eval(t, d);
                if(t -> s == 0) break;
                if(x >> (W - d - 1) & 1) t = t -> r;
                else t = t -> l;
                d++;
            }
            if(t) return t -> s;
            else return 0;
        }
    
        ll max_element() {
            assert(root -> s > 0);
            return search_maix(root, 1, 0);
        }
    
        ll min_element() {
            assert(root -> s > 0);
            return search_maix(root, 0, 0);
        }
    
        ll kth_element(S k) {
            assert(k < size());
            np t = root;
            int d = 0;
            ll res = 0;
			while(d < W) {
				eval(t, d);
                if(t -> l && t -> l -> s >= k + 1) {
					t = t -> l;
				}
                else {
					if(t -> l) k -= t -> l -> s;
					res += 1LL << (W - d - 1);
					t = t -> r;
                }
				++d;
			}
			return res;
        }

        S order_of_key(ll key) {//key未満の数字の個数
            np t = root;
            int d = 0;
            S res = 0;
            while(d < W) {
                if(!t) break;
                eval(t, d);
                if(key >> (W - d - 1) & 1) {
                    if(t -> l) res += t -> l -> s;
                    t = t -> r;
                }
                else {
                    t = t -> l;
                }
                d++;
            }
            return res;
        }

        ll upper_bound(ll x) {
            S p = order_of_key(x+1);
            if(p >= size()) return -1;
            else return kth_element(p);
        }

        ll lower_bound(ll x) {
            return upper_bound(--x);
        }

        ll upper_left_bound(ll x) {
            if(empty()) return -1;
            if(min_element() >= x) return -1;
            S p = order_of_key(x);
            return kth_element(--p);
        }

        ll lower_left_bound(ll x) {
            if(empty()) return -1;
            return upper_left_bound(++x);
        }
    
        void all_xor(X x) {//収容されている要素全てにxをxor作用させる
            if(root -> s == 0) return;//要素が存在しない
            root -> lazy ^= x;
            eval(root, 0);
        }
        
        S size() {//収容されている要素の総数
            return root -> s;
        }

        bool empty() {
            return size() == 0;
        }
};    
/*
@brief binary_trie
@docs doc/binarytrie.md
*/