// C++ program to compute Sliding Window Maximum using deque
#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMax(const vector<int>& a, int k){
    deque<int> dq; vector<int> ans;
    for(int i=0;i<(int)a.size();++i){
        while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) ans.push_back(a[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> a={1,3,-1,-3,5,3,6,7}; int k=3;
    auto res=slidingMax(a,k);
    cout<<"Sliding max: ";
    for(int x:res) cout<<x<<" ";
    cout<<"\n"; return 0;
}
