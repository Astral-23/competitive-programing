template <typename T, typename F> T bisect(T ok, T ng, F pred) {
    if(ok <= ng) ng++;
    else ng--;
    
    if (!pred(ok)) return ok;


    while (ng > ok + 1 || ok > ng + 1) {
        T mid = ((ok ^ ng) >> 1) + (ok & ng);
        (pred(mid) ? ok : ng) = mid;
    }
    return ok;
}
/*
@brief 抽象化二分探索
@docs doc/bisect.md
*/