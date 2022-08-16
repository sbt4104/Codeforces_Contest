#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,q, a, k;
    cin>>test;
    while(test--) {
        cin>>n>>q;
        vector<ll> vec(n+1), ans, mp(n+1), veca(n+1,0);
        for(ll i=1; i<=n; i++) {
            cin>>vec[i];
            mp[vec[i]]=i;
        }

        ans.push_back(max(vec[1],vec[2]));
        veca[max(vec[1],vec[2])]=1;
        ll j=0;
        for(ll i=3; i<=n; i++) {
            if(ans[j] < vec[i]) {
                veca[vec[i]]=i;
                ans.push_back(vec[i]);
                j++;
            } else {
                break;
            }
        }
        ll size = ans.size();
        // for(ll index=0; index<size; index++) {
        //     cout<<ans[index]<<" ";
        // } cout<<endl;
        while(q--) {
            cin>>a>>k;
            a = vec[a];
            //cout<<"a: "<<a<<endl;
            if(veca[a]==0) {cout<<0<<endl; continue;}
            if(k > size) {
                if(ans[size-1] ==  a) {
                    cout<<(k-ans.size()+1)<<endl;
                } else {
                    cout<<1<<endl;
                }
            } else {
                cout<<1<<endl;
            }

        }
    }
    return 0;
}