#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, N, M, val, ans;
    cin>>test;
    while(test--) {
        cin>>N>>M;
        vector<ll> vec(N+1,0);
        for(ll index=0; index<M; index++) {
            cin>>val;
            vec[val]++;
        }
        // invariant: l is always 0 (false) & r is 1 (true)
        ll l=0;
        ll r=10000000000;
        while(r > l+1) {
            //cout<<"r: "<<r<<" l: "<<l<<endl;
            ll mid = (r+l)/2;
            ll workDone=0;
            for(ll index=1; index<=N; index++) {
                if(vec[index] >= mid) {
                    workDone += mid;
                } else {
                    workDone += (vec[index] + (mid-vec[index])/2);
                }
            }

            if(workDone >= M) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}