#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,k;
    cin>>test;
    while(test--) {
        cin>>n>>k;
        ll half=n/2;
        vector<ll> vec(n+2,0), a(n+2,-1), b(n+2,-1);
        if(k%2==1) {
            // straight forward
            cout<<"YES\n";
            for(ll i=1; i<=n/2; i++) {
                ll curr=2*i;
                cout<<curr-1<<" "<<curr<<endl;
            }
            continue;
        }

        // manage /4 directly
        ll j=1,l=1;
        for(ll i=1; i<=n; i++) {
            if((i%4)==0 || ((i+k)%4)==0) {
                //cout<<"in: "<<i<<endl;
                a[j]=i;
                vec[i]=1;
                j++;
            } else {
                b[l]=i;
                l++;
            }
        }

        //cout<<"j: "<<j<<" l: "<<l<<endl;
        if(!(j>(n/2) && l>(n/2))) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(ll i=1; i<=n/2; i++) {
            if((a[i]%4)!=0) {
                cout<<a[i]<<" "<<b[i]<<endl;
            } else {
                cout<<b[i]<<" "<<a[i]<<endl;
            }
        }
    }
    return 0;
}