#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, ans;
    string input, shouldBe;
    cin>>test;
    while(test--) {
        cin>>input;
        shouldBe = "1";
        if(input.length() > 1) {
            for(ll index=1; index<input.length(); index++) {
                shouldBe += "0";
            }
        }
        ans = stoi(input)-stoi(shouldBe);
        cout<<ans<<endl;
    }
    return 0;
}