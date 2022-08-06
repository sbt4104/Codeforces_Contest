#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void process(ll curr, ll prev, ll i, ll j, vector<ll> &clock) {

}

int main() {
    ll test,n;
    cin>>test;
    while(test--) {
        cin>>n;
        vector<vector<ll>> vec(2), clock(2), anti(2), zigzag(2);
        vec[0] = vec[1] = clock[0] = clock[1] = anti[0] = anti[1] = zigzag[0] = zigzag[1] = vector<ll> (n);
        for(ll i=0; i<2; i++) {
            for(ll j=0; j<n; j++) {
                cin>>vec[i][j];
            }
        }

        // can go clockwises
        clock[0][0]=0;
        ll time=0, diff;
        for(ll j=1; j<n; j++) {
            diff = vec[0][j] - time;
            if(diff <= 0) {
                clock[0][j]=time+1;
                time=clock[0][j];
            } else {
                clock[0][j] = clock[0][j-1] + diff+1; 
                time=clock[0][j];
            }
        }

        diff = vec[1][n-1] - time;
        if(diff <=0) {
            clock[1][n-1] = time+1;
            time=clock[1][n-1];
        } else {
            clock[1][n-1] = clock[0][n-1] + diff+1; 
            time=clock[1][n-1];
        }

        for(ll j=n-2; j>=0; j--) {
            diff = vec[1][j] - time;
            if(diff <= 0) {
                clock[1][j]=time+1;
                time=clock[1][j];
            } else {
                clock[1][j] = clock[1][j+1] + diff+1; 
                time=clock[1][j];
            }
        }


        // can go anticlockwises
        anti[0][0]=0;
        time=0, diff;

        diff = vec[1][0] - time;
        if(diff <=0) {
            anti[1][0] = time+1;
            time=anti[1][0];
        } else {
            anti[1][0] = anti[0][0] + diff+1; 
            time=anti[1][0];
        }

        for(ll j=1; j<n; j++) {
            diff = vec[1][j] - time;
            if(diff <= 0) {
                anti[1][j]=time+1;
                time=anti[1][j];
            } else {
                anti[1][j] = anti[1][j-1] + diff+1; 
                time=anti[1][j];
            }
        }

        diff = vec[0][n-1] - time;
        if(diff <=0) {
            anti[0][n-1] = time+1;
            time=anti[0][n-1];
        } else {
            anti[0][n-1] = anti[1][n-1] + diff+1; 
            time=anti[0][n-1];
        }

        for(ll j=n-2; j>=0; j--) {
            diff = vec[0][j] - time;
            if(diff <= 0) {
                anti[0][j]=time+1;
                time=anti[0][j];
            } else {
                anti[0][j] = anti[0][j+1] + diff+1; 
                time=anti[0][j];
            }
        }

        // solve zigzag
        zigzag[0][0]=0;
        time=0, diff;
        for(ll j=0; j<n; j++) {
            if(j%2==0) {
                //go down and right;
                diff = vec[1][j] - time;
                if(diff <=0) {
                    zigzag[1][j] = time+1;
                    time=zigzag[1][j];
                } else {
                    zigzag[1][j] = zigzag[0][j] + diff+1; 
                    time=zigzag[1][j];
                }
            } else {
                // go up ans right;
                diff = vec[0][j] - time;
                if(diff <=0) {
                    zigzag[0][j] = time+1;
                    time=zigzag[0][j];
                } else {
                    zigzag[0][j] = zigzag[1][j] + diff+1; 
                    time=zigzag[0][j];
                }
            }

            // go right
            if(j<n-1) {
                ll k=0;
                if(j%2==0) {
                    k=1;
                }
                diff = vec[k][j+1] - time;
                if(diff <=0) {
                    zigzag[k][j+1] = time+1;
                    time=zigzag[k][j+1];
                } else {
                    zigzag[k][j+1] = zigzag[k][j] + diff+1; 
                    time=zigzag[k][j+1];
                }
            }
        }

        // cout<<"clockwise\n";
        // for(ll i=0; i<2; i++) {
        //     for(ll j=0; j<n; j++) {
        //         cout<<clock[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<"anti-clockwise\n";
        // for(ll i=0; i<2; i++) {
        //     for(ll j=0; j<n; j++) {
        //         cout<<anti[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<"zig-zag\n";
        // for(ll i=0; i<2; i++) {
        //     for(ll j=0; j<n; j++) {
        //         cout<<zigzag[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        ll glans=clock[1][0] - clock[0][0], ans=1e18;
        for(ll j=0; j<n; j++) {
            for(ll i=0; i<2; i++) {

            }
        }
        cout<<glans<<endl;
    }
    return 0;
}