#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll give(ll a, ll c, ll b) {
    ll ans = max(b,a)-c+1;
    return max((ll)0, ans);
}

class storeData{
    public:
    string store;
    ll pos,sum,total;
    storeData(ll a, ll b, ll c, string str) {
        pos=a;
        sum=b;
        total=c;
        store=str;
    }
};

int main() {
    ll test,N;
    cin>>test;
    while(test--) {
        cin>>N;
        vector<ll> vec(N);
        for(ll index=0; index<N; index++) {
            cin>>vec[index];
        }
        ll sum=0;
        for(ll index=1; index<N-1; index+=2) {
            sum += give(vec[index-1] ,vec[index], vec[index+1]);
        }

        if(N%2) {
            cout<<sum<<endl;
            continue;
        }
        ll ans=sum;
        for(ll index=N-2; index>1; index-=2) {
            sum+=give(vec[index-1] ,vec[index], vec[index+1]);
            sum-=give(vec[index-2], vec[index-1], vec[index]);
            ans=min(ans, sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}