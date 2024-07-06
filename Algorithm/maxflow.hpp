template<class T> 
struct mf_graph {
    struct edge {
        int st, to;
        T cap, flow;
    };

    struct nedge {
        int to, rev;
        T cap;
    };

    int n;
    vec<unordered_map<int, int>> rev;
    vec<pair<int, int>> pos;
    vec<vec<nedge>> g;

    mf_graph(int _n) : n(_n), g(n), rev(n) {}

    int add_edge(int s, int t, T cap) {
        int m = pos.size();
        pos.push_back({s, g[s].size()});
        int fi = g[s].size(); int ti = g[t].size();
        if(s==t)ti++;
        g[s].push_back(nedge{t, ti, cap});
        g[t].push_back(nedge{s, fi, 0});
        rev[s][t] = m;
        return m;
    }

    T flow(int s, int t, T flow_limit = numeric_limits<T>::max()) {
        vec<int> lv(n), it(n, 0);

        auto bfs = [&]() {
            queue<int> que;
            fill(lv.begin(), lv.end(), -1);
            lv[s] = 0;
            que.push(s);
            while(!que.empty()) {
                int v = que.front();
                que.pop();

                for(auto e : g[v]) {
                    if(e.cap == 0 || lv[e.to] >= 0) continue;
                    lv[e.to] = lv[v] + 1;
                    if(e.to == t) return;
                    que.push(e.to);
                }
            }
        };

        auto dfs = [&](auto f, int v, T up) {
            if(v==s) return up;
            T res = 0;
            int LV = lv[v];
            for(int& i = it[v]; i < int(g[v].size()); i++) {
                nedge& e = g[v][i];
                if(LV <= lv[e.to] || g[e.to][e.rev].cap == 0) continue;
                T d = f(f, e.to, min(up - res, g[e.to][e.rev].cap));
                if(d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if(res == up) return res;
            }
            lv[v] = n;
            return res;
        };

        T flow = 0;
        while(flow < flow_limit) {
            bfs();
            if(lv[t] == -1) break;
            fill(it.begin(), it.end(), 0);
            T f = dfs(dfs, t, flow_limit - flow);
            if(!f) break;
            flow += f;
        }
        return flow;
    }

    //以下、不要なら省略

    int get_id(int s, int t) {
        return rev[s][t];
    }

    edge get_edge(int i) {
        int m = pos.size();
        auto e = g[pos[i].first][pos[i].second];
        auto re = g[e.to][e.rev];
        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }

    void change_edge(int i, T nc, T nf) {
        int m = pos.size();
        auto& e = g[pos[i].first][pos[i].second];
        auto& re = g[e.to][e.rev];
        e.cap = nc - nf;
        re.cap = nf;
    }

    vec<bool> min_cut(int s) {
        vec<bool> seen(n);
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int p = que.front();
            que.pop();
            seen[p]=true;
            for(auto e : g[p]) {
                if(e.cap && !seen[e.to]) {
                    seen[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return seen;
    }

};



/*
@brief Maxflow
@docs doc/maxflow.md
*/
