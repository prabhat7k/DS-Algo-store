// C++ program to implement Segment Tree (range sum)
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n; vector<long long> st;
    SegTree(const vector<int>& a){
        n=1; while(n<(int)a.size()) n<<=1;
        st.assign(2*n,0);
        for(size_t i=0;i<a.size();++i) st[n+i]=a[i];
        for(int i=n-1;i>0;--i) st[i]=st[i<<1]+st[i<<1|1];
    }
    void update(int idx, long long val){
        int i=n+idx; st[i]=val;
        for(i>>=1;i;i>>=1) st[i]=st[i<<1]+st[i<<1|1];
    }
    long long query(int l,int r){ // inclusive
        long long L=0,R=0; l+=n; r+=n;
        while(l<=r){
            if(l&1) L+=st[l++];
            if(!(r&1)) R+=st[r--];
            l>>=1; r>>=1;
        }
        return L+R;
    }
};

int main(){
    vector<int> a={5,2,9,1,6,3};
    SegTree st(a);
    cout << st.query(1,4) << "\n"; // 2+9+1+6 = 18
    st.update(2, 10);              // a[2]=10
    cout << st.query(1,4) << "\n"; // 2+10+1+6 = 19
    return 0;
}
