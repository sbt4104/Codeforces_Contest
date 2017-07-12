#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test;
    string str;
    cin>>test;
    while(test--) {
        cin>>str;
        if(str.length() != 3) {
            cout<<"NO\n";
            continue;
        }
        if(!(str[0]=='Y' || str[0]=='y')) {
            cout<<"NO\n";
            continue;
        }
        if(!(str[1]=='E' || str[1]=='e')) {
            cout<<"NO\n";
            continue;
        }
        if(!(str[2]=='S' || str[2]=='s')) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}