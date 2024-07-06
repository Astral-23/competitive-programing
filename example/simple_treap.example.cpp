#include "../Utility/template.hpp"
#include "../Datastructure/simple_treap.hpp"


int main() {
    int n = 10;
    treap<int> tr(n);

    rep(i, 0, n) tr[i] = i;
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 3 4 5 6 7 8 9 

    tr.reverse(1, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 7 6 5 4 3 2 1 8 9 

    tr.reverse(1, 8);
    // 0 1 2 3 4 5 6 7 8 9

    tr.rotate(3, 5, 8);
    rep(i, 0, n) cout << tr[i] << " ";
    cout << endl;
    //0 1 2 5 6 7 3 4 8 9 

    //cout << tr[n] << endl; assert落ち。
}