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
            ll firstDiv = index*floor(r*1.0/index);
            while(firstDiv >= l) {
                if(mp.find(firstDiv) == mp.end()) {
                    mp[firstDiv]=1;
                    ans.push_back(firstDiv);
                    break;
                }
                firstDiv -= index;
            }
            if(firstDiv < l) {
                flag=false;
                break;
            }
        }
        if(!flag || ans.size()!=n) {
            bool flag1=true;
            unordered_map<ll,ll> mp1;
            deque<ll> ans1;
            for(ll index=n; index>=1; index--) {
                ll firstDiv = index*floor(l*1.0/index);
                while(firstDiv <= r) {
                    if(mp1.find(firstDiv) == mp1.end()) {
                        mp1[firstDiv]=1;
                        ans.push_back(firstDiv);
                        break;
                    }
                    firstDiv += index;
                }
                if(firstDiv < l) {
                    flag=false;
                    break;
                }
            }
            if(!flag1 || ans1.size()!=n) {
                cout<<"NO\n";
                continue;
            }
            cout<<"YES\n";
            for(ll index=ans1.size()-1; index>=0; index--) {
                cout<<ans1[index]<<" ";
            }
            cout<<endl;
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