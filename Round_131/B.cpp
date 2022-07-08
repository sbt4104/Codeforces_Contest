#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, N;
    cin>>test;
    while(test--) {
        cin>>N;
        vector<ll> vec(N+1,0);
        cout<<2<<endl;
        for(ll index=1; index<=N; index++) {
            if(vec[index]%2) {continue;}
            for(ll indexJ=index; indexJ<=N; indexJ*=2) {
                vec[indexJ]=1;
                cout<<indexJ<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}   