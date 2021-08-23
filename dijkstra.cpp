#include <iostream>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    priority_queue< pair<int, int> > q;
    vector<int> dis((int)adj.size(), (int)1000000000);
    q.push({0, 0});
    dis[0] = 0;

    while (!q.empty()) {

        
        int u = q.top().second;
        if (-q.top().first != dis[u]) {
            q.pop();
            continue;
        }
        q.pop();

        for (auto e : adj[u]) {
            int m = e.first, n = e.second;
            if (dis[m] > dis[u] + n) {
                dis[m] = dis[u] + n;
                q.push({-dis[m], m});
            }
        }
    }
    return dis;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}