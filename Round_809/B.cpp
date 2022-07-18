#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,N;
    cin>>test;
    while(test--) {
        cin>>N;
        vector<ll> vec(N), ans(N+1);
        vector<vector<ll>> store(N+1);
        for(ll index=0; index<N; index++) {
            cin>>vec[index];
            store[vec[index]].push_back(index);
        }
        for(ll index=1; index<=N; index++) {
            ll len=store[index].size();
            if( len <=1) {
                ans[index]=len;
                continue;
            }
            ll fir=store[index][0];
            ll sec=store[index][1];
            ll pos=1, count1=1, count2=1;
            while(pos<len) {
                if((store[index][pos] - store[index][pos-1])%2) {
                    count1++;
                }
                pos++;
            }
            pos=2;
            while(pos<len) {
                if((store[index][pos] - store[index][pos-1])%2) {
                    count2++;
                }
                pos++;
            }
            ans[index]=max(count1, count2);
        }
        for(ll index=1; index<=N; index++) {
            cout<<ans[index]<<" ";
        }
        cout<<endl;
    }
    return 0;
}