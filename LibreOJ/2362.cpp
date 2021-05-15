#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e5+5;
int n,m,q,t;
ll u,v;
int len[N];
queue<int>Q[3];

int main()
{
    scanf("%d%d%d%lld%lld%d",&n,&m,&q,&u,&v,&t);
    for(int i=0;i<n;i++) scanf("%d",&len[i]);
    sort(len,len+n);
    for(int i=n-1;i>=0;i--) Q[0].push(len[i]);
    int delta=0;
    for(int i=1;i<=m;i++)
    {
        int now;
        int maxn=INT_MIN;
        for(int j=0;j<3;j++) if(!Q[j].empty()&&Q[j].front()>maxn) maxn=Q[j].front(),now=j;
        maxn+=delta;
        if(i%t==0) printf("%d ",maxn);
        Q[1].push(maxn*u/v-delta-q);
        Q[2].push(maxn-maxn*u/v-delta-q);
        delta+=q;
        Q[now].pop();
    }
    printf("\n");
    for(int i=1;i<=m+n;i++)
    {
        int now;
        int maxn=INT_MIN;
        for(int j=0;j<3;j++) if(!Q[j].empty()&&Q[j].front()>maxn) maxn=Q[j].front(),now=j;
        if(i%t==0) printf("%d ",maxn+delta);
        Q[now].pop();
    }
    return 0;
}