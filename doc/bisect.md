## 概要
抽象化二分探索。  
[l, r)の **半開区間** に対して行う

## max_right
`[l, max_r_plus_one)` について、[oooxxx)を想定して二分探索
okになる右端 + 1を返す
(全部okならmax_r_plus_oneが帰る)
[使用例](https://judge.yosupo.jp/submission/258880)
## min_left 
`[min_l, r)`について、[xxxoooo)を想定して二分探索
okになる左端を返す
(全部ngならrを返す)
[使用例](https://atcoder.jp/contests/abc312/submissions/61216108)


イメージ: l,rがoとxの境目になっている。ただし、半開区間を加味しても、探索範囲内が全てo/xになっていた場合、ifで分岐している
両者とも、半開区間に含まれないところにはクエリが来ない