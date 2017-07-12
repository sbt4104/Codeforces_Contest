#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, n;
    string str;
    cin>>test;
    while(test--) {
        cin>>n;
        cin>>str;
        ll count=0;
        vector<ll> vec(26,0);
        for(ll index=0; index<n; index++) {
            ll curr = str[index]-'A';
            if(vec[curr]==0) {
                count +=2;
            } else {
                count++;
            }
            vec[curr]++;
        }
        cout<<count<<endl;
    }
    return 0;
}