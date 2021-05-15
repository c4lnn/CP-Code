#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=2e3+5;

int n;
ll a[N];
ll c[N];
ll dp[N][N];
int cnt;
ll res;

void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0][1]=0;
    for(int i=1;i<=n;i++)
    {
        ll minn=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=cnt;j++)
        {
            minn=min(minn,dp[i-1][j]);
            dp[i][j]=min(dp[i][j],minn+abs((int)(a[i]-c[j])));
        }
    }
    for(int i=1;i<=cnt;i++) res=min(res,dp[n][i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],c[++cnt]=a[i];
    sort(c+1,c+1+cnt);
    cnt=unique(c+1,c+1+cnt)-c-1;
    res=0x3f3f3f3f3f3f3f3f;
    solve();
    reverse(c+1,c+1+cnt);
    solve();
    cout<<res<<endl;
    return 0;
}