#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,m;
    cin>>test;
    while(test--) {
        cin>>n>>m;
        vector<ll> vec(n);
        unordered_map<ll,ll> mp;
        vector<ll> visited(51,0);
        string ans="";
        for(ll index=0; index<m; index++) {
            ans+="B";
        }
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            ll a=vec[index];
            ll b=m+1-vec[index];
            a--, b--;
            if(visited[a]==0 && visited[b]==0) {
                visited[min(a,b)]=1;
                ans[min(a,b)]='A';
            } else if(visited[a] == 0) {
                visited[a]=1;
                ans[a]='A';
            } else if(visited[b] == 0) {
                visited[b]=1;
                ans[b]='A';
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}