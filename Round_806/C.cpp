#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n, m;
    string moves;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<int> seq(n), ans(n);
        for(ll index=0; index<n; index++) {
            cin>>seq[index];
        }
        for(ll pos=0; pos<n; pos++) {
            cin>>m;
            cin>>moves;
            ll count=0;
            for(ll index=0; index<m; index++) {
                if(moves[index]=='U') {
                    count--;
                } else {
                    count++;
                }
            }
            ans[pos] = (seq[pos]+count)%10;
            if(ans[pos] < 0) {ans[pos] += 10;}
        }
        for(ll pos=0; pos<n; pos++) {
            cout<<ans[pos]<<" ";
        }
        cout<<endl;
    }
    return 0;
}