#include<bits/stdc++.h>

using namespace std;

int x,y;

int cal(int p) {
    return p+min((x-2*p)/4,y-3*p);
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>x>>y;
        int l=0,r=min(x/2,y/3);
        while(r-l>10) {
            int mid=(r-l)/3;
            if(cal(l+mid)>cal(r-mid)) r=r-mid;
            else l=l+mid;
        }
        int ans=0;
        for(int i=l;i<=r;i++) ans=max(ans,cal(i));
        cout<<ans<<endl;
    }
    return 0;
}