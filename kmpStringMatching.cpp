// C++ program to implement KMP string matching
#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string& p){
    int m=p.size(); vector<int> lps(m,0);
    for(int i=1,len=0;i<m;){
        if(p[i]==p[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    return lps;
}

vector<int> kmpSearch(const string& s, const string& p){
    if(p.empty()) return {};
    auto lps=buildLPS(p);
    vector<int> pos; int i=0,j=0;
    while(i<(int)s.size()){
        if(s[i]==p[j]){ i++; j++; if(j==(int)p.size()){ pos.push_back(i-j); j=lps[j-1]; } }
        else if(j) j=lps[j-1];
        else i++;
    }
    return pos;
}

int main(){
    string s="ababcabcabababd", p="ababd";
    auto idxs = kmpSearch(s,p);
    for(int x: idxs) cout << x << " "; // expected: 10
    cout << "\n";
    return 0;
}
