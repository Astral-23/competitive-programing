#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/4/ITP2_4_A"
#include "../Utility/template.hpp"
#include "../Datastructure/simple_treap.hpp"


int main() {
    int N;
    cin >> N;
    treap<int> tr;
    rep(i, 0, N) {
        int a;
        cin >> a;
        tr.push_back(a);
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int b, e;
        cin >> b >> e;
        tr.reverse(b, e);
    }

    auto res = tr.dump();
    
    rep(i,0,N) {
        cout << res[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
}