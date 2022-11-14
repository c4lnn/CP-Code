#include<iostream>
#include<cstring>
#include<cmath>
#include<climits>

using namespace std;

typedef long long ll;

const int N=1e6+5;

int l,r;
int vis[N];
int primes[N];
int cnt;

void prime()
{
    for(int i=2;i<=N;i++)
    {
        if(!vis[i]) vis[i]=1,primes[++cnt]=i;
        for(int j=1;j<=cnt;j++)
        {
            if(i>N/primes[j]) break;
            vis[primes[j]*i]=1;
            if(i%primes[j]==0) break;
        }
    }
}
void solve()
{
    memset(vis,0,sizeof vis);
    for(int i=1;primes[i]<=r/primes[i];i++)
    {

        for(int j=ceil((double)l/primes[i]);j<=r/primes[i];j++)
            if(j!=1)
                vis[j*primes[i]-l]=1;
    }
    int pre=-1;
    int minn=INT_MAX,maxn=-1;
    pair<int,int> res_min,res_max;
    for(int i=0;i<=r-l;i++)
        if(!vis[i])
        {
            if(pre!=-1)
            {

                if(i-pre<minn)
                {
                    minn=i-pre;
                    res_min.first=pre,res_min.second=i;
                }
                if(i-pre>maxn)
                {
                    maxn=i-pre;
                    res_max.first=pre,res_max.second=i;
                }
            }
            pre=i;
        }
    if(maxn==-1) cout<<"There are no adjacent primes."<<endl;
    else cout<<res_min.first+l<<","<<res_min.second+l<<" are closest, "<<res_max.first+l<<","<<res_max.second+l<<" are most distant."<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    prime();
     while(cin>>l>>r)
     {
         if(l==1) l++;
         solve();
     }
    return 0;
}