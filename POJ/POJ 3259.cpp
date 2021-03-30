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
const int N=505;
int n,m,o,dist[N],cnt[N];
bool st[N];
VPII G[N];
bool spfa() {
    for(int i=1;i<=n;i++) cnt[i]=0,dist[i]=0x3f3f3f3f,st[i]=false;
    queue<int> q;
    q.push(1);
    dist[1]=0;
    cnt[1]=1;
    st[1]=true;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i].FI,w=G[u][i].SE;
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n) return true;
                if(!st[v]) {
                    st[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&o);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=m+o;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(i<=m) G[u].PB(MP(v,w)),G[v].PB(MP(u,w));
            else G[u].PB(MP(v,-w));
        }
        puts(spfa()?"YES":"NO");
    }
    return 0;
}