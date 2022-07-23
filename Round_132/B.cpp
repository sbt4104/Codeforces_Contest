#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,m,a,b;
        cin>>n>>m;
        vector<ll> vec(n), forward(n,0), backward(n,0);
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
        }

        for(ll index=1; index<n; index++) {
            if(vec[index] >= vec[index-1]) {
                forward[index]=forward[index-1];
            } else {
                forward[index]=forward[index-1] + (vec[index-1]-vec[index]);
            }
        }

        for(ll index=n-2; index>=0; index--) {
            if(vec[index] >= vec[index+1]) {
                backward[index]=backward[index+1];
            } else {
                backward[index]=backward[index+1] + (vec[index+1]-vec[index]);
            }
        }

        ll ans;
        while(m--) {
            cin>>a>>b;
            a--; b--;
            if(a <= b) {
                //forward
               ans = forward[b]-forward[a]; 
            } else {
                ans= backward[b]-backward[a];
            }
            cout<<ans<<endl;
        }

    return 0;
}