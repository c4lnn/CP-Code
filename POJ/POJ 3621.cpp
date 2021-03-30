#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1005;
int n,m,cnt[N];
DB a[N],dist[N];
bool st[N];
vector<pair<int,DB> > G[N];
bool spfa(DB mid) {
    for(int i=1;i<=n;i++) {
        dist[i]=1e9;
        cnt[i]=0;
        st[i]=false;
    }
    queue<int> q;
    q.push(1);
    st[1]=true;
    dist[1]=0;
    cnt[1]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i].FI;
            DB w=G[u][i].SE*mid-a[u];
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n) return true;
                if(!st[v]) st[v]=true,q.push(v);
            }
        }
    }
    return false;
}
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=m;i++) {
        int u,v;
        DB w;
        scanf("%d%d%lf",&u,&v,&w);
        G[u].PB(MP(v,w));
    }
    DB l=0,r=10000000;
    DB res=0;
    while(r-l>1e-4) {
        DB mid=(l+r)/2;
        if(spfa(mid)) l=mid;
        else r=mid;
    }
    printf("%.2f\n",r);
    return 0;
}