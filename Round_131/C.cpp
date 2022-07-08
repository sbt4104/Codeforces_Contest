#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, N, M, val, ans;
    cin>>test;
    while(test--) {
        cin>>N>>M;
        ans=0;
        vector<ll> vec(N+1,0);
        for(ll index=0; index<M; index++) {
            cin>>val;
            vec[val]++;
        }
        while(1) {
            ll count1=0, currMaxi=1000002;
            for(ll index=1; index<=N; index++) {
                if(vec[index]!=0) {
                    currMaxi=min(currMaxi, vec[index]);
                    count1++;
                }
            }
            //cout<<"currMaxi: "<<currMaxi<<" count1: "<<count1<<endl;
            if(count1==0) {
                break;
            }
            ans += currMaxi;
            for(ll index=1; index<=N; index++) {
                if(vec[index]!=0) {
                    vec[index]-=currMaxi;
                }
            }
            sort(vec.begin(), vec.end(), greater<ll>());
            for(ll index=1; index<=N; index++) {
                if(rest>=vec[index]) {
                    rest-=vec[index];
                    vec[index]=0;
                } else {
                    rest = 0;
                    vec[index]-=rest;
                }
            }
            if(count1==1) {
                ll  X = ceil(currMaxi*2/3.0);
                ans += X;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}