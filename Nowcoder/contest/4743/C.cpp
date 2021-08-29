#include<bits/stdc++.h>
using namespace std;
int x,y;
int cal(int p) {
    return p+min((x-2*p)/4,y-3*p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>x>>y;
        int l=0,r=min(x/2,y/3);
        while(l<r) {
            int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
            if(cal(lmid)>cal(rmid)) r=rmid-1;
            else l=lmid+1;
        }
        cout<<cal(l)<<'\n';
    }
    return 0;
}