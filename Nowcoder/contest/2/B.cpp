#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll f[400][400];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a,b;
    for(int i=1;i<n;i++) cin>>a>>b;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++) {
            f[i][j]=(f[i-1][j]+f[i-1][j-1]*(k-j+1))%mod;
        }
    ll res=0;
    for(int i=1;i<=k;i++) res=(res+f[n][i])%mod;
    cout<<res<<endl;
    return 0;
}