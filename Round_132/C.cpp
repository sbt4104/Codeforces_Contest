/*
?   (   ?   )   (   )   ?   )
0   1   1   0   1   0   0   -1

open - close = 1
open + close = 3;
open = 2
close = 1

(()
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test;
    string str;
    cin>>test;
    while(test--) {
        cin>>str;
        ll n=str.length();
        vector<ll> countOdd(n,0), countEven(n,0), visited(n,0);
        ll open=0, close=0, quest=0, prefix=0;
        for(ll index=0; index<n; index++) {
            if(str[index]=='(') {
                prefix++;
            } else if(str[index]==')') {
                prefix--;
            } else {
                quest++;
            }
        }

        /* 
            open-close = -prefix
            open+close = quest
        */

        open = (-prefix + quest)/2;
        close = open+prefix;

        if(close==0 || open==0) {
            // unique
            cout<<"YES\n";
            continue;
        }

        string optim2 = string(open-1, '(') + string(1,')') + string(1,'(') + string(close-1,')');
        bool flag=true;
        ll pos=0;
        for(ll index=0; index<n; index++) {
            if(str[index]=='?') {
                str[index]=optim2[pos];
                pos++;
            }
        }
        prefix=0;
        for(ll index=0; index<n; index++) {
            if(str[index]=='(') {
                prefix++;
            } else {
                prefix--;
            }

            if(prefix < 0) {
                flag=false;
                break;
            }
        }
        cout<<(flag==true ? "NO\n" : "YES\n");

    }
    return 0;
}