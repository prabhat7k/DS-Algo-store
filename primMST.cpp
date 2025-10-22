// C++ program to implement Prim's MST (adjacency list)
#include <bits/stdc++.h>
using namespace std;

int primMST(int n, const vector<vector<pair<int,int>>>& g){
    const int INF = 1e9;
    vector<int> dist(n, INF), used(n,0), parent(n,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[0]=0; pq.push({0,0}); int total=0;
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(used[u]) continue; used[u]=1; total+=d;
        for(auto [v,w]: g[u]) if(!used[v] && w<dist[v]){
            dist[v]=w; parent[v]=u; pq.push({w,v});
        }
    }
    return total;
}

int main(){
    int n=5;
    vector<vector<pair<int,int>>> g(n);
    auto add=[&](int u,int v,int w){ g[u].push_back({v,w}); g[v].push_back({u,w}); };
    add(0,1,2); add(0,3,6); add(1,2,3); add(1,3,8); add(1,4,5); add(2,4,7); add(3,4,9);
    cout << "MST weight: " << primMST(n,g) << "\n";
    return 0;
}
