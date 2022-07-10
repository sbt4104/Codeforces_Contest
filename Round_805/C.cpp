#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, n, k, a, b;
    cin>>test;
    while(test--) {
        cin>>n>>k;
        vector<ll> stations(n);
        map<ll, pair<ll, ll>> mp;
        for(ll index=0; index<n; index++) {
            cin>>stations[index];
            if(mp.find(stations[index]) == mp.end()) {
                mp[stations[index]] = make_pair(index, index); 
            } else {
                ll start = mp[stations[index]].first;
                ll end = mp[stations[index]].second;
                mp[stations[index]] = make_pair(min(start, index), max(end, index));
            }
        }
        while(k--) {
            cin>>a>>b;
            if((mp.find(a) == mp.end()) || (mp.find(b) == mp.end())) {
                cout<<"NO\n";
                continue;
            }
            ll s1 = mp[a].first;
            ll e1 = mp[a].second;

            ll s2 = mp[b].first;
            ll e2 = mp[b].second;

            if(s1 <= e2) {
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}