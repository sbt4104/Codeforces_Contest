#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Timer{
    public:
    ll H, M;
    Timer(ll a=0, ll b=0) {
        H=a, M=b;
    }
    void print() {
        cout<<"H: "<<H<<" M: "<<M<<endl;
    }
};

/*
3:50 - 1:40
3:30 - 1:40

3:30 - 5:40
3:30 - 5:20
*/
Timer compareTime(ll H, ll M, ll h, ll m){
    ll h1,m1;
    h1=h-H;
    m1=m-M;
    if(h < H) {
        if(M > m) {
            h1+=23;
            m1=60+m1;
        } else if(M <= m){
            h1+=24;
        }
    } else if(h > H){
        if(M < m) {

        } else if(M >= m){
            h1--;
            m1=60+m1;
        }
    } else {
        if(M > m) {
            h1+=23;
            m1=60+m1;
        } else {
            
        }
    }

    if(m1==60) {h1++; m1=0;}
    return Timer({h1,m1});
}
int main() {
    ll test,n,H,M,h,m;
    //compareTime(22,40,21,40).print();
    cin>>test;
    while(test--) {
        cin>>n>>H>>M;
        ll ansH=25, ansM=0;
        while(n--) {
            cin>>h>>m;
            Timer temp = compareTime(H,M, h,m);
            if(temp.H < ansH) {
                ansH=temp.H;
                ansM=temp.M;
            } else if(temp.H == ansH) {
                if(temp.M < ansM) {
                    ansM=temp.M;
                }
            }
            //two stages
        }
        cout<<ansH<<" "<<ansM<<endl;
    }
    return 0;
}