#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

int main() {
    ll test,n,m,a,b;
    cin>>test;
    while(test--) {
        cin>>n>>m;
        vector<pair<ll,ll>> pairs(m);
        vector<ll> countPair(n+1,0), unHappy(n+1,0);
        for(ll index=0; index<n; index++) {
            cin>>unHappy[index];
        }

        ll index=0;
        while(index<m) {
            cin>>a>>b;
            a--, b--;
            pairs[index].first=a;
            pairs[index].second=b;
            countPair[a]++;
            countPair[b]++;
            index++;
        }

        if(!m%2) {
            cout<<0<<endl;
            continue;
        }

        ll ans=1e12;
        for(ll index=0; index<n; index++) {
            if(countPair[index]%2) {
                ans = min(ans, unHappy[index]);
            }
        }

        for(ll index=0; index<m; index++) {
            a=pairs[index].first;
            b=pairs[index].second;
            //cout<<"a: "<<a<<" countPaira: "<< countPair[a] <<" b: "<<b<<" countPairb: "<< countPair[b]<<endl;
            if(countPair[a]%2==0 && countPair[b]%2==0) {
                ans = min(ans, unHappy[a] + unHappy[b]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}