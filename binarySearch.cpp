// C++ program to implement Binary Search (lower_bound/upper_bound)
#include <bits/stdc++.h>
using namespace std;

int lower_bound_idx(const vector<int>& a, int x){
    int l=0,r=(int)a.size();
    while(l<r){ int m=(l+r)/2; if(a[m]<x) l=m+1; else r=m; } return l;
}
int upper_bound_idx(const vector<int>& a, int x){
    int l=0,r=(int)a.size();
    while(l<r){ int m=(l+r)/2; if(a[m]<=x) l=m+1; else r=m; } return l;
}

int main(){
    vector<int> a={1,2,4,4,4,7,9};
    cout<<"lower_bound(4)= "<<lower_bound_idx(a,4)<<"\n";
    cout<<"upper_bound(4)= "<<upper_bound_idx(a,4)<<"\n";
    cout<<"present? "<<boolalpha<<(lower_bound_idx(a,5)<(int)a.size() && a[lower_bound_idx(a,5)]==5)<<"\n";
    return 0;
}
