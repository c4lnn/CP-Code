#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)

typedef pair<int,int>pii;
int a[1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(m--)
    {
        int q;
        scanf("%d",&q);
        int ans=0;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(!f&&a[i]>q) ans++,f=1;
            else if(a[i]<=q) f=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}