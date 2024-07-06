#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../Utility/template.hpp"
#include "../String/Rhash.hpp"

int main() {
    string S;
    cin >> S;

    Rhash rs(S);
    reverse(all(S));
    Rhash rev(S);
    reverse(all(S));

    rep(ti, 0, ll(S.size()) * 2 - 1) {
        if(ti%2==0) {//文字
            int i = ti/2;
            ll li = 1;
            ll ri = min<int>(i+1, (ll)S.size() - i);
            while(li < ri) {//oooxxx
                ll mid = (li + ri + 1) >> 1;
                auto [l, r] = rs.conv(i - mid + 1, i + mid);
                if(rs.get(i - mid + 1, i + mid).x == rev.get(l, r).x) {
                    li = mid;
                }
                else {
                    ri = mid - 1;
                }
            }
            cout << li*2-1 << " ";
        }
        else {
            int i = ti/2;
            ll li = 0;
            ll ri = min<int>(i+1, (ll)S.size() - i - 1);
            while(li < ri) {
                ll mid = (li + ri + 1) >> 1;
                auto [l, r] = rs.conv(i - mid + 1, i + mid + 1);
                if(rs.get(i - mid + 1, i + mid + 1).x == rev.get(l, r).x) {
                    li = mid;
                }
                else {
                    ri = mid - 1;
                }
            }
            cout << li*2 << " ";
        }
    }
    
}