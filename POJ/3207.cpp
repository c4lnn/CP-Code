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
int a[N],b[N];
int n,m,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N];
bool ins[N];
VI G[N];
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    stk[++top]=u;
    ins[u]=true;
    for(int i=0;i<SZ(G[u]);i++) {
        int v=G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        cnt_scc++;
        int x;
        do {
            x=stk[top--];
            ins[x]=false;
            c[x]=cnt_scc;
        } while(u!=x);
    }
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i]) swap(a[i],b[i]);
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) {
            if(i==j) continue;
            if(a[j]>=b[i]||b[j]<=a[i]||a[j]<=a[i]&&b[j]>=b[i]||a[j]>=a[i]&&b[j]<=b[i]) continue;
            G[i].PB(j+m);
            G[i+m].PB(j);
        }
    for(int i=1;i<=m*2;i++) if(!dfn[i]) tarjan(i);
    bool f=false;
    for(int i=1;i<=m;i++) if(c[i]==c[i+m]) {f=true;break;}
    puts(f?"the evil panda is lying again":"panda is telling the truth...");
    return 0;
}