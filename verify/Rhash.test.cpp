#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"
using namespace rolling_hash;
int main() {
    string S;
    cin >> S;

    Rhash rs(S);

    rep(i, 0, S.size()) {
        int li = 0;
        int ri = int(S.size()) - i;

        while(li < ri) {//ooxxxx   
            int mid = (li + ri + 1) >> 1;
            if(rs.prod(i, i + mid) == rs.prod(0, mid)) {
                li = mid;
            }
            else {
                ri = mid - 1;
            }
        }

        cout << li << " ";
    }
    
}