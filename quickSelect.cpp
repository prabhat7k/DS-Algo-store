// C++ program to implement Quickselect (k-th smallest)
#include <bits/stdc++.h>
using namespace std;

int partitionL(vector<int>& a, int l, int r){
    int pivot=a[r], i=l;
    for(int j=l;j<r;++j) if(a[j]<=pivot) swap(a[i++],a[j]);
    swap(a[i],a[r]); return i;
}
int quickselect(vector<int>& a, int l, int r, int k){
    while(true){
        int p = partitionL(a,l,r);
        if(p==k) return a[p];
        else if(p>k) r=p-1;
        else l=p+1;
    }
}

int main(){
    vector<int> a={7,2,9,4,1,6,3,8,5};
    int k=3; // 0-indexed -> 4th smallest
    cout<<"k-th smallest: "<<quickselect(a,0,(int)a.size()-1,k)<<"\n";
    return 0;
}
