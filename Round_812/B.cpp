#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<ll> vec(n);
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
        }
        ll up=0, down=0;
        bool inc = true;
        for(ll index=1; index<n; index++) {
            if(vec[index]<vec[index-1] && inc==true) {
                inc = false;
                up++;
            } else if(vec[index]>vec[index-1] && inc==false) {
                inc = true;
                down++;
                break;
            }
        }

        if(up<=1 && down==0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}