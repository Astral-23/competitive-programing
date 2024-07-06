//ここから
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
TT using TR = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
TT using MTR = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// set
// insert, erase, find, find_by_order, order_of_key, size

/*
--set--
insert(要素)
erase(find(要素)), erase(要素)
find(要素)
find_by_order(数字)
order_of_key(要素)
size()
*/

/* 
--multiset--
insert(要素)
erase(find_by_order(order_of_key(要素)))
  注:  erase(要素), erase(find(要素))は意味がなかった
find(要素)
find_by_order(数字)
order_of_key(要素)
size()
*/

/*
@brief pdbsのテンプレート
*/