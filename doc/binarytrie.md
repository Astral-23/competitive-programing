## 概要
binary trie

## 使用例
```
#include "../Utility/template.hpp"
#include "../Datastructure/binarytrie.hpp"

int main() {
    binary_trie<int, int,30> tr;
    //xorの型がint, 個数の型がint, 2 ^ 30未満の要素を格納できる 空の binary_trieを宣言


    tr.insert(10, 1);//10を1つ挿入
    tr.insert(15, 1);
    tr.insert(20, 1);//{10, 15, 20}
    
    cout << tr.order_of_key(10) << endl;//0番目
    cout << tr.order_of_key(15) << endl;//1番目
    cout << tr.order_of_key(12) << endl;//12未満の個数を返すので、1を返す

    cout << tr.kth_element(1) << endl; //15
    // cout << tr.kth_element(3) << endl; 要素数より大きい値はassert

    tr.insert(15, 2); // {10, 15, 15, 15, 20}
    cout << tr.order_of_key(15) << endl;//1
    

    cout << tr.lower_bound(15) << endl;//15  自分以上 
    cout << tr.upper_bound(15) << endl;//20  自分超過
    cout << tr.lower_bound(25) << endl;//-1 存在しない時

    cout << tr.upper_left_bound(15) << endl;//10 自分未満
    cout << tr.lower_left_bound(15) << endl;//15 自分以下

    tr.all_xor(1);//全てに1をxor。 {11, 14, 14, 14, 21}
    cout << tr.min_element() << endl; //11
    cout << tr.count(14) << endl; //3個
    cout << tr.max_element() << endl; //21

    //tr.erase(11, 3);//消しすぎるとassert
    tr.erase(11, 1);
    tr.erase(14, 3);
    tr.erase(21, 1);

    //cout << tr.max_element() << endl;//空の時 max/minを呼ぶとassert


}
```