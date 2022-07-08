#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test, val;
    cin>>test;
    while(test--) {
        int count=0;
        for(int i=0;i<2; i++) {
            for(int j=0; j<2;j++) {
                cin>>val;
                count += val;
            }
        }
        switch(count) {
            case 0: cout<<0<<endl;
            break;
            case 1: cout<<1<<endl;
            break;
            case 2: cout<<1<<endl;
            break;
            case 3: cout<<1<<endl;
            break;
            case 4: cout<<2<<endl;
            break;
        }
    }
    return 0;
}