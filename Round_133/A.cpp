#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        ll c = floor(n/3.0);
        if(n%3==1) {
            c++;
        } else if(n%3==2) {
            c++;
        }
        if(n==1 || n==4) {c=2;}

        cout<<c<<endl;
    }
    return 0;
}