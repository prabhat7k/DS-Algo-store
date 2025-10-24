#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

void dijkstra(int n, int src, vector<vector<pair<int,int>>> &graph) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "Node " << i << " -> " << dist[i] << "\n";
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> graph(n);
    graph[0] = {{1, 2}, {2, 4}};
    graph[1] = {{2, 1}, {3, 7}};
    graph[2] = {{4, 3}};
    graph[3] = {{4, 1}};
    dijkstra(n, 0, graph);
}
