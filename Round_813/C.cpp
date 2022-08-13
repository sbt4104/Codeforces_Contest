#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        ll count=0;
        vector<ll> vec(n);
        unordered_map<ll, vector<ll>> mp;
        for(ll i=0; i<n; i++) {
            cin>>vec[i];
        }

        for(ll i=0; i<n; i++) {
            if(mp.find(vec[i])==mp.end()) {
                mp[vec[i]] = {i};
            } else {
                mp[vec[i]].push_back(i);
            }
        }

        for(ll i=n-2; i>=0; i--) {
            if(vec[i] > vec[i+1]) {
                vector<ll> temp = mp[vec[i]];
                ll size = temp.size(), prev=0;
                //cout<<"curr: "<<vec[i]<<" size: "<<size<<endl;
                for(ll j=0; j<size; j++) {
                    ll index = temp[j];
                    prev=index;
                    //cout<<"index: "<<index<<endl;
                    vec[index] = 0;
                }
                count++;
                if(prev>i) {
                    i=prev;
                }
            }
        }

        cout<<count<<endl;
    }
    return 0;
}