#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../Utility/template.hpp"
#include "../Datastructure/binarytrie.hpp"

int main() {
    int q;
    cin >> q;
    binary_trie<int, int, 30> tr;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            if(!tr.count(x)) tr.insert(x, 1);
        }
        else if(t == 1) {
            if(tr.count(x)) tr.erase(x, 1);
        }
        else {
            tr.all_xor(x);
            cout << tr.min_element() << '\n';
            tr.all_xor(x);

        }
    }
}