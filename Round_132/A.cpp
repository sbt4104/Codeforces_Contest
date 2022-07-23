#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,x,a,b,c;
    cin>>test;
    ll arr[3];
    while(test--) {
        cin>>x;
        cin>>arr[0]>>arr[1]>>arr[2];
        x--;arr[0]--;arr[1]--;arr[2]--;
        int count=2;
        bool flag=true;
        while(count--) {
            x=arr[x];
            if(x==-1) {
                flag=false;
                break;
            }
        }
        cout<<(flag? "YES\n" : "NO\n");
    }
    return 0;
}