#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,k;
    cin>>test;
    while(test--) {
        cin>>n>>k;
        vector<ll> a(n);
        ll count=0;
        for(ll i=0; i<n; i++) {
            cin>>a[i];
        }

        for(ll i=1; i<=k; i++) {
            if(a[i-1] > k) {
                count++;
            }
        }
        cout<<count<<endl;

    }
    return 0;
}