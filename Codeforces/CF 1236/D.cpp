#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mem(i,j) memset(i,j,sizeof(i))
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=1e5+5;
ll n,m;
int k;
int a,b;
set<int>x[maxn],y[maxn];
int main()
{
    scanf("%I64d%I64d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        x[a].insert(b);
        y[b].insert(a);
    }
    int turn=1;
    int xx=1,yy=1;
    ll cnt=1;
    int t;
    int minx=2,maxx=n,miny=1,maxy=m;
    while(1)
    {
        if(turn==1)
        {
            t=yy;
            auto it=x[xx].lower_bound(yy);
            if(it==x[xx].end()) yy=m;
            else yy=*it-1;
            if(yy>maxy) yy=maxy;
            maxy=yy-1;
            if(t-yy==0&&xx!=1&&yy!=1) break;
            cnt+=yy-t;
        }
        else if(turn==2)
        {
            t=xx;
            auto it=y[yy].lower_bound(xx);
            if(it==y[yy].end()) xx=n;
            else xx=*it-1;
            if(xx>maxx) xx=maxx;
            maxx=xx-1;
            if(t-xx==0) break;
            cnt+=xx-t;
        }
        else if(turn==3)
        {
            t=yy;
            auto it=x[xx].lower_bound(yy);
            if(it==x[xx].begin()) yy=1;
            else yy=*(--it)+1;
            if(yy<miny) yy=miny;
            miny=yy+1;
            if(t-yy==0) break;
            cnt+=t-yy;
        }
        else if(turn==0)
        {
            t=xx;
            auto it=y[yy].lower_bound(xx);
            if(it==y[yy].begin()) xx=1;
            else xx=*(--it)+1;
            if(xx<minx) xx=minx;
            minx=xx+1;
            if(t-xx==0) break;
            cnt+=t-xx;
        }
        if(cnt==n*m-k) {printf("Yes\n");return 0;}
        turn=(turn+1)%4;
    }
    printf("No\n");
    return 0;
}