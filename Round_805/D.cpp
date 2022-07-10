#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,p;
    string str;
    cin>>test;
    while(test--) {
        vector<ll> vec(27,0), countRem(27,0);
        cin>>str;
        cin>>p;
        ll sum=0;
        for(ll index=0; index<str.length(); index++) {
            int val=str[index]-'a';
            val++;
            sum += val;
            vec[val]++;
        }
        string ans="";
        for(ll index=26; index>0; index--) {
            if(vec[index]==0) {continue;}
            if(sum <= p) {
                break;
            }
            while(vec[index]!=0 && sum > p) {
                sum -= index;
                countRem[index]++;
                vec[index]--;
            }
        }

        for(ll index=0; index<str.length(); index++) {
            int val=str[index]-'a';
            val++;
            if(countRem[val]!=0) {
                countRem[val]--;
                continue;
            }
            ans+=str[index];
        }
        cout<<ans<<endl;
    }
    return 0;
}