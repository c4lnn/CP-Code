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

#define mem(i,j) memset(i,j,sizeof i)

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

int n;
pair<int,pii> a[50005];
int res[50005];
int cnt;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second.first),a[i].second.second=i;
        sort(a+1,a+1+n);
        priority_queue<pii,vector<pii>,greater<pii> > q;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(q.empty()||q.top().first>=a[i].first) q.push(make_pair(a[i].second.first,++cnt)),res[a[i].second.second]=cnt;
            else if(q.top().first<a[i].first) res[a[i].second.second]=q.top().second,q.push(make_pair(a[i].second.first,q.top().second)),q.pop();
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) printf("%d\n",res[i]);
    }
    return 0;
}