#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, n;
    cin>>test;
    while(test--) {
        cin>>n;
        bool flag=true;
        vector<string> vec(n);
        ll count=0;
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
        }
        for(ll indexi=0; indexi<n/2; indexi++) {
            for(ll indexj=indexi; indexj<n-1-indexi; indexj++) {
                //cout<<"index: [ "<<indexi<<" "<<indexj<<" ] ["<<indexj<<" "<<n-1-indexi<<" ] [ "<<n-1-indexi<<" "<<n-1-indexj<<" ] [ "<<n-1-indexj<<" "<<indexi<<" ]"<<endl;
                // four cases
                map<ll,ll> mp;
                ll b1 = vec[indexi][indexj]-'0';
                ll b2 = vec[indexj][n-1-indexi]-'0'; 
                ll b3 = vec[n-1-indexi][n-1-indexj]-'0';
                ll b4 = vec[n-1-indexj][indexi]-'0';   
                mp[b1]++;mp[b2]++;mp[b3]++;mp[b4]++;
                count += (ll)4 - max(max(mp[b1],mp[b2]), max(mp[b3], mp[b4])); 
            }
        }
        cout<<count<<endl;
    }
    return 0;
}