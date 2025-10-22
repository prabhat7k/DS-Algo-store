// C++ program to implement a Trie (lowercase a-z)
#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node { int nxt[26]; bool end; Node(){ memset(nxt,-1,sizeof(nxt)); end=false; } };
    vector<Node> t; Trie(){ t.emplace_back(); }
    void insert(const string& s){
        int u=0;
        for(char c: s){
            int k=c-'a';
            if(t[u].nxt[k]==-1){ t[u].nxt[k]=t.size(); t.emplace_back(); }
            u=t[u].nxt[k];
        }
        t[u].end=true;
    }
    bool search(const string& s){
        int u=0; for(char c: s){ int k=c-'a'; if(t[u].nxt[k]==-1) return false; u=t[u].nxt[k]; }
        return t[u].end;
    }
    bool startsWith(const string& p){
        int u=0; for(char c: p){ int k=c-'a'; if(t[u].nxt[k]==-1) return false; u=t[u].nxt[k]; }
        return true;
    }
};

int main(){
    Trie tr; tr.insert("apple"); tr.insert("app"); tr.insert("ape");
    cout << boolalpha << tr.search("app") << " " << tr.search("ap") << "\n"; // true false
    cout << tr.startsWith("ap") << " " << tr.startsWith("bat") << "\n";      // true false
    return 0;
}
