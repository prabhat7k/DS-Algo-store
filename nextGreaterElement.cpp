// C++ program to find Next Greater Element using stack
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> a){
    int n=a.size(); vector<int> ans(n,-1); stack<int> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && a[i]>a[st.top()]){
            ans[st.top()]=a[i]; st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> a={2,1,2,4,3};
    auto ng = nextGreater(a);
    cout<<"Next greater: ";
    for(int x:ng) cout<<x<<" ";
    cout<<"\n"; return 0;
}
