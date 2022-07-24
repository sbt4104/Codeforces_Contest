#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        if(n==1) {
            cout<<1<<endl;
            continue;
        }
        //ll count=0;
        vector<ll> vec(n+1,0);
        for(ll index=1; index<=n; index++) {
            if(index%2) {
                vec[index]=index+1;
                //if((index+1)%index==0) {count++;}
            } else  {
                vec[index]=index-1;
                //if((index-1)%index==0) {count++;}
            }
        }
        if(n%2) {
                vec[n]=2;
                vec[1]=n;
        }

        for(ll index=1; index<=n; index++) {
            cout<<vec[index]<<" ";
        }
        cout<<endl;
        //cout<<"count: "<<count<<endl; 
    }
    return 0;
}