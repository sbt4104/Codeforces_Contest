#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,m;
    cin>>test;
    while(test--) {
        cin>>n>>m;
        vector<ll> vec(m);
        for(ll index=0; index<m; index++) {
            cin>>vec[index];
        }

        sort(vec.begin(), vec.end());

        vector<ll> interval;
        ll start=0;
        if(vec[0] > 1) {
            start += vec[0]-1;
        }
        if(vec[m-1] < n) {
            start += n-vec[m-1];
        }

        //cout<<"start: "<<start<<endl;
        if(start>0) {
            interval.push_back(start);
        }
        for(ll index=1; index<m; index++) {
            ll diff = vec[index]-vec[index-1]-1;
           // cout<<"diff "<<diff<<endl;
            if(diff>0) {
                interval.push_back(diff);
            }
        }

        sort(interval.begin(), interval.end(), greater<ll>());

        // cout<<"intervals\n";
        // for(ll index=0; index<interval.size(); index++) {
        //     cout<<interval[index]<<" ";
        // } cout<<endl;

        ll days=0;
        ll save=0;
        for(ll index=0; index<interval.size(); index++) {
            ll total = interval[index]-2*days;
            //if(vec[index]%2==0 && total==0) {total++;}
            //cout<<"toal: "<<total<<endl;
            if(total > 0) {
                if(total==1) {save += total;} else {
                save += total-1;}
            }
            days+=2;
        }

        cout<<n-save<<endl;
    }
    return 0;
}