// C++ program to implement Sieve + Smallest Prime Factor (SPF)
#include <bits/stdc++.h>
using namespace std;

struct SieveSPF {
    int N; vector<int> spf; vector<int> primes;
    SieveSPF(int n): N(n), spf(n+1,0){
        for(int i=2;i<=N;++i){
            if(!spf[i]){ spf[i]=i; primes.push_back(i); }
            for(int p: primes){
                long long x=1LL*p*i; if(p>spf[i]||x>N) break;
                spf[x]=p;
            }
        }
    }
    vector<pair<int,int>> factorize(int x){
        vector<pair<int,int>> f;
        while(x>1){ int p=spf[x], c=0; while(x%p==0){ x/=p; ++c; } f.push_back({p,c}); }
        return f;
    }
};

int main(){
    int N=1000000;
    SieveSPF sieve(N);
    int x=75600; // example
    auto fac=sieve.factorize(x);
    cout<<"Prime factorization of "<<x<<": ";
    for(auto [p,c]: fac) cout<<p<<"^"<<c<<" ";
    cout<<"\n#primes up to "<<N<<": "<<sieve.primes.size()<<"\n";
    return 0;
}
