#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<ll> vec(n);
        
        ll start = ceil(sqrt((n-1)*1.0));
        ll fix = n-1;
        start = start*start- (n-1);
        for(ll index=n-1; index>=0; index--) {
            if(start > fix) {
                fix = index;
                start = ceil(sqrt((index)*1.0));
                start = start*start - index;
                //cout<<"index: "<<index<<" start: "<<start<<endl;
            }
            vec[index] = start;
            start++;
        }
        for(ll index=0; index<n; index++) {
            cout<<vec[index]<<" ";
        }
        cout<<endl;
    }
    return 0;
}