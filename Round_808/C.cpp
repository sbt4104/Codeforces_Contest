#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool check(vector<ll> &vec, vector<ll> &ans, ll mid, ll q) {
    
    for(ll index=0; index<ans.size(); index++) {
        ans[index]=0;
    }

    ll currQ=q;
    for(ll index=0; index<mid; index++) {
        if(currQ >= vec[index]) {
            ans[index]=1;
        }
    }
    for(ll index=mid; index<ans.size(); index++) {
        ans[index]=1;
        if(vec[index] > currQ) {
            if(currQ==0) {return false;}
            currQ--;
        }
    }
    if(currQ < 0) {return false;}
    return true;
}

int main() {
    ll test,n,q;
    cin>>test;
    while(test--) {
        cin>>n>>q;
        vector<ll> vec(n), ans(n,0);
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
        }

        ll l=0;
        ll r=n-1;
        while(r>l+1) {
            ll mid = (l+r)/2;
            if(check(vec, ans, mid, q)) {
                r=mid;
            } else {
                l=mid;
            }
        }
        check(vec,ans,r,q);
        for(ll index=0; index<n; index++) {
            cout<<ans[index];
        }
        cout<<endl;
    }
    return 0;
}