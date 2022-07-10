#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main() {
    ll test;
    string str;
    cin>>test;
    while(test--) {
        cin>>str;
        ll index=0, ans=0;
        while(index<str.length()) {
            set<int> st;
            while(st.size() <= 3 && index<str.length()) {
                st.insert(str[index]);
                if(st.size() > 3) {break;}
                index++;
            }
            //cout<<"index: "<<index<<endl;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}