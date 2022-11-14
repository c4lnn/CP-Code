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

int n;
pii a[10005];
int ans;

int cmp(pii a,pii b)
{
    return a.second<b.second;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n,cmp);
    int mid=a[n>>1].second;
    for(int i=0;i<n;i++) ans+=abs(a[i].second-mid);
    sort(a,a+n);
    for(int i=0;i<n;i++) a[i].first-=i;
    sort(a,a+n);
    mid=a[n>>1].first;
    for(int i=0;i<n;i++) ans+=abs(a[i].first-mid);
    printf("%d\n",ans);
    return 0;
}