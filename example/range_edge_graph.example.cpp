#include "../Utility/template.hpp"
#include "../Datastructure/range_edge_graph.hpp"


int main() {
    int n = 10;
    range_edge_graph gh(n); //n頂点で無辺のグラフを生成。

    gh.add_edge(0, 3, 6, 9, 10, -1); // [0, 3) の頂点から [6, 9) に向けて 重み = 10の辺を追加。

    gh.add_edge(6, 9, 9, 10, 5, -1); //[6, 9) の頂点から [9, 10) の頂点に向けて　重み = 5の辺を追加。

    gh.add_edge(0, 9, 30, -1); // 0 から 9 に　重み = 30の辺を追加。

    auto g = gh.graph();
    int new_n = g.size();
    //0から9への最短距離を求める。
    
    vec<int> dist(new_n, 100000);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.emplace(0, 0);

    while(!que.empty()) {
        auto [c, v] = que.top();
        que.pop();
        if(dist[v] < c) continue;

        for(auto e : g[v]) {
            if(chmin(dist[e.to], e.cost + c)) {
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    cout << dist[9] << endl; //15
}