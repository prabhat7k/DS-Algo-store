// C++ program to implement Dijkstra's shortest path
#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int n, int src, const vector<vector<pair<int,int>>>& g){
    const long long INF = (1LL<<60);
    vector<long long> dist(n, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]: g[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n=5;
    vector<vector<pair<int,int>>> g(n);
    auto add=[&](int u,int v,int w){ g[u].push_back({v,w}); g[v].push_back({u,w}); };
    add(0,1,2); add(0,2,5); add(1,2,1); add(1,3,2); add(2,3,3); add(3,4,1);
    auto dist=dijkstra(n,0,g);
    for(int i=0;i<n;++i) cout<<dist[i]<<" "; // 0 2 3 4 5
    cout<<"\n"; return 0;
}
