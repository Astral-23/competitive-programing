#include "../Utility/template.hpp"
#include "../Datastructure/undabledsu.hpp"
#include "../Datastructure/offline_connectivity.hpp"

int main() {
    int n = 10;
    offline_connectivity<dsu, bool, pair<int, int>, false> uf(n); 
    /* 
      n頂点の offlien_connevtivityを宣言。　使用するdsuの型名がdsu 答えの型がbool クエリの型がpair<int, int> 多重辺無し
      この状態では、無辺のグラフ。
    */

    uf.link(0, 1);// 0, 1に辺を貼る。

    uf.query(pair<int, int>(0, 1)); // 0, 1についてクエリを飛ばす

    uf.cut(0, 1); // 0, 1辺を切る

    uf.query(pair<int, int>(0, 1)); // 0, 1についてクエリを飛ばす。


    uf.build(); //クエリを飛ばし終わったら呼ぶ。

    auto f = [&](dsu &UF, pair<int, int> query) {
        return UF.same(query.first, query.second);
    };
    //クエリを処理する関数。 dsuは参照で受け取る。

    vec<bool> res = uf.run(f); //fを引数に渡し、結果を受け取る。

    if(res[0] == true) cout << "0と1は連結だった" << endl;
    if(res[1] == false) cout << "0と1は不連結になった" << endl; 
}