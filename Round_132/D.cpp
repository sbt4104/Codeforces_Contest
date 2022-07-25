#include<bits/stdc++.h>
using namespace std;

typedef int ll;
const ll MAX_N=200001;
const ll LOG=18;
ll m[MAX_N][LOG];
ll a[MAX_N];
ll LOGN=0;
vector<int> pw(MAX_N, 0);
void preprocess(ll &m1) {
    for(ll index=1; index<LOGN; index++) {
        for(ll pos=0; pos+(1<<index)-1<m1; pos++) {
            m[pos][index] = max(m[pos][index-1], m[pos+(1<<(index-1))][index-1]);
        }
    }
}

ll query(ll a, ll b){
    ll size=b-a+1,k=0;
    while(1<<(k+1) <= size) {
        k++;
    }
    return max(m[a][k], m[b-(1<<k)+1][k]);
}

int main() {
    ll test,n,m1,q,xs,ys,xf,yf,k;
        cin>>n>>m1;
        LOGN = 0;
        while ((1 << LOGN) <= m1) ++LOGN;
        
        for(ll index=0; index<m1; index++) {
            cin>>a[index];
            m[index][0]=a[index];
        }
        preprocess(m1);
        cin>>q;
        while(q--) {
            scanf("%d%d%d%d%d",&xs,&ys,&xf,&yf,&k);
            yf--;ys--;
            if(xf%k!=xs%k || yf%k!=ys%k) {
                puts("NO");
                continue;
            }
            ll hMax = query(min(ys,yf), max(ys,yf));
            ll hPos = ((n-xs)/k)*k + xs;
            if(hPos>hMax) {
                puts("YES");
            } else {
                puts("NO");
            }
        }

    return 0;
}