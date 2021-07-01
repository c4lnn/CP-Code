#include<bits/stdc++.h>

using namespace std;

long long a[100010];

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++) {
        long long x,y;
        cin>>x>>y;
        a[i]=abs(x*x*y-2*x*y*y+y*y*y);
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) ans+=a[i]-a[i-1];
    cout<<ans<<endl;
    return 0;
}