// C++ program to implement Fenwick Tree (BIT) for prefix sums
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<long long> bit;
    Fenwick(int n): n(n), bit(n+1,0) {}
    void add(int idx,long long val){ for(; idx<=n; idx+=idx&-idx) bit[idx]+=val; }
    long long sumPrefix(int idx){ long long s=0; for(; idx>0; idx-=idx&-idx) s+=bit[idx]; return s; }
    long long sumRange(int l,int r){ return sumPrefix(r)-sumPrefix(l-1); }
};

int main(){
    vector<int> a={0,5,2,9,1,6,3}; // 1-indexed idea; a[0] dummy
    int n=(int)a.size()-1;
    Fenwick ft(n);
    for(int i=1;i<=n;++i) ft.add(i,a[i]);
    cout << ft.sumRange(2,5) << "\n"; // 2+9+1+6 = 18
    ft.add(3, +5); // a[3]+=5
    cout << ft.sumRange(2,5) << "\n"; // now 23
    return 0;
}
