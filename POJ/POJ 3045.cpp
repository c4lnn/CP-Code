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

pii a[50005];
bool cmp(pii a,pii b)
{
    return a.first+a.second<b.first+b.second;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n,cmp);
    int ans=0xc0c0c0c0;
    int sum=0;
    for(int i=0;i<n;i++) ans=max(ans,sum-a[i].second),sum+=a[i].first;
    printf("%d",ans);
    return 0;
}