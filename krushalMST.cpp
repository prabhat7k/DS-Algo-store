// C++ program to implement Kruskal's MST
#include <bits/stdc++.h>
using namespace std;

struct DSU{ vector<int> p,r; DSU(int n):p(n),r(n,0){ iota(p.begin(),p.end(),0);} 
int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
bool unite(int a,int b){ a=f(a); b=f(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }};

struct Edge{int u,v,w;};
int main(){
    int n=5; vector<Edge> e={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    sort(e.begin(), e.end(), [](auto &a, auto &b){return a.w<b.w;});
    DSU d(n); int mst=0; vector<Edge> pick;
    for(auto &ed: e) if(d.unite(ed.u, ed.v)){ mst+=ed.w; pick.push_back(ed); }
    cout << "MST weight: " << mst << "\nEdges:\n";
    for(auto &ed: pick) cout << ed.u << "-" << ed.v << " ("<<ed.w<<")\n";
    return 0;
}
