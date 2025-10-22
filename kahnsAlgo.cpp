// C++ program to implement Topological Sort (Kahn's Algorithm)
#include <bits/stdc++.h>
using namespace std;

vector<int> topoKahn(int n, const vector<vector<int>>& g) {
    vector<int> indeg(n,0);
    for (int u=0; u<n; ++u) for (int v: g[u]) indeg[v]++;
    queue<int> q; for (int i=0;i<n;++i) if(!indeg[i]) q.push(i);
    vector<int> order;
    while(!q.empty()){
        int u=q.front(); q.pop(); order.push_back(u);
        for(int v:g[u]) if(--indeg[v]==0) q.push(v);
    }
    return order; // if size<n, there was a cycle
}

int main() {
    int n=6;
    vector<vector<int>> g(n);
    auto add=[&](int u,int v){ g[u].push_back(v); };
    add(5,2); add(5,0); add(4,0); add(4,1); add(2,3); add(3,1);
    auto order = topoKahn(n,g);
    cout << "Topological order: ";
    for(int x: order) cout << x << " ";
    cout << "\n";
    return 0;
}
