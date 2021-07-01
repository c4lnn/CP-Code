//µ¹Ðò²î·Ö
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)

typedef pair<int,int>pii;

const int maxn=1e5+5;
const int mod=1e9+7;

int n,m;
int opt[maxn],l[maxn],r[maxn];

int d[maxn],cz[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&opt[i],&l[i],&r[i]);
    mem(d,0);
    mem(cz,0);
    cz[m]=1;
    for(int i=m;i>=1;i--)
    {
        cz[i]=(cz[i]+cz[i+1])%mod;
        if(opt[i]==1) d[l[i]]=(d[l[i]]+cz[i])%mod,d[r[i]+1]=((d[r[i]+1]-cz[i])%mod+mod)%mod;
        else if(opt[i]==2) cz[r[i]]=(cz[r[i]]+cz[i])%mod,cz[l[i]-1]=((cz[l[i]-1]-cz[i])%mod+mod)%mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+d[i])%mod,printf("%d ",ans);
    return 0;
}