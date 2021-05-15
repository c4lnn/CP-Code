#include<iostream>
#include<cstring>
using namespace std;
const int N=21;
int n,m;
int p[N*10],d[N*10];
int dp[N][N*40];
int pre[N][N*40][N*40];
int cnt;

void show(int x,int dif,int sum,int sum_p,int sum_d)
{
    if(x==0)
    {
        cout<<"Jury #"<<++cnt<<endl; 
        cout<<"Best jury has value "<<sum_p<<" for prosecution and value "<<sum_d<<" for defence:"<<endl;
        return;
    }
    int t=pre[x][dif][sum];
    show(x-1,dif-(p[t]-d[t]+20),sum-p[t]-d[t],sum_p+p[t],sum_d+d[t]);
    cout<<" "<<t;
}
int main()
{
    while(cin>>n>>m&&n&&m)
    {
        for(int i=1;i<=n;i++) cin>>p[i]>>d[i];
        memset(dp,-1,sizeof dp);
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=min(i,m);j>0;j--)
                for(int k=p[i]-d[i]+20;k<=800;k++)
                {
                    if(dp[j][k]<dp[j-1][k-(p[i]-d[i]+20)]+p[i]+d[i]&&dp[j-1][k-(p[i]-d[i]+20)]>=0)
                    {
                        dp[j][k]=dp[j-1][k-(p[i]-d[i]+20)]+p[i]+d[i];
                        pre[j][k][dp[j][k]]=i;
                    }
                }
        for(int k=0;;k++)
        {
            int i=m*20-k,j=m*20+k;
            if(dp[m][i]!=-1||dp[m][j]!=-1)
            {
                int t=dp[m][i]>=dp[m][j]?i:j;
                show(m,t,dp[m][t],0,0);
                cout<<endl<<endl;
                break;
            }
        }
    }
    return 0;
}