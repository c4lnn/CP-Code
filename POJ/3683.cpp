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
const int N=2005;
int n,s[N],t[N],d[N],cnt,cnt_scc,top,stk[N],dfn[N],low[N],c[N];
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
bool check(int a,int b,int c,int d) {
    if(d<=a||c>=b) return false;
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int h,m;
        scanf(" %d:%d",&h,&m);
        s[i]=h*60+m;
        scanf(" %d:%d",&h,&m);
        t[i]=h*60+m;
        scanf("%d",&d[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(check(s[i],s[i]+d[i],s[j],s[j]+d[j])) G[i].PB(j+n);
            if(check(s[i],s[i]+d[i],t[j]-d[j],t[j])) G[i].PB(j);
            if(check(t[i]-d[i],t[i],s[j],s[j]+d[j])) G[i+n].PB(j+n);
            if(check(t[i]-d[i],t[i],t[j]-d[j],t[j])) G[i+n].PB(j);
        }
    }
    for(int i=1;i<=2*n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) if(c[i]==c[i+n]) {puts("NO");return 0;}
    puts("YES");
    for(int i=1;i<=n;i++) {
        if(c[i]<c[i+n]) printf("%02d:%02d %02d:%02d\n",s[i]/60,s[i]%60,(s[i]+d[i])/60,(s[i]+d[i])%60);
        else printf("%02d:%02d %02d:%02d\n",(t[i]-d[i])/60,(t[i]-d[i])%60,t[i]/60,t[i]%60);
    }
    return 0;
}