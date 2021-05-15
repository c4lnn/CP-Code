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
const int N=205;
int x[N],y[N];
int n,cnt,cnt_scc,top,dfn[N],low[N],c[N],stk[N];
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
bool check(int mid) {
    for(int i=1;i<=n*2;i++) G[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(abs(x[i]-x[j])>=mid) continue;
            if(abs(y[i]-y[j])>=mid*2) continue;
            if(y[i]>y[j]) {
                if(y[i]-y[j]<mid) G[i+n].PB(i);
                else G[i+n].PB(j+n);
            }
            else if(y[i]<y[j]) {
                if(y[j]-y[i]<mid) G[i].PB(i+n);
                else G[i].PB(j);
            }
            else G[i].PB(j+n),G[i+n].PB(j);
        }
    cnt=cnt_scc=top=0;
    for(int i=1;i<=n*2;i++) dfn[i]=low[i]=c[i]=0,ins[i]=false;
    for(int i=1;i<=n*2;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) if(c[i]==c[i+n]) return false;
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        int l=0,r=20000;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}