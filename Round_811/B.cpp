#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<ll> vec(n);
        unordered_map<ll,ll> mp;

        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            mp[vec[index]]++;
        }

        ll ans=0;
        for(ll index=0; index<n; index++) {
            mp[vec[index]]--;
            if(mp[vec[index]]==1) {
                ans=index+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}