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
const int N=105;
int n,m,dist[N],cnt[N];
bool st[N];
VPII G[N];
bool spfa() {
    for(int i=1;i<=n;i++) st[i]=false,cnt[i]=0,dist[i]=0x3f3f3f3f;
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
            if(dist[v]>dist[u]+w) {
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
    while(~scanf("%d%d",&n,&m)&&n) {
        for(int i=1;i<=n+2;i++) G[i].clear();
        for(int i=1;i<=m;i++) {
            int a,b,c;
            char d[3];
            scanf("%d%d%s%d",&a,&b,d,&c);
            a++;
            if(d[0]=='g') G[a+b].PB(MP(a-1,-c-1));
            else G[a-1].PB(MP(a+b,c-1));
        }
        for(int i=1;i<=n+1;i++) G[n+2].PB(MP(i,0));
        n+=2;
        puts(spfa()?"lamentable kingdom":"successful conspiracy");
    }
    return 0;
}