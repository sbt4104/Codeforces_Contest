#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<string> vec(n);
        unordered_map<string, ll> mp;
        for(ll index=0; index<n; index++) {
            cin>>vec[index];
            mp[vec[index]]++;
        }
        string ans="";
        for(ll index=0; index<n; index++) {
            bool flag=false;
            for(ll pos=1; pos<vec[index].length(); pos++) {
                string str1 = vec[index].substr(0,pos);
                string str2 = vec[index].substr(pos, vec[index].length()-pos);
                if(mp.find(str1) != mp.end() && mp.find(str2) != mp.end()) {
                    flag =true;
                    break;
                }
            }
            ans += (flag ? "1" : "0");
        }
        cout<<ans<<endl;
    }
    return 0;
}