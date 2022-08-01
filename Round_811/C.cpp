#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        string ans="";

        ll index=9, sum=0, total=n;
        while(n && index>0) {
            if(n>=index) {
                ans += index+'0';
                sum+=index;
                n-=index;
                index--;
            } else {
                ans += total-sum + '0';
                break;
            }
        }
        //ans += index+'0';
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    return 0;
}