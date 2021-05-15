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

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

pii a[505];
int b[1005];
int s[1005][1005];
int k;
int c,n;
bool check(int x)
{
    for(int x1=0,x2=1;x2<=k;x2++)
    {
        while(b[x2]-b[x1+1]+1>x) x1++;
        for(int y1=0,y2=1;y2<=k;y2++)
        {   
            while(b[y2]-b[y1+1]+1>x) y1++; 
            if(s[x2][y2]-s[x2][y1]-s[x1][y2]+s[x1][y1]>=c) return true; 
        }   
    }
    return false;
}
int main()
{
    scanf("%d%d",&c,&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        b[++k]=a[i].first;
        b[++k]=a[i].second;
    }
    sort(b+1,b+1+k);
    k=unique(b+1,b+k+1)-b-1;
    for(int i=0;i<n;i++) s[lower_bound(b+1,b+1+k,a[i].first)-b][lower_bound(b+1,b+1+k,a[i].second)-b]++;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]+s[i][j]-s[i-1][j-1];        
    int l=1,r=10000;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",r);
    return 0;
}