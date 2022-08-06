#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll N_MAX=1001;
ll arr[N_MAX][N_MAX];

void preformSwap(int k, int n) {
    for(ll index=0; index<n; index++) {
        // swap   [0][k] with [k][0], [1][k] with [k][1].....
        ll temp = arr[k][index];
        arr[k][index] = arr[index][k];
        arr[index][k] = temp;  
    }
}

int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                cin>>arr[i][j];
            }
        }
        for(ll k=0; k<n; k++) {
            // check if we need to swap
            bool flag=false;

            for(ll i=0; i<n; i++) {
                if(arr[k][i] < arr[i][k]) {
                    flag=true;
                    break;
                } else if(arr[k][i] > arr[i][k]){
                    break;
                }
            }

            if(flag) {
                //cout<<"swap("<<k<<")\n";
                preformSwap(k,n);
            }
        }

        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
    return 0;
}