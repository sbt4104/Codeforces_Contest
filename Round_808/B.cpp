#include<bits/stdc++.h>
using namespace std;

/*
Let's greedy it
*/

typedef long long int ll;
int main() {
    ll test,n,l,r;
    cin>>test;
    while(test--) {
        cin>>n>>l>>r;
        
        bool flag=true;
        unordered_map<ll,ll> mp;
        deque<ll> ans;
        for(ll index=n; index>=1; index--) {
            ll firstDiv = index*ceil(l*1.0/index);
            if(firstDiv > r) {
                flag=false;
                break;
            } else {
                ans.push_back(firstDiv);
            }
        }
        if(!flag || ans.size()!=n) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(ll index=ans.size()-1; index>=0; index--) {
            cout<<ans[index]<<" ";
        }
        cout<<endl;
    }
    return 0;
}