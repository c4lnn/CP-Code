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
int n,m,dist[N],cnt[N];
bool st[N];
VPII G[N];
bool spfa() {
    for(int i=1;i<=n;i++) st[i]=false,cnt[i]=0,dist[i]=0xc0c0c0c0;
    queue<int> q;
    q.push(n);
    st[n]=true;
    dist[n]=0;
    cnt[n]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i].FI,w=G[u][i].SE;
            if(dist[v]<dist[u]+w) {
                dist[v]=dist[u]+w;
                cnt[v]++;
                if(cnt[v]>=n) return false;
                if(!st[v]) {
                    st[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=1;i<=n+1;i++) G[i].clear();
        for(int i=1;i<=m;i++) {
            int u,v,w;
            char s[2];
            scanf("%s%d%d",s,&u,&v);
            if(s[0]=='P') {
                int w;
                scanf("%d",&w);
                G[v].PB(MP(u,w));
                G[u].PB(MP(v,-w));
            }
            else G[v].PB(MP(u,1));
        }
        for(int i=1;i<=n;i++) G[n+1].PB(MP(i,0));
        n++;
        puts(spfa()?"Reliable":"Unreliable");
    }
    return 0;
}