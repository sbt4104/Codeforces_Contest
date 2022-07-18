#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll give(ll a, ll c, ll b) {
    ll ans = max(b,a)-c+1;
    return max((ll)0, ans);
}

class storeData{
    public:
    string store;
    ll pos,sum,total;
    storeData(ll a, ll b, ll c, string str) {
        pos=a;
        sum=b;
        total=c;
        store=str;
    }
};

int main() {
    ll test,N;
    cin>>test;
    while(test--) {
        cin>>N;
        vector<ll> vec(N);
        for(ll index=0; index<N; index++) {
            cin>>vec[index];
        }
        ll ans=0;
        if(N%2) {
        for(ll index=1; index<N; index+=2) {
            if(index>=N || index+1 >= N) {break;}
            ll a=vec[index-1];
            ll b=vec[index+1];
            ans += give(a,vec[index], b);
            //vec[index]+=max((ll)0, ans);
        }
            cout<<ans<<endl;
            continue;
        }

        queue<storeData> queue;
        vector<string> soln;
        ans=1e12;
        for(ll index=0; index<N; index++) {
            if(index==0) {
                queue.push({-1, 0, 0, "0"});
                continue;
            }
            ll size=queue.size();
            while(size--) {
                storeData curr = queue.front();
                queue.pop();
                ll left = (N-1-index)/2;
                if(left + curr.total +2 < (N-2)/2) {
                    continue;
                }
                if(curr.total >= (N-2)/2) {
                    soln.push_back(curr.store);
                    continue;
                }
                if(index==N-1) {continue;}
                queue.push({curr.pos, curr.sum, curr.total, curr.store+"0"});
                if((index - curr.pos) > 1) {
                    queue.push({index, curr.sum+vec[index], curr.total+1, curr.store+"1"});
                }
            }
        }


        ans=0;
        for(ll index=0; index<soln.size(); index++) {
            string curr=soln[index];
            ll len=curr.length();
            ll currSum=0;
            //cout<<index<<" : "<<curr<<endl;
            for(ll pos=0; pos<len; pos++) {
                if(curr[pos]=='1') {
                    currSum+= give(vec[pos-1], vec[pos], vec[pos+1]);
                }
            }
            if(index==0) {
                ans=currSum;
            } else {
                ans=min(ans, currSum);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}