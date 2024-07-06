
template<class S, S (*op)(S, S)>  struct SWAG {
    struct foldable_stack {
        stack<S> data;
        stack<S> res;
        foldable_stack(){}

        void push(S a, int type) {//type == 1 : 配列の右に追加、つまりR  type == 0 : 配列の左に追加、つまりL 
            data.push(a);
            if(!res.empty()) {
               if(type == 0) res.push(op(a, res.top()));//resが空ならそれを入れる
               else res.push(op(res.top(), a));
            }
            else res.push(a);
            return;
        }

        void pop() {
            assert(!data.empty());
            data.pop();
            res.pop();
            return;
        }

        S top() const {
            assert(!data.empty());
            return data.top(); 
        }

        S get() const { 
            assert(!data.empty());
            return res.top(); 
        }

        bool empty() {return data.empty();}
        int size() {return data.size();}
    };

    
    SWAG() {}
    foldable_stack L, R;
    private:

      void move(foldable_stack& s, foldable_stack& t, int type) {//sの要素を半分tの要素に移す。ここで、type == 0 : s = L, t = R  type == 1 s = R, t = L
        assert(t.empty());
        int oth = 1 - type;
        stack<S> tmp;
        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()), s.pop();
        while(!s.empty()) t.push(s.top(), oth), s.pop(); 
        while(!tmp.empty()) s.push(tmp.top(), type), tmp.pop(); 
      }
    
    public:
      void push_front(S a) {
          L.push(a, 0);
      }
  
      void push_back(S a) {
          R.push(a, 1);
      }
  
      void pop_front() {
          assert(!L.empty() || !R.empty());
          if(L.empty()) move(R, L, 1);
          L.pop();
      }
  
      void pop_back() {
          assert(!L.empty() || !R.empty());
          if(R.empty()) move(L, R, 0);
          R.pop();
      }
  

      S get()  {
        assert(!L.empty() || !R.empty());
        if(L.empty()) return R.get();
        if(R.empty()) return L.get();
        return op(L.get(), R.get());
      }

      int size() {
        return L.size() + R.size();
      }

      bool empty() {
        return size() == 0;
      }
};


/*
@brief SWAG
@docs doc/swag.md
*/