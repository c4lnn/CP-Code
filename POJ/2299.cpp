#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

int n;
int a[500005];
int t[500005];
ll res;

void sort(int l,int r,int mid)
{
    int i=l,j=mid+1;
    int cnt=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) t[cnt++]=a[i++];
        else t[cnt++]=a[j++],res+=mid-i+1;
    }
    while(i<=mid) t[cnt++]=a[i++];
    while(j<=r) t[cnt++]=a[j++];
    for(int i=l;i<=r;i++) a[i]=t[i];
}
void merge(int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)>>1;
        merge(l,mid);
        merge(mid+1,r); 
        sort(l,r,mid);  
    }
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        res=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        merge(1,n);
        printf("%lld\n",res);
    }

    return 0;
}