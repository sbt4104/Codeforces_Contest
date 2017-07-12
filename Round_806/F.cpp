#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<ll> vec(n);
        vector< pair<ll, ll> > seq;
        vector<ll> counter(n+1,0);
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            if(vec[index] < index+1) {seq.push_back(make_pair(vec[index], index+1));}
        }
        n=seq.size();
        ll count=0, ans=0;
        for(ll index=0; index<n; index++) {
            for(ll pos=index+1; pos<n; pos++) {
                if(seq[pos].first > seq[index].second) {ans++;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}