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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1005;
int n,ml,md,dist[N],cnt[N];
bool st[N];
VPII g[N];
int spfa() {
    queue<int> q;
    q.push(1);
    for(int i=1;i<=n;i++) dist[i]=0x3f3f3f3f;
    dist[1]=0;
    cnt[1]=1;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i].FI,w=g[u][i].SE;
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n) return -1;
                if(!st[v]) {st[v]=true,q.push(v);}
            }
        }
    }
    return dist[n]==0x3f3f3f3f?-2:dist[n];
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d%d",&n,&ml,&md);
    for(int i=1;i<=ml;i++) {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        g[a].PB(MP(b,d));
    }
    for(int i=1;i<=md;i++) {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        g[b].PB(MP(a,-d));
    }
    printf("%d\n",spfa());
    return 0;
}