#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        ll ans=0;
        vector<ll> vec(n), storeLegal;
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            if(vec[index] >= index+1) {continue;}
            ans += lower_bound(storeLegal.begin(), storeLegal.end(), vec[index]) - storeLegal.begin();
            storeLegal.push_back(index+1);
        }

        cout<<ans<<endl;
    }
    return 0;
}