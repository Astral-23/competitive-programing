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
        - 一番右のoを返す。ただし、
            - (1-1)[xxxx]の時
                - ok-1を返す。
            - (1-2)[oooo]の時
                - ngを返す。
    - ok > ngの時 : [ng, ok] で [xxxooo]
        - 一番左のoを返す。ただし、
            - (2-1)[xxxx]の時
                - ok+1を返す。
            - (2-2)[oooo]の時
                - ngを返す。
    - 総じて、[xxxx]の場合、返り値 x は [ok, ng] or [ng, ok]から外れる
        - 返り値が区間に入っているか確認すると良い
            - 逆に、[xxxx]でなければ、戻り値 x は [ok, ng] or [ng, ok]に入る。