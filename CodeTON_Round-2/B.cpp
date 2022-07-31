#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,x;
    cin>>test;
    while(test--) {
        cin>>n>>x;
        vector<ll> vec(n), sum(n);
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            if(index==0) {sum[0]=vec[0];} else {
                sum[index]=sum[index-1]+vec[index];
            }
        }
        ll mini=vec[0], maxi=vec[0];

        ll changes=0,  last=-1;
        double v,v1, vmax,vmax1, vmin,vmin1;
        for(ll index=1; index<n; index++) {
            maxi=max(maxi, vec[index]);
            mini=min(mini, vec[index]);
            v=floor((sum[index]*1.0 - (last==-1 ? 0 : sum[last])) /(index-last));
            v1=ceil((sum[index]*1.0 - (last==-1 ? 0 : sum[last])) /(index-last));;
            vmax = v+x;
            vmin = v-x;
            ll diff = maxi-mini;
            ll diff1 = vmax-vmin;
            if(diff <= diff1) {
                //all good
            } else {
                //change v
                changes++;  
                mini=maxi=vec[index];
                last=index-1;
            }
        }
        cout<<changes<<endl;
    }
    return 0;
}