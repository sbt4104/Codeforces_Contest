#include<bits/stdc++.h>
using namespace std;

/*
2 cases:
1] starts with 1
2] its a table
*/

typedef long long int ll;
int main() {
    ll test,N;
    cin>>test;
    while(test--) {
        cin>>N;
        vector<ll> vec(N);
        for(ll index=0; index<N; index++) {
            cin>>vec[index];
        }

        bool flag=true;
        for(ll index=1; index<N; index++) {
            if(vec[index]%vec[0] != 0) {
                    flag=false; break;
            }
        }
        cout<<(flag? "YES\n": "NO\n");
    }
    return 0;
}