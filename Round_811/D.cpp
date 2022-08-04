#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool search(ll &i, ll &j1, string &str, vector<string> &Str) {
    for(ll index=0; index<Str.size(); index++) {
        string temp=Str[index];
        ll j;
        for(j=0; j<temp.length(); j++) {
            if(str[j+i]!=temp[j]) {break;}
        }
        if(j==temp.length() && temp.length()==j1-i+1) {return true;}
    }
    return false;
}

ll search2(string &str, ll &i, ll &next, vector<string> &String) {
    for(ll index=0; index<String.size(); index++) {
        string temp=String[index];
        ll j;
        for(j=0; j<temp.length(); j++) {
            if(temp[j]!=str[i+j]) {break;}
        }
        if(j==temp.length() && temp.length()==next-i+1) {return index+1;}
    }
    return -1;
}

int main() {
    ll test,n;
    string str,temp;
    cin>>test;
    while(test--) {
        cin>>str;
        vector<ll> vec(str.length(),-1);
        cin>>n;
        vector<string> String(n); 
        ll index=0;
        while(index<n) {
            cin>>String[index];
            index++;
        }

        bool flag=true;
        ll curr=0, last=0, count=0, i, j, k, next;
        for(i=0; i<str.length(); i++) {
            for(j=i; j<min(i+11,(ll)str.length()); j++) {
                if(search(i,j,str, String)) {
                    vec[i]=j;
                }
            }
        }
        
        vector<pair<ll,ll>> ans;
        for(i=0; i<str.length(); i++) {
            ll index=i;
            next=vec[i];
            if(next==-1) {flag=false; break;}
            ans.push_back({search2(str, i,next, String), index+1});
            curr=next;
            //cout<<"i: "<<i<<" next: "<<next<<endl;
            for(j=i; j<=min((ll)str.length()-1,curr+1); j++) {
               if(vec[j] >= next) {
                    next=vec[j];
                    i=j-1;
               }
            }
            count++;
            if(curr==str.length()-1) {break;}
        }

        if(flag==false) {cout<<-1<<endl; continue;}
        cout<<count<<endl;
        for(ll index=0; index<ans.size(); index++) {
            cout<<ans[index].first<<" "<<ans[index].second<<endl;
        }
    }
    return 0;
}