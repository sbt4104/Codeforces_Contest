#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n,m;
    string a,b;
    cin>>test;
    while(test--) {
        cin>>n>>m;
        cin>>a;
        cin>>b;
        bool flag=true;
        ll ia=n-1, ib=m-1;
        while(ib>0) {
            if(a[ia]!=b[ib]) {
                flag=false;
                break;
            }
            ia--,ib--;
        }

        if(flag==false) {
            cout<<"NO\n";
            continue;
        }
        flag=false;
        char ch=b[0];
        while(ia>=0) {
            if(a[ia]==ch) {
                flag=true;
            }
            ia--;
        }

        cout<<(flag ? "YES\n" : "NO\n");
    }
    return 0;
}