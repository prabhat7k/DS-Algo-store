// C++ program to implement an LRU Cache
#include <bits/stdc++.h>
using namespace std;

struct LRUCache {
    int cap;
    list<pair<int,int>> dq; // front = most recent
    unordered_map<int, list<pair<int,int>>::iterator> pos;
    LRUCache(int capacity): cap(capacity) {}

    int get(int key){
        auto it = pos.find(key);
        if(it==pos.end()) return -1;
        dq.splice(dq.begin(), dq, it->second); // move node to front
        return it->second->second;
    }
    void put(int key, int value){
        auto it = pos.find(key);
        if(it!=pos.end()){
            it->second->second = value;
            dq.splice(dq.begin(), dq, it->second);
        }else{
            if((int)dq.size()==cap){
                auto [oldk,_]=dq.back(); dq.pop_back(); pos.erase(oldk);
            }
            dq.emplace_front(key,value);
            pos[key]=dq.begin();
        }
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1,10); cache.put(2,20);
    cout << cache.get(1) << "\n"; // 10
    cache.put(3,30);              // evicts key 2
    cout << cache.get(2) << "\n"; // -1
    cache.put(4,40);              // evicts key 1
    cout << cache.get(1) << " " << cache.get(3) << " " << cache.get(4) << "\n"; // -1 30 40
    return 0;
}
