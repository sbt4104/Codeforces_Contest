#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
void swap(ll a, ll b, vector<ll> &vec) {
    ll temp=vec[a];
    vec[a]=vec[b];
    vec[b]=temp;
}
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<ll> vec(n+2);
        for(ll index=1; index<=n; index++) {
            vec[index]=index;
        }
        ll t=1;
        cout<<n<<endl;
        do {
            for(ll index=1; index<=n; index++) {
                cout<<vec[index]<<" ";
            }
            cout<<endl;
            swap(t,t+1,vec);
            t++;
        } while(t<=n);
    }
    return 0;
}