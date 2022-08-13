#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        ll place = n;
        vector<ll> vec(n+1);
        for(ll i=n; i>=1; i--) {
            if((n-i)%2==0) {
                vec[i] = i-1;
            } else {
                vec[i] = i+1;
            }
        }
        if(n%2==1) {
            vec[1]=1;
        }
        for(ll i=1; i<=n; i++) {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}