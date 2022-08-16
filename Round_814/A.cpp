#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test,a,b;
    cin>>test;
    while(test--) {
        cin>>a>>b;
        ll odd=0, even=0;

        a%2 ? even++ : odd++;
        b%2 ? even++ : odd++;
        if(even && odd) {
            cout<<"Burenka\n";
        } else {
            cout<<"Tonya\n";
        }
    }
    return 0;
}