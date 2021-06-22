#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int s=0,cnt=0;
        for(int i=1;i<=n;i++) {
            int a;
            cin>>a;
            if(!a) cnt++;
            else s+=a;
        }
        cout<<max(cnt,s+cnt==0?cnt+1:0)<<endl;
    }
    return 0;
}