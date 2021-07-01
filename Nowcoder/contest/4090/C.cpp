#include<bits/stdc++.h>

using namespace std;

const int N=20;

int n,m,t;
int a[N][N];
int sum[N];
int ans;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    t=min(t,min(n,m));
    for(int i=0;i<(1<<m);i++) {
        int cnt=__builtin_popcount(i);
        int res=0;
        if(cnt>t) continue;
        memset(sum,0,sizeof sum);
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                if(i&1<<k) res+=a[j][k];
                else sum[j]+=a[j][k];
            }
        }
        sort(sum,sum+n);
        for(int j=n-1,k=t-cnt;k;j--,k--) {
            res+=sum[j];
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}