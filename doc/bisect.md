## 概要
抽象化二分探索。  
[ok, ng] 或いは [ng, ok] の **閉区間** に対して行う。

## 関数
- `template <typename T, typename F> T bisect(T ok, T ng, F pred) 
`
    - **計算量**
        - $O(\log \|ok - ng\|)$

    - **渡す関数**
        - `pred(T x)` ... xが条件を満たすならばtrue,でなければfalseを返す関数

    - **説明**

    - ok <= ngの時 : [ok, ng] で [oooxxxx]
        - 一番右のoを返す。
            - (1-1)[xxxx]の時
                - okを返す。
            - (1-2)[oooo]の時
                - ngを返す。
    - ok > ngの時 : [ng, ok]で[xxxooo]
        - 一番左のoを返す。ただし、
            - (2-1)[xxxx]の時
                - okを返す。
            - (2-2)[oooo]の時
                - ngを返す。
    - 総じて、[xxxx]の可能性がある場合、返り値をpredに入れて再度その値が有効か判定すると良い。逆に、[xxxx]でなければ、返り値は有効な値。