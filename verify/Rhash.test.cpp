#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

int main() {
    string S;
    cin >> S;

    Rhash rs(S);

    rep(i, 0, S.size()) {
        int li = 0;
        int ri = int(S.size()) - i;

        while(li < ri) {//ooxxxx   
            int mid = (li + ri + 1) >> 1;
            if(rs.get(i, i + mid).x == rs.get(0, mid).x) {
                li = mid;
            }
            else {
                ri = mid - 1;
            }
        }

        cout << li << " ";
    }
    
}