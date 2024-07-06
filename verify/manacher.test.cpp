#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../Utility/template.hpp"
#include "../String/manacher.hpp"

int main() {
    string s;
    cin >> s;
    manacher ma(s);

    rep(i, 0, s.size()*2-1) {
        if(i%2==0) {
            cout << ma.get(i/2) * 2 - 1 << " ";
        }
        else {
            cout << ma.get(i/2, i/2+1) * 2 << " ";
        }

    }

}