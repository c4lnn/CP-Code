#include<bits/stdc++.h>

using namespace std;

int n;

map<int,int>mp;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int t;
        cin>>t;
        if(getchar()=='\n') {
            if(t==-1) {
                if(mp.empty()) cout<<"skipped"<<endl;
                else cout<<mp.begin()->second<<endl,mp.erase(mp.begin());
            }
            else {
                if(mp.count(t)) cout<<mp[t]<<endl;
                else cout<<0<<endl;
            }
        }
        else {
            int d;
            cin>>d;
            auto pos=mp.lower_bound(t-30);
            if(pos==mp.end()||pos->first>t+30) mp[t]+=d;
        }
    }
    return 0;
}