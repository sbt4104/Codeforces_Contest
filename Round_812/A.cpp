#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, n, x, y;
    cin>>test;
    while(test--) {
        cin>>n;
        ll xneg=0, xpos=0, yneg=0, ypos=0;
        ll index=0;
        while(index<n) {
            cin>>x>>y;
            // if(index==0) {
            //     xneg = xpos = x;
            //     yneg = ypos = y;
            // }
            if(x==0) {
                // y-axis
                if(y<=0){
                    yneg = min(y, yneg);
                } else {
                    ypos = max(y, ypos);
                }
            } else {
                // x-axis
                if(x<=0){
                    xneg = min(x, xneg);
                } else {
                    xpos = max(x, xpos);
                }
            }
            index++;
        }

        ll ans = 2*xpos - 2*xneg + 2*ypos - 2*yneg;
        cout<<ans<<endl;
    }
    return 0;
}