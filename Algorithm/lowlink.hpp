struct lowlink {
    using vi = vec<int>;
    using vvi = vec<vi>;
    using pii = pair<int, int>;
    
    int n;
    vvi tr;
    vi low, in;
    vec<pii> bridges;
    vec<int> joints;

    lowlink(vvi g) : n(g.size()) {
        low = vi(n, 1001001001);
        in = vi(n, -1);
        tr.resize(n);
    
        
        int t = 0;
        int r = 0;
        auto dfs = [&](auto f, int v, int p) -> void {
            in[v] = low[v] = t++;
            bool duplication = false;
            for(int to: g[v]) {
                if(in[to] == -1) {
                    tr[v].push_back(to);
                    f(f, to, v);
                }
                else {
                    if(to != p) chmin(low[v], in[to]);
                    else if(duplication == false) duplication = true;
                    else {
                        chmin(low[v], in[to]);
                    }
                }
            }

            for(int to : tr[v]) {
                chmin(low[v], low[to]);
            }
            //部分木について、low/inが求まった
            bool isjoint = false;
            for(int to : tr[v]) {
                if(low[to] > in[v]) bridges.emplace_back(v, to);
                if(low[to] >= in[v]) isjoint = true;
            }

            if(v != r && isjoint) joints.push_back(v);
            else if(v == r) {
                if(tr[v].size() > 1) joints.push_back(v);
            }
        };

        rep(i, 0, n) if(in[i] == -1) {
            r = i;
            dfs(dfs, i, -1);
        }
    }

};

/*
@brief lowlink
@docs doc/lowlink.md
*/