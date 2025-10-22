// C++ program to implement Disjoint Set Union (Union-Find)
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x: p[x]=find(p[x]); }
    bool unite(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
    bool same(int a,int b){ return find(a)==find(b); }
};

int main(){
    DSU d(7); // 0..6
    d.unite(0,1); d.unite(1,2);
    d.unite(3,4); d.unite(5,6);
    cout << boolalpha << d.same(0,2) << " " << d.same(0,3) << "\n"; // true false
    d.unite(2,3);
    cout << d.same(0,4) << "\n"; // true
    return 0;
}
