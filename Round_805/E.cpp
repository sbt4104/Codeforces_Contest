#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

	ll  test, N, A,B;
    cin>>test;
    while(test--) {
        cin>>N;
        ll arr[N][2];
        ll input[N][2];
        for(ll index=0; index<N; index++) {
            arr[index][0]=arr[index][1]=0;
            cin>>input[index][0]>>input[index][1];
        }

        bool flag=true;
        for(ll index=0; index<N; index++) {
            ll A=input[index][0];
            ll B=input[index][1];
            if(index==0) {
                arr[A][1]=1;
                arr[B][1]=1;
                continue;
            }

            // same vertices connected
            if(A==B) {
                flag=false;
                continue;
            }
            // no encounter before
            if((arr[A][0]==0 && arr[A][1]==0) && (arr[B][0]==0 && arr[B][1]==0)) {
                //cout<<"in here index: "<<index<<" group: "<<1<<endl;
                arr[A][1]=1;
                arr[B][1]=1;
                continue;                                
            }

            // any 1 present in both the groups
            if((arr[A][0]==1 && arr[A][1]==1) || (arr[B][0]==1 && arr[B][1]==1)) {
                //cout<<"in here index: "<<index<<" group: "<<2<<endl;
                flag = false;
                continue;
            }

            // A in 1, B in other
            if((arr[A][0]==1 && arr[A][1]==0) && (arr[B][0]==0 && arr[B][1]==1)) {
                //cout<<"in here index: "<<index<<" group: "<<3<<endl;
                flag = false;
                continue;
            }

            // A in 1, B in other
            if((arr[A][0]==0 && arr[A][1]==1) && (arr[B][0]==1 && arr[B][1]==0)) {
                //cout<<"in here index: "<<index<<" group: "<<4<<endl;
                flag = false;
                continue;
            }

            // A & B belongs to the same group
            if((arr[A][0]==1 && arr[B][0]==1) && (arr[A][1]==0 && arr[B][1]==0)) {
                //cout<<"in here index: "<<index<<" group: "<<5<<endl;
                arr[A][1]=arr[B][1]=1;
                continue;
            }

            // A & B belongs to the same group
            if((arr[A][0]==0 && arr[B][0]==0) && (arr[A][1]==1 && arr[B][1]==1)) {
                //cout<<"in here index: "<<index<<" group: "<<6<<endl;
                arr[A][0]=arr[B][0]=1;
                continue;
            }
        
            // A is present, other absent
            if((arr[A][0]==1 || arr[A][1]==1) && (arr[B][0]==0 && arr[B][1]==0)) {
                //cout<<"in here index: "<<index<<" group: "<<7<<endl;
                if(arr[A][0]==1) {
                    arr[B][1]=1;
                } else {
                    arr[B][0]=1;
                }
                continue;
            }
            // B is present, other absent
            if((arr[B][0]==1 || arr[B][1]==1) && (arr[A][0]==0 && arr[A][1]==0)) {
                //cout<<"in here index: "<<index<<" group: "<<8<<endl;
                if(arr[B][0]==1) {
                    arr[A][1]=1;
                } else {
                    arr[A][0]=1;
                }
                continue;
            }

        }
        flag ? cout<<"YES\n" : cout<<"NO\n";
    }

	return 0;
}
