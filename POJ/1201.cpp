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
const int N=5e4+5;
int n,mx,dist[N];
bool st[N];
VPII G[N];
void spfa() {
    for(int i=0;i<=mx;i++) dist[i]=0xc0c0c0c0;
    queue<int> q;
    q.push(0);
    dist[0]=0;
    st[0]=true;
    while(q.size()) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=0;i<SZ(G[u]);i++) {
            int v=G[u][i].FI,w=G[u][i].SE;
            if(dist[v]<dist[u]+w) {
                dist[v]=dist[u]+w;
                if(!st[v]) {
                    st[v]=true;
                    q.push(v);
                }
            }
        }
    }
    printf("%d\n",dist[mx]);
}
int main() {
    //freopen("D:/Program Files (x86)/Sublime Text 3/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        v++;
        mx=max(mx,v);
        G[u].PB(MP(v,w));
    }
    for(int i=0;i<mx;i++) G[i].PB(MP(i+1,0));
    for(int i=1;i<=mx;i++) G[i].PB(MP(i-1,-1));
    spfa();
    return 0;
}